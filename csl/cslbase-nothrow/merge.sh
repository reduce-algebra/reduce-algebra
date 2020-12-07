#! /bin/bash

F="${1:-lispthrow.h}"
echo @@@ $F
diff -D FAKE_EXCEPTIONS old/$F $F > merged/$F 
