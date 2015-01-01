% CSL provides 8, 16 and 32-bit integer vectors. Use of them can
% save space compared with use of generic Lisp vectors that just
% happen to contain integer values.

% Up until the end of 2014 the CSL code that supported 32-bit vectors
% would fail to retrieve a value properly if its value was in the
% range 0x08000000 to 0x0fffffff because a test relating to whether the
% result could be returned as a "small" integer was incorrect.

% Because these specialised vectors do not exist for PSL at all this
% code has to be slightly odd in order to generate identical log
% files for both Lisps...

lisp begin
  if memq('csl, lispsystem!*) then <<
    a := mkvect32 1;
    putv32(a, 0, 0x0d123456);
    if getv32(a, 0) neq 0x0d123456 then rederr "vec32 test failure" >>;
  return "test complete"
end;

end;
