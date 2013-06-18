#! /bin/bash -v

# create launcher scripts based on using "csl" as the master one

sed -e s/csl/reduce/g < csl > reduce.tmp
mv reduce reduce.old
mv reduce.tmp reduce

sed -e s/csl/fwindemo/g < csl > fwindemo.tmp
mv fwindemo fwindemo.old
mv fwindemo.tmp fwindemo

sed -e s/csl/bootstrapreduce/g < csl > bootstrapreduce.tmp
mv bootstrapreduce bootstrapreduce.old
sed -e s/.com/.exe/g < bootstrapreduce.tmp > bootstrapreduce

sed -e s/.com/.exe/g < csl > csl-nogui

sed -e s/.com/.exe/g < fwindemo > fwindemo-nogui

sed -e s/.com/.exe/g < reduce > reduce-nogui

chmod +x csl reduce fwindemo bootstrapreduce
chmod +x csl-nogui reduce-nogui fwindemo-nogui

exit 0

