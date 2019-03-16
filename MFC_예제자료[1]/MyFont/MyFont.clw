; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyFontDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyFont.h"

ClassCount=4
Class1=CMyFontApp
Class2=CMyFontDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MYFONT_DIALOG

[CLS:CMyFontApp]
Type=0
HeaderFile=MyFont.h
ImplementationFile=MyFont.cpp
Filter=N

[CLS:CMyFontDlg]
Type=0
HeaderFile=MyFontDlg.h
ImplementationFile=MyFontDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MyFontDlg.h
ImplementationFile=MyFontDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYFONT_DIALOG]
Type=1
Class=CMyFontDlg
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTT_PRINT,button,1342242816
Control3=IDC_BUTT_EXIT,button,1342242816

