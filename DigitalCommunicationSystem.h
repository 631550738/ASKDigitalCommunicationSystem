// DigitalCommunicationSystem.h : main header file for the DIGITALCOMMUNICATIONSYSTEM application
//

#if !defined(AFX_DIGITALCOMMUNICATIONSYSTEM_H__04E9FE98_3908_47E3_ACB6_367A3A7DFB54__INCLUDED_)
#define AFX_DIGITALCOMMUNICATIONSYSTEM_H__04E9FE98_3908_47E3_ACB6_367A3A7DFB54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDigitalCommunicationSystemApp:
// See DigitalCommunicationSystem.cpp for the implementation of this class
//

class CDigitalCommunicationSystemApp : public CWinApp
{
public:
	CDigitalCommunicationSystemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDigitalCommunicationSystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDigitalCommunicationSystemApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIGITALCOMMUNICATIONSYSTEM_H__04E9FE98_3908_47E3_ACB6_367A3A7DFB54__INCLUDED_)
