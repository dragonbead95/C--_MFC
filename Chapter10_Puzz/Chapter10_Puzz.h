
// Chapter10_Puzz.h: PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.


// CChapter10PuzzApp:
// 이 클래스의 구현에 대해서는 Chapter10_Puzz.cpp을(를) 참조하세요.
//

class CChapter10PuzzApp : public CWinApp
{
public:
	CChapter10PuzzApp();

// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.

	DECLARE_MESSAGE_MAP()
};

extern CChapter10PuzzApp theApp;
