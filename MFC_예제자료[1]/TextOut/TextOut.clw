; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTextOutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TextOut.h"

ClassCount=4
Class1=CTextOutApp
Class2=CTextOutDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TEXTOUT_DIALOG

[CLS:CTextOutApp]
Type=0
HeaderFile=TextOut.h
ImplementationFile=TextOut.cpp
Filter=N

[CLS:CTextOutDlg]
Type=0
HeaderFile=TextOutDlg.h
ImplementationFile=TextOutDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TextOutDlg.h
ImplementationFile=TextOutDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TEXTOUT_DIALOG]
Type=1
Class=CTextOutDlg
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTT_PRINT,button,1342242816
Control3=IDC_BUTT_EXIT,button,1342242816

