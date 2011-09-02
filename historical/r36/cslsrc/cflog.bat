REM this file is invoked when you are in a build-directory
REM (eg r36\cslwat). It compares log files with the ones provided
REM as part of the REDUCE distribution
REM NOTE that you should NOT expect the logs to match exactly - some
REM calculations deliver results where the exact presentation of the
REM answers depends on very fine details of the computer on which the
REM tests are run.
del cflog.log
call ..\cslsrc\cflog1 algint.log
call ..\cslsrc\cflog1 applysym.log
call ..\cslsrc\cflog1 arnum.log
call ..\cslsrc\cflog1 assist.log
call ..\cslsrc\cflog1 avector.log
call ..\cslsrc\cflog1 boolean.log
call ..\cslsrc\cflog1 cali.log
call ..\cslsrc\cflog1 camal.log
call ..\cslsrc\cflog1 changevr.log
call ..\cslsrc\cflog1 compact.log
call ..\cslsrc\cflog1 complex.log
call ..\cslsrc\cflog1 crack.log
call ..\cslsrc\cflog1 cvit.log
call ..\cslsrc\cflog1 decompos.log
call ..\cslsrc\cflog1 defint.log
call ..\cslsrc\cflog1 desir.log
call ..\cslsrc\cflog1 dfpart.log
call ..\cslsrc\cflog1 dummy.log
call ..\cslsrc\cflog1 elem.log
call ..\cslsrc\cflog1 excalc.log
call ..\cslsrc\cflog1 factor.log
call ..\cslsrc\cflog1 fide.log
call ..\cslsrc\cflog1 fps.log
call ..\cslsrc\cflog1 gcd.log
call ..\cslsrc\cflog1 gentran.log
call ..\cslsrc\cflog1 groebner.log
call ..\cslsrc\cflog1 ideals.log
call ..\cslsrc\cflog1 ineq.log
call ..\cslsrc\cflog1 int.log
call ..\cslsrc\cflog1 invbase.log
call ..\cslsrc\cflog1 laplace.log
call ..\cslsrc\cflog1 lie.log
call ..\cslsrc\cflog1 limits.log
call ..\cslsrc\cflog1 linalg.log
call ..\cslsrc\cflog1 math.log
call ..\cslsrc\cflog1 matrix.log
call ..\cslsrc\cflog1 modsr.log
call ..\cslsrc\cflog1 ncpoly.log
call ..\cslsrc\cflog1 normform.log
call ..\cslsrc\cflog1 numeric.log
call ..\cslsrc\cflog1 odesolve.log
call ..\cslsrc\cflog1 orthovec.log
call ..\cslsrc\cflog1 pf.log
call ..\cslsrc\cflog1 physop.log
call ..\cslsrc\cflog1 pmrules.log
call ..\cslsrc\cflog1 randpoly.log
call ..\cslsrc\cflog1 reacteqn.log
call ..\cslsrc\cflog1 reduce.log
call ..\cslsrc\cflog1 residue.log
call ..\cslsrc\cflog1 rlfi.log
call ..\cslsrc\cflog1 rlisp88.log
call ..\cslsrc\cflog1 roots.log
call ..\cslsrc\cflog1 rounded.log
call ..\cslsrc\cflog1 rsolve.log
call ..\cslsrc\cflog1 scope.log
call ..\cslsrc\cflog1 sets.log
call ..\cslsrc\cflog1 solve.log
call ..\cslsrc\cflog1 spde.log
call ..\cslsrc\cflog1 specfn.log
call ..\cslsrc\cflog1 sum.log
call ..\cslsrc\cflog1 symmetry.log
call ..\cslsrc\cflog1 taylor.log
call ..\cslsrc\cflog1 tps.log
call ..\cslsrc\cflog1 tri.log
call ..\cslsrc\cflog1 trigsimp.log
call ..\cslsrc\cflog1 wu.log
call ..\cslsrc\cflog1 xcolor.log
call ..\cslsrc\cflog1 xideal.log
call ..\cslsrc\cflog1 zeilberg.log
call ..\cslsrc\cflog1 ztrans.log
REM end of cflog.bat
