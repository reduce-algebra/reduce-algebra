;;----------------------------------------------------------------;;
;; -- reduce.iss --  REDUCE InnoSetup installation script         ;;
;;----------------------------------------------------------------;;
;;                                                                ;;
;;  * InnoSetup version 5.1.7 or above is recommended             ;;
;;                                                                ;;
;;  * IMPORTANT!                                                  ;;
;;    Section [CustomMessages] below contains messages            ;;
;;    in several 8-bit encodings (code pages 1251, 1252).         ;;
;;    Don't use any encoding conversion tool (e.g. iconv,         ;;
;;    recode) on this file directly! That section is in fact in a ;;
;;    separate file "messages.iss" that is usid via #include to   ;;
;;    leave this top-level file more robust. The "files" section  ;;
;;    has also moved to "files.iss" since it is a part of the     ;;
;;    script most liable to change.                               ;;
;;                                                                ;;
;;----------------------------------------------------------------;;


[Setup]
AppName=REDUCE
AppVerName=REDUCE
AppId=REDUCE
UsePreviousAppDir=yes
AppPublisher=REDUCE Developers
VersionInfoCopyright=REDUCE Developers
AppPublisherURL=https://reduce-algebra.sourceforge.io/
AppSupportURL=https://reduce-algebra.sourceforge.io/
AppUpdatesURL=https://reduce-algebra.sourceforge.io/
AppVersion={#myver}
OutputBaseFilename=Reduce-Setup
DefaultDirName={pf}\Reduce
DefaultGroupName=Reduce
AllowNoIcons=yes
LicenseFile={#mydir}\C\csl\reduce.doc\BINARY-LICENSE.txt
Compression=lzma/ultra
SolidCompression=yes
Uninstallable=yes
UninstallFilesDir={app}\uninst
ShowLanguageDialog=yes
ChangesAssociations=yes
PrivilegesRequired=none
ArchitecturesInstallIn64BitMode=x64


[Languages]
Name: "en"; MessagesFile: "compiler:Default.isl"
Name: "de"; MessagesFile: "compiler:Languages\German.isl"
Name: "fr"; MessagesFile: "compiler:Languages\French.isl"
Name: "it"; MessagesFile: "compiler:Languages\Italian.isl"
Name: "es"; MessagesFile: "compiler:Languages\Spanish.isl"


[Types]
Name: "full"; Description: "{cm:FullInstallation}"
Name: "cslonly"; Description: "{cm:CslOnlyInstallation}"
Name: "pslonly"; Description: "{cm:PslOnlyInstallation}"
Name: "custom"; Description: "{cm:CustomInstallation}"; Flags: iscustom


[Components]
Name: "common"; Description: "{cm:ReduceCommon}"; Types: full cslonly pslonly custom; Flags: fixed
Name: "common\source"; Description: "{cm:ReduceSrc}"; Types: full custom
Name: "csl"; Description: "{cm:ReduceCSL}"; Types: full cslonly custom
Name: "psl32"; Description: "{cm:ReducePSL}"; Types: full pslonly custom; Check: not Is64BitInstallMode
Name: "psl64"; Description: "{cm:ReducePSL}"; Types: full pslonly custom; Check: Is64BitInstallMode


#include "files.iss"

[Icons]
;Name: "{group}\redcsl"; Filename: "{app}\bin\redcsl.bat"; IconFileName: "{app}\bin\redcsl.bat"; WorkingDir: "%USERPROFILE%\Documents"; Components: csl
Name: "{group}\CSL Reduce"; Filename: "{app}\lib\csl\winreduce.exe"; WorkingDir: "%USERPROFILE%\Documents"; Components: csl
Name: "{group}\CSL Bootstrap Reduce"; Filename: "{app}\lib\csl\bootstrapreduce.exe"; WorkingDir: "%USERPROFILE%\Documents"; Components: csl
Name: "{group}\CSL Lisp system"; Filename: "{app}\lib\csl\wincsl.exe"; WorkingDir: "%USERPROFILE%\Documents"; Components: csl
Name: "{group}\PSL Reduce"; Filename: "{app}\bin\redpsl.bat"; IconFileName: "{app}\lib\psl\psl\bpslw.exe"; WorkingDir: "%USERPROFILE%\Documents"; Components: psl32 psl64
Name: "{group}\Reduce Manual (PDF version)"; Filename: "{app}\lib\csl\reduce.doc\manual.pdf" ; Components: common
Name: "{group}\Reduce Manual (HTML version)"; Filename: "{app}\lib\csl\reduce.doc\manual.html" ; Components: common
Name: "{group}\Inside Reduce"; Filename: "{app}\doc\insidereduce.pdf" ; Components: common
Name: "{group}\Reduce Symbolic Mode Primer"; Filename: "{app}\doc\primer.pdf" ; Components: common
Name: "{group}\Standard Lisp Report"; Filename: "{app}\doc\sl.pdf" ; Components: common


[Run]
Filename: "{app}\lib\gp460-win32-setup.exe"; Description: "Install Gnuplot"; Flags: postinstall; Check: MyGnuPlotCheck
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\lib\csl\reduce.exe"" redcsl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\lib\csl\bootstrapreduce.exe"" bootstrapreduce"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\lib\csl\csl.exe"" csl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\bin\rfcsl.exe"" ""{app}\bin\rfcsl.exe"" rfcsl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\psl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\bin\redpsl"" redpsl"; Flags: runhidden; Components: psl32 psl64
Filename: "{app}\lib\psl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\bin\rfpsl.exe"" ""{app}\bin\rfpsl.exe"" rfpsl"; Flags: runhidden; Components: psl32 psl64


[UninstallRun]
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Parameters: "redcsl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Parameters: "bootstrapreduce"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Parameters: "csl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Parameters: "rfcsl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\psl\make-cygwin-symlink.exe"; Parameters: "redpsl"; Flags: runhidden; Components: psl32 psl64
Filename: "{app}\lib\psl\make-cygwin-symlink.exe"; Parameters: "rfpsl"; Flags: runhidden; Components: psl32 psl64


[Code]
var
  NeedGnuPlotInstall: Boolean;
  GnuPlotPath: String;

function InitializeSetup(): Boolean;
var
  RegVal: String;
begin
  Log('InitializeSetup called');
  if not RegQueryStringValue(HKEY_CLASSES_ROOT, 'gnuplot\shell\open\command', '', RegVal) then begin
    NeedGnuPlotInstall := True;
    Log('No Gnuplot Installed');
  end else begin
    NeedGnuPlotInstall := False;
    GnuPlotPath := RegVal;
    Delete(GnuPlotPath, Pos(' -p ', RegVal), Length(RegVal));
    Log('Gnuplot found at '+GnuPlotPath);
  end;
  Result := True;
end;


function MyGnuPlotCheck(): Boolean;
begin
  Result := NeedGnuPlotInstall;
end;

#include "messages.iss"

#expr SaveToFile("ReducePreprocessed.iss")

;; End if reduce.iss
