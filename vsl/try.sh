#! /bin/bash -v
./Winfasl.sh
./try-real.sh
./try-Winfasl.sh
od -Ax -tx1z Winfoo.b > Win.txt
od -Ax -tx1z realfoo.b > real.txt
diff Win.txt real.txt | tee diffs.txt

