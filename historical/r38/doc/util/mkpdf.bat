rem Create a dvi and pdf file of the REDUCE manual.
rem This requires MikTeX version 1.11c or later.

latex r38
bibtex r38
latex r38
latex r38
makeindex r38
latex r38

dvipdfm r38



