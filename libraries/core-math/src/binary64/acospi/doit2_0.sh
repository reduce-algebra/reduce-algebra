#!/bin/bash
sed "s/X0/$1/g" acos2_0.sollya | sed "s/L/$2/g" | sed "s/H/$3/g" | sed "s/P0h/$4/g" | sed "s/P0l/$5/g" | sed "s/P1/$6/g" | sed "s/P2/$7/g" | sed "s/P3/$8/g" | sed "s/P4/$9/g" | sed "s/P5/${10}/g" | sed "s/P6/${11}/g" > in
/localdisk/zimmerma/sollya-7.0/sollya in > out
