# Package Documentation Not Included in the REDUCE Manual

**Francis Wright, January 2025**

At the top of `doc/manual/user.tex` is the following:

```
% List of documentation/packages missing:
%
% atensor/*.tex - only atensor.ps
% crack/conlaw.tex
% crack/crack.tex
% crack/v3tools.tex
% gentran/gentran.tex -- too long!
% mathml/*.tex
% occal/ocpaper.tex
% rtrace/rdebug.tex -- PSL only
% scope/scope.tex -- too long!
% susy2/susy2.tex
% tri/*.tex -- too long!
```

This directory is an attempt to remedy the omission by providing the missing documentation on the web as PDF files, but only for pre-compiled packages. If these packages have documentation stubs in the REDUCE manual then they can link to the files here.

Source files were copied from the `packages` directories. Some documents need `reduce.sty`, which was copied from `doc/misc`. Formatting was done with the current versions of Ghostscript and TeX Live. Details are provided below. All the results look at least superficially OK.

## Atensor

`atensor.ps` converted to `atensor.pdf` using Ghostscript command `ps2pdf`.

## Crack/Conlaw

`conlaw.tex` formatted as `conlaw.pdf` using `pdflatex conlaw` twice. Minor update for current REDUCE.

## Crack/Crack

`crack.tex` formatted as `crack.pdf` using `latex crack; latex crack; dvipdfm -p a4 crack`. NB: using `pdflatex` doesn't work. Minor typographical corrections and update for current REDUCE.

## Crack/V3tools

`v3tools.tex` formatted as `v3tools.pdf` using `pdflatex v3tools` twice. Minor typographical corrections and update for current REDUCE.

## Gentran

`gentran.tex`, `gentran.bib` and `reduce.sty` formatted as `gentran.pdf` using `pdflatex gentran; bibtex gentran; pdflatex gentran; pdflatex gentran`. One minor typographical correction and one update for current REDUCE.

## Mathml/Mathml

`mathml.tex` formatted as `mathml.pdf` using `pdflatex mathml`.

## Mathml/Mathmlom

`mathmlom_user.pdf` copied from `packages/mathml`.

## Scope

`scope.tex`, `scope.bib` and `reduce.sty` formatted as `scope.pdf` using `pdflatex scope; bibtex scope; makeindex scope; pdflatex scope; pdflatex scope`. A minor typographical correction.

## Susy2

`susy2.tex` formatted as `susy2.pdf` using `pdflatex susy2` twice.

## Tri

`tri.tex` and `tridefs.tex` formatted as `tri.pdf` using `pdftex tri.tex`. NB: documentation written in raw TeX, not LaTeX!

<!-- Local Variables: -->
<!-- fill-column: 1000 -->
<!-- eval: (auto-fill-mode -1) -->
<!-- eval: (visual-line-mode 1) -->
<!-- eval: (visual-wrap-prefix-mode 1) -->
<!-- End: -->
