
// MultiEchiquier.cpp : Définit les comportements de classe pour l'application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "MultiEchiquier.h"
#include "MainFrm.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMultiEchiquierApp

BEGIN_MESSAGE_MAP(CMultiEchiquierApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CMultiEchiquierApp::OnAppAbout)
	ON_COMMAND(ID_FILE_NEW, &CMultiEchiquierApp::OnFileNew)
END_MESSAGE_MAP()


// construction CMultiEchiquierApp

CMultiEchiquierApp::CMultiEchiquierApp()
{

	m_bHiColorIcons = TRUE;

	// TODO? ajoutez ici du code de construction,
	// Placez toutes les initialisations significatives dans InitInstance
}

// Seul et unique objet CMultiEchiquierApp

CMultiEchiquierApp theApp;


// initialisation de CMultiEchiquierApp

BOOL CMultiEchiquierApp::InitInstance()
{
	// InitCommonControlsEx() est requis sur Windows XP si le manifeste de l'application
	// spécifie l'utilisation de ComCtl32.dll version? ou ultérieure pour activer les
	// styles visuels.  Dans le cas contraire, la création de fenêtres échouera.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ?définir pour inclure toutes les classes de contrôles communs ?utiliser
	// dans votre application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// Initialiser les bibliothèques OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// Initialisation standard
	// Si vous n'utilisez pas ces fonctionnalités et que vous souhaitez réduire la taille
	// de votre exécutable final, vous devez supprimer ci-dessous
	// les routines d'initialisation spécifiques dont vous n'avez pas besoin.
	// Changez la cl?de Registre sous laquelle nos paramètres sont enregistrés
	// TODO : modifiez cette chaîne avec des informations appropriées,
	// telles que le nom de votre sociét?ou organisation
	SetRegistryKey(_T("Applications locales générées par AppWizard"));

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Pour créer la fenêtre principale, ce code crée un nouvel objet fenêtre frame
	// qu'il définit ensuite en tant qu'objet fenêtre principale de l'application
	CMDIFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;

	// crée la fenêtre frame MDI principale
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	// Essaie de charger les menus MDI partagés et la table d'accélérateurs
	//TODO : ajoutez des variables membres supplémentaires et chargez des appels pour
	//	d'autres types de menus requis par votre application
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_MultiEchiquierTYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_MultiEchiquierTYPE));





	// La fenêtre principale a ét?initialisée et peut donc être affichée et mise ?jour
	pFrame->ShowWindow(m_nCmdShow);
	pFrame->UpdateWindow();

	return TRUE;
}


// gestionnaires de messages pour CMultiEchiquierApp

int CMultiEchiquierApp::ExitInstance() 
{
	//TODO : gérez les ressources supplémentaires que vous avez ajoutées
	if (m_hMDIMenu != NULL)
		FreeResource(m_hMDIMenu);
	if (m_hMDIAccel != NULL)
		FreeResource(m_hMDIAccel);

	return CWinAppEx::ExitInstance();
}

void CMultiEchiquierApp::OnFileNew() 
{
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, m_pMainWnd);
	// crée une nouvelle fenêtre enfant MDI
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_MultiEchiquierTYPE, m_hMDIMenu, m_hMDIAccel);
}


// boîte de dialogue CAboutDlg utilisée pour la boîte de dialogue '?propos de' pour votre application

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Données de boîte de dialogue
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Implémentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// Commande App pour exécuter la boîte de dialogue
void CMultiEchiquierApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMultiEchiquierApp, méthodes de chargement/d'enregistrement de la personnalisation

void CMultiEchiquierApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CMultiEchiquierApp::LoadCustomState()
{
}

void CMultiEchiquierApp::SaveCustomState()
{
}

// gestionnaires de messages pour CMultiEchiquierApp



