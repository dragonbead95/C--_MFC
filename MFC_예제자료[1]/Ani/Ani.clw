; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAniDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ani.h"

ClassCount=3
Class1=CAniApp
Class2=CAniDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ANI_DIALOG

[CLS:CAniApp]
Type=0
HeaderFile=Ani.h
ImplementationFile=Ani.cpp
Filter=N

[CLS:CAniDlg]
Type=0
HeaderFile=AniDlg.h
ImplementationFile=AniDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAniDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=AniDlg.h
ImplementationFile=AniDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ANI_DIALOG]
Type=1
Class=CAniDlg
ControlCount=5
Control1=IDC_ANIMATE,SysAnimate32,1350631426
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BUTT_PLAY,button,1342242816
Control4=IDC_BUTT_EXIT,button,1342242816
Control5=IDC_BUTT_STOP,button,1342242816

