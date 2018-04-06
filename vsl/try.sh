#! /bin/bash -v
./Winfasl.sh
./try-real.sh
./try-Winfasl.sh
od -Ax -tx1z Winfoo.b > Win.txt
od -Ax -tx1z realfoo.b > real.txt
diff real1.txt real.txt
diff Win.txt real1.txt
