
// MultiEchiquier.h : fichier d'en-tête principal pour l'application MultiEchiquier
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"       // symboles principaux


// CMultiEchiquierApp:
// Consultez MultiEchiquier.cpp pour l'implémentation de cette classe
//

class CMultiEchiquierApp : public CWinAppEx
{
public:
	CMultiEchiquierApp();


// Substitutions
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implémentation
protected:
	HMENU  m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
};

extern CMultiEchiquierApp theApp;
