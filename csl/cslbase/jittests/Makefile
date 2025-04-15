# test JIT

# $(PX) must give the directory that bootstrapreduce (with JIT) is in.


.PHONY:	alltests
alltests:
	rm *.log
	make alltests1

.PHONY:	alltests1
alltests1:	a-addf1.log a-addf.log a-binom1.log a-binom2.log \
	a-binom.log a-call1.log a-call2.log a-call2r.log \
	a-call3bad.log a-call3.log a-fastget.log a-loadlit1.log \
	a-plus.log a-reduce.log a-sub1.log a-tak.log \
	a-testfn.log byte.log c1.log c3.log \
	fact.log lap1.log lap2.log lap.log \
	lessp.log sub1.log t1.log t2.log \
	t3.log tak1.log tak2.log tak3.log \
	tak4.log tak5.log tak.log

.PHONY:	clean
clean:
	rm *.log

%.log:	%.red
	scr $@ limit -t 20 rr record $(PX)/bootstrapreduce -w $<

