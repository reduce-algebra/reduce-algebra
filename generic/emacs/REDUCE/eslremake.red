module eslremake;  % Update the fast loading version of a given file.

% Authors: Martin L. Griss and Anthony C. Hearn.
% Revised for ESL REDUCE by Francis J. Wright.

fluid '(!*break
	!*faslp
	!*loadall
	!*writingfaslfile);

global '(!*argnochk nolist!*);

symbolic procedure olderfaslp(u,v);
   % Return t if file u does not exist or is older than file v.
   % (Return nil if file v does not exist, but this should not happen!)
   !¦file!-newer!-than!-file!-p(v,u);

% Support for packages directory.

symbolic procedure package!-remake x;
   (if y then package!-remake2(x,y) else package!-remake2(x,x))
   where y=get(x,'folder);

symbolic procedure package!-remake2(u,v);
   % Remake module u in directory packages/v or current directory if v
   % is nil.
   begin scalar y, !*int;		% to avoid faslout interaction message
      update!-fasl2(u,v);
      evload list u;
      y := get(u,'package);
      if y then
      	 for each j in cdr y do update!-fasl2(j,v);
   end;

symbolic procedure update!-fasl2(u,v);
   % Update fasl file for module u in directory packages/v or current
   % directory if v is nil.
   begin scalar y,z;
	  y := concat("fasl/", string!-downcase u, ".elc");
      if memq(u,'(fide)) then !*argnochk := nil;   % STILL TRUE??
      z := module2!-to!-file(u,v);
      if olderfaslp(y,z)
        then <<terpri();
               terpri();
               if errorp errorset!*(list('upd!-fasl1,mkquote u,
                                                   mkquote z,
                                                   mkquote v),
                                  t)
                 then <<if !*writingfaslfile then lispeval '(faslend);
                        lprie list("Error during mkfasl of", u . v)>>>>
   end;

symbolic procedure upd!-fasl1(u,v,w);
   % Update fasl file for module u corresponding to file v in
   % directory packages/w or current directory if w is nil.
   begin scalar !*break;
      !*faslp := t;
      if !*loadall and w neq u then evload list w;
      u := string!-downcase u;
      lprim list("Compiling",u,"...");
%     prin2t bldmsg("*** Compiling %w ...",u);
      terpri();
	  lispeval list('faslout, concat("fasl/",u));
      infile v;
      lispeval '(faslend)
   end;

symbolic procedure module2!-to!-file(u,v);
   <<
   	  u := concat(string!-downcase u, ".red");
   	  if v then
      	 concat("packages/", string!-downcase v, "/", u)
   	  else u
   >>;

endmodule;

end;
