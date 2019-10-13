
// ChildFrm.cpp : implémentation de la classe CChildFrame
//

#include "stdafx.h"
#include "MultiEchiquier.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
	ON_COMMAND(ID_FILE_CLOSE, &CChildFrame::OnFileClose)
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// construction ou destruction de CChildFrame

CChildFrame::CChildFrame()
{
	// TODO : ajoutez ici le code d'une initialisation de membre
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO : changez ici la classe ou les styles de fenêtre en modifiant CREATESTRUCT cs
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// diagnostics pour CChildFrame

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// gestionnaires de messages pour CChildFrame
void CChildFrame::OnFileClose() 
{
	// Pour fermer le frame, envoyer un WM_CLOSE, ce qui équivaut à
	// choisir la commande Fermer dans le menu Système.
	SendMessage(WM_CLOSE);
}

int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMDIChildWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// créer une vue de manière qu'elle occupe la zone cliente du frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, 
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Impossible de créer la fenêtre d'affichage\n");
		return -1;
	}

	return 0;
}

void CChildFrame::OnSetFocus(CWnd* pOldWnd) 
{
	CMDIChildWndEx::OnSetFocus(pOldWnd);

	m_wndView.SetFocus();
}

BOOL CChildFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// laisser la priorité à la vue pour cette commande
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;
	
	// sinon, la gestion par défaut est utilisée
	return CMDIChildWndEx::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
