module lievalfm;

% Author: Eberhard Schruefer

symbolic procedure liebrackstat;
   begin scalar x;
     x := xread nil;
     scan();
     return 'lie . cdr x
   end;

flag(list '!},'delim); %Since Liebrackets can be nested we can't
                       %remove the flag in the stat proc;

put('!{,'stat,'liebrackstat); %We'd rather liked to use squarebrackets;
                       %but they are not available on most terminals;


put('lie,'prifn,'lieprn);

symbolic procedure lieprn u;
   <<prin2!* "{";
     inprint('!*comma!*,0,u);
     prin2!* "}">>;

endmodule;

end;
