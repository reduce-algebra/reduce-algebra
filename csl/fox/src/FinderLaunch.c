/*
    File:        FinderLaunch.c

    Description:
                A routine for sending an open documents Apple event to the
                finder.  This routine provides functionality equivalent to
                selecting a document/file/application and choosing the
                open command in the Finder's file menu.

    Author:     JM

    Copyright:  © Copyright 2003 Apple Computer, Inc. All rights reserved.

    Disclaimer: IMPORTANT: This Apple software is supplied to you by
    Apple Computer, Inc.  ("Apple") in consideration of your agreement
    to the following terms, and your use, installation, modification
    or redistribution of this Apple software constitutes acceptance of
    these terms.  If you do not agree with these terms, please do not
    use, install, modify or redistribute this Apple software.

    In consideration of your agreement to abide by the following
    terms, and subject to these terms, Apple grants you a personal,
    non-exclusive license, under Apple's copyrights in this original
    Apple software (the "Apple Software"), to use, reproduce, modify
    and redistribute the Apple Software, with or without
    modifications, in source and/or binary forms; provided that if you
    redistribute the Apple Software in its entirety and without
    modifications, you must retain this notice and the following text
    and disclaimers in all such redistributions of the Apple Software.
    Neither the name, trademarks, service marks or logos of Apple
    Computer, Inc. may be used to endorse or promote products derived
    from the Apple Software without specific prior written permission
    from Apple.  Except as expressly stated in this notice, no other
    rights or licenses, express or implied, are granted by Apple
    herein, including but not limited to any patent rights that may be
    infringed by your derivative works or by other works in which the
    Apple Software may be incorporated.

    The Apple Software is provided by Apple on an "AS IS" basis.
    APPLE MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT
    LIMITATION THE IMPLIED WARRANTIES OF NON-INFRINGEMENT,
    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, REGARDING
    THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR IN
    COMBINATION WITH YOUR PRODUCTS.

    IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT,
    INCIDENTAL OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
    TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) ARISING IN ANY WAY OUT
    OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION OF THE
    APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF
    CONTRACT, TORT (INCLUDING NEGLIGENCE), STRICT LIABILITY OR
    OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.

    Change History (most recent first):
    7/2003    MK    Updated for Project Builder
    9/13/99 created by JM
    2004 Apr 18 simplified by JPff to a single file name

*/
#include <Carbon/Carbon.h>

OSErr FinderLaunch(const char *target)
{
    OSErr err;
    AppleEvent theAEvent, theReply;
    AEAddressDesc fndrAddress;
    AEDescList targetListDesc;
    OSType fndrCreator;
    AliasHandle targetAlias;

    FSSpec fileinfo;
    FSRef privateInfo;

/*
 * FSPathMakeRef needs (UInt8 *) as its first argument, but my current
 * understanding is that this is "just" a string but in an exlicitly
 * 8-bit code. Thus "char *" ought to suffice UNLESS you are compiling in a
 * world where char is a 16-bit item or some other wide-char messing about is
 * happening. The C compiler with 10.3 adjusted things without an explicit
 * cast hear and gave a warning. WIth 10.4 it gives an error.
 *    ACN, August 2005
 */
    err = FSPathMakeRef((const UInt8 *)target, &privateInfo, NULL);
#ifdef DEBUG
    printf("FSPathMakeRef()-> %d\n", err);
#endif
    err = FSGetCatalogInfo(&privateInfo, kFSCatInfoNone,
                           NULL, NULL, &fileinfo, NULL);
#ifdef DEBUG
    printf("FSGetCatalogInfo()-> %d\n",err);
#endif
    /* set up locals  */
    AECreateDesc(typeNull, NULL, 0, &theAEvent);
    AECreateDesc(typeNull, NULL, 0, &fndrAddress);
    AECreateDesc(typeNull, NULL, 0, &theReply);
    AECreateDesc(typeNull, NULL, 0, &targetListDesc);
    targetAlias = NULL;
    fndrCreator = 'MACS';

    /* create an open documents event targeting the finder */
    err = AECreateDesc(typeApplSignature, (Ptr) &fndrCreator,
                       sizeof(fndrCreator), &fndrAddress);
#ifdef DEBUG
    printf("AECreateDesc()-> %d\n",err);
#endif

    if (err == noErr) {
      err = AECreateAppleEvent(kCoreEventClass, kAEOpenDocuments,
                               &fndrAddress, kAutoGenerateReturnID,
                               kAnyTransactionID, &theAEvent);
#ifdef DEBUG
      printf("AECreateAppleEvent()-> %d\n",err);
#endif
    }

    if (err == noErr) {
      err = AECreateList(NULL, 0, false, &targetListDesc);
#ifdef DEBUG
      printf("AECreateList()-> %d\n", err);
#endif
    }

    if (err == noErr) {
      err = NewAlias(NULL, &fileinfo, &targetAlias);
#ifdef DEBUG
      printf("NewAlias()-> %d\n",err);
#endif

      if (err == noErr) {
        HLock((Handle) targetAlias);
        err = AEPutPtr(&targetListDesc,
                       1,
                       typeAlias,
                       *targetAlias,
                       GetHandleSize((Handle) targetAlias));
#ifdef DEBUG
        printf("AEPutPtr()-> %d\n",err);
#endif
        HUnlock((Handle) targetAlias);
      }
    }

    /* add the file list to the apple event */
    if( err == noErr ) {
      err = AEPutParamDesc(&theAEvent, keyDirectObject, &targetListDesc);
#ifdef DEBUG
      printf("AEPutParamDesc()-> %d\n",err);
#endif
    }
    if (err == noErr) {
      /* send the event to the Finder */
      err = AESend(&theAEvent, &theReply, kAENoReply,
                   kAENormalPriority, kAEDefaultTimeout, NULL, NULL);
#ifdef DEBUG
      printf("AESend()-> %d\n",err);
#endif
    }

    /* clean up and leave */
    if (targetAlias != NULL) DisposeHandle((Handle) targetAlias);
    AEDisposeDesc(&targetListDesc);
    AEDisposeDesc(&theAEvent);
    AEDisposeDesc(&fndrAddress);
    AEDisposeDesc(&theReply);
    return err;
}
