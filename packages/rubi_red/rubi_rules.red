%
% Read and save the Rubi rules.
%
%                                                   A C Norman, 2013

module 'rubi_rules;

% I now have something that is basically a horrible trick that results
% in the parsing of rule-files being performed while this source file
% is compiled. When Reduce parses anything it will expand macros. In this
% case that act will cause it to invoke read_rubi_rules(). The end
% effect will be that the invocation of save_rubi_rules will expand
% to  "rubi_rules := '(some big list);".
% At present the big list is merely a raw parse of the original information
% but in a while I will arrange that it is a "compiled" version of the
% rule-set in the form of some variety of decision tree. Maybe.

% Note that all the code used by the macro must be loaded for this to
% behave properly. That is achieved here by having rubi_red.red set
% an autoload action on read_rubi_rules such that the module rubi_parse
% gets loaded as needbe.

fluid '(rubi_rules);

symbolic macro procedure save_rubi_rules u;
    list('setq, 'rubi_rules, mkquote read_rubi_rules());

save_rubi_rules();

endmodule;

end;

