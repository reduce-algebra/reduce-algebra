#! /bin/bash

for x in *.otf fireflysung.ttf
do
  echo ot2kpx $x
  ot2kpx $x > tfm/${x%.otf}.kpx
done


