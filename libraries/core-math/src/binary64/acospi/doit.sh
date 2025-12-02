#!/bin/bash
sed "s/X0/$1/g" acos.sollya | sed "s/H/$2/g" | sed "s/DEGREE/$3/g" > in
/localdisk/zimmerma/sollya-7.0/sollya in > out
