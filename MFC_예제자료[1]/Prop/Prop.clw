; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPage2
LastTemplate=CPropertySheet
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Prop.h"

ClassCount=6
Class1=CPropApp
Class2=CPropDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_PROP_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG1
Resource4=IDD_ABOUTBOX
Class4=CPage1
Class5=CPage2
Class6=CMySheet
Resource5=IDD_DIALOG2

[CLS:CPropApp]
Type=0
HeaderFile=Prop.h
ImplementationFile=Prop.cpp
Filter=N

[CLS:CPropDlg]
Type=0
HeaderFile=PropDlg.h
ImplementationFile=PropDlg.cpp
Filter=D
LastObject=CPropDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=PropDlg.h
ImplementationFile=PropDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PROP_DIALOG]
Type=1
Class=CPropDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTT_PRINT,button,1342242816
Control3=IDC_BUTT_EXIT,button,1342242816
Control4=IDC_BUTT_WIZARD,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CPage1
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG2]
Type=1
Class=CPage2
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:CPage1]
Type=0
HeaderFile=Page.h
ImplementationFile=Page.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPage1
VirtualFilter=idWC

[CLS:CPage2]
Type=0
HeaderFile=Page.h
ImplementationFile=Page.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPage2
VirtualFilter=idWC

[CLS:CMySheet]
Type=0
HeaderFile=MySheet.h
ImplementationFile=MySheet.cpp
BaseClass=CPropertySheet
Filter=W
LastObject=CMySheet

