#! /bin/bash -v

gcc -O3 vsl/vsl.c -ledit -lz -lm -o redvsl
strip redvsl

./redvsl  -z buildvsl.lsp -o redvsl.img | tee buildvsl.log

ls -l redvsl redvsl.img
