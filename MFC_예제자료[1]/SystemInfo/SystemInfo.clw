; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSystemInfoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SystemInfo.h"

ClassCount=3
Class1=CSystemInfoApp
Class2=CSystemInfoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SYSTEMINFO_DIALOG

[CLS:CSystemInfoApp]
Type=0
HeaderFile=SystemInfo.h
ImplementationFile=SystemInfo.cpp
Filter=N

[CLS:CSystemInfoDlg]
Type=0
HeaderFile=SystemInfoDlg.h
ImplementationFile=SystemInfoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT_VGA

[CLS:CAboutDlg]
Type=0
HeaderFile=SystemInfoDlg.h
ImplementationFile=SystemInfoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SYSTEMINFO_DIALOG]
Type=1
Class=CSystemInfoDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_MUSBUTT,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_BOOTING,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_VGA,edit,1350631552
Control8=IDC_BUTT_PRINT,button,1342242816
Control9=IDC_BUTT_EXIT,button,1342242816

