#! /bin/sh
cp trycase.tst trycase.input
./casefold trycase.input
diff trycase.tst trycase.input

cp trycase1.tst trycase1.input
./casefold + trycase1.input sf : SF
diff trycase1.tst trycase1.input
