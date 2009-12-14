# Remove old executables and restore pslcomp (apollo only)

rm -f $psys/old-*
rm -f $pxk/old-*

if ($MACHINE == apollo) then
   cp $psys/pslcomp.standard $psys/pslcomp
   rm -f $pxk/xbpsl
 endif

