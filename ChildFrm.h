
// ChildFrm.h : interface de la classe CChildFrame
//

#pragma once
#include "ChildView.h"

class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// Attributs
public:

// Opérations
public:

// Substitutions
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// Implémentation
public:
	// afficher la zone cliente du frame.
	CChildView m_wndView;
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Fonctions générées de la table des messages
protected:
	afx_msg void OnFileClose();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};
