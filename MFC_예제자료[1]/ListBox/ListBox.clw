; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CListBoxDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ListBox.h"

ClassCount=3
Class1=CListBoxApp
Class2=CListBoxDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_LISTBOX_DIALOG

[CLS:CListBoxApp]
Type=0
HeaderFile=ListBox.h
ImplementationFile=ListBox.cpp
Filter=N

[CLS:CListBoxDlg]
Type=0
HeaderFile=ListBoxDlg.h
ImplementationFile=ListBoxDlg.cpp
Filter=D
LastObject=IDC_LISTBOX
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ListBoxDlg.h
ImplementationFile=ListBoxDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LISTBOX_DIALOG]
Type=1
Class=CListBoxDlg
ControlCount=6
Control1=IDC_LISTBOX,listbox,1352728835
Control2=IDC_EDIT_INPUT,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTT_ADD,button,1342242816
Control5=IDC_BUTT_DELETE,button,1342242816
Control6=IDC_BUTT_EXIT,button,1342242816

