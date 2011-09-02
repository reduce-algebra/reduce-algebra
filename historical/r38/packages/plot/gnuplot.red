module gnuplot;  % REDUCE interface for gnuplot graphics.

create!-package('(gnuplot gnuintfc gnupldrv),nil);
                
global '(plotdta!* plotdta!*2 plotmax!*
	 plotmin!* plotcmds!* plotcommand!*
	 lispsystem!*
	 plotdriver!*);

plotdriver!*:='gnuplot;

put('gnuplot,'do,'gp!-do);

put('gnuplot,'option,'gp!-option);

load_package plot;   % Generic plot package.

endmodule;

end;
