#! /bin/bash -v

make clean
time make bootstrapreduce.img
rm bootstrapreduce.img
time make bootstrapreduce.img
time make c-code
time make reduce.img

echo All made!
