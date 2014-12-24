#! /bin/bash

for x in *.ttf
do
  echo ttf2ufm -a -F $x ${x%.ttf}
  ttf2ufm -a -F $x ${x%.ttf}
done

mv *.ufm tfm

