#! /bin/awk -f
#
# Awk script for producing a set of commands to feed to the psl 
# cross-assembler to produce main.s. Script expects a single line
# of file names. These are to be dskin'ed in between $pk/firstkernel.sl and
# $pk/lastkernel.sl in the cross-assembler. This line of file names is 
# supplied by the $(SLFILES) variable in the Makefile.
#

# Common set up commands
BEGIN {
# print "(setf loaddirectories* '(\"\" \"$pxk/\" \"$pk/\" \"$pxc/\" \"$pl/\"))";
print "(setf *writingasmfile t)";
print "(reload sys-consts)";
print "(off pcmac)";
print "(off usermode)";
print "(on verboseload)";
print "(asmout \"main\")";
print "(dskin \"$pk/firstkernel.sl\")";
}

# Produce a (dskin "filename") line for each file name on input line.
{ for( i = 1; i <= NF; i++ ) printf("(dskin \"%s\")\n", $i) }

# Finish up and exit the cross-assembler.
END {
print "(dskin \"$pk/lastkernel.sl\")";
print "(asmend)";
print "(exitlisp)";
}

