# Makefile for REDUCE2 recovery project


.PHONY:	redvsl.img
redvsl.img:	redvsl
	gcc -O3 vsl.c -ledit -lz -lm -o redvsl
	./redvsl  -z -o redvsl.img buildvsl.lsp | tee buildvsl.log

redvsl:	vsl.c
	gcc -O3 vsl.c -ledit -lz -lm -o redvsl

# A test file from 1973
testvsl.log:	redvsl.img
	time ./redvsl -i redvsl.img testvsl.red | tee testvsl.log

# The 2025 version of the same test file
alg.rlg:	redvsl.img alg.tst
	time ./redvsl -i redvsl.img alg.tst | tee alg.rlg

demo1.log:	redvsl.img demo1.red
	time ./redvsl -i redvsl.img demo1.red | tee demo1.log

demo2.log:	redvsl.img demo2.red
	time ./redvsl -i redvsl.img demo2.red | tee demo2.log

demo3.log:	redvsl.img demo3.red
	time ./redvsl -i redvsl.img demo3.red | tee demo3.log

demo4.log:	redvsl.img demo4.red
	time ./redvsl -i redvsl.img demo4.red | tee demo4.log

demo5.log:	redvsl.img demo5.red
	time ./redvsl -i redvsl.img demo5.red | tee demo5.log

# end of Makefile
