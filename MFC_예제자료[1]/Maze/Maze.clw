; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMazeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Maze.h"

ClassCount=3
Class1=CMazeApp
Class2=CMazeDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_MAZE_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_MENU1

[CLS:CMazeApp]
Type=0
HeaderFile=Maze.h
ImplementationFile=Maze.cpp
Filter=N

[CLS:CMazeDlg]
Type=0
HeaderFile=MazeDlg.h
ImplementationFile=MazeDlg.cpp
Filter=D
LastObject=FILE_EXIT
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MazeDlg.h
ImplementationFile=MazeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MAZE_DIALOG]
Type=1
Class=CMazeDlg
ControlCount=10
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC_LEFT,static,1342308352
Control3=IDC_STATIC_UP,static,1342308352
Control4=IDC_STATIC_RIGHT,static,1342308352
Control5=IDC_STATIC_DOWN,static,1342308352
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC_FRAG,static,1342308352
Control8=IDC_BUTT_START,button,1342242816
Control9=IDC_BUTT_RESTART,button,1342242816
Control10=IDC_BUTT_EXIT,button,1342242816

[MNU:IDR_MENU1]
Type=1
Class=CMazeDlg
Command1=FILE_LOAD
Command2=FILE_EXIT
CommandCount=2

