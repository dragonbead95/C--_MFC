; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRectangleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Rectangle.h"

ClassCount=4
Class1=CRectangleApp
Class2=CRectangleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_RECTANGLE_DIALOG

[CLS:CRectangleApp]
Type=0
HeaderFile=Rectangle.h
ImplementationFile=Rectangle.cpp
Filter=N

[CLS:CRectangleDlg]
Type=0
HeaderFile=RectangleDlg.h
ImplementationFile=RectangleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=RectangleDlg.h
ImplementationFile=RectangleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RECTANGLE_DIALOG]
Type=1
Class=CRectangleDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTT_ELLIPSE,button,1342242816
Control3=IDC_BUTT_RECTANGLE,button,1342242816
Control4=IDC_BUTT_EXIT,button,1342242816

