
// ChildView.h : interface de la classe CChildView
//


#pragma once

class CEquichier
{
protected:
BYTE cas[32][32];
CPoint mpoint;
public:
  WORD cx,cy,nx,ny;
  bool show;
  CFont cfont;

  COLORREF c1,c2,ct;
  CEquichier(WORD _nx=8, WORD _ny=8,WORD _cx=32, WORD _cy=32,COLORREF _c1=0x0000FF,COLORREF _c2=0x303030,COLORREF _ct=0xFFFFFF):nx(_nx),ny(_ny),cx(_cx),cy(_cy),c1(_c1),c2(_c2),ct(_ct),show(true)
  {
	  cfont.CreatePointFont(120,_T("Arial"));
	  for(WORD y=0; y<32; y++)
			  for(WORD x=0; x<32; x++)
				  cas[x][y]=0;
  }
  void Show(CDC &dc)
  {
    if(!show)
      return;
    //COPY
    CString str;
    dc.SetTextColor(ct);
    dc.SetBkMode(TRANSPARENT);
    CFont* pold_f=dc.SelectObject(&cfont);
      for(WORD y=0;y<ny;y++)
      {
          for(WORD x=0;x<nx;x++)
          {
              CRect r(x*cx,y*cy,(x+1)*cx,(y+1)*cy);
              dc.FillSolidRect(r,((x+y)&1? c1:c2));
              str.Format(_T("%c%hu"),_T('A')+x,y+1);
              dc.DrawText(str,r,DT_CENTER | DT_VCENTER | DT_SINGLELINE);
          }
      }
	  dc.SelectObject(pold_f);
  }
};

// fenêtre CChildView

class CChildView : public CWnd,public CEquichier
{
// Construction
public:
	CChildView();

// Attributs
public:
  static COLORREF tclr[3][2];
  static int zoom;
// Opérations
public:
  //Show(dc);
  /*void Table(CDC &dc, WORD nx,WORD ny)
  {
    WORD cx=32,cy=32;
    COLORREF c1=0x0000FF,c2=0x000000,ct=0xFFFFFF;
    CString str;
    dc.SetTextColor(ct);
      for(WORD y=0;y<ny;y++)
      {
          for(WORD x=0;x<nx;x++)
          {
              CRect r(x*cx,y*cy,(x+1)*cx,(y+1)*cy);
              dc.FillSolidRect(r,((x+y)&1? c1:c2));
              str.Format(_T("%c%hu"),_T('A')+x,y+1);
              dc.DrawText(str,r,DT_CENTER | DT_VCENTER | DT_SINGLELINE);
          }
      }
  }*/
// Substitutions
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implémentation
public:
	virtual ~CChildView();


	// Fonctions générées de la table des messages
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnPaire1();
  afx_msg void OnUpdatePaire1(CCmdUI *pCmdUI);
  afx_msg void OnPaire2();
  afx_msg void OnUpdatePaire2(CCmdUI *pCmdUI);
  afx_msg void OnPaire3();
  afx_msg void OnUpdatePaire3(CCmdUI *pCmdUI);
  afx_msg void OnTaille10x10();
  afx_msg void OnUpdateTaille10x10(CCmdUI *pCmdUI);
  afx_msg void OnTaille12x12();
  afx_msg void OnUpdateTaille12x12(CCmdUI *pCmdUI);
  afx_msg void OnTaille4x4();
  afx_msg void OnUpdateTaille4x4(CCmdUI *pCmdUI);
  afx_msg void OnTaille6x6();
  afx_msg void OnUpdateTaille6x6(CCmdUI *pCmdUI);
  afx_msg void OnTaille8x8();
  afx_msg void OnUpdateTaille8x8(CCmdUI *pCmdUI);
  afx_msg void OnVisible();
  afx_msg void OnUpdateVisible(CCmdUI *pCmdUI);
  afx_msg void OnAffichageZoomin();
  afx_msg void OnUpdateAffichageZoomin(CCmdUI *pCmdUI);
  afx_msg void OnAffichageZoomout();
  afx_msg void OnUpdateAffichageZoomout(CCmdUI *pCmdUI);
  afx_msg void OnCouleurCasespaires();
  afx_msg void OnCouleurCasesimpaires();
  afx_msg void OnFichier();
  afx_msg void OnFichierSaveimg();
  afx_msg void OnParams();
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnNoire();
  afx_msg void OnBlanche();
};

