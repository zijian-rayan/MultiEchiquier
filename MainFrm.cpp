
// MainFrm.cpp : implémentation de la classe CMainFrame
//

#include "stdafx.h"
#include "MultiEchiquier.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_WINDOW_MANAGER, &CMainFrame::OnWindowManager)
	ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
	ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // indicateur de la ligne d'état
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// construction ou destruction de CMainFrame

CMainFrame::CMainFrame()
{
	// TODO : ajoutez ici le code d'une initialisation de membre
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;

	CMDITabInfo mdiTabParams;
	mdiTabParams.m_style = CMFCTabCtrl::STYLE_3D_ONENOTE; // autres styles disponibles...
	mdiTabParams.m_bActiveTabCloseButton = TRUE;      // définir ?FALSE pour placer le bouton de fermeture ?droite de la zone d'onglet
	mdiTabParams.m_bTabIcons = FALSE;    // définir ?TRUE pour activer les icônes de document sous les onglets MDI
	mdiTabParams.m_bAutoColor = TRUE;    // définir ?FALSE pour désactiver la coloration automatique des onglets MDI
	mdiTabParams.m_bDocumentMenu = TRUE; // activer le menu de document ?l'extrémit?droite de la zone d'onglet
	EnableMDITabbedGroups(TRUE, mdiTabParams);

	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("Impossible de créer la barre de menus\n");
		return -1;      // échec de la création
	}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

	// empêche la barre de menus de prendre le focus lors de l'activation
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(theApp.m_bHiColorIcons ? IDR_MAINFRAME_256 : IDR_MAINFRAME))
	{
		TRACE0("Impossible de créer toolbar\n");
		return -1;      // échec de la création
	}

	CString strToolBarName;
	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_STANDARD);
	ASSERT(bNameValid);
	m_wndToolBar.SetWindowText(strToolBarName);
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);
	m_wndToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
//m_wndToolBar.LoadToolBar(IDR_MAINFRAME1);

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);
	//if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
	//	!m_wndToolBar.LoadToolBar(IDR_MAINFRAME1))
	//{
	//	TRACE0("Impossible de créer toolbar\n");
	//	return -1;      // échec de la création
	//}
	//
	//m_wndToolBar.SetWindowText(strToolBarName);
	//bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	//ASSERT(bNameValid);
	//m_wndToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	//this->RecalcLayout();  




	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Impossible de créer la barre d'état\n");
		return -1;      // échec de la création
	}

	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO : supprimez ces cinq lignes si vous ne souhaitez pas que la barre d'outils et la barre de menus soient ancrables
	m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndMenuBar);
	DockPane(&m_wndToolBar);


	// activer le comportement de la fenêtre d'ancrage de style Visual Studio?005
	CDockingManager::SetDockingMode(DT_SMART);
	// activer le comportement de masquage automatique de la fenêtre d'ancrage de style Visual Studio?005
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// Activer la boîte de dialogue de gestion de fenêtres avancée
	EnableWindowsDialog(ID_WINDOW_MANAGER, IDS_WINDOWS_MANAGER, TRUE);

	// Activer le remplacement du menu de la fenêtre d'ancrage et de la barre d'outils
	EnablePaneMenu(TRUE, ID_VIEW_CUSTOMIZE, strCustomize, ID_VIEW_TOOLBAR);

	// activer la personnalisation de barre d'outils rapide (Alt+faire glisser)
	CMFCToolBar::EnableQuickCustomization();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO : changez ici la classe ou les styles de fenêtre en modifiant
	//  CREATESTRUCT cs

	return TRUE;
}

// diagnostics pour CMainFrame

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// gestionnaires de messages pour CMainFrame

void CMainFrame::OnWindowManager()
{
	ShowWindowsDialog();
}

void CMainFrame::OnViewCustomize()
{
	CMFCToolBarsCustomizeDialog* pDlgCust = new CMFCToolBarsCustomizeDialog(this, TRUE /* analyser les menus */);
	pDlgCust->Create();
}

LRESULT CMainFrame::OnToolbarCreateNew(WPARAM wp,LPARAM lp)
{
	LRESULT lres = CMDIFrameWndEx::OnToolbarCreateNew(wp,lp);
	if (lres == 0)
	{
		return 0;
	}

	CMFCToolBar* pUserToolbar = (CMFCToolBar*)lres;
	ASSERT_VALID(pUserToolbar);

	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	return lres;
}
