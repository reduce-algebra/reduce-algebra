#! /bin/sh

for f in `find . -name \*.red -print`
do
echo $f
cp $f $f.saved
./addlicense $f
mv $f.fixed $f
done

