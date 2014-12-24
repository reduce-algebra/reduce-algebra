#! /bin/bash

for x in STIX*.ttf
do
  echo ttf2ufm -a -F $x ${x%.ttf}
  ttf2ufm -a -F $x ${x%.ttf}
done

mv STIX*.ufm tfm

