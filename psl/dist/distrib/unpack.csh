# Unpack the relevant PSL directories

if ($MACHINE == apollo) then
   set ending='.map'
  else
   set ending=''
 endif

# Make sparsify executable (for removing holes from PSL executables).

cc -o $psys/sparsify $pdist/sparsify.c

# Unpack bpsl (apollo only), $MACHINE-cross

if ( -e $pxk/$MACHINE-cross$ending.Z ) then
   uncompress < $pxk/$MACHINE-cross$ending.Z > $pxk/$MACHINE-cross$ending
   chmod 755 $pxk/$MACHINE-cross$ending
   $psys/sparsify $pxk/$MACHINE-cross$ending
   rm $pxk/$MACHINE-cross$ending.Z
  else
   echo '*** Compressed cross compiler not found'
 endif

if ($MACHINE == apollo) then
 if ( -e $pxk/bpsl.Z ) then
    uncompress < $pxk/bpsl.Z > $pxk/bpsl
    chmod 755 $pxk/bpsl
    $psys/sparsify $pxk/bpsl
    rm $pxk/bpsl.Z
   else
    echo '*** Compressed bpsl not found'
  endif
 endif

# Unpack asm (apollo only) pslcomp

 if ( -e $psys/pslcomp$ending.Z ) then
    uncompress < $psys/pslcomp$ending.Z > $psys/pslcomp$ending
    chmod 755 $psys/pslcomp$ending
    $psys/sparsify $psys/pslcomp$ending
    rm $psys/pslcomp$ending.Z
   else
    echo '*** Compressed pslcomp not found'
  endif
if ($MACHINE == apollo) then
 if ( -e $psys/asm.Z ) then
    uncompress < $psys/asm.Z > $psys/asm
    chmod 755 $psys/asm
    obty asm obj
    rm $psys/asm.Z
   else
    echo '*** Compressed asm not found'
  endif
endif
