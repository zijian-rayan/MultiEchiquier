
// MultiEchiquier.cpp : D�finit les comportements de classe pour l'application.
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
	// InitCommonControlsEx() est requis sur Windows�XP si le manifeste de l'application
	// sp�cifie l'utilisation de ComCtl32.dll version? ou ult�rieure pour activer les
	// styles visuels.  Dans le cas contraire, la cr�ation de fen�tres �chouera.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ?d�finir pour inclure toutes les classes de contr�les communs ?utiliser
	// dans votre application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// Initialiser les biblioth�ques OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// Initialisation standard
	// Si vous n'utilisez pas ces fonctionnalit�s et que vous souhaitez r�duire la taille
	// de votre ex�cutable final, vous devez supprimer ci-dessous
	// les routines d'initialisation sp�cifiques dont vous n'avez pas besoin.
	// Changez la cl?de Registre sous laquelle nos param�tres sont enregistr�s
	// TODO : modifiez cette cha�ne avec des informations appropri�es,
	// telles que le nom de votre soci�t?ou organisation
	SetRegistryKey(_T("Applications locales g�n�r�es par AppWizard"));

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Pour cr�er la fen�tre principale, ce code cr�e un nouvel objet fen�tre frame
	// qu'il d�finit ensuite en tant qu'objet fen�tre principale de l'application
	CMDIFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;

	// cr�e la fen�tre frame MDI principale
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	// Essaie de charger les menus MDI partag�s et la table d'acc�l�rateurs
	//TODO : ajoutez des variables membres suppl�mentaires et chargez des appels pour
	//	d'autres types de menus requis par votre application
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_MultiEchiquierTYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_MultiEchiquierTYPE));





	// La fen�tre principale a �t?initialis�e et peut donc �tre affich�e et mise ?jour
	pFrame->ShowWindow(m_nCmdShow);
	pFrame->UpdateWindow();

	return TRUE;
}


// gestionnaires de messages pour CMultiEchiquierApp

int CMultiEchiquierApp::ExitInstance() 
{
	//TODO : g�rez les ressources suppl�mentaires que vous avez ajout�es
	if (m_hMDIMenu != NULL)
		FreeResource(m_hMDIMenu);
	if (m_hMDIAccel != NULL)
		FreeResource(m_hMDIAccel);

	return CWinAppEx::ExitInstance();
}

void CMultiEchiquierApp::OnFileNew() 
{
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, m_pMainWnd);
	// cr�e une nouvelle fen�tre enfant MDI
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_MultiEchiquierTYPE, m_hMDIMenu, m_hMDIAccel);
}


// bo�te de dialogue CAboutDlg utilis�e pour la bo�te de dialogue '?propos de' pour votre application

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Donn�es de bo�te de dialogue
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Impl�mentation
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

// Commande App pour ex�cuter la bo�te de dialogue
void CMultiEchiquierApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMultiEchiquierApp, m�thodes de chargement/d'enregistrement de la personnalisation

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



