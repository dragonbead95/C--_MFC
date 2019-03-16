; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CProcValueDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ProcValue.h"

ClassCount=3
Class1=CProcValueApp
Class2=CProcValueDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PROCVALUE_DIALOG

[CLS:CProcValueApp]
Type=0
HeaderFile=ProcValue.h
ImplementationFile=ProcValue.cpp
Filter=N

[CLS:CProcValueDlg]
Type=0
HeaderFile=ProcValueDlg.h
ImplementationFile=ProcValueDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ProcValueDlg.h
ImplementationFile=ProcValueDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PROCVALUE_DIALOG]
Type=1
Class=CProcValueDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTT_PRINT,button,1342242816
Control3=IDC_BUTT_EXIT,button,1342242816
Control4=IDC_LIST_VALUE,SysListView32,1350631425

