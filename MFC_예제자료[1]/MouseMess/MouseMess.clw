; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMouseMessDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MouseMess.h"

ClassCount=3
Class1=CMouseMessApp
Class2=CMouseMessDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MOUSEMESS_DIALOG

[CLS:CMouseMessApp]
Type=0
HeaderFile=MouseMess.h
ImplementationFile=MouseMess.cpp
Filter=N

[CLS:CMouseMessDlg]
Type=0
HeaderFile=MouseMessDlg.h
ImplementationFile=MouseMessDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMouseMessDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=MouseMessDlg.h
ImplementationFile=MouseMessDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MOUSEMESS_DIALOG]
Type=1
Class=CMouseMessDlg
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_MOUSE,edit,1350631552
Control3=IDC_BUTT_EXIT,button,1342242816

