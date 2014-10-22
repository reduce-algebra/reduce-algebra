%
% Testing the #if conditional compilation scheme

off echo;
lisp;
print "A1: should appear"$

#if t
print "A2: should appear"$
#endif

#if nil
print "A3: should not appear"$
#endif

#if t
print "A4: should appear"$
#else
print "A5: should not appear"$
#endif

#if nil
print "A6: should not appear"$
#else
print "A7: should appear"$
#endif

#if t
print "A8: should appear"$
#elif t
print "A9: should not appear"$
#else
print "A10: should not appear"$
#endif

#if nil
print "A11: should not appear"$
#elif t
print "A12: should appear"$
#else
print "A13: should not appear"$
#endif

#if t
print "A14: should appear"$
#elif nil
print "A15: should not appear"$
#else
print "A16: should not appear"$
#endif

#if nil
print "A17: should not appear"$
#elif nil
print "A18: should not appear"$
#else
print "A19: should appear"$
#endif

#if t
#if t
#if t
print "A20: should appear"$
#endif
#endif
#endif

#if nil
#else
#if t
#if t
print "A21: should appear"$
#endif
#endif
#endif

#if t
#if nil
#else
#if t
print "A22: should appear"$
#endif
#endif
#endif

#if nil
#else
#if nil
#else
#if t
print "A23: should appear"$
#endif
#endif
#endif

#if t
#if t
#if nil
#else
print "A24: should appear"$
#endif
#endif
#endif

#if nil
#else
#if t
#if nil
#else
print "A25: should appear"$
#endif
#endif
#endif

#if t
#if nil
#else
#if nil
#else
print "A26: should appear"$
#endif
#endif
#endif

#if nil
#else
#if nil
#else
#if nil
#else
print "A27: should appear"$
#endif
#endif
#endif

end;
