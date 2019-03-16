; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPuzzDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Puzz.h"

ClassCount=3
Class1=CPuzzApp
Class2=CPuzzDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PUZZ_DIALOG

[CLS:CPuzzApp]
Type=0
HeaderFile=Puzz.h
ImplementationFile=Puzz.cpp
Filter=N

[CLS:CPuzzDlg]
Type=0
HeaderFile=PuzzDlg.h
ImplementationFile=PuzzDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CPuzzDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=PuzzDlg.h
ImplementationFile=PuzzDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PUZZ_DIALOG]
Type=1
Class=CPuzzDlg
ControlCount=2
Control1=IDC_BUTT_START,button,1342242816
Control2=IDC_BUTT_EXIT,button,1342242816

