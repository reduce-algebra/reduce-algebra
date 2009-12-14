# Pack the PSL directories for distribution

set list=(bobcat sun sun4 vax sun386)

# Remove .b files

cd $pnk
foreach x ($list apollo)
   rm -f $x/lap/*
 end

cd $psl/lap
foreach x ($list apollo)
  rm -f $x/*
 end

# Clean up $pxk directories

cd $pk
foreach x ($list)
   rm -f $x/*.o
   rm -f $x/main.init $x/main.s $x/dmain.s
   rm -f $x/$x.sym
end

   rm -f apollo/*.bin
   rm -f apollo/*.lst apollo/*.asm apollo/main.s apollo/dmain.s
   rm -f apollo/main.init apollo/apollo.sym

# Compress bpsl, xxx-cross

foreach x ($list)
   if ( -e $x/$x-cross ) then
      compress < $x/$x-cross > $x/$x-cross.Z
    endif
   rm -f $x/bpsl $x/$x-cross
end

  if ( -e apollo/apollo-cross.map ) then
     compress < apollo/apollo-cross.map > apollo/apollo-cross.map.Z
    endif
  if ( -e apollo/bpsl ) then
     compress < apollo/bpsl > apollo/bpsl.Z
    endif
  rm -f apollo/bpsl apollo/bpsl.map apollo/bpsl.MAP apollo/apollo-cross.map

# Compress executables

cd $proot/bin
foreach x ($list)
   if ( -e $x/pslcomp ) then
      compress < $x/pslcomp > $x/pslcomp.Z
    endif
   rm -f $x/bare-psl $x/psl $x/pslcomp $x/sparsify
end

   if ( -e apollo/asm ) then
      compress < apollo/asm > apollo/asm.Z
    endif
   if ( -e apollo/pslcomp.map ) then
      compress < apollo/pslcomp.map > apollo/pslcomp.map.Z
    endif
   rm -f apollo/asm  apollo/bare-psl.map apollo/psl.map apollo/pslcomp.map
