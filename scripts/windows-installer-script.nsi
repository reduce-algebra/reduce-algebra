/*
Copyright 2009 Jim Michaels, Joost Verburg
*/
;NSIS Modern User Interface
;Start Menu Folder Selection Example Script
;Written by Joost Verburg
;mostly modified by Jim Michaels June Sept 25, 2009

;--------------------------------

	RequestExecutionLevel admin ;for windows vista/7.  I think this is necessary for this installer only because we write into HKLM and because we expect to write into $PROGRAMFILES
	;for some reason, this does not work in .onInit
	;Reduce application does not have a manifest I don't think.  It was not built with Microsoft Visual Studio.

;Include Modern UI
	!include "MUI2.nsh"

	

;--------------------------------
;General

  ;Name and file
  Name "Reduce Computer Algebra System (CAS) 20090226"
  OutFile "reduce-20090226-setup.exe"

  ;Default installation folder
;  InstallDir "$LOCALAPPDATA\Reduce"
  InstallDir "$PROGRAMFILES\Reduce"
  
  ;Get installation folder from registry if available
  InstallDirRegKey HKCU "Software\Reduce" ""

  ;Request application privileges for Windows Vista
  RequestExecutionLevel user

;--------------------------------
;Variables

  Var StartMenuFolder

;--------------------------------
;Interface Settings

  !define MUI_ABORTWARNING
Function .onInit
    #prevent multiple instances of the installer running
    System::Call 'kernel32::CreateMutexA(i 0, i 0, t "ReduceSetup") i .r1 ?e'
    Pop $R0

    StrCmp $R0 0 +3
    MessageBox MB_OK|MB_ICONEXCLAMATION "The installer is already running."
    Abort

;    SetOutPath "."
;    File /oname=$PLUGINSDIR\welcome.bmp "${NSISDIR}\Contrib\Graphics\Wizard\orange-nsis.bmp"
;  File "setup.ini"
	GetDlgItem $0 $HWNDPARENT 1
	CreateFont $1 "$(^Font)" "14" "700"
;culprit. worked in older versions.  what do I do now?  got this from the forums.
;    CreateFont $HEADLINE_FONT "$(^Font)" "14" "700"
    InitPluginsDir
;    SetOutPath "$PLUGINSDIR"
    SetOutPath "$PROGRAMFILES\Reduce"



	SetShellVarContext all ;all users
	
  
;	!insertmacro MUI_LANGDLL_DISPLAY ;required I think for multiple languages
FunctionEnd




;--------------------------------
;Pages

  !insertmacro MUI_PAGE_WELCOME
;  !insertmacro MUI_PAGE_LICENSE "${NSISDIR}\Docs\Modern UI\License.txt"
  !insertmacro MUI_PAGE_LICENSE "license.txt"
  !insertmacro MUI_PAGE_COMPONENTS
  !insertmacro MUI_PAGE_DIRECTORY
  
  ;Start Menu Folder Page Configuration
  !define MUI_STARTMENUPAGE_REGISTRY_ROOT "HKCU" 
  !define MUI_STARTMENUPAGE_REGISTRY_KEY "Software\Reduce" 
  !define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "Start Menu Folder"
  
  !insertmacro MUI_PAGE_STARTMENU Application $StartMenuFolder
  
  !insertmacro MUI_PAGE_INSTFILES
  !insertmacro MUI_PAGE_FINISH
  
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES

;--------------------------------
;Languages
 
  !insertmacro MUI_LANGUAGE "English"

;--------------------------------
;Installer Sections

Section "-Dummy Section" SecDummy
	File /r /x reduce-20090226-setup.exe *.* ;all files go into compressed setup file except setup file

  SetOutPath "$INSTDIR"
  
  ;ADD YOUR OWN FILES HERE...
  
  ;Store installation folder
  WriteRegStr HKCU "Software\Reduce" "" $INSTDIR
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"
  
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
    
    ;Create shortcuts
    CreateDirectory "$SMPROGRAMS\$StartMenuFolder"
    CreateShortCut "$SMPROGRAMS\$StartMenuFolder\Uninstall.lnk" "$INSTDIR\Uninstall.exe"

	;set up add/remove programs control panel entry
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Reduce" "DisplayName" "Reduce 20090226"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Reduce" "UninstallString" "$\"$INSTDIR\uninstall.exe$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Reduce" "URLUpdateInfo" "http://reduce-algebra.sourceforge.net"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Reduce" "URLInfoAbout" "http://reduce-algebra.sourceforge.net"
;	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Reduce" "VersionMajor" 1
;	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Reduce" "VersionMinor" 7
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Reduce" "DisplayVersion" "20090226"
;	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Reduce" "Publisher" "Jim Michaels"

				 !insertmacro MUI_STARTMENU_WRITE_END

SectionEnd


Section "Reduce Computer Algebra System (CAS) 20090226" Sec_gui
	CreateDirectory '$INSTDIR'
	CreateDirectory "$INSTDIR\reduce.doc"
	CreateDirectory "$INSTDIR\reduce.fonts"  ;this line not necessary
	CreateDirectory "$INSTDIR\reduce.fonts\src"
	CreateDirectory "$INSTDIR\reduce.fonts\pfmfiles"

	;I only have to specify a destination folder, but it was less work this way.
	;copy from to, where from is inside the compressed setup EXE

	CopyFiles "\reduce.doc\sl.pdf"                      "$INSTDIR\reduce.doc\sl.pdf"
	CopyFiles "\reduce.doc\redlog.pdf"                  "$INSTDIR\reduce.doc\redlog.pdf"
	CopyFiles "\guardian.red"                           "$INSTDIR\guardian.red"

	CopyFiles "\reduce.com"                             "$INSTDIR\reduce.com"
	CopyFiles "\reduce.exe"                             "$INSTDIR\reduce.exe"
	CopyFiles "\reduce.img"                             "$INSTDIR\reduce.img"
	CopyFiles "\reduce.doc\abstract.tex"                "$INSTDIR\reduce.doc\abstract.tex"
	CopyFiles "\reduce.doc\acknowl.tex"                 "$INSTDIR\reduce.doc\acknowl.tex"
	CopyFiles "\reduce.doc\appenda.tex"                 "$INSTDIR\reduce.doc\appenda.tex"
	CopyFiles "\reduce.doc\aprop.tex"                   "$INSTDIR\reduce.doc\aprop.tex"
	CopyFiles "\reduce.doc\cfrac.tex"                   "$INSTDIR\reduce.doc\cfrac.tex"
	CopyFiles "\reduce.doc\command.tex"                 "$INSTDIR\reduce.doc\command.tex"
	CopyFiles "\reduce.doc\convert.tex"                 "$INSTDIR\reduce.doc\convert.tex"
	CopyFiles "\reduce.doc\exprn.tex"                   "$INSTDIR\reduce.doc\exprn.tex"
	CopyFiles "\reduce.doc\header.tex"                  "$INSTDIR\reduce.doc\header.tex"
	CopyFiles "\reduce.doc\hephys.tex"                  "$INSTDIR\reduce.doc\hephys.tex"
	CopyFiles "\reduce.doc\heugcd.tex"                  "$INSTDIR\reduce.doc\heugcd.tex"
	CopyFiles "\reduce.doc\index.html"                  "$INSTDIR\reduce.doc\index.html"
	CopyFiles "\reduce.doc\inter.tex"                   "$INSTDIR\reduce.doc\inter.tex"
	CopyFiles "\reduce.doc\intro.tex"                   "$INSTDIR\reduce.doc\intro.tex"
	CopyFiles "\reduce.doc\io.tex"                      "$INSTDIR\reduce.doc\io.tex"
	CopyFiles "\reduce.doc\list.tex"                    "$INSTDIR\reduce.doc\list.tex"
	CopyFiles "\reduce.doc\macros.tex"                  "$INSTDIR\reduce.doc\macros.tex"
	CopyFiles "\reduce.doc\maintain.tex"                "$INSTDIR\reduce.doc\maintain.tex"
	CopyFiles "\reduce.doc\manual.tex"                  "$INSTDIR\reduce.doc\manual.tex"
	CopyFiles "\reduce.doc\map.tex"                     "$INSTDIR\reduce.doc\map.tex"
	CopyFiles "\reduce.doc\matrix.tex"                  "$INSTDIR\reduce.doc\matrix.tex"
	CopyFiles "\reduce.doc\oper.tex"                    "$INSTDIR\reduce.doc\oper.tex"
	CopyFiles "\reduce.doc\oper2.tex"                   "$INSTDIR\reduce.doc\oper2.tex"
	CopyFiles "\reduce.doc\polyrat.tex"                 "$INSTDIR\reduce.doc\polyrat.tex"
	CopyFiles "\reduce.doc\proc.tex"                    "$INSTDIR\reduce.doc\proc.tex"
	CopyFiles "\reduce.doc\progstr.tex"                 "$INSTDIR\reduce.doc\progstr.tex"
	CopyFiles "\reduce.doc\r38_0001.html"               "$INSTDIR\reduce.doc\r38_0001.html"
	CopyFiles "\reduce.doc\r38_0050.html"               "$INSTDIR\reduce.doc\r38_0050.html"
	CopyFiles "\reduce.doc\r38_0100.html"               "$INSTDIR\reduce.doc\r38_0100.html"
	CopyFiles "\reduce.doc\r38_0150.html"               "$INSTDIR\reduce.doc\r38_0150.html"
	CopyFiles "\reduce.doc\r38_0200.html"               "$INSTDIR\reduce.doc\r38_0200.html"
	CopyFiles "\reduce.doc\r38_0250.html"               "$INSTDIR\reduce.doc\r38_0250.html"
	CopyFiles "\reduce.doc\r38_0300.html"               "$INSTDIR\reduce.doc\r38_0300.html"
	CopyFiles "\reduce.doc\r38_0350.html"               "$INSTDIR\reduce.doc\r38_0350.html"
	CopyFiles "\reduce.doc\r38_0400.html"               "$INSTDIR\reduce.doc\r38_0400.html"
	CopyFiles "\reduce.doc\r38_0450.html"               "$INSTDIR\reduce.doc\r38_0450.html"
	CopyFiles "\reduce.doc\r38_0500.html"               "$INSTDIR\reduce.doc\r38_0500.html"
	CopyFiles "\reduce.doc\r38_0550.html"               "$INSTDIR\reduce.doc\r38_0550.html"
	CopyFiles "\reduce.doc\r38_0600.html"               "$INSTDIR\reduce.doc\r38_0600.html"
	CopyFiles "\reduce.doc\r38_0650.html"               "$INSTDIR\reduce.doc\r38_0650.html"
	CopyFiles "\reduce.doc\r38_idx.html"                "$INSTDIR\reduce.doc\r38_idx.html"
	CopyFiles "\reduce.doc\redlogo.gif"                 "$INSTDIR\reduce.doc\redlogo.gif"
	CopyFiles "\reduce.doc\rememb.tex"                  "$INSTDIR\reduce.doc\rememb.tex"
	CopyFiles "\reduce.doc\rest.tex"                    "$INSTDIR\reduce.doc\rest.tex"
	CopyFiles "\reduce.doc\rlisp88.tex"                 "$INSTDIR\reduce.doc\rlisp88.tex"
	CopyFiles "\reduce.doc\rlispref.tex"                "$INSTDIR\reduce.doc\rlispref.tex"
	CopyFiles "\reduce.doc\solve.tex"                   "$INSTDIR\reduce.doc\solve.tex"
	CopyFiles "\reduce.doc\statemnt.tex"                "$INSTDIR\reduce.doc\statemnt.tex"
	CopyFiles "\reduce.doc\structr.tex"                 "$INSTDIR\reduce.doc\structr.tex"
	CopyFiles "\reduce.doc\subst.tex"                   "$INSTDIR\reduce.doc\subst.tex"
	CopyFiles "\reduce.doc\symbolic.tex"                "$INSTDIR\reduce.doc\symbolic.tex"
	CopyFiles "\reduce.doc\title.tex"                   "$INSTDIR\reduce.doc\title.tex"
	CopyFiles "\reduce.doc\util.tex"                    "$INSTDIR\reduce.doc\util.tex"
	CopyFiles "\reduce.fonts\cmex10.pfa"                "$INSTDIR\reduce.fonts\cmex10.pfa"
	CopyFiles "\reduce.fonts\cmex10.pfb"                "$INSTDIR\reduce.fonts\cmex10.pfb"
	CopyFiles "\reduce.fonts\cmex10.ttf"                "$INSTDIR\reduce.fonts\cmex10.ttf"
	CopyFiles "\reduce.fonts\cmex7.ttf"                 "$INSTDIR\reduce.fonts\cmex7.ttf"
	CopyFiles "\reduce.fonts\cmex8.ttf"                 "$INSTDIR\reduce.fonts\cmex8.ttf"
	CopyFiles "\reduce.fonts\cmex9.ttf"                 "$INSTDIR\reduce.fonts\cmex9.ttf"
	CopyFiles "\reduce.fonts\cmmi10.pfa"                "$INSTDIR\reduce.fonts\cmmi10.pfa"
	CopyFiles "\reduce.fonts\cmmi10.pfb"                "$INSTDIR\reduce.fonts\cmmi10.pfb"
	CopyFiles "\reduce.fonts\cmmi10.ttf"                "$INSTDIR\reduce.fonts\cmmi10.ttf"
	CopyFiles "\reduce.fonts\cmmi12.ttf"                "$INSTDIR\reduce.fonts\cmmi12.ttf"
	CopyFiles "\reduce.fonts\cmmi5.ttf"                 "$INSTDIR\reduce.fonts\cmmi5.ttf"
	CopyFiles "\reduce.fonts\cmmi6.ttf"                 "$INSTDIR\reduce.fonts\cmmi6.ttf"
	CopyFiles "\reduce.fonts\cmmi7.ttf"                 "$INSTDIR\reduce.fonts\cmmi7.ttf"
	CopyFiles "\reduce.fonts\cmmi8.ttf"                 "$INSTDIR\reduce.fonts\cmmi8.ttf"
	CopyFiles "\reduce.fonts\cmmi9.ttf"                 "$INSTDIR\reduce.fonts\cmmi9.ttf"
	CopyFiles "\reduce.fonts\cmr10.pfa"                 "$INSTDIR\reduce.fonts\cmr10.pfa"
	CopyFiles "\reduce.fonts\cmr10.pfb"                 "$INSTDIR\reduce.fonts\cmr10.pfb"
	CopyFiles "\reduce.fonts\cmr10.ttf"                 "$INSTDIR\reduce.fonts\cmr10.ttf"
	CopyFiles "\reduce.fonts\cmr12.ttf"                 "$INSTDIR\reduce.fonts\cmr12.ttf"
	CopyFiles "\reduce.fonts\cmr17.ttf"                 "$INSTDIR\reduce.fonts\cmr17.ttf"
	CopyFiles "\reduce.fonts\cmr5.ttf"                  "$INSTDIR\reduce.fonts\cmr5.ttf"
	CopyFiles "\reduce.fonts\cmr6.ttf"                  "$INSTDIR\reduce.fonts\cmr6.ttf"
	CopyFiles "\reduce.fonts\cmr7.ttf"                  "$INSTDIR\reduce.fonts\cmr7.ttf"
	CopyFiles "\reduce.fonts\cmr8.ttf"                  "$INSTDIR\reduce.fonts\cmr8.ttf"
	CopyFiles "\reduce.fonts\cmr9.ttf"                  "$INSTDIR\reduce.fonts\cmr9.ttf"
	CopyFiles "\reduce.fonts\cmsy10.pfa"                "$INSTDIR\reduce.fonts\cmsy10.pfa"
	CopyFiles "\reduce.fonts\cmsy10.pfb"                "$INSTDIR\reduce.fonts\cmsy10.pfb"
	CopyFiles "\reduce.fonts\cmsy10.ttf"                "$INSTDIR\reduce.fonts\cmsy10.ttf"
	CopyFiles "\reduce.fonts\cmsy5.ttf"                 "$INSTDIR\reduce.fonts\cmsy5.ttf"
	CopyFiles "\reduce.fonts\cmsy6.ttf"                 "$INSTDIR\reduce.fonts\cmsy6.ttf"
	CopyFiles "\reduce.fonts\cmsy7.ttf"                 "$INSTDIR\reduce.fonts\cmsy7.ttf"
	CopyFiles "\reduce.fonts\cmsy8.ttf"                 "$INSTDIR\reduce.fonts\cmsy8.ttf"
	CopyFiles "\reduce.fonts\cmsy9.ttf"                 "$INSTDIR\reduce.fonts\cmsy9.ttf"
	CopyFiles "\reduce.fonts\fonts.dir"                 "$INSTDIR\reduce.fonts\fonts.dir"
	CopyFiles "\reduce.fonts\fonts.scale"               "$INSTDIR\reduce.fonts\fonts.scale"
	CopyFiles "\reduce.fonts\README"                    "$INSTDIR\reduce.fonts\README"
	CopyFiles "\reduce.fonts\README.BaKoMa"             "$INSTDIR\reduce.fonts\README.BaKoMa"
	CopyFiles "\reduce.fonts\README.cmps-fonts"         "$INSTDIR\reduce.fonts\README.cmps-fonts"
	CopyFiles "\reduce.fonts\pfmfiles\cmex10.pfm"       "$INSTDIR\reduce.fonts\pfmfiles\cmex10.pfm"
	CopyFiles "\reduce.fonts\pfmfiles\cmmi10.pfm"       "$INSTDIR\reduce.fonts\pfmfiles\cmmi10.pfm"
	CopyFiles "\reduce.fonts\pfmfiles\cmr10.pfm"        "$INSTDIR\reduce.fonts\pfmfiles\cmr10.pfm"
	CopyFiles "\reduce.fonts\pfmfiles\cmsy10.pfm"       "$INSTDIR\reduce.fonts\pfmfiles\cmsy10.pfm"
	CopyFiles "\reduce.fonts\src\cmex10.asm.gz"         "$INSTDIR\reduce.fonts\src\cmex10.asm.gz"
	CopyFiles "\reduce.fonts\src\cmmi10.asm.gz"         "$INSTDIR\reduce.fonts\src\cmmi10.asm.gz"
	CopyFiles "\reduce.fonts\src\cmr10.asm.gz"          "$INSTDIR\reduce.fonts\src\cmr10.asm.gz"
	CopyFiles "\reduce.fonts\src\cmsy10.asm.gz"         "$INSTDIR\reduce.fonts\src\cmsy10.asm.gz"


	CreateDirectory "$SMPROGRAMS\$StartMenuFolder"

	CreateShortCut "$SMPROGRAMS\$StartMenuFolder\reduce-text-mode.lnk" 	"$INSTDIR\reduce.com"
	CreateShortCut "$SMPROGRAMS\$StartMenuFolder\reduce-GUI-mode.lnk" 	"$INSTDIR\reduce.exe"
	CreateShortCut "$SMPROGRAMS\$StartMenuFolder\manual.lnk" 			"$INSTDIR\reduce.doc\index.html"
	CreateShortCut "$SMPROGRAMS\$StartMenuFolder\license.lnk" 			"$INSTDIR\license.htm"
	CreateShortCut "$SMPROGRAMS\$StartMenuFolder\redlog.lnk" 			"$INSTDIR\reduce.doc\redlog.pdf"
	CreateShortCut "$SMPROGRAMS\$StartMenuFolder\standard-lisp-manual.lnk" 				"$INSTDIR\reduce.doc\sl.pdf"
	CreateShortCut "$SMPROGRAMS\$StartMenuFolder\readme-fonts.lnk" 		"$INSTDIR\reduce.fonts\README"
	CreateShortCut "$SMPROGRAMS\$StartMenuFolder\readme-BaKoMa.lnk" 	"$INSTDIR\reduce.fonts\README.BaKoMa"
	CreateShortCut "$SMPROGRAMS\$StartMenuFolder\readme-cmps-fonts.lnk"	"$INSTDIR\reduce.fonts\README.cmps-fonts"

SectionEnd




;--------------------------------
;Descriptions

  ;Language strings
  LangString DESC_Sec_gui ${LANG_ENGLISH} "Reduce Compurer Algebra System (CAS), DOS command-line and GUI version(Windows). 32-bit. 9x/me/nt/2000/2003/xp/ may work in vista/7."

  ;Assign language strings to sections. 
  ;makes checkboxes in the installer page in this order.
  !insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${Sec_gui} $(DESC_Sec_gui)
  !insertmacro MUI_FUNCTION_DESCRIPTION_END
 
;--------------------------------
;Uninstaller Section

Function un.onInit 
	;set context of $SMPROGRAMS and $APPDATA to All Users rather than Current User.
	SetShellVarContext all
FunctionEnd

Section "Uninstall"
	;close any open windows of Phone
lupe:
	Processes::FindProcess "reduce"	;without ".exe"
	Pop $R0
	StrCmp $R0 "1" +1 exitlupe
	;	Searches the currently running processes for the given
	;	process name.
	;	
	;	return:	1	- the process was found
	;			0	- the process was not found
	
	Processes::KillProcess "reduce"	; without ".exe"
	
	;	Searches the currently running processes for the given
	;	process name. If the process is found then the it gets
	;	killed.
	;	
	;	return:	1	- the process was found and killed
	;			0	- the process was not found or the process
	;					cannot be killed (insuficient rights)
	Pop $R0
	StrCmp $R0 "1" +1 exitlupe ;if fail to kill process, exit so we don't get in permanent loop.
	Goto lupe
exitlupe:

	Delete "$INSTDIR\Uninstall.exe"

	RMDir "$INSTDIR"
  
	!insertmacro MUI_STARTMENU_GETFOLDER Application $StartMenuFolder
    
	Delete "$SMPROGRAMS\$StartMenuFolder\Uninstall.lnk"
	RMDir "$SMPROGRAMS\$StartMenuFolder"
  
	DeleteRegKey /ifempty HKCU "Software\Reduce"

	;remove files
	Delete "$INSTDIR\reduce.doc\sl.pdf"
	Delete "$INSTDIR\reduce.doc\redlog.pdf"
	Delete "$INSTDIR\guardian.red"

	Delete "$INSTDIR\reduce.com"
	Delete "$INSTDIR\reduce.exe"
	Delete "$INSTDIR\reduce.img"
	Delete "$INSTDIR\reduce.doc\abstract.tex"
	Delete "$INSTDIR\reduce.doc\acknowl.tex"
	Delete "$INSTDIR\reduce.doc\appenda.tex"
	Delete "$INSTDIR\reduce.doc\aprop.tex"
	Delete "$INSTDIR\reduce.doc\cfrac.tex"
	Delete "$INSTDIR\reduce.doc\command.tex"
	Delete "$INSTDIR\reduce.doc\convert.tex"
	Delete "$INSTDIR\reduce.doc\exprn.tex"
	Delete "$INSTDIR\reduce.doc\header.tex"
	Delete "$INSTDIR\reduce.doc\hephys.tex"
	Delete "$INSTDIR\reduce.doc\heugcd.tex"
	Delete "$INSTDIR\reduce.doc\index.html"
	Delete "$INSTDIR\reduce.doc\inter.tex"
	Delete "$INSTDIR\reduce.doc\intro.tex"
	Delete "$INSTDIR\reduce.doc\io.tex"
	Delete "$INSTDIR\reduce.doc\list.tex"
	Delete "$INSTDIR\reduce.doc\macros.tex"
	Delete "$INSTDIR\reduce.doc\maintain.tex"
	Delete "$INSTDIR\reduce.doc\manual.tex"
	Delete "$INSTDIR\reduce.doc\map.tex"
	Delete "$INSTDIR\reduce.doc\matrix.tex"
	Delete "$INSTDIR\reduce.doc\oper.tex"
	Delete "$INSTDIR\reduce.doc\oper2.tex"
	Delete "$INSTDIR\reduce.doc\polyrat.tex"
	Delete "$INSTDIR\reduce.doc\proc.tex"
	Delete "$INSTDIR\reduce.doc\progstr.tex"
	Delete "$INSTDIR\reduce.doc\r38_0001.html"
	Delete "$INSTDIR\reduce.doc\r38_0050.html"
	Delete "$INSTDIR\reduce.doc\r38_0100.html"
	Delete "$INSTDIR\reduce.doc\r38_0150.html"
	Delete "$INSTDIR\reduce.doc\r38_0200.html"
	Delete "$INSTDIR\reduce.doc\r38_0250.html"
	Delete "$INSTDIR\reduce.doc\r38_0300.html"
	Delete "$INSTDIR\reduce.doc\r38_0350.html"
	Delete "$INSTDIR\reduce.doc\r38_0400.html"
	Delete "$INSTDIR\reduce.doc\r38_0450.html"
	Delete "$INSTDIR\reduce.doc\r38_0500.html"
	Delete "$INSTDIR\reduce.doc\r38_0550.html"
	Delete "$INSTDIR\reduce.doc\r38_0600.html"
	Delete "$INSTDIR\reduce.doc\r38_0650.html"
	Delete "$INSTDIR\reduce.doc\r38_idx.html"
	Delete "$INSTDIR\reduce.doc\redlogo.gif"
	Delete "$INSTDIR\reduce.doc\rememb.tex"
	Delete "$INSTDIR\reduce.doc\rest.tex"
	Delete "$INSTDIR\reduce.doc\rlisp88.tex"
	Delete "$INSTDIR\reduce.doc\rlispref.tex"
	Delete "$INSTDIR\reduce.doc\solve.tex"
	Delete "$INSTDIR\reduce.doc\statemnt.tex"
	Delete "$INSTDIR\reduce.doc\structr.tex"
	Delete "$INSTDIR\reduce.doc\subst.tex"
	Delete "$INSTDIR\reduce.doc\symbolic.tex"
	Delete "$INSTDIR\reduce.doc\title.tex"
	Delete "$INSTDIR\reduce.doc\util.tex"
	Delete "$INSTDIR\reduce.fonts\cmex10.pfa"
	Delete "$INSTDIR\reduce.fonts\cmex10.pfb"
	Delete "$INSTDIR\reduce.fonts\cmex10.ttf"
	Delete "$INSTDIR\reduce.fonts\cmex7.ttf"
	Delete "$INSTDIR\reduce.fonts\cmex8.ttf"
	Delete "$INSTDIR\reduce.fonts\cmex9.ttf"
	Delete "$INSTDIR\reduce.fonts\cmmi10.pfa"
	Delete "$INSTDIR\reduce.fonts\cmmi10.pfb"
	Delete "$INSTDIR\reduce.fonts\cmmi10.ttf"
	Delete "$INSTDIR\reduce.fonts\cmmi12.ttf"
	Delete "$INSTDIR\reduce.fonts\cmmi5.ttf"
	Delete "$INSTDIR\reduce.fonts\cmmi6.ttf"
	Delete "$INSTDIR\reduce.fonts\cmmi7.ttf"
	Delete "$INSTDIR\reduce.fonts\cmmi8.ttf"
	Delete "$INSTDIR\reduce.fonts\cmmi9.ttf"
	Delete "$INSTDIR\reduce.fonts\cmr10.pfa"
	Delete "$INSTDIR\reduce.fonts\cmr10.pfb"
	Delete "$INSTDIR\reduce.fonts\cmr10.ttf"
	Delete "$INSTDIR\reduce.fonts\cmr12.ttf"
	Delete "$INSTDIR\reduce.fonts\cmr17.ttf"
	Delete "$INSTDIR\reduce.fonts\cmr5.ttf"
	Delete "$INSTDIR\reduce.fonts\cmr6.ttf"
	Delete "$INSTDIR\reduce.fonts\cmr7.ttf"
	Delete "$INSTDIR\reduce.fonts\cmr8.ttf"
	Delete "$INSTDIR\reduce.fonts\cmr9.ttf"
	Delete "$INSTDIR\reduce.fonts\cmsy10.pfa"
	Delete "$INSTDIR\reduce.fonts\cmsy10.pfb"
	Delete "$INSTDIR\reduce.fonts\cmsy10.ttf"
	Delete "$INSTDIR\reduce.fonts\cmsy5.ttf"
	Delete "$INSTDIR\reduce.fonts\cmsy6.ttf"
	Delete "$INSTDIR\reduce.fonts\cmsy7.ttf"
	Delete "$INSTDIR\reduce.fonts\cmsy8.ttf"
	Delete "$INSTDIR\reduce.fonts\cmsy9.ttf"
	Delete "$INSTDIR\reduce.fonts\fonts.dir"
	Delete "$INSTDIR\reduce.fonts\fonts.scale"
	Delete "$INSTDIR\reduce.fonts\README"
	Delete "$INSTDIR\reduce.fonts\README.BaKoMa"
	Delete "$INSTDIR\reduce.fonts\README.cmps-fonts"
	Delete "$INSTDIR\reduce.fonts\pfmfiles\cmex10.pfm"
	Delete "$INSTDIR\reduce.fonts\pfmfiles\cmmi10.pfm"
	Delete "$INSTDIR\reduce.fonts\pfmfiles\cmr10.pfm"
	Delete "$INSTDIR\reduce.fonts\pfmfiles\cmsy10.pfm"
	Delete "$INSTDIR\reduce.fonts\src\cmex10.asm.gz"
	Delete "$INSTDIR\reduce.fonts\src\cmmi10.asm.gz"
	Delete "$INSTDIR\reduce.fonts\src\cmr10.asm.gz"
	Delete "$INSTDIR\reduce.fonts\src\cmsy10.asm.gz"


	Delete "$SMPROGRAMS\$StartMenuFolder\reduce-text-mode.lnk"
	Delete "$SMPROGRAMS\$StartMenuFolder\reduce-GUI-mode.lnk"
	Delete "$SMPROGRAMS\$StartMenuFolder\manual.lnk"
	Delete "$SMPROGRAMS\$StartMenuFolder\license.lnk"
	Delete "$SMPROGRAMS\$StartMenuFolder\redlog.lnk"
	Delete "$SMPROGRAMS\$StartMenuFolder\standard-lisp-manual.lnk"
	Delete "$SMPROGRAMS\$StartMenuFolder\readme-fonts.lnk"
	Delete "$SMPROGRAMS\$StartMenuFolder\readme-BaKoMa.lnk"
	Delete "$SMPROGRAMS\$StartMenuFolder\readme-cmps-fonts.lnk"

	RMDir "$SMPROGRAMS\$StartMenuFolder"
	RMDir "$INSTDIR\reduce.doc"
	RMDir "$INSTDIR\reduce.fonts\pfmfiles"
	RMDir "$INSTDIR\reduce.fonts\src"
	RMDir "$INSTDIR\reduce.fonts"
	RMDir '$INSTDIR'
	DeleteRegKey HKCU "Software\Reduce"
;    MessageBox MB_OK|MB_ICONEXCLAMATION "remove '$INSTDIR\cmd-line\win' and '$INSTDIR\cmd-line\dos' from your PATH.  This installer cannot do it safely."
	;remove add/remove programs control panel entry
	DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Reduce"
	;remove directories, c:\program files subfolder and Start Menu subfolder
	RMDir /r /REBOOTOK '$INSTDIR'
	RMDir /r /REBOOTOK "$SMPROGRAMS\$StartMenuFolder"
SectionEnd