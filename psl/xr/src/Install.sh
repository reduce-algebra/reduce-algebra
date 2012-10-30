#!/bin/sh

# Shell script to set up the XReduce file defaults for the X resource file
# and Reduce initialisation script.  Hope it works; I'm no shell programmer

# Chris Cannam, Jan 1993

echo
echo
echo '                ========================================'
echo '                        XR Installation Program'
echo '                ========================================'
echo '                 Chris Cannam, ZIB Berlin: January 1993'
echo '                ========================================'
echo
echo '    This is the XR Installation program, which is designed to assist'
echo '         in installing XR in systems for which a pre-installed'
echo '    version is not supplied in the current Reduce installation tree.'
echo
echo ' This program alters the files xr.red.orig  and XR.orig  to reflect the'
echo ' requirements of your system, placing the new versions in xr.red and XR'
echo ' respectively.  It does not affect the .orig versions of the files, and'
echo ' it may safely be run more than once.   It then runs  Reduce to compile'
echo ' the RLisp code necessary for the use of  XR,  runs make to compile the'
echo ' XR sources, and runs the new XR executable in batch mode to create the'
echo ' Help mode search index file.   It then moves the new files to suitable'
echo '                             directories.'
echo
echo ' Please answer any questions you are asked. Entering q or Q in response'
echo ' to a question abandons the whole thing; enter h or H if you need help.'
echo ' For some of the questions there is a default shown in square brackets;'
echo '             to choose the default answer, just hit Return.'
echo
echo ' If you wish to refer to environment variables in pathnames,  they will'
echo ' be expanded;  also, ~ is expanded to $HOME.  It is unwise to use paths'
echo '            containing . or ..; all paths should be absolute.'
echo


# First define a handy function for expanding twiddles &c.

XRedExp() {

   if   [ -x /bin/bash ];
   then /bin/bash -c  "echo $1";
   elif [ -x /bin/csh  ];
   then /bin/csh  -cf "echo $1";
   else echo $1;
   fi
}


# Now discover exactly what is required of us.

echo ' Checking command line options...'
echo
XRedWhich='n'

sleep 1;

if   [ t$1 = 't-install' ];
then echo '    -=> Found -install option; shall only install, not compile.'
     echo
     XRedWhich='i'
elif [ t$1 = 't-compile' ];
then echo '    -=> Found -compile option; shall only compile, not install.'
     XRedWhich='c'
elif [ t$1 = 't-both' ];
then echo '    -=> Found -both option; shall both compile and install.'
     echo
     XRedWhich='b'
else echo '    -=> Found neither -install, -compile nor -both.  Querying...'
fi;

while   [ $XRedWhich = 'n' ];
do echo
   echo '[?] Shall I compile only, install only or do both (c/i/b)? [b] '
   read XRedWhich
   if   [ t$XRedWhich = 'tq' -o t$XRedWhich = 'tQ' ];
   then echo '    Quitting.'
        echo
        exit 0 ;
   elif [ t$XRedWhich = 'tb' -o t$XRedWhich = 'tB' -o t$XRedWhich = 't' ];
   then echo ' Preparing to compile and install.'
        XRedWhich='b'
   elif [ t$XRedWhich = 'tc' -o t$XRedWhich = 'tC' ];
   then echo ' Preparing to compile only.'
        XRedWhich='c'
   elif [ t$XRedWhich = 'ti' -o t$XRedWhich = 'tI' ];
   then echo ' Preparing to install only.'
        XRedWhich='i'
   elif [ t$XRedWhich = 'th' -o t$XRedWhich = 'tH' ];
   then echo
        echo '    I need to know whether to do the full compile/install task,'
        echo '    or whether to do only compilation or only installation.  If'
        echo '    you already have everything compiled  (perhaps because your'
        echo '    XR was supplied as executables  but you need some different'
        echo '    installation,  or because you have already run this program'
        echo '    and it failed after compiling, or something), just install;'
        echo '    if you want to hand-install, just compile.  The compilation'
        echo '    process includes compiling both C and RLisp sources.'
        XRedWhich='n'
   else echo '    Please answer c, i or b, or q to quit or h for help.'
        XRedWhich='n'
   fi;
done


# Now see if we can be clever and find the
# installation locations based on $reduce and things.
# We do some of this even if only compilation is required,
# because we still need to know where REDUCE is.

XRedLI='n'
XRedFN='Reduce-executable'
XRedAuto='no'

if [ $XRedWhich = 'i' -o $XRedWhich = 'b' ];
then

echo ' Checking XR installation source files...'
echo
if   [ -r ./xr.red.orig ]
then echo '    -=> File xr.red.orig present.';
else echo '    -=> File xr.red.orig not found.'
     exit 1;
fi;
if   [ -r ./XR.orig ]
then echo '    -=> File XR.orig present.';
else echo '    -=> File XR.orig not found.'
     exit 1;
fi;
if   [ -r ./fmprint.red ]
then echo '    -=> File fmprint.red present.';
else echo '    -=> File fmprint.red not found.'
     exit 1;
fi;
if   [ -r ./Makefile ]
then echo '    -=> Makefile present.';
else if   [ -r ./makefile ]
     then echo '    -=> Makefile not present; using makefile.';
     else echo '    -=> No make file found.'
          exit 1;
     fi;
fi;

fi;

echo
echo ' Trying to find your version of Reduce...'
echo

if   [ t$reduce = 't' ];
then echo '    -=> Environment variable "reduce" not set.';
elif [ -f $reduce/reduce.img ];
then echo '    -=> File '$reduce'/reduce.img exists'
     sleep 1;
     if   [ -r $reduce/reduce.img ];
     then echo '    -=> It is readable.'
      	  echo '    -=> You might have an image file Reduce.'
          sleep 1;
          if   [ -f $reduce/psl/bpsl ];
          then echo '    -=> File '$reduce'/psl/bpsl exists'
               sleep 1;
      	       if   [ -x $reduce/psl/bpsl ];
      	       then echo '    -=> It is executable.'
                    echo '    -=> You probably have an image file Reduce.'
      	            XRedLI='y'
                    XRedFN='Lisp-executable'
      	       	    XRedFNd=$reduce/psl
      	            XRedFNm='bpsl'
      	       	    XRedINm=$reduce/reduce.img
      	       	    XRedAuto='yes';
                    sleep 1;
      	       else echo '    -=> However, it is not executable.';
               sleep 1;
      	       fi;
      	  else echo '    -=> File '$reduce'/psl/bpsl does not exist.';
          sleep 1;
      	  fi;
     else echo '    -=> However, it is not readable.';
     sleep 1;
     fi;
fi;

if   [ t$XRedAuto = 'tno' ];
then if   [ -f $reduce/reduce ];
     then echo '    -=> File '$reduce'/reduce exists'
          sleep 1;
          if   [ -x $reduce/reduce ];
          then echo '    -=> It is executable.'
      	       echo '    -=> You probably have a binary Reduce.'
               XRedLI='n'
               XRedFN='Reduce-executable'
               XRedFNd=$reduce
      	       XRedFNm='reduce'
      	       XRedAuto='yes';
               sleep 1;
          else echo '    -=> However, it is not executable.';
          sleep 1;
          fi;
     else echo '    -=> Cannot find either of the likely executables.';
     sleep 1;
     fi;
fi;

XRedOK='n'
if   [ t$XRedAuto = 'tyes' ];
then echo
     echo '    I think I can do a partly automatic job,'
     if   [ t$XRedLI = 'ty' ];
     then echo '    using the following parameters:'
      	  echo
          echo '[!] '$XRedFN' is in '$XRedFNd/$XRedFNm';'
      	  echo '[!] Reduce Image is in '$XRedINm'.';
     else echo '    using the following parameter:'
      	  echo
          echo '[!] '$XRedFN' is in '$XRedFNd/$XRedFNm'.';
     fi;
     XRedOK='plugh'
     while [ t$XRedOK = 'tplugh' ];
     do echo
        echo '[?] Shall I use these values (y/n)? [y] '
        read XRedOK
        if   [ t$XRedOK = 'ty' -o t$XRedOK = 'tY' -o t$XRedOK = 't' ];
        then echo  '    OK, automatic it is.  Please answer the following.';
      	elif [ t$XRedOK = 'tn' -o t$XRedOK = 'tN' ];
        then echo '    All right:  Please answer the following.';
        elif [ t$XRedOK = 'tq' -o t$XRedOK = 'tQ' ];
      	then echo '    Quitting.'
      	     echo
      	     exit 0 ;
        elif [ t$XRedOK = 'th' -o t$XRedOK = 'tH' ];
      	then echo '    These parameters have been decided upon as  reasonable'
      	     echo '    possible values by looking at the environment variable'
      	     echo '    $reduce and the contents of the directory named in it.'
      	     echo '    It is probable that they are the right values,  but if'
      	     echo '    you know that not all of them are right, as may happen'
      	     echo '    if you have an unusual system, you will have to supply'
      	     echo '    the right answers yourself, in which case enter n.  If'
      	     echo '    you are happy with the default  parameters,  or if you'
      	     echo '    really have no idea either way, you should enter y.';
             XRedOK='plugh';
      	else echo '    Please answer y or n, or q to quit or h for help.'
             XRedOK='plugh';
      	fi;
     done;
else echo
     echo '    I cannot deduce enough information to carry'
     echo '    out a partly-automatic compile or install.'
     echo
     echo '    Working manually:  Please answer the following.';
fi;


if [ t$XRedOK = 'tn' -o t$XRedOK = 'tN' ];

# Discover whether we run a Reduce binary ('n')
# or image ('y'); result in XRedLI.

then XRedSFin='no'
     while [ $XRedSFin = 'no' ];
     do echo
        echo '[?] Is your version of Reduce a Lisp Image version (y/n)? [y] '
        read XRedLI
        if   [ t$XRedLI = 'ty' -o t$XRedLI = 'tY' -o t$XRedLI = 't' ];
        then echo '    Preparing to install for a Lisp Image Reduce.'
             XRedFN='Lisp-executable'
             XRedSFin='yes' ;
        elif [ t$XRedLI = 'tn' -o t$XRedLI = 'tN' ];
        then echo '    Preparing to install for a binary Reduce.'
      	     XRedFN='Reduce-executable'
             XRedSFin='yes' ;
        elif [ t$XRedLI = 'tq' -o t$XRedLI = 'tQ' ];
        then echo '    Quitting.'
      	     echo
      	     exit 0 ;
        elif [ t$XRedLI = 'th' -o t$XRedLI = 'tH' ];
        then 
        echo '    If you have a MIPS or Sun4 SunOS machine, you probably have'
        echo '    a binary Reduce, not a Lisp Image one.  Most other machines'
        echo '    use a Lisp Image Reduce.  If your Reduce displays a message'
        echo '    at startup saying it is loading an Image file, then it is a'
        echo '    Lisp Image Reduce.  If you normally run Reduce by executing'
        echo '    a shellscript, you can pretend your Reduce is a binary one,'
        echo '    and give the path of the script as the binary executable.' ;
        else echo '    Please answer y or n, or q to quit or h for help.' ;
        fi ;
     done

# Get default for reducePath

     if [ t$reduce = 't' ];
     then XRedFNdD='plugh';
     else if [ $XRedFN = 'Lisp-executable' ];
        then XRedFNdD=$reduce/psl;
        else XRedFNdD=$reduce;
        fi;
        if   [ -d $XRedFNdD ];
        then :;
        else XRedFNdD='plugh';
        fi;
     fi;

# Get reducePath into XRedFNd

     XRedSFin='no'

     while [ $XRedSFin = 'no' ];
     do echo
        if   [ $XRedFNdD = 'plugh' ];
        then echo '[?] Enter path of directory of '$XRedFN':';
        else echo '[?] Enter path of directory of '$XRedFN': ['$XRedFNdD'] ';
        fi;
        read XRedFNd
	XRedFNd=`XRedExp $XRedFNd`
        if   [ t$XRedFNd = 'tq' -o t$XRedFNd = 'tQ' ];
        then echo '    Quitting.'
             echo
      	     exit 0 ;
        elif [ t$XRedFNd = 't' ];
        then if   [ $XRedFNdD = 'plugh' ];
             then echo '    Sorry, there is no default available here';
             else XRedFNd=$XRedFNdD;
                  echo '    Using directory '$XRedFNd' for '$XRedFN'.'
                  XRedSFin='yes';
             fi;
        elif [ t$XRedFNd = 'th' -o t$XRedFNd = 'tH' ];
        then echo
        echo '    The directory containing the executable is normally kept in'
        echo '    the environment variable  $reduce,  for a binary Reduce, or'
      	echo '    $reduce/psl, for an Image version.  If this variable is not'
        echo '    set, try executing "which reduce";  this may tell you where'
        echo '    the executable is kept.'
        elif [ -d $XRedFNd ];
        then echo '    Using directory '$XRedFNd' for '$XRedFN'.'
             XRedSFin='yes' ;
        else echo '    '$XRedFNd' is not a directory.  Try again.' ;
        fi ;
     done

# Get default for reduceName

     if   [ $XRedFN = 'Lisp-executable' ];
     then XRedFNmD='bpsl';
     else XRedFNmD='reduce';
     fi;
     if   [ -f $XRedFNd/$XRedFNmD ];
     then if [ -x $XRedFNd/$XRedFNmD ];
          then :;
          else XRedFNmD='plugh';
          fi;
     else XRedFNmD='plugh';
     fi;

# Get reduceName into XRedFNm

     XRedSFin='no'
     while [ $XRedSFin = 'no' ];
     do echo
        if   [ $XRedFNmD = 'plugh' ];
        then echo '[?] Enter filename of '$XRedFN' in that dir:'
        else echo '[?] Enter filename of '$XRedFN' in that dir: ['$XRedFNmD']';
        fi;
        read XRedFNm
	XRedFNm=`XRedExp $XRedFNm`
        if   [ t$XRedFNm = 'tq' -o t$XRedFNm = 'tQ' ];
        then echo '    Quitting.'
      	     echo
      	     exit 0 ;
        elif [ t$XRedFNm = 't' ];
        then if   [ $XRedFNmD = 'plugh' ];
             then echo '    Sorry, there is no default available here';
             else XRedFNm=$XRedFNmD;
                  echo '    Using file '$XRedFNd'/'$XRedFNm' for '$XRedFN'.'
                  XRedSFin='yes';
             fi;
        elif [ t$XRedFNm = 'th' -o t$XRedFNm = 'tH' ];
        then echo
          if [ t$XRedLI = 'ty' -o t$XRedLI = 'tY' ];
        then
        echo '    This file is, for an Image File Reduce, the file containing'
      	echo '    the Lisp executable that is used to load the Image. Usually'
        echo '    this is the file $reduce/psl/bpsl.  You should already have'
      	echo '    given me the directory path, in reply to the last question,'
      	echo '    so now all I need is the name of the file.' ;
        else
        echo '    This file is, for a binary Reduce,  the actual Reduce exec-'
        echo '    utable file.  It is usually the file $reduce/reduce; as you'
        echo '    should have already given me the  directory path,  in reply'
      	echo '    to the last question, now I only need the name of the file.';
        fi ;
        elif [ -f $XRedFNd/$XRedFNm ];
        then if   [ -x $XRedFNd/$XRedFNm ]
             then echo '    Using file '$XRedFNd'/'$XRedFNm' for '$XRedFN'.'
      	          XRedSFin='yes' ;
             else echo '    '$XRedFNd'/'$XRedFNm' not executable; try again.';
             fi ;
        else echo '    '$XRedFNd/$XRedFNm' nonexistent or special; try again.';
        fi ;
     done;

     if   [ $XRedFN = 'Lisp-executable' ];
     then

# Get default for reduceImageFile

          if   [ t$reduce = 't' ];
          then XRedINmD='plugh';
          else XRedINmD=$reduce/reduce.img;
               if   [ -f $XRedINmD ];
               then if   [ -r $XRedINmD ];
                    then :;
                    else XRedINmD='plugh';
                    fi;
               else XRedINmD='plugh';
               fi;
          fi;

# Get reduceImageFile into XRedINm

          XRedSFin='no'
          while [ $XRedSFin = 'no' ];
          do echo
             if   [ $XRedFNmD = 'plugh' ];
             then echo '[?] Enter full pathname of Reduce image:'
             else echo '[?] Enter full pathname of Reduce image: ['$XRedINmD']'
             fi;
             read XRedINm
             XRedINm=`XRedExp $XRedINm`
             if   [ t$XRedINm = 'tq' -o t$XRedINm = 'tQ' ];
             then echo '    Quitting.'
      	          echo
      	          exit 0 ;
             elif [ t$XRedINm = 't' ];
             then if   [ $XRedINmD = 'plugh' ];
             then echo '    Sorry, there is no default available here';
             else XRedINm=$XRedINmD;
                  echo '    Using file '$XRedINm' for Reduce image.'
                  XRedSFin='yes';
             fi;
             elif [ t$XRedINm = 'th' -o t$XRedINm = 'tH' ];
                  then echo
        echo '    The file I need is the image file which the Lisp executable'
        echo '    loads in order to run Reduce.   The name of this file might'
        echo '    be displayed by Lisp when it loads it at startup; the usual'
        echo '    default is $reduce/reduce.img.  I need to know the complete'
        echo '    absolute pathname of the file.';
             elif [ -f $XRedINm ];
             then if   [ -r $XRedINm ]
                  then echo '    Using file '$XRedINm' for Reduce image.'
      	               XRedSFin='yes' ;
                  else echo '    '$XRedINm' unreadable; try again.';
                  fi ;
             else echo '    '$XRedINm' nonexistent or special; try again.';
             fi ;
          done;
     fi;
fi;


if [ $XRedWhich = 'i' -o $XRedWhich = 'b' ];
then

# Get default for Reduce->XReduce binary directory

if   [ -t$reduce = 't' ];
then XRedXNdD=`pwd`;
     if   [ -w $XRedXNdD ];
     then :;
     else XRedXNdD='plugh';
     fi;
else XRedXNdD=$reduce/xr/bin;
     if   [ -d $XRedXNdD -a -w $XRedXNdD ];
     then :;
     else XRedXNdD=$reduce/xr;
          if   [ -d $XRedXNdD -a -w $XRedXNdD ];
          then :;
          else XRedXNdD=$reduce/binary;
               if   [ -d $XRedXNdD -a -w $XRedXNdD ];
               then :;
               else XRedXNdD=$reduce;
                    if   [ -d $XRedXNdD -a -w $XRedXNdD ];
                    then :;
                    else XRedXNdD=`pwd`;
                         if   [ -w $XRedXNdD ];
                         then :;
                         else XRedXNdD='plugh';
                         fi;
                    fi;
               fi;
          fi;
     fi;
fi;

# Get directory to hold the Reduce->XReduce
# binary, in XRedXNd

XRedSFin='no'
while [ $XRedSFin = 'no' ];
do echo
   if   [ $XRedXNdD = 'plugh' ];
   then echo '[?] Enter the directory which will hold the file fmprint.b and'
        echo '    , the XR setup files for Reduce:'
   else echo '[?] Enter the directory which will hold the file fmprint.b and'
        echo '    , the XR setup files for Reduce: ['$XRedXNdD'] '
   fi;
   read XRedXNd
   XRedXNd=`XRedExp $XRedXNd`
   if   [ t$XRedXNd = 'tq' -o t$XRedXNd = 'tQ' ];
   then echo '    Quitting.'
      	echo
      	exit 0 ;
   elif [ t$XRedXNd = 't' ];
   then if   [ $XRedXNdD = 'plugh' ];
        then echo '    Sorry, there is no default available here';
        else XRedXNd=$XRedXNdD;
             echo '    Using directory '$XRedXNd' for fmprint.b.'
             XRedSFin='yes';
        fi;
   elif [ t$XRedXNd = 'th' -o t$XRedXNd = 'tH' ];
   then echo
        echo '    The directory I need is the one which can contain the files'
        echo '    fmprint.b,  which Reduce loads when it is started under the'
      	echo '    control of xr, which versions of Reduce older'
	echo '    than 3.4.2 load to retain XR compatibility.  This directory'
	echo '    is often somewhere buried in the code tree for Reduce,  and'
	echo '    in order to perform this installation,  you must have write'
	echo '    permission on it, as this script tries to compile the files'
	echo '    and place them there.  There will be no attempt to make the'
	echo '    directory if it does not already exist.'
   elif [ -d $XRedXNd ];
   then if   [ -w $XRedXNd ];
        then echo '    Using directory '$XRedXNd' for fmprint.b.'
      	     XRedSFin='yes' ;
      	else echo '    '$XRedXNd' not writable; try again.';
        fi ;
   else echo '    '$XRedXNd' is not a directory.  Try again.';
   fi ;
done


# Get directory to hold the XR
# executable and xr.red, in XRedHome
# Note default is same as previous

XRedXNdD=$XRedXNd
XRedSFin='no'
while [ $XRedSFin = 'no' ];
do echo
   if   [ t$XRedXNdD = 't' ];
   then echo '[?] Enter directory to hold XR executable:'
   else echo '[?] Enter directory to hold XR executable: ['$XRedXNdD'] '
   fi;
   read XRedHome
   XRedHome=`XRedExp $XRedHome`
   if   [ t$XRedHome = 'tq' -o t$XRedHome = 'tQ' ];
   then echo '    Quitting.'
      	echo
      	exit 0 ;
   elif [ t$XRedHome = 't' ];
   then if   [ $XRedXNdD = 'plugh' ];
        then echo '    Sorry, there is no default available here';
        else XRedHome=$XRedXNdD;
             echo '    Using directory '$XRedHome' for binary and xr.red.'
             XRedSFin='yes';
        fi;
   elif [ t$XRedHome = 'th' -o t$XRedHome = 'tH' ];
   then echo
      	echo '    The directory I need is the one in which  you want to place'
      	echo '    the executable for XR.  The same directory will be used for'
      	echo '    the file xr.red,  the small RLisp file fed into Reduce when'
        echo '    XR starts.  This directory could be a  Reduce-tree or local'
	echo '    binaries directory. In order to run the script successfully'
        echo '    you must have write permission on the directory. There will'
	echo '    be no attempt to create the directory if it is found not to'
	echo '    exist.' ;
   elif [ -d $XRedHome ];
   then if   [ -w $XRedHome ]
        then echo '    Using '$XRedHome' for binary and xr.red.'
      	     XRedSFin='yes' ;
      	else echo '    '$XRedHome' not writable; try again.';
        fi ;
   else echo '    '$XRedHome' is not a directory; try again.';
   fi ;
done


# Get default for Help file directory

if   [ -t$reduce = 't' ];
then XRedHFdD=`pwd`;
     if   [ -w $XRedHFdD ];
     then :;
     else XRedHFdD='plugh';
     fi;
else XRedHFdD=$reduce/xr/help;
     if   [ -d $XRedHFdD -a -w $XRedHFdD ];
     then :;
     else XRedHFdD=$reduce/xr/doc;
          if   [ -d $XRedHFdD -a -w $XRedHFdD ];
          then :;
          else XRedHFdD=$reduce/help;
               if   [ -d $XRedHFdD -a -w $XRedHFdD ];
               then :;
               else XRedHFdD=`pwd`;
                    if   [ -w $XRedHFdD ];
                    then :;
                    else XRedHFdD='plugh';
                    fi;
               fi;
          fi;
     fi;
fi;

# Get Help file directory

XRedSFin='no'
while [ $XRedSFin = 'no' ];
do echo
   if   [ $XRedHFdD = 'plugh' ];
   then echo '[?] Enter directory to hold the Help files:'
   else echo '[?] Enter directory to hold the Help files: ['$XRedHFdD'] '
   fi;
   read XRedHFd
   XRedHFd=`XRedExp $XRedHFd`
   if   [ t$XRedHFd = 'tq' -o t$XRedHFd = 'tQ' ];
   then echo '    Quitting.'
      	echo
      	exit 0 ;
   elif [ t$XRedHFd = 't' ];
   then if   [ $XRedHFdD = 'plugh' ];
        then echo '    Sorry, there is no default available here';
        else XRedHFd=$XRedHFdD;
             echo '    Using directory '$XRedHFd' for Help files.'
             XRedSFin='yes';
        fi;
   elif [ t$XRedHFd = 'th' -o t$XRedHFd = 'tH' ];
   then echo
        echo '    The directory I need is the one which can contain the files'
        echo '    redref.info and redref.hnx, which are used by the XR built-in'
        echo '    info help system.  The directory should be writable, and if'
        echo '    it does not exist it will not be created.  The availability'
        echo '    of the Help files is currently not of paramount importance,'
        echo '    as at the moment their contents are somewhat rudimentary.'
   elif [ -d $XRedHFd ];
   then if   [ -w $XRedHFd ];
        then echo '    Using directory '$XRedHFd' for Help files.'
      	     XRedSFin='yes' ;
      	else echo '    '$XRedHFd' not writable; try again.';
        fi ;
   else echo '    '$XRedHFd' is not a directory.  Try again.';
   fi ;
done

fi;  # This should be the end of the install-only bit.


unset XRedFNdD XRedFNmD XRedINmD XRedXNdD XRedHFdD XRedSFin ;

# All right.  Now we should have:
#
#     	 XRedFNd  : reducePath
#     	 XRedFNm  : reduceName
#     	 XRedINm  : reduceImageFile, but only if XRedLI = 'y'
#        XRedXNd  : directory to contain fmprint.b
#        XRedHome : directory to contain xr and xr.red
#    and XRedHFd  : directory to contain the Help info files
#
# If we are doing install as well as compile, these should
# be okay; if compiling, only the first three may be looked
# at (because we haven't bothered to set the others).
#
# Now all we have to do is apply them...!

# We assume we are in the right directory, and fmprint.red,
# xr.red.orig, XR.orig and the xr sources and Makefile are
# in here with us.


if [ $XRedWhich = 'i' -o $XRedWhich = 'b' ]
then XRedRedf=$XRedHome/xr.red
     XRedXNf=$XRedXNd/fmprint
     XRedHFm=$XRedHFd/redref.info
fi;

if   [ t$XRedLI = 'ty' ]
then :;
else XRedINm=;
fi;


# define a couple of handy warning functions

XRedTestSrc() {

     if   [ -s ./$1 ];
     then echo
          echo '[!] File ./'$1' exists:'
          echo '    If you do not want it to be overwritten, hit ^C now.'
          sleep 2;
     fi;
}

XRedTestObj() {

# take no action if the file to test is in the current dir,
# because it'll already have been tested against

     if   [ `XRedExp ./$2` = `XRedExp $1/$2` ];
     then :;

# otherwise check if it already exists and warn if so

     else if   [ -s `XRedExp $1/$2` ];
          then echo
               echo '[!] File '`XRedExp $1/$2`' exists:'
               echo '    If you do not want it to be overwritten, hit ^C now.'
               sleep 2;
          fi;
     fi;
}


if [ $XRedWhich = 'c' -o $XRedWhich = 'b' ];
then

XRedTestSrc xr
sleep 2;

echo
echo '    -=> Running make.  If there are old object files left'
echo '        over from a failed installation attempt on a different'
echo '        machine, or if you have changed the Makefile or any'
echo '        header files since a previous failed attempt on this'
echo '        machine, you should probably interrupt this make and'
echo '        run "make clean" first.'
echo
if ( make xr )
then echo
     echo '    -=> Make successful.'
     XRedOK='yes';
else echo
     echo '    -=> Make failed.'
     XRedOK='no';
fi;

XRedTestSrc fmprint.b

rm -f ./fmprint.b

fi;  # End of compile-only bit


if [ $XRedWhich = 'i' -o $XRedWhich = 'b' ]
then

XRedTestSrc XR
XRedTestSrc xr.red
XRedTestSrc redref.hnx

XRedTestObj $XRedXNd  fmprint.b
XRedTestObj $XRedHome xr
XRedTestObj $XRedHome xr.red
XRedTestObj $XRedHFd  redref.info
XRedTestObj $XRedHFd  redref.hnx

rm -f ./XR ./xr.red ./fmprint.b ./redref.hnx;

if [ $XRedOK = 'yes' ];
then

if   (sed -e "s|-rPa-|$XRedFNd|"  -e "s|-rNa-|$XRedFNm|"\
      	  -e "s|-rIn-|$XRedRedf|" -e "s|-rIm-|$XRedINm|"\
          -e "s|-rHn-|$XRedHFm|"\
         ./XR.orig | sed -e "s|$reduce|\\\$reduce|" > ./XR;)
then echo
     echo '    -=> File XR created.'
     if   (sed -e "s|-rBf-|$XRedXNf|" -e "s|-rBd-|$XRedXNd|"\
               ./xr.red.orig | sed -e "s|$reduce|\\\$reduce|" > ./xr.red;)
     then echo '    -=> File xr.red created.'
     else echo '    -=> Failure to create file xr.red.'
      	  exit 1;
     fi;
else echo '    -=> Failure to create file XR.'
     exit 1;
fi;

fi;  # NOT the end of the install-only bit



XRedDispSet=no;

if   [ t$XRedOK = 'tyes' ];
     then if ( mv -f ./xr $XRedHome/xr );
      	  then echo '    -=> xr moved to '$XRedHome'.';
      	  else echo
      	       echo '    -=> xr could not be moved (ignoring).'
      	  fi;
          if   [ -x $XRedHome/xr ];
          then :;
          else if ( chmod u+x $XRedHome/xr );
               then echo '    -=> '$XRedHome'/xr rendered executable.'
               else echo
               echo '    -=> Could not get exec permission on '$XRedHome'/xr.'
               fi;
          fi;
      	  if ( mv -f ./xr.red $XRedHome/xr.red );
      	  then echo '    -=> xr.red moved to '$XRedHome'.';
      	  else echo
      	       echo '    -=> xr.red could not be moved (ignoring).'
      	  fi;
          if ( cp ./redref.info $XRedHFd/redref.info );
      	  then echo '    -=> redref.info copied to '$XRedHFd'.';
      	  else echo
       	       echo '    -=> redref.info could not be copied (ignoring).'
      	  fi;
          if   [ t$DISPLAY = 't' ]
          then echo
               echo '    -=> Warning: environment variable DISPLAY is unset.'
               echo '        Setting it to the default "unix:0.0"; I shall not'
               echo '        attempt actually to display anything, and shall'
               echo '        unset it again afterwards.'
               DISPLAY=unix:0.0 ;
               export DISPLAY ;
               XRedDispSet=yes ;
          fi;
          echo '    -=> Attempting to create help index file.'
          if ( $XRedHome/xr -xrm '*foundDefaults: True' \
                              -rhelpfile ./redref.info -writehelpix );
          then echo '    -=> Help index file successfully created.'
               if ( mv -f ./redref.hnx $XRedHFd/redref.hnx );
               then echo '    -=> redref.hnx moved to '$XRedHFd'.';
      	       else echo
       	            echo '    -=> redref.hnx could not be moved (ignoring).'
      	       fi;
          else echo '    -=> Help index file could not be created (ignoring).'
          fi;
fi;

if   [ $XRedDispSet = 'yes' ]
then unset DISPLAY ;
fi;

fi;  # This is the end of an install-only bit


if   [ $XRedWhich = 'c' -o $XRedWhich = 'b' ]
then

if   [ t$XRedOK = t'yes' ];
then if   [ -r ./fmprint.red ];
     then if   [ t$XRedLI = 'ty' ];
          then XRedCom=$XRedFNd/$XRedFNm' -td 10000000 -f '$XRedINm ;
          else XRedCom=$XRedFNd/$XRedFNm ;
          fi
          echo
          if ( echo 'write "        Compiling RLisp code: please wait";
off output, msg, usermode;
faslout "./fmprint";
in "./fmprint.red"$
faslend;
bye;
' | $XRedCom );
          then echo
               echo '    -=> Files fmprint.b created.'
      	       XRedOK='yes';
      	  else echo '    -=> Reduce batch execution failed.'
               XRedOK='no';
#      	       exit 1;
          fi;
     else echo '    -=> Files ./fmprint.red not readable.'
          XRedOK='no';
#          exit 1;
     fi;
fi;

fi;  # End of compile-only bit


if   [ $XRedWhich = 'i' -o $XRedWhich = 'b' ]
then

if   [ t$XRedOK = 'tyes' ];
then      if ( mv -f ./fmprint.b $XRedXNd/fmprint.b );
      	  then echo '    -=> fmprint.b moved to '$XRedXNd'.';
      	  else echo
       	       echo '    -=> fmprint.b could not be moved (ignoring).'
      	  fi;
fi;

fi;  # End of install-only bit


unset XRedExp XRedTestSrc XRedTestObj XRedFNd XRedFNm XRedINm XRedXNd;
unset XRedHome XRedHFd XRedRedf XRedXNf XRedHFm

if   [ $XRedWhich = 'i' ];
then

if   [ t$XRedOK = 'tyes' ];
then echo
     echo '    -=> Installation successful.  You may now need to move'
     echo '        the file XR to an X application default directory,'
     echo '        or to your home directory -- somewhere the X resource'
     echo '        manager will find it when XR starts --; then you'
     echo '        should be ready to go.'
     echo
     echo '    -=> Thank you for flying XR airlines.'
     echo;
else echo
     echo '    -=> Installation failed.  Sorry...'
     echo;
fi;

elif [ $XRedWhich = 'c' ];
then

if   [ t$XRedOK = 'tyes' ];
then echo
     echo '    -=> Compilation successful.  It is unlikely that you will'
     echo '        be able to run XR until you have installed it properly,'
     echo '        whether by hand or by running this script with the'
     echo '        -install option.'
     echo
     echo '    -=> Thank you for flying XR airlines.'
     echo;
else echo
     echo '    -=> Compilation failed.  Sorry...'
     echo;
fi;

else

if   [ t$XRedOK = 'tyes' ];
then echo
     echo '    -=> Compilation and installation both successful.  You'
     echo '        may now need to move the file XR to an X application'
     echo '        default directory, or to your home directory -- somewhere'
     echo '        the X resource manager will find it when XR starts --;'
     echo '        then you should be ready to go.'
     echo
     echo '    -=> Thank you for flying XR airlines.'
     echo;
else echo
     echo '    -=> Compilation/Installation failed.  Sorry...'
     echo;
fi;

fi;

unset XRedOK;
exit 0 ;

