; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCtlCheckDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ctlCheck.h"

ClassCount=3
Class1=CCtlCheckApp
Class2=CCtlCheckDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CTLCHECK_DIALOG

[CLS:CCtlCheckApp]
Type=0
HeaderFile=ctlCheck.h
ImplementationFile=ctlCheck.cpp
Filter=N

[CLS:CCtlCheckDlg]
Type=0
HeaderFile=ctlCheckDlg.h
ImplementationFile=ctlCheckDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ctlCheckDlg.h
ImplementationFile=ctlCheckDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CTLCHECK_DIALOG]
Type=1
Class=CCtlCheckDlg
ControlCount=3
Control1=IDC_CHECK_MESS,button,1342242819
Control2=IDC_EDIT,edit,1350631552
Control3=IDC_BUTT_EXIT,button,1342242816

