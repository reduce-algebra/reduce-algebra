#!/bin/bash
sed "s/X0/$1/g" acos3.sollya | sed "s/L/$2/g" | sed "s/H/$3/g" | sed "s/P0/$4/g" | sed "s/P1/$5/g" | sed "s/P2/$6/g" | sed "s/P3/$7/g" | sed "s/P4/$8/g" | sed "s/P5/$9/g" > in
/localdisk/zimmerma/sollya-7.0/sollya in > out
