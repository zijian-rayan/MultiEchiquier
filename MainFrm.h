
// MainFrm.h : interface de la classe CMainFrame
//

#pragma once

class CMainFrame : public CMDIFrameWndEx
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attributs
public:

// Opérations
public:

// Substitutions
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implémentation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // membres incorporés de la barre de contrôle
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;

// Fonctions générées de la table des messages
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnWindowManager();
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()

};


