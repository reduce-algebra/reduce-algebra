#! /bin/bash -v
sed 's/symval+[0-9]*/&(%rip)/g; s/symfnc+[0-9]*/&(%rip)/g; s/mov l[0-9]*/&(%rip)/g' < AMD64_ext_main.s > main.s
