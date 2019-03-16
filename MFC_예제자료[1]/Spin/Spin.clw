; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSpinDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Spin.h"

ClassCount=3
Class1=CSpinApp
Class2=CSpinDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SPIN_DIALOG

[CLS:CSpinApp]
Type=0
HeaderFile=Spin.h
ImplementationFile=Spin.cpp
Filter=N

[CLS:CSpinDlg]
Type=0
HeaderFile=SpinDlg.h
ImplementationFile=SpinDlg.cpp
Filter=D
LastObject=IDC_SPIN_NUM
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SpinDlg.h
ImplementationFile=SpinDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SPIN_DIALOG]
Type=1
Class=CSpinDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_NUM,edit,1350631552
Control3=IDC_SPIN_NUM,msctls_updown32,1342177330
Control4=IDC_BUTT_EXIT,button,1342242816

