#!/bin/sh
#
#  XR Export Script.
#
#  A little script to copy the XR files to a new directory and set
#  them up ready for installation.
#
#  It takes two arguments -- the first is an identifier for the system
#  for which the XR is required, which currently must be one of sun4,
#  solaris, alpha, hp, linux, irix, aviion and ibmrs, and the second
#  is the directory to which to copy.  This should already exist and
#  should be writable.
#
#  The script created the relevant subdirectories (if they're absent),
#  copies over the files, and creates an executable shell script in
#  the top level of the new tree, called ZIB-Compile.sh, which when
#  executed (on the correct machine) will compile and install XR.
#
#  There is also an optional -compile flag which if used when running
#  this script (before either argument) causes the newly built
#  ZIB-Compile script to be executed, and then deleted.  This option
#  should only be used if you're running this script on the same kind
#  of machine as you wish to install XR for.
#
#  This script is dependent on its current location.  Don't move it,
#  at least not relative to the rest of the XR tree.

if   [ t$1 = 't-compile' ]
then Compile=yes;
     shift;
else Compile=no;
fi;

if   [ t$1 = 't' -o t$2 = 't' ] ;
then echo 'XR-Export: Missing argument'
     exit 1;
fi;

Textname='none'

case "$1" in
        sun4) Textname='Sun-4';;
     solaris) Textname='Solaris';;
       alpha) Textname='DEC Alpha';;
          hp) Textname='HP';;
       linux) Textname='Linux';;
        irix) Textname='SGI IRIX';;
      aviion) Textname='AViiON';;
       ibmrs) Textname='IBM-RS';;
esac

if   [ "$Textname" = 'none' ]
then echo 'XR-Export: Have no information for machine type '$1
     exit 1;
elif [ $Compile = 'yes' ]
then echo
     echo ' Found -compile flag; shall attempt to compile if copy succeeds.';
fi

echo
echo ' Attempting to create directories and copy files as appropriate.'
echo

if   [ -d $2 ] ;
then if   [ -d $2/bin ];
     then echo '    -=> '$2/bin' already exists.';
     else if ( mkdir $2/bin )
          then echo '    -=> Created directory '$2/bin'.'
          else echo '    -=> Cannot create directory '$2/bin'.'
               echo; exit 1;
          fi;
     fi;
     if   [ -d $2/src ];
     then echo '    -=> '$2/src' already exists.';
     else if ( mkdir $2/src )
          then echo '    -=> Created directory '$2/src'.'
          else echo '    -=> Cannot create directory '$2/src'.'
               echo; exit 1;
          fi;
     fi;
     if   [ -d $2/doc ];
     then echo '    -=> '$2/doc' already exists.';
     else if ( mkdir $2/doc )
          then echo '    -=> Created directory '$2/doc'.'
          else echo '    -=> Cannot create directory '$2/doc'.'
               echo; exit 1;
          fi;
     fi;

     echo;

   ( cd   src;
     for  x in *.c *.h Makefile Install.sh *.dist *.orig *.red *.xbm rhelp.info
     do   echo '    -=> Copying 'src/$x'...'
          if ( cp $x $2/src/$x )
          then :;
          else echo '    -=> Could not copy 'src/$x'.'
               echo
               exit 1;
          fi;
     done )

     echo;

   ( cd   doc;
     for  x in xr-*.ps xr.tex xr.ps.Z defaults packages
     do   echo '    -=> Copying 'doc/$x'...'
          if ( cp $x $2/doc/$x )
          then :;
          else echo '    -=> Could not copy 'doc/$x'.'
               echo
               exit 1;
          fi;
     done )

     echo '    -=> Copying and altering README...'
     if ( cat README | sed -e "s/DEC\ Alpha/$Textname/" > $2/README )
     then :;
     else echo '    -=> Could not copy README.'
          echo
          exit 1;
     fi;
fi;

echo
echo '    -=> Copied files successfully.'
echo
echo ' Creating executable shellscript to install XR.'

Filename=$2/ZIB-Compile.sh

echo '
#!/bin/sh
#
# Shell script to compile and install XR, created by Export.sh, C Cannam 1993

if ( cd src;' > $Filename;

case "$1" in

# Machines with binary REDUCEs

 sun4|irix|aviion)
  echo "  echo 'n" >> $Filename;
  echo 'n
$reduce



' >> $Filename;
  echo "' | ./Install.sh -both )" >> $Filename;;

# Machines with image-file REDUCEs

 solaris|alpha|hp|linux|ibmrs)
  echo "  echo 'n" >> $Filename;
  echo 'y
$reduce/psl




' >> $Filename;
  echo "' | ./Install.sh -both );" >> $Filename;;
esac
echo '
then ( cd src; make clean )
     exit 0;
else echo Unsuccessful
     exit 1;
fi;
' >> $Filename;

chmod +x $Filename

if   [ $Compile = 'yes' ]
then echo
     echo ' Attempting to compile and install XR system.'
     echo
     sleep 1;
     if ( cd $2; $Filename )
     then rm $Filename;
     else echo
          echo '    -=> Compile and install procedure failed.'
          exit 1;
     fi;
fi;

echo ;
echo '    -=> Successful.'
exit 0;

