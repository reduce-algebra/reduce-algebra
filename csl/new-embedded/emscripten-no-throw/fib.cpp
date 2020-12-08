#include <iostream>
#include <ctime>
#include <stdexcept>

volatile long long int kkk = 0;
volatile bool never = false;

void harmless()
{   kkk = 12345;
}

unsigned long long int fib(int n)
{   kkk++;
    if (never) harmless();
    if (n < 2) return 1;
    else return fib(n-1) + fib(n-2);
}

unsigned long long int fib1(int n)
{   kkk++;
    if (never) throw std::logic_error("bad");
    if (n < 2) return 1;
    else return fib1(n-1) + fib1(n-2);
}

class WithDestruct
{
public:
   ~WithDestruct()
   {   kkk++;
   }
};

unsigned long long int fib2(int n)
{   WithDestruct RAII;
    if (never) throw std::logic_error("bad");
    if (n < 2) return 1;
    else return fib2(n-1) + fib2(n-2);
}

int functionThatThrows(int n)
{   kkk *= 13;
    if (never) throw std::logic_error("bad");
    else if (n < 1) return kkk;
    else return kkk*functionThatThrows(n-1);
}

unsigned long long int fib3(int n)
{   try
    {   kkk++;
        if (never) return functionThatThrows(n);
        if (n < 2) return 1;
        else return fib3(n-1) + fib3(n-2);
    }
    catch (std::exception &e)
    {   kkk=54321;
        throw;
    }
}


int main()
{   std::cout << "Starting" << std::endl;
    kkk = 0;
    clock_t c0 = clock(), c1;
    std::cout << fib(48) << "\n";
    c1 = clock();
    std::cout << "fib  " << kkk << " " << (c1-c0)/(double)CLOCKS_PER_SEC << std::endl;
    kkk = 0;
    c0 = clock();
    std::cout << fib1(48) << "\n";
    c1 = clock();
    std::cout << "fib1 " << kkk << " " << (c1-c0)/(double)CLOCKS_PER_SEC << std::endl;
    kkk = 0;
    c0 = clock();
    std::cout << fib2(48) << "\n";
    c1 = clock();
    std::cout << "fib2 " << kkk << " " << (c1-c0)/(double)CLOCKS_PER_SEC << std::endl;
    kkk = 0;
    c0 = clock();
    std::cout << fib3(48) << "\n";
    c1 = clock();
    std::cout << "fib3 " << kkk << " " << (c1-c0)/(double)CLOCKS_PER_SEC << std::endl;
    return 0;
}
