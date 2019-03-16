; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COMokDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OMok.h"

ClassCount=3
Class1=COMokApp
Class2=COMokDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_OMOK_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_MENU1

[CLS:COMokApp]
Type=0
HeaderFile=OMok.h
ImplementationFile=OMok.cpp
Filter=N

[CLS:COMokDlg]
Type=0
HeaderFile=OMokDlg.h
ImplementationFile=OMokDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=FILE_EXIT

[CLS:CAboutDlg]
Type=0
HeaderFile=OMokDlg.h
ImplementationFile=OMokDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_OMOK_DIALOG]
Type=1
Class=COMokDlg
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC_COLAL,static,1342308352
Control3=IDC_BUTT_START,button,1342242816
Control4=IDC_BUTT_RESTART,button,1342242816
Control5=IDC_BUTT_EXIT,button,1342242816

[MNU:IDR_MENU1]
Type=1
Class=COMokDlg
Command1=FILE_OPEN
Command2=FILE_SAVE
Command3=FILE_EXIT
CommandCount=3

