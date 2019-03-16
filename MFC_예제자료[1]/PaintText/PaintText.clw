; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPaintTextDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PaintText.h"

ClassCount=4
Class1=CPaintTextApp
Class2=CPaintTextDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PAINTTEXT_DIALOG

[CLS:CPaintTextApp]
Type=0
HeaderFile=PaintText.h
ImplementationFile=PaintText.cpp
Filter=N

[CLS:CPaintTextDlg]
Type=0
HeaderFile=PaintTextDlg.h
ImplementationFile=PaintTextDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=PaintTextDlg.h
ImplementationFile=PaintTextDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PAINTTEXT_DIALOG]
Type=1
Class=CPaintTextDlg
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTT_EXIT,button,1342242816

