#! /bin/bash

for x in old/*.h old/*.cpp
do
  y=${x##old/}
  ./merge.sh $y
done
