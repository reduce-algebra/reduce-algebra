[Files]

; common
Source: "{#mydir}\C\csl\reduce.doc\BINARY-LICENSE.txt"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\csl\reduce.doc\BSD-LICENSE.txt"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\csl\reduce.doc\LGPL-2.1.txt"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\misc\primer.tex"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\misc\primer.pdf"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\misc\sl.tex"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\misc\sl.bib"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\misc\sl.pdf"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\primers\insidereduce.tex"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\primers\insidereduce.pdf"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\misc\reduce.sty"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\manual\redlogo.png"; \
  DestDir: "{app}\lib\csl\reduce.doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\manual\*.tex"; \
  DestDir: "{app}\doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\manual\manual.pdf"; \
  DestDir: "{app}\lib\csl\reduce.doc\"; \
  Flags: ignoreversion; \
  Components: common
Source: "{#mydir}\C\doc\manual\manual*.html"; \
  DestDir: "{app}\lib\csl\reduce.doc\"; \
  Components: common
Source: "{#mydir}\C\doc\manual\manual*.png"; \
  DestDir: "{app}\lib\csl\reduce.doc\"; \
  Components: common
;Source: "{#mydir}\C\doc\manual\bild*.png"; \
  DestDir: "{app}\lib\csl\reduce.doc\"; \
  Components: common
;Source: "{#mydir}\C\doc\manual\cmsy10*.png"; \
  DestDir: "{app}\lib\csl\reduce.doc\"; \
  Components: common
;Source: "{#mydir}\C\doc\manual\gnuplotex*.png"; \
  DestDir: "{app}\lib\csl\reduce.doc\"; \
  Components: common
;Source: "{#mydir}\C\doc\manual\turtleeg*.png"; \
  DestDir: "{app}\lib\csl\reduce.doc\"; \
  Components: common
Source: "{#mydir}\C\doc\manual\manual.css"; \
  DestDir: "{app}\lib\csl\reduce.doc\"; \
  Components: common
Source: "{#mydir}\C\doc\manual\manual.html"; \
  DestDir: "{app}\lib\csl\reduce.doc\"; \
  DestName: "index.html"; \
  Components: common
Source: "{#mydir}\C\winbuild\gp460-win32-setup.exe"; \
  DestDir: "{app}\lib\"; \
  Components: common

Source: "{#mydir}\C\packages\*.*"; Excludes: "regressions\*"; \
  DestDir: "{app}\packages\"; \
  Flags: recursesubdirs; \
  Components: common\source
;Source: "{#mydir}\C\xmpl\*.tst"; \
  DestDir: "{app}\xmpl\"; \
  Components: common
;Source: "{#mydir}\C\xmpl\*.rlg"; \
  DestDir: "{app}\xmpl\"; \
  Components: common
;Source: "{#mydir}\C\xmpl\README"; \
  DestDir: "{app}\xmpl\"; \
  Components: common

; csl
Source: "cslbuild\reduce.exe"; \
  DestDir: "{app}\lib\csl\"; \
  Components: csl;
Source: "cslbuild\winreduce.exe"; \
  DestDir: "{app}\lib\csl\"; \
  Components: csl;
Source: "cslbuild\reduce.img"; \
  DestDir: "{app}\lib\csl\"; \
  Components: csl;
Source: "cslbuild\reduce.fonts\*.*"; \
  DestDir: "{app}\lib\csl\reduce.fonts"; \
  Components: csl;
Source: "cslbuild\reduce.resources\*.*"; \
  DestDir: "{app}\lib\csl\reduce.resources"; \
  Components: csl;
Source: "cslbuild\bootstrapreduce.exe"; \
  DestDir: "{app}\lib\csl\"; \
  Components: csl;
Source: "cslbuild\bootstrapreduce.img"; \
  DestDir: "{app}\lib\csl\"; \
  Components: csl;
Source: "cslbuild\csl.exe"; \
  DestDir: "{app}\lib\csl\"; \
  Components: csl;
Source: "cslbuild\wincsl.exe"; \
  DestDir: "{app}\lib\csl\"; \
  Components: csl;
Source: "cslbuild\csl.img"; \
  DestDir: "{app}\lib\csl\"; \
  Components: csl;
Source: "{#mydir}\redcsl.bat"; \
  DestDir: "{app}\bin\"; \
  Components: csl;
Source: "{#mydir}\redcsl.sh"; \
  DestDir: "{app}\bin\"; \
  DestName: "redcsl"; \
  Components: csl;
Source: "{#mydir}\bootstrapreduce.bat"; \
  DestDir: "{app}\bin\"; \
  Components: csl;
Source: "{#mydir}\bootstrapreduce.sh"; \
  DestDir: "{app}\bin\"; \
  DestName: "bootstrapreduce"; \
  Components: csl;
Source: "{#mydir}\csl.bat"; \
  DestDir: "{app}\bin\"; \
  Components: csl;
Source: "{#mydir}\csl.sh"; \
  DestDir: "{app}\bin\"; \
  DestName: "csl"; \
  Components: csl;
Source: "{#mydir}\cslcyg32\redfront\.libs\rfcsl.exe"; \
  DestDir: "{app}\bin\"; \
  DestName: "rfcsl32.exe"; \
  Components: csl;
Source: "{#mydir}\cslcyg64\redfront\.libs\rfcsl.exe"; \
  DestDir: "{app}\bin\"; \
  DestName: "rfcsl.exe"; \
  Components: csl;
Source: "{#mydir}\cslcyg64\redfront\rfcslwin.exe"; \
  DestDir: "{app}\bin\"; \
  DestName: "rfcsl.com"; \
  Components: csl;

Source: "cslbuild\make-cygwin-symlink.exe"; \
  DestDir: "{app}\lib\csl\"; \
  Components: csl;
Source: "cslbuild\make-cygwin-symlink.exe"; \
  DestDir: "{app}\lib\psl\"; \
  Components: psl32 psl64;



;psl
Source: "{#mydir}\C\pslbuild\i686-pc-windows\psl\*"; \
  DestDir: "{app}\lib\psl\psl\"; \
  Components: psl32
Source: "{#mydir}\C\pslbuild\i686-pc-windows\red\*.b"; \
  DestDir: "{app}\lib\psl\red\"; \
  Components: psl32
Source: "{#mydir}\C\pslbuild\i686-pc-windows\red\*.lap"; \
  DestDir: "{app}\lib\psl\red\"; \
  Components: psl32; \
  Flags: skipifsourcedoesntexist
Source: "{#mydir}\redpsl.sh"; \
  DestDir: "{app}\bin\"; \
  DestName: "redpsl"; \
  Components: psl32;
Source: "{#mydir}\cslcyg32\redfront\.libs\rfpsl.exe"; \
  DestDir: "{app}\bin\"; \
  DestName: "rfpsl32.exe"; \
  Components: psl32;
Source: "{#mydir}\cslcyg64\redfront\.libs\rfpsl.exe"; \
  DestDir: "{app}\bin\"; \
  Components: psl64;
Source: "{#mydir}\cslcyg64\redfront\rfpslwin.exe"; \
  DestDir: "{app}\bin\"; \
  DestName: "rfpsl.com"; \
  Components: psl32 psl64;

Source: "{#mydir}\C\pslbuild\x86_64-pc-windows\psl\*"; \
  DestDir: "{app}\lib\psl\psl\"; \
  Components: psl64
Source: "{#mydir}\C\pslbuild\x86_64-pc-windows\red\*.b"; \
  DestDir: "{app}\lib\psl\red\"; \
  Components: psl64
Source: "{#mydir}\C\pslbuild\x86_64-pc-windows\red\*.lap"; \
  DestDir: "{app}\lib\psl\red\"; \
  Components: psl64

Source: "{#mydir}\reduce64.img"; \
  DestDir: "{app}\lib\psl\red\"; \
  DestName: "reduce.img"; \
  Components: psl64
Source: "{#mydir}\reduce.img"; \
  DestDir: "{app}\lib\psl\red\"; \
  DestName: "reduce.img"; \
  Components: psl32
Source: "{#mydir}\redpsl.bat"; \
  DestDir: "{app}\bin\"; \
  Components: psl32 psl64; Check: not Is64BitInstallMode
;;;Source: "{#mydir}\redpslw.bat"; \
  DestDir: "{app}\bin\"; \
  Components: psl32
Source: "{#mydir}\redpsl64.bat"; \
  DestName: "redpsl.bat"; \
  DestDir: "{app}\bin\"; \
  Components: psl64
;;;Source: "{#mydir}\redpsl64w.bat"; \
  DestName: "redpslw.bat"; \
  DestDir: "{app}\bin\"; \
  Components: psl64
Source: "{#mydir}\redpsl64.sh"; \
  DestDir: "{app}\bin\"; \
  DestName: "redpsl"; \
  Components: psl64;
Source: "{#mydir}\cslcyg64\redfront\.libs\rfpsl.exe"; \
  DestDir: "{app}\bin\"; \
  Destname: "rfpsl.exe"; \
  Components: psl32 psl64;

Source: "cslbuild\make-cygwin-symlink.exe"; \
  DestDir: "{app}\lib\psl\"; \
  Components: psl32 psl64;

; end of files section
