#
cd ../pslbuild
mkdir $1
cd $1
mkdir psl
mkdir red
cp -r ../$2/xport .
cp -r ../$2/deps .
cp -r ../$2/conf* .
mkdir buildlogs
cp -r ../$2/Makefile .
cp ../../psl/dist/nonkernel/$1/lap/* psl
cp ../../psl/dist/lap/$1/* psl
cp ../..//psl/dist/kernel/$1/bpsl psl/
cp psl/nbig32.b psl/zbig.b
rm psl/*rlisp*.b
make
cat > redpsl << EOF
#
`pwd`/psl/bpsl -td 500 -f `pwd`/red/reduce.img

EOF
chmod +x redpsl

