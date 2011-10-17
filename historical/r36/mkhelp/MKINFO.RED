%
% This file arranges to convert the TEX-formatted Reduce help files
% info GNU-info format.
%

symbolic;
off echo;
on comp;

fluid '(package);

package := 'redhelp;

symbolic procedure inf x;
   char!-code x;

symbolic procedure channellinelength(f, l);
  begin
    f := wrs f;
    l := linelength l;
    wrs f;
    return l
  end;

symbolic procedure channelprin2(f, x);
  begin
    f := wrs f;
    prin2 x;
    wrs f;
    return x
  end;

symbolic macro procedure channelprintf u;
  begin
    scalar g;
    g := gensym();
    return list('prog, list g,
       list('setq, g, list('wrs, cadr u)),
       'printf . cddr u,
       list('wrs, g))
  end;

symbolic procedure channelterpri f;
  begin
    f := wrs f;
    terpri();
    wrs f;
  end;

symbolic procedure channelreadch f;
  begin
    scalar c;
    f := rds f;
    c := readch();
    rds f;
    return c
  end;

in "comphelp.red"$
in "helpunx.red"$
in "minitex.red"$
 
dir_src := "../help/";

job(bldmsg("%w.tex",package), "null.fil");

delete!-file "null.fil";

job(bldmsg("%w.tex",package), bldmsg("%w.x",package));

bye;

