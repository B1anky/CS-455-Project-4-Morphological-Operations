// kingimageView.h : interface of the CKingimageView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KINGIMAGEVIEW_H__358E35BF_08DB_11D3_AA68_00E0CCDDAE2D__INCLUDED_)
#define AFX_KINGIMAGEVIEW_H__358E35BF_08DB_11D3_AA68_00E0CCDDAE2D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <vector>
#include <iostream>
#include <conio.h>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <array>
#include <cmath>
#include <math.h>
#include <random>

class CKingimageView : public CScrollView
{
protected: // create from serialization only
	CKingimageView();
	DECLARE_DYNCREATE(CKingimageView)

// Attributes
public:
	CKingimageDoc* GetDocument();

//	void Processing();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKingimageView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKingimageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKingimageView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//afx_msg void OnNegative();
	afx_msg
	void OnNegative();
	void OnEqualize();
	void OnThreshold();
	void OnUnsharpMask();
	void OnSobel();
	void OnLog7();
	void OnLog11();
	void eightPointDCT();
	void sixteenPointDCT();
	std::vector<float> DCTHelper1(int point, int pImg[]);
	void DCTHelper2(int point, BYTE * pImg, int iHeight, int iWidth, bool lowewstNine, bool DC);
	void IDCTHelper(int point, BYTE * pImg, int iHeight, int iWidth);
	void DCT();
	void applyHSIToImage(std::vector<std::tuple<float, float, float>> hsi, int iHeight, int iWidth, BYTE * pImg);
	void HSIToRGBHelper(BYTE * pImg, int iHeight, int iWidth);
	void RGBtoHSI();
	void HSItoRGB();
	std::vector<std::tuple<float, float, float>> RGBtoHSIHelper(BYTE * pImg, int iHeight, int iWidth);
	void freqDomain1();
	void freqDomain2();
	void IDCT();
	void HoughTransform();
	std::vector<int> floodFillUtil(BYTE * screen, int i, int j, int prevC, int newC, int M, int N);
	std::vector<float> idctInfo;

	void OnBinarize();
	void binarize();
	void OnErode();
	void erode();
	void OnDilate();
	void dilate();
	int count();
	std::vector<int> floodFillUtil24Bit(BYTE * pImg, int i, int j, int prevC, int newC, int M, int N);
	void onDoAll();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in kingimageView.cpp
inline CKingimageDoc* CKingimageView::GetDocument()
   { return (CKingimageDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KINGIMAGEVIEW_H__358E35BF_08DB_11D3_AA68_00E0CCDDAE2D__INCLUDED_)

float applyFilter8Bit(float mask[][7], BYTE * orig, int row, int col, int wid, float weight, int offset);

float applyFilter8Bit(double mask[][11], BYTE * orig, int row, int col, int wid, float weight, int offset);

float applyFilter8Bit(double mask[][7], BYTE * orig, int row, int col, int wid, float weight, int offset);

float applyFilter8Bit(float mask[][5], BYTE * orig, int row, int col, int wid, float weight, int offset);

float applyFilter24Bit(float mask[][3], BYTE * orig, int row, int col, int wid, float weight, int offset);

double alpha(int i, int n);

