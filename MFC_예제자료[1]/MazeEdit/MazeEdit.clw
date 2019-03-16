; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMazeEditDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MazeEdit.h"

ClassCount=3
Class1=CMazeEditApp
Class2=CMazeEditDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MAZEEDIT_DIALOG
Resource4=IDR_MENU1

[CLS:CMazeEditApp]
Type=0
HeaderFile=MazeEdit.h
ImplementationFile=MazeEdit.cpp
Filter=N

[CLS:CMazeEditDlg]
Type=0
HeaderFile=MazeEditDlg.h
ImplementationFile=MazeEditDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMazeEditDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=MazeEditDlg.h
ImplementationFile=MazeEditDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MAZEEDIT_DIALOG]
Type=1
Class=CMazeEditDlg
ControlCount=8
Control1=IDC_STATIC_MUS,static,1342308352
Control2=IDC_STATIC_BLOCK,static,1342308352
Control3=IDC_BUTT_REDRAW,button,1342242816
Control4=IDC_BUTT_START,button,1342242816
Control5=IDC_BUTT_END,button,1342242816
Control6=IDC_BUTT_BLOCK,button,1342242816
Control7=IDC_BUTT_ROAD,button,1342242816
Control8=IDC_BUTT_EXIT,button,1342242816

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=FILE_LOAD
Command2=FILE_SAVE
Command3=FILE_EXIT
CommandCount=3

