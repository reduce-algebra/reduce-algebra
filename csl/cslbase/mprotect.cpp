// Testing memory protection to spot write operations  (A C Norman, 2018)

// The BSD license as used elsewhere with CSL applies to this code.


// This is a file where I am developing, demonstrating and testing code
// that I might wish to use as part of a write barrier in a generational
// garbage collector. The concept will be to mark all heap pages as read-only,
// and then have a signal handler that traps write operations and both
// resets the page to be read-wrire and records that it is "dirty".
// I would like this to work in a multi-threaded environment too, and being
// confident about that adds to the delicacy.

// I can at least dream that when I check this in somebody who is a greater
// expert than me in this area will provide me with useful advice! The
// questions highest in my mind at present are:
// (1) What question do I not even know enough to ask?
// (2) Just how does the strategy embodied here interact with threading
//     across a range of operating systems? For instance in the Boehm garbage
//     collector configuration files I think I see things that make me worry
//     that this way of doing things might not be supportable at all on
//     multi-threaded BSD platforms. I am expecting to use C++11 std::thread
//     and friends for thread support.
// (3) I have heard suggestion that some platforms use guard pages to
//     support gradually-allocated stack space, and that that involves
//     trapping SIGSEGV. What are the interactions between that and this, and
//     if the combination is problemetic then what platforms does it apply
//     on and what can be done to ameliorate the situation (eg making my
//     trap handler chain to the one extant when I set things up?).


// STD_FORMAT_MACROS really ought not to be needed, but it helps in case
// your C++ compiler is a little old.
#define __STDC_FORMAT_MACROS 1

#define __USE_MINGW_ANSI_STDIO 1

#include <stdio.h>
#include <string.h>

// I will need to use different system calls on Linux and Windows! At present
// the code covers Linux, Macintosh and *BSD, all using mprotefct/sigaction,
// and Windows using WriteWatch.
// Cases such as Solaris and other Unix variants, Android,
// z/OS, RiscOS and the (un-)like have not been considered at all. 

// Right now the Linux (etc) and Winndows versions are really very different
// in structure and their arrangement in the file here is not at all neat.
// That needs sorting out!

#include <signal.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <atomic>

#ifdef WIN32
#include <windows.h>
#else // !WIN32
#include <unistd.h>
#include <sys/mman.h>
#endif // !WIN32

// The system will have its idea of the granularity at which it can
// provide memory protection. At least in this demo code I want to know
// the largest and smallest size pages I am liable to need to deal with.
// On Linux I find a page_size of 0x1000 while on Cygwin I see 0x10000.

#define MAX_PAGE_SIZE 0x10000
#define MIN_PAGE_SIZE 0x1000

#define MAX_MEMORY (6*MAX_PAGE_SIZE)

// I am going to set up a region of memory aligned so that it starts
// at a multiple of MAX_PAGE_SIZE.
//

char *raw_memory;
char *memory;

// I rather hope that an atomic_flag will be only a single byte (ie that the
// hardware will support a test-and-set operation on individual bytes), but
// there is no guarantee of that. However I will be using just one atomic_flag
// for each page of memory, so even in the worst case that I can plausibly
// imagine the space overead is not too bad. In this sample code I do not
// yet know the actual page size, so I will use a pessimistic size here.

std::atomic_flag memory_used[(MAX_MEMORY+MAX_PAGE_SIZE+MIN_PAGE_SIZE-1)/
                             MIN_PAGE_SIZE];

static size_t page_size;


static inline void fail(const char *msg)
{
    printf("%s", msg);
    exit(EXIT_FAILURE);
}

#ifndef WIN32

static void handler(int sig, siginfo_t *si, void *unused);

typedef int action_handler(int, const siginfo_t *, void *);

// The following function is actually something of a joke! It arranges to
// mask SIGSEGV and SIGBUS events while calling mprotect. It does this
// because my regular handler for those two exceptions calls mprotect. So
// if an exception arose while mprotect was already being executed the
// consequences could be BAD. Making the exceptions might be expected to
// help. However two issues arise. The first is that I see a comment in
// the documentation that if I use sigprocmask to mask out SIGSEGV or
// SIGBUS and one of those events arises then the result is undefined. Which
// is not in fact a lot better than the situation I was in without all of
// this! The second issue is that at least in my code if a SIGSEGV or SIGBUS
// occurs while the main code is setting up its trap handlers I have a
// disaster on my hand anyway. I will keep this code here since I expect
// sigprocmask to be cheap and it gives me a chance to write this section
// is really here to say:
//      mprotect is not async-signal-safe so for my code to be valid
//      I must ensure that no signal handler calls it while it is active
//      in the interrupted part of the program. The easy way to achieve
//      this is to avoid its use in any signal handler (doh!) but it should
//      also be acceptable if I can guarantee that any signal handler that
//      does use it can never be activated while it is being used, and the
//      masking done here should achieve that.

static inline int safe_mprotect(void *a, size_t n, int m)
{   sigset_t ss, ssold;
    sigemptyset(&ss);
    sigaddset(&ss, SIGSEGV);
    sigaddset(&ss, SIGBUS);
    if (sigprocmask(SIG_BLOCK, &ss, &ssold) == -1)
        fail("can not block SIGSEGv/SIGBUS\n");
    int r = mprotect(a, n, m);
    if (sigprocmask(SIG_SETMASK, &ssold, NULL) == -1)
        fail("Unable to restart signal mask\n");
    return r;
}

#endif // !WIN32

int main(int argc, char *argv[])
{
#ifdef WIN32
    SYSTEM_INFO si;
    GetSystemInfo(&si);
// The page size gives the granularity at which memory protection can be
// applied, and hence the granularity of information that WRITE_WATCH uses
// when reporting "dirty pages".
    printf("Windows page size = %" PRIx64 "\n",
        (uint64_t)si.dwPageSize);
// The allocation granularity is to do with aligment for memory block
// allocation. Since and If I pass a NULL as the first argument to
// VirtualAlloc I do not need to do anything about this, but the
// returned memory will end up alligned as per this value.
    printf("Windows allocation granularity = %" PRIx64 "\n",
        (uint64_t)si.dwAllocationGranularity);
    printf("About to VirtualAlloc\n");
    fflush(stdout);
    memory = (char *)VirtualAlloc(
        NULL,                    // system selects address
        MAX_MEMORY,              // size to allocate
// I should consider MEM_WRITE_WATCH here since there is a chance that that
// does pretty well exactly what I need! Well what it does is arrange to
// monitow writes to all the area of memory allocated here.
        MEM_RESERVE | MEM_COMMIT | MEM_WRITE_WATCH,
                                 // allocate reserved pages
        PAGE_READWRITE);         // Read and Write access
    if (memory == NULL) fail("Unable to allocate memory\n");
    printf("VirtualAlloc = %p\n", memory);
#else // !WIN32
    raw_memory = (char *)malloc(MAX_MEMORY+MAX_PAGE_SIZE);
    if (raw_memory == NULL) fail("Unable to allocate memory\n");
    memory = (char *)((-(uintptr_t)MAX_PAGE_SIZE) &
                      (MAX_PAGE_SIZE - 1 + (uintptr_t)&raw_memory[0]));
#endif // !WIN32
    printf("Start of memory block:  %#" PRIx64 "\n", (uint64_t)memory);

    for (size_t i=0; i<(MAX_MEMORY+MAX_PAGE_SIZE)/MIN_PAGE_SIZE; i++)
        memory_used[i].clear();
    printf("size of atomic_flag = %.1f\n",
        sizeof(memory_used)/(double)((MAX_MEMORY+MAX_PAGE_SIZE)/MIN_PAGE_SIZE));

#ifndef WIN32
// Set a signal action handler for SIGSEGV
    struct sigaction new_action, old_action1, old_action2;
// Do not disable any other signals while you process this one.
    sigemptyset(&new_action.sa_mask);
// handle the signal using the action handler. If an interruptible
// system call is active when the sigal arises then restart it on exit.
    new_action.sa_flags = SA_SIGINFO | SA_RESTART;
    new_action.sa_sigaction = handler;
// Well it seems that Windows and Linux send a SIGSEGV if I attempt to
// write to protected memory, while on a Macintosh there will be a
// SIGBUS. So I set up a handler for both!
    if (sigaction(SIGSEGV, &new_action, &old_action1) == -1)
        fail("can not trap SIGSEGV\n");
    if (sigaction(SIGBUS, &new_action, &old_action2) == -1)
        fail("can not trap SIGBUS\n");
#endif // WIN32

// Determine the page size that this computer uses and complain if the
// result is unexpected.
#ifdef WIN32
    page_size = si.dwPageSize;
#else
    page_size = sysconf(_SC_PAGE_SIZE);
#endif
    if (page_size == (size_t)(-1)) fail("unable to get page size\n");
    printf("page_size = %d = %#x\n", (int)page_size, (int)page_size);
    if (page_size < MIN_PAGE_SIZE ||
        page_size > MAX_PAGE_SIZE)
        fail("page_size is unacceptable here\n");

#ifndef WIN32
// Here as a demonstration I will make pages 1 and 3 read-only.
    if (safe_mprotect(memory + 1*page_size, page_size, PROT_READ) == -1)
        fail("unable to page page 1 read-only");
    if (safe_mprotect(memory + 3*page_size, page_size, PROT_READ) == -1)
        fail("unable to make page 3 read-only");
#endif // !WIN32

// I am going to step through the memory writing bytes. Each time I
// hit a page that I have marked read-only I should display a message
// and reset it is R/W, and the rest of that page should then be
// updated painlessly.

#ifdef WIN32
#define STEP (2*page_size-1313)
#else // !WIN32
#define STEP 1313
#endif // !WIN32
    for (char *p = memory ; p<memory+6*page_size ; p+=STEP)
    {   *p = 'a';
#ifdef WIN32
        printf("Probe at %" PRIx64 "\n", (uint64_t)(p - memory));
#else // !WIN32
        printf("#");
#endif // !WIN32
        fflush(stdout);
    }

    printf("\nLoop completed\n");

// Check that I have successfully written data everywhere I tried to.
    for (char *p = memory ; p<memory+6*page_size ; p+=STEP)
    {   if (*p != 'a') fail("memory not correct at end\n");
    }

#ifdef WIN32
    void *changedpages[1000];
    ULONG nchangedpages = 1000;
    ULONG granularity;
    if (GetWriteWatch(WRITE_WATCH_FLAG_RESET,
            (void *)memory,
            MAX_MEMORY,
            changedpages,
            &nchangedpages,
            &granularity) != 0) fail("GetWriteWatch failed\n");
    printf("Number of changed pages = %" PRIu64 "\n", (uint64_t)nchangedpages);
    printf("Granularity = %" PRIu64 "\n", (uint64_t)granularity);
    for (unsigned int i=0; i<nchangedpages; i++)
        printf("%u: %" PRIx64 "\n", i, (uint64_t)changedpages[i]);
#else // !WIN32
    for (size_t i=0; i<MAX_MEMORY/page_size; i++)
    {
// A side effect of checking the value of memory_used is that I set it!
        if (memory_used[i].test_and_set())
        {   printf("Page %u was used\n", (unsigned int)i);
        }
        memory_used[i].clear();  // leave the map tidy.
    }
#endif // !WIN32

    printf("End of demonstration/test\n");
    exit(EXIT_SUCCESS);
}

#ifndef WIN32

// printf is not async exception safe, but write is, so I arrange that
// I can generate messages from within the handler using write.

static void safe_print0(const char *msg)
{   if (write(0, msg, strlen(msg)) < 0)
        fail("write to stdout failed\n");
}

static void safe_print1(const char *msg1, uint64_t x, const char *msg2)
{   if (write(0, msg1, strlen(msg1)) < 0)
        fail("write to stdout failed\n");
    for (int i=0; i<16; i++)
    {   if (write(0,
            (const char *)"0123456789abcdef"+((x>>(60-4*i)) & 0xf), 1) < 0)
            fail("write to stdout failed\n");
    }
    if (write(0, msg2, strlen(msg2)) < 0)
        fail("write to stdout failed\n");
}

static void handler(int sig, siginfo_t *si, void *unused)
{   int errsav = errno;
    uintptr_t addr = (uintptr_t)si->si_addr;
    safe_print1("\nGot exception at address: 0x", addr, "\n");
    safe_print0(".. try to reinstate write access...\n");
    addr = addr & -(uintptr_t)page_size;
    safe_print1("page to make RW at 0x", addr, "\n");
// Well in the code here the only thing I do to a memory_used location is
// setting it, and I rather suspect that using an explicitly carefully
// atomic type and a test-and-set operation is not needed - ie I could
// probably just use and array of bools.
    if (addr >= (uintptr_t)memory &&
        addr < (uintptr_t)memory + MAX_MEMORY)
    {
// mprotect is NOT in the list of async-signal-safe functions and so I
// may only use it here if I guarantee that this handler will not be activated
// when I am calling it elsewhere. See safe_mprotect for the arrangements
// that I make!
        if (mprotect((void *)addr, page_size, PROT_READ | PROT_WRITE) == -1)
            fail("unable to restart R/W status to memory page");
        memory_used[(addr - (uintptr_t)memory)/page_size].test_and_set();
    }
    else fail("SIGSEGV or SIGBUS outside expected address range\n");
    safe_print0("Resume test:\n");
    errno = errsav;
}

#endif // !WIN32

// end of mprotect.cpp
