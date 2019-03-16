; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDiskInfoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DiskInfo.h"

ClassCount=3
Class1=CDiskInfoApp
Class2=CDiskInfoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DISKINFO_DIALOG

[CLS:CDiskInfoApp]
Type=0
HeaderFile=DiskInfo.h
ImplementationFile=DiskInfo.cpp
Filter=N

[CLS:CDiskInfoDlg]
Type=0
HeaderFile=DiskInfoDlg.h
ImplementationFile=DiskInfoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COMBO_DRIVER

[CLS:CAboutDlg]
Type=0
HeaderFile=DiskInfoDlg.h
ImplementationFile=DiskInfoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DISKINFO_DIALOG]
Type=1
Class=CDiskInfoDlg
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_COMBO_DRIVER,combobox,1344340226
Control4=IDC_STATIC_SELDRV,static,1342308352
Control5=IDC_STATIC_TYPE,static,1342308352
Control6=IDC_STATIC_LABEL,static,1342308352
Control7=IDC_STATIC_FAT,static,1342308352
Control8=IDC_STATIC_ALLDISK,static,1342308352
Control9=IDC_STATIC_USEDISK,static,1342308352
Control10=IDC_STATIC_FREEDISK,static,1342308352
Control11=IDC_BUTT_EXIT,button,1342242816

