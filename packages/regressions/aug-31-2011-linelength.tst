lisp;

linelength 60;

symbolic procedure test_wrap x;
  begin
    scalar a, b;
    for i := 1:60 do <<
      terpri();
      prin2 "Test at offset "; print i;
      for j := 1:i-1 do prin2 ".";
      prin2 "<";
      a := posn();
      prin1 x;
      b := posn();
      prin2 ">";
      terpri();
      print list("positions", a, b) >>;
    print "done"
  end;

test_wrap 'a;
test_wrap 'abcdefghijklmnopqr;
test_wrap '!+;
test_wrap '!+!-!+!-!+!-!+!-!+!-!+!-!+!-!+!-!+!-;
test_wrap '!	!	;
test_wrap $eol$;
test_wrap 2;
test_wrap 1234567890123456789;
test_wrap "a";
test_wrap "abcdefghijklmnopqr";
test_wrap '(a);
test_wrap '(a b c d e f g h i j k l m n o p q r);
test_wrap '(a . x);
test_wrap '(a b c d e f g h i j k l m n o p q r . x);

end;
