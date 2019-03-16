; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCalenDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Calen.h"

ClassCount=3
Class1=CCalenApp
Class2=CCalenDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CALEN_DIALOG

[CLS:CCalenApp]
Type=0
HeaderFile=Calen.h
ImplementationFile=Calen.cpp
Filter=N

[CLS:CCalenDlg]
Type=0
HeaderFile=CalenDlg.h
ImplementationFile=CalenDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COMBO_MONTH

[CLS:CAboutDlg]
Type=0
HeaderFile=CalenDlg.h
ImplementationFile=CalenDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CALEN_DIALOG]
Type=1
Class=CCalenDlg
ControlCount=4
Control1=IDC_COMBO_MONTH,combobox,1344339970
Control2=IDC_EDIT_YEAR,edit,1350631552
Control3=IDC_SCROLL_YEAR,scrollbar,1342177281
Control4=IDC_BUTT_EXIT,button,1342242816

