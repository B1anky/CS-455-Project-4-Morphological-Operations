// kingimageView.cpp : implementation of the CKingimageView class
//

#include "stdafx.h"
#include "kingimage.h"

#include "kingimageDoc.h"
#include "kingimageView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKingimageView

IMPLEMENT_DYNCREATE(CKingimageView, CScrollView)

BEGIN_MESSAGE_MAP(CKingimageView, CScrollView)
	//{{AFX_MSG_MAP(CKingimageView)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_NEGATE, OnNegative)
	ON_COMMAND(ID_EQUALIZE, OnEqualize)
	ON_COMMAND(ID_THRESHOLD, OnThreshold)
	ON_COMMAND(ID_MASK_UNSHARPMASK, OnUnsharpMask)
	ON_COMMAND(ID_MASK_SOBEL, OnSobel)
	ON_COMMAND(ID_MASK_LOG7, OnLog7)
	ON_COMMAND(ID_MASK_LOG11, OnLog11)
	ON_COMMAND(ID_COMPRESSION_8, eightPointDCT)
	ON_COMMAND(ID_COMPRESSION_16, sixteenPointDCT)
	ON_COMMAND(ID_COMPRESSION_HSI, RGBtoHSI)
	ON_COMMAND(ID_COMPRESSION_HSITORGB, HSItoRGB)
	ON_COMMAND(ID_COMPRESSION_FREQUENCYDOMAIN1, freqDomain1)
	ON_COMMAND(ID_COMPRESSION_FREQUENCYDOMAIN2, freqDomain2)
	ON_COMMAND(ID_COMPRESSION_IDCT, IDCT)
	ON_COMMAND(ID_COMPRESSION_DCT, DCT)
	ON_COMMAND(ID_HOUGHTRANSFORM, HoughTransform)
	ON_COMMAND(ID_MORPHOLOGICAL_BINARIZE, OnBinarize)
	ON_COMMAND(ID_MORPHOLOGICAL_ERODE, OnErode)
	ON_COMMAND(ID_MORPHOLOGICAL_DILATE, OnDilate)
	ON_COMMAND(ID_MORPHOLOGICAL_DOALL, onDoAll)
	//}}AFX_MSG_MAP 
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKingimageView construction/destruction

CKingimageView::CKingimageView()
{
	// TODO: add construction code here
	AllocConsole();
}

CKingimageView::~CKingimageView()
{
	~AllocConsole();
}

BOOL CKingimageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CKingimageView drawing

void CKingimageView::OnDraw(CDC* pDC)
{
	CKingimageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
//	pDC->SetStretchBltMode(COLORONCOLOR);
//	int x,y,bytes;
	if (pDoc->imagetype==PCX)
		(pDoc->_pcx)->draw(pDC);
	if (pDoc->imagetype==BMP)
		(pDoc->_bmp)->draw(pDC);
	if (pDoc->imagetype==GIF)
		(pDoc->_gif)->draw(pDC);
	if (pDoc->imagetype==JPG)
		(pDoc->_jpg)->draw(pDC);
/*	if (pDoc->imagetype==BMP)
	{
	
	x=((KINGBMP*)(pDoc->_ppicture))->bmpinfo.bmiHeader.biWidth;
	y=((KINGBMP*)(pDoc->_ppicture))->bmpinfo.bmiHeader.biHeight;
	bytes=(pDoc->_ppicture)->needbyte;
	int place=0;
	for (int j=0;j<y;j++)
		for (int i=0;i<x;i++){
//			int color= (pDoc->_bmp)->point[place++] ;
			pDC->SetPixel(i,j,RGB( (pDoc->_picture)->pixel[place+2], (pDoc->_picture)->pixel[place+1] ,(pDoc->_picture)->pixel[place]));
			place+=3;
		}

  /*	if ( (pDoc->_bmp)->bitsperpixel!=24 ){
		CPalette *palette=new CPalette();
		LOGPALETTE palet;
		palet.palVersion=0x300;
		palet.palNumEntries=(pDoc->_bmp)->usedcolor;
		for (int i=0;i<palet.palNumEntries;i++){
			palet.palPalEntry[i].peRed=( (pDoc->_bmp) -> bmpinfo) .bmiColors[i].rgbRed;
			palet.palPalEntry[i].peBlue=( (pDoc->_bmp) -> bmpinfo) .bmiColors[i].rgbBlue;
			palet.palPalEntry[i].peGreen=( (pDoc->_bmp) -> bmpinfo) .bmiColors[i].rgbGreen;
			palet.palPalEntry[i].peFlags=0;//( (pDoc->_bmp) -> bmpinfo) .bmiColors[0].rgbRed;
		}
		BOOL re=palette->CreatePalette(&palet);
		CPalette *pp;
		pp=pDC->SelectPalette(palette,TRUE);
	}
*/
//	::SetDIBitsToDevice(pDC->m_hDC,0,0,x,y,0,0,0,y,(pDoc->_ppicture)->point,&(((KINGBMP*)(pDoc->_ppicture))->bmpinfo),DIB_RGB_COLORS);
	
//	}
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CKingimageView printing

BOOL CKingimageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKingimageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKingimageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CKingimageView diagnostics

#ifdef _DEBUG
void CKingimageView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CKingimageView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CKingimageDoc* CKingimageView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKingimageDoc)));
	return (CKingimageDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKingimageView message handlers



void CKingimageView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CSize totalSize=CSize(::GetSystemMetrics(SM_CXSCREEN),
		                  ::GetSystemMetrics(SM_CYSCREEN));
	CSize pageSize=CSize(totalSize.cx/2,totalSize.cy/2);
	CSize lineSize=CSize(totalSize.cx/10,totalSize.cy/10);

	SetScrollSizes(MM_TEXT,totalSize,pageSize,lineSize);
}

void CKingimageView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CScrollView::OnMouseMove(nFlags, point);
}


//******************************************************
//  Image Processing Sample Program for CS555
//  Image origin: lower-left point
//  Image info:
//		int width;
//		int height;
//		int bitsperpixel;
//		int needbyte;
//		int usedcolor;
//		int usedbyte;
//		BYTE *pixel;	//maybe serval point in one BYTE
//		BYTE *point;
//
//  
//******************************************************

void CKingimageView::OnNegative() {
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	std::vector<int> histogram(256, 0);
	std::vector<int> histogramNegated(256, 0);
	int Wp = iWidth;

	//Read in pixel values
	for (int i = 0; i < iHeight; i++)
	{
		for (int j = 0; j < iWidth; j++)
		{
			if (iBitPerPixel == 8)
			{
				histogram[(int)pImg[i * Wp + j]]++;
			}
			else if (iBitPerPixel == 24)
			{
				int curVal = pImg[i * Wp * 3 + j * 3] + pImg[i * Wp * 3 + j * 3 + 1] + pImg[i * Wp * 3 + j * 3 + 2];
				histogram[curVal / 3]++;
			}
		}
	}

	//Negate image's pixels
	for (int i = 0; i < iHeight; i++)
	{
		for (int j = 0; j < iWidth; j++)
		{
			if (iBitPerPixel == 8)
			{
				pImg[i*Wp + j] = 255 - pImg[i*Wp + j];
			}
			else if (iBitPerPixel == 24)
			{
				pImg[i * Wp * 3 + j * 3] = 255 - pImg[i * Wp * 3 + j * 3];
				pImg[i * Wp * 3 + j * 3 + 1] = 255 - pImg[i * Wp * 3 + j * 3 + 1];
				pImg[i * Wp * 3 + j * 3 + 2] = 255 - pImg[i * Wp * 3 + j * 3 + 2];
			}
		}
	}

	//Read in pixel values
	for (int i = 0; i < iHeight; i++)
	{
		for (int j = 0; j < iWidth; j++)
		{
			if (iBitPerPixel == 8)
			{
				histogramNegated[(int)pImg[i * Wp + j]]++;
			}
			else if (iBitPerPixel == 24)
			{
				int curVal = pImg[i * Wp * 3 + j * 3] + pImg[i * Wp * 3 + j * 3 + 1] + pImg[i * Wp * 3 + j * 3 + 2];
				histogramNegated[curVal / 3]++;
			}
		}
	}

	//redraw the screen
	OnDraw(GetDC());
	_cprintf("Done Negating\n");
}


void CKingimageView::OnEqualize()
{
	// TODO: Add your command handler code here
	CKingimageDoc* pDoc = GetDocument();
	
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	std::vector<int> histogram(256, 0);
	std::vector<int> histogramNormalized(256, 0);
	std::vector<int> mappedBinVals(256, 0);
	int Wp = iWidth;
	int totalPix = iWidth * iHeight;
	
	//Read in pixel values
	for (int i = 0; i < iHeight; i++) 
	{
		for (int j = 0; j < iWidth; j++) 
		{
			if (iBitPerPixel == 8) 
			{
				histogram[(int)pImg[i * Wp + j]]++;
			}
			else if (iBitPerPixel == 24)
			{
				int curVal = pImg[i * Wp * 3 + j * 3] + pImg[i * Wp * 3 + j * 3 + 1] + pImg[i * Wp * 3 + j * 3 + 2];
				histogram[curVal / 3]++;
			}
		}
	}

	//Equalize pixel values based on histogram
	float curBin = 0; //will go up to 255 bins
	for (unsigned int cnt = 0; cnt < 256; cnt++) 
	{
		curBin += (float)histogram[cnt] / (float)totalPix;
		histogramNormalized[(int)(255 * curBin)] += histogram[cnt];
		mappedBinVals[cnt] = (int)(255 * curBin);
	}


	//Equalize pixels for 8 - bit or 24 bit
	for (int i = 0; i < iHeight; i++) 
	{
		for (int j = 0; j < iWidth; j++) 
		{
			if (iBitPerPixel == 8) 
			{
				pImg[i*Wp + j] = mappedBinVals[pImg[i*Wp + j]];
			}
			else if (iBitPerPixel == 24) 
			{
				pImg[i * Wp * 3 + j * 3] = mappedBinVals[pImg[i*Wp*3 + j*3]];
				pImg[i * Wp * 3 + j * 3 + 1] = mappedBinVals[pImg[i*Wp*3 + j*3 + 1]];
				pImg[i * Wp * 3 + j * 3 + 2] = mappedBinVals[pImg[i*Wp*3 + j*3 + 2]];
			}
		}
	}
	
	//redraw the screen
	OnDraw(GetDC());
	_cprintf("Done Equalizing\n");
}

void CKingimageView::OnThreshold() {
	// TODO: Add your command handler code here
	CKingimageDoc* pDoc = GetDocument();

	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	std::vector<int> histogram(256, 0);
	std::vector<int> histogramNormalized(256, 0);
	int Wp = iWidth;
	int totalPix = iWidth * iHeight;
	int threshold = 256 / 2;

	//Read in pixel values
	for (int i = 0; i < iHeight; i++)
	{
		for (int j = 0; j < iWidth; j++)
		{
			if (iBitPerPixel == 8)
			{
				histogram[(int)pImg[i * Wp + j]]++;
			}
			else if (iBitPerPixel == 24)
			{
				int curVal = pImg[i * Wp * 3 + j * 3] + pImg[i * Wp * 3 + j * 3 + 1] + pImg[i * Wp * 3 + j * 3 + 2];
				histogram[curVal / 3]++;
			}
		}
	}
	/* This method is the one in class, but fails for these images
	//Determine best threshold to make image binary
	int prevThreshold = 0;
	int passes = 0;
	while (prevThreshold != threshold) {
		int avgPixAbove = 0;
		int avgPixBelow = 0;
		int avgAbove = 0;
		int avgBelow = 0;
		for (int i = 0; i < iHeight; i++) {
			for (int j = 0; j < iWidth; j++) {
				if ((int)pImg[i * Wp + j] < threshold) {
					avgBelow += (int)pImg[i * Wp + j];
					avgPixBelow++;
				}
				else {
					avgAbove += (int)pImg[i * Wp + j];
					avgPixAbove++;
				}
			}
		}
		avgAbove /= avgPixAbove;
		avgBelow /= avgPixBelow;
		prevThreshold = threshold;
		threshold = (avgAbove + avgBelow) / 2;
		passes++;
	}
	*/

	//One pass threshold calculation
	int totalIntensity = 0;
	int cnt = 0;
	for (auto pix : histogram) {
		totalIntensity += cnt * pix;
		cnt++;
	}

	threshold = totalIntensity / totalPix;
	_cprintf("Threshold: %d\n", threshold);

	//Binarize image based on threshold
	for (int i = 0; i < iHeight; i++)
	{
		for (int j = 0; j < iWidth; j++)
		{
			if (iBitPerPixel == 8)
			{
				if (pImg[i*Wp + j] >= threshold) {
					pImg[i*Wp + j] = 255;
				}
				else {
					pImg[i*Wp + j] = 0;
				}
					
			}
			else if (iBitPerPixel == 24)
			{
				if (pImg[i*Wp + j] >= threshold) {
					pImg[i * Wp * 3 + j * 3] = 255;
					pImg[i * Wp * 3 + j * 3 + 1] = 255;
					pImg[i * Wp * 3 + j * 3 + 2] = 255;
				}
				else {
					pImg[i * Wp * 3 + j * 3] = 0;
					pImg[i * Wp * 3 + j * 3 + 1] = 0;
					pImg[i * Wp * 3 + j * 3 + 2] = 0;
				}	
			}
		}
	}

	//Look for connected components
	//Implements flood fill 
	int objectCnt = 0;
	std::vector<int> intensities{50, 65, 80, 95, 110, 125, 140, 155, 170, 185, 200, 215, 230, 245};
	std::vector<std::vector<int>> shapes;
	for (int i = 0; i < iHeight; i++)
	{
		for (int j = 0; j < iWidth; j++)
		{
			if (iBitPerPixel == 8) 
			{
				if (pImg[i*Wp + j] == 255) //Found first pixel of new region
				{
					shapes.push_back(floodFillUtil(pImg, i, j, 255, intensities[objectCnt], iWidth, iHeight));
					if (objectCnt < intensities.size() - 1) {
						objectCnt++;
					}
				}
			}
		}	
	}

	//Sort regions from smallest to largest
	std::sort(shapes.begin(), shapes.end(), [](const std::vector<int> & lhs, const std::vector<int> & rhs) { return lhs.size() < rhs.size(); });

	cnt = 0;
	for (auto shape : shapes)
	{
		for (auto pixl : shape) 
		{
			pImg[pixl] = intensities[cnt];
		}
		cnt++;
		_cprintf("Size of current shape in piexels: %d\n", shape.size());
	}

	//redraw the screen
	OnDraw(GetDC());
	_cprintf("Done Thresholding %d\n", objectCnt);
}

std::vector<int> CKingimageView::floodFillUtil(BYTE * pImg, int i, int j, int prevC, int newC, int M, int N){
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(i,j));
	std::vector<int> shape;
	while (!q.empty()) 
	{
		int curCoordI = q.front().first;
		int curCoordJ = q.front().second;
		int curCoord = curCoordI * M + curCoordJ;
		q.pop();
		if (curCoord <= M * N && pImg[curCoord] == prevC)
		{
			// Replace the color at (x, y) to mark found and push to shape vector
			shape.push_back(curCoord);
			pImg[curCoord] = newC;
			
			// Push for north, east, south and west pixels
			q.push(std::make_pair(curCoordI - 1, curCoordJ));
			q.push(std::make_pair(curCoordI + 1, curCoordJ));
			q.push(std::make_pair(curCoordI, curCoordJ + 1));
			q.push(std::make_pair(curCoordI, curCoordJ - 1));
		}
	}
	return shape;
}

void CKingimageView::OnUnsharpMask(){
	_cprintf("Unsharpening\n");
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	std::vector<float> contrastImg;
	std::vector<float> gbImg;
	std::vector<float> invGBImg;
	std::vector<float> scaledInvGBImg;
	std::vector<float> edgeImg;
	std::vector<float> unsharpMask;
	std::vector<float> killMeNow;
	int Wp = iWidth;
	int totalPix = iWidth * iHeight;
	//make a blur check
	//invert the blur check
	//scale the blur check
	//Add scaled blur with original and hard cap
	
	float blurMask[5][5] = { { .003765, .015019, .023792, .015019, .003765 },
						     { .015019, .059912, .094907, .059912, .015019 },
						     { .023792, .094907, .150342, .094907, .023792 },
							 { .015019, .059912, .094907, .059912, .015019 },
							 { .003765, .015019, .023792, .015019, .003765 } };

	float weight = 1;

	int offset = 2;

	float C = 10;
	float F = (259 * (C + 255)) / (255 * (259 - C));

	//Make the contrasting image
	for (int i = offset; i < iHeight - offset; i++) {
		for (int j = offset; j < iWidth - offset; j++) {
			int curVal = pImg[i *Wp + j];
			curVal = (F * (curVal - 128)) + 128;
			if (curVal > 255) {
				contrastImg.push_back(255);
			}
			else if (curVal < 0) {
				contrastImg.push_back(0);
			}else {
				contrastImg.push_back(curVal);
			}
		}
	}

	//Make Gaussion blur and invert it
	for (int i = offset; i < iHeight - offset; i++){
		for (int j = offset; j < iWidth - offset; j++){
			gbImg.push_back(applyFilter8Bit(blurMask, pImg, i, j, iWidth, weight, offset));
		}
	}

	//Make Gaussion blur and invert it
	for (int i = 0; i < gbImg.size(); i++) {
			invGBImg.push_back(255 - gbImg[i]);
	}

	float max = 100;
	for (int i = 0; i < invGBImg.size(); i++) {
		if (invGBImg[i] < max) {
			scaledInvGBImg.push_back(0);
		}else{
			scaledInvGBImg.push_back((invGBImg[i] / 255.0) * max);
		}
	}

	//Make unsharp mask
	int cnt = 0;
	for (int i = offset; i < iHeight - offset; i++) {
		for (int j = offset; j < iWidth - offset; j++) {
			float curVal = abs(pImg[i *Wp + j] - gbImg[cnt]);
			if (curVal > 255) {
				unsharpMask.push_back(255);
			}else{
				unsharpMask.push_back(curVal);
			}
			cnt++;
		}
	}

	//Apply the final transformation to the original
	cnt = 0;
	for (int i = offset; i < iHeight - offset; i++) {
		for (int j = offset; j < iWidth - offset; j++) {
			pImg[i * iWidth + j] = pImg[i * iWidth + j] + unsharpMask[cnt];
			cnt++;
		}
	}

	//Make the final image more contrasted
	for (int i = offset; i < iHeight - offset; i++) {
		for (int j = offset; j < iWidth - offset; j++) {
			int curVal = pImg[i *Wp + j];
			curVal = (F * (curVal - 128)) + 128;
			if (curVal > 255) {
				pImg[i *Wp + j] = 255;
			}
			else if (curVal < 0) {
				pImg[i *Wp + j] = 0;
			}
			else {
				pImg[i *Wp + j] = curVal;
			}
		}
	}

	OnDraw(GetDC());
	_cprintf("Done Unsharpening\n");

}

float applyFilter8Bit(double mask[][11], BYTE *orig, int row, int col, int wid, float weight, int offset) {
	float finalVal = 0;
	row -= offset;
	col -= offset;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			finalVal += (mask[i][j] * orig[(row + j) * wid + (col + i)]);
		}
	}
	return finalVal / weight;
}

float applyFilter8Bit(double mask[][7], BYTE *orig, int row, int col, int wid, float weight, int offset) {
	float finalVal = 0;
	row -= offset;
	col -= offset;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			finalVal += (mask[i][j] * orig[(row + j) * wid + (col + i)]);
		}
	}
	return finalVal / weight;
}

float applyFilter8Bit(float mask[][5], BYTE *orig, int row, int col, int wid, float weight, int offset) {
	float finalVal = 0;
	row -= offset;
	col -= offset;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			finalVal += (mask[i][j] * orig[(row + j) * wid + (col + i)]);
		}
	}
	return finalVal / weight;
}

float applyFilter8Bit(float mask[][3], BYTE *orig, int row, int col, int wid, float weight, int offset) {
	float finalVal = 0;
	row -= offset;
	col -= offset;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			finalVal += (mask[i][j] * orig[(row + j) * wid + (col + i)]);
		}
	}
	return finalVal / weight;
}

float applyFilter24Bit(float mask[][3], BYTE *orig, int row, int col, int wid, float weight, int offset) {
	float finalVal1 = 0;
	float finalVal2 = 0;
	float finalVal3 = 0;
	row -= offset;
	col -= offset;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			finalVal1 += (mask[i][j] * orig[(row + j) * wid * 3 + (col + i) * 3]);
			finalVal2 += (mask[i][j] * orig[(row + j) * wid * 3 + (col + i) * 3 + 1]);
			finalVal3 += (mask[i][j] * orig[(row + j) * wid * 3+ (col + i) * 3 + 2]);
		}
	}
	finalVal1 /= weight;
	finalVal2 /= weight;
	finalVal3 /= weight;
	return (finalVal1 + finalVal2 + finalVal3) / 3.0;
}

void CKingimageView::OnSobel() {
	CKingimageDoc* pDoc = GetDocument();

	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	std::vector<float> sobelXImg;
	std::vector<float> sobelYImg;
	int Wp = iWidth;
	int totalPix = iWidth * iHeight;

	float sobelX[3][3] = { { 1, 0, -1 },
						   { 2, 0, -2 },
						   { 1, 0, -1 } };

	float sobelY[3][3] = { { 1,  2,  1 },
						   { 0,  0,  0 },
						   { -1, -2, -1 } };

	float weight = 1.0;
	int offset = 1;
	if (iBitPerPixel == 8){
		//Apply sobel in x direction
		for (int i = offset; i < iHeight - offset; i++) {
			for (int j = offset; j < iWidth - offset; j++) {
				sobelXImg.push_back(applyFilter8Bit(sobelX, pImg, i, j, iWidth, weight, offset));
			}
		}

		//Apply sobel in y direction
		for (int i = offset; i < iHeight - offset; i++) {
			for (int j = offset; j < iWidth - offset; j++) {
				sobelYImg.push_back(applyFilter8Bit(sobelY, pImg, i, j, iWidth, weight, offset));
			}
		}

		//Sum the squares of both x and y and take the result's square root
		int cnt = 0;
		for (int i = offset; i < iHeight - offset; i++) {
			for (int j = offset; j < iWidth - offset; j++) {
				pImg[i * iWidth + j] = sqrt(pow(sobelXImg[cnt],2) + pow(sobelYImg[cnt], 2));
				cnt++;
			}
		}
	}else if (iBitPerPixel == 24) {
		//Apply sobel in x direction
		for (int i = offset; i < iHeight - offset; i++) {
			for (int j = offset; j < iWidth - offset; j++) {
				sobelXImg.push_back(applyFilter24Bit(sobelX, pImg, i, j, iWidth, weight, offset));
			}
		}

		//Apply sobel in y direction
		for (int i = offset; i < iHeight - offset; i++) {
			for (int j = offset; j < iWidth - offset; j++) {
				sobelYImg.push_back(applyFilter24Bit(sobelY, pImg, i, j, iWidth, weight, offset));
			}
		}

		//Sum the squares of both x and y and take the result's square root
		int cnt = 0;
		for (int i = offset; i < iHeight - offset; i++) {
			for (int j = offset; j < iWidth - offset; j++) {
				float val = sqrt(pow(sobelXImg[cnt], 2) + pow(sobelYImg[cnt], 2));
				if (val < 75) {
					val = 0;
				}else {
					val = 255;
				}
				pImg[i * iWidth * 3 + j * 3] = val;
				pImg[i * iWidth * 3 + j * 3 + 1] = val;
				pImg[i * iWidth * 3 + j * 3 + 2] = val;
				cnt++;
			}
		}
	}

	OnDraw(GetDC());
	_cprintf("Done applying Sobel\n");
}

void CKingimageView::OnLog7(){
	CKingimageDoc* pDoc = GetDocument();

	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	std::vector<std::vector<float>> log7;
	log7.reserve(iHeight);
	std::vector<float> temp;
	temp.resize(iWidth);
	for (int i = 0; i < iHeight; i++) {
		log7.push_back(temp);
	}
	std::vector<float> zeroCrossing;
	
	int Wp = iWidth;
	int totalPix = iWidth * iHeight;
	int offset = 3;
	int weight = 1;
	int size = 7;
	
	int min = ceil((-1.0 * (double)size / (double)2));
	int max = floor(((double)size / (double)2));
	double sigma = 1.4;
	double logMask[7][7];
	double pi = 3.14159265358979323846;
	double e = 2.71828182845904523536;
	int xInd = 0;
	for (int i = min; i <= max; i++) {
		int yInd = 0;
		for (int j = min; j <= max; j++) {
			double part1 = 1 / (pi * pow(sigma, 4));
			double part2 = (pow(i, 2) + pow(j, 2)) / (2 * pow(sigma, 2));
			double part3 = pow(e, (-1 * part2));
			logMask[xInd][yInd] = ( -1 * part1) * (1 - part2) * part3;
			yInd++;
		}
		xInd++;
	}

	double total = 0;
	double posTotal = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			total += logMask[i][j];
			if (logMask[i][j] > 0) {
				posTotal += logMask[i][j];
			}
			_cprintf("%lf ", logMask[i][j]);
		}
		_cprintf("\n");
	}
	cprintf("Original total: %lf\n", total);

	double newTotal = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (logMask[i][j] > 0) {
				logMask[i][j] -= total / (pow(size, 2) - pow(offset, 2));
			}
			newTotal += logMask[i][j];
			_cprintf("%lf ", logMask[i][j]);
		}
		_cprintf("\n");
	}

	_cprintf("New Total: %lf\n", newTotal);

	//Apply LOG 7x7
	for (int i = offset; i < iHeight - offset; i++) {
		for (int j = offset; j < iWidth - offset; j++) {
			float curVal = applyFilter8Bit(logMask, pImg, i, j, iWidth, weight, offset);
			log7[i][j] = curVal;
		}
	}

	int cnt = 0;
	for (int i = offset; i < iHeight - offset; i++) {
		for (int j = offset; j < iWidth - offset; j++) {
			if (log7[i][j] > 0) {
				pImg[i * iWidth + j] = 255;
			}
			else {
				pImg[i * iWidth + j] = 0;
			}
			cnt++;
		}
	}

	OnDraw(GetDC());
	_cprintf("Done applying LOG 7x7\n");
}

void CKingimageView::OnLog11(){
	CKingimageDoc* pDoc = GetDocument();

	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	std::vector<std::vector<float>> log11;
	log11.reserve(iHeight);
	std::vector<float> temp;
	temp.resize(iWidth);
	for (int i = 0; i < iHeight; i++) {
		log11.push_back(temp);
	}
	std::vector<float> zeroCrossing;

	int Wp = iWidth;
	int totalPix = iWidth * iHeight;
	int offset = 5;
	int weight = 1;
	int size = 11;

	int min = ceil((-1.0 * (double)size / (double)2));
	int max = floor(((double)size / (double)2));
	double sigma = 5;
	double logMask[11][11];
	double pi = 3.14159265358979323846;
	double e = 2.71828182845904523536;
	int xInd = 0;
	_cprintf("Max: %d, Min: %d\n\n",max, min);
	for (int i = min *2; i <= max*2; i+=2) {
		int yInd = 0;
		for (int j = min*2; j <= max*2; j+=2) {
			double part1 = 1 / (pi * pow(sigma, 4));
			double part2 = (pow(i, 2) + pow(j, 2)) / (2 * pow(sigma, 2));
			double part3 = pow(e, (-1 * part2));
			logMask[xInd][yInd] = (-1 * part1) * (1 - part2) * part3;
			yInd++;
		}
		xInd++;
	}
	

	double total = 0;
	double posTotal = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			total += logMask[i][j];
			if (logMask[i][j] > 0) {
				posTotal += logMask[i][j];
			}
			_cprintf("%lf ", logMask[i][j]);
		}
		_cprintf("\n");
	}
	cprintf("Original total: %lf\n", total);

	double newTotal = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (logMask[i][j] > 0) {
				logMask[i][j] -= total / (double)(pow(size, 2) - (double)pow(offset, 2));
			}
			newTotal += logMask[i][j];
			_cprintf("%lf ", logMask[i][j]);
		}
		_cprintf("\n");
	}

	_cprintf("New Total: %lf\n", newTotal);

	//Apply LOG 11x11
	for (int i = offset; i < iHeight - offset; i++) {
		for (int j = offset; j < iWidth - offset; j++) {
			float curVal = applyFilter8Bit(logMask, pImg, i, j, iWidth, weight, offset);
			log11[i][j] = curVal;
		}
	}

	int cnt = 0;
	for (int i = offset; i < iHeight - offset; i++) {
		for (int j = offset; j < iWidth - offset; j++) {
			if (log11[i][j] > 0) {
				pImg[i * iWidth + j] = 255;
			}
			else {
				pImg[i * iWidth + j] = 0;
			}
			cnt++;
		}
	}

	OnDraw(GetDC());
	_cprintf("Done applying LOG 11x11\n");

}

void CKingimageView::eightPointDCT() {
	_cprintf("Starting Eight Point DCT\n");
	int a1 [8] = { 10, 11, 12, 11, 12, 13, 12, 11 };
	int a2 [8] = { 10, -10, 8, -7, 8, -8, 7, -7 };
	std::vector<float> v1 = DCTHelper1(8, a1);
	for (int i = 0; i < 8; i++) {
		_cprintf("%.5f\n", v1[i]);
	}
	std::vector<float> v2 = DCTHelper1(8, a2);

	for (int i = 0; i < 8; i++) {
		_cprintf("%.5f\n", v2[i]);
	}
	_cprintf("Done with Eight Point DCT\n");
}

void CKingimageView::sixteenPointDCT() {
	_cprintf("Starting Sixteen Point DCT\n");
	int a1[16] = { 10, 11, 12, 11, 12, 13, 12, 11, 10, -10, 8, -7, 8, -8, 7, -7 };
	std::vector<float> v1 = DCTHelper1(16, a1);
	for (int i = 0; i < 16; i++) {
		_cprintf("%.5f\n", v1[i]);
	}
	_cprintf("Done with Sixteen Point DCT\n");
}

std::vector<float> CKingimageView::DCTHelper1(int point, int pImg []) {
	int iWidth = point;
	int iHeight = 1;

	std::vector<float> intensities;
	intensities.resize(iWidth);

	for (int i = 0; i < iWidth; i++) {
		intensities[i] = pImg[i];
	}

	std::vector<float> dct;
	dct.resize(iWidth * iWidth);

	std::vector<std::vector<double>> cos;
	std::vector<double> temp;
	temp.resize(point);
	for (int i = 0; i < point; i++) {
		cos.push_back(temp);
	}

	double inv2N = 1.0 / (double)(point * 2);
	double M_PI = 3.14159265358979323846;
	for (int i = 0; i < point; i++) {
		for (int j = 0; j < point; j++) {
			cos[i][j] = std::cos(M_PI * i * (2.0 * j + 1) * inv2N);
		}
	}

	//DCT transform for the block on each level
	for (int i = 0; i < iWidth; i++) {
		for (int x = 0; x < point; x++) {
			for (int y = 0; y < point; y++) {
				dct[x * point + y] = 0;
				for (int u = 0; u < point; u++) {
					for (int v = 0; v < point; v++) {
						float formula = cos[x][u] * cos[y][v];
						dct[x * point + y] += formula * intensities[v];
					}
				}

				dct[x * point + y] *= alpha(x, point) * alpha(y, point);
			}
		}
	}
	return dct;
}

void CKingimageView::DCTHelper2(int point, BYTE* pImg, int iHeight, int iWidth, bool DC, bool lowestNine) {
	std::vector<float> intensitiesI;
	intensitiesI.resize(iHeight * iWidth);
	/*
	for (int i = 0; i < iHeight; i++) {
		intensitiesI.push_back(temp3);
	}
	*/
	for (int i = 0; i < iHeight; i++) {
		for (int j = 0; j < iWidth; j++) {
			intensitiesI[i * iWidth + j] = pImg[i * iWidth * 3 + j * 3 + 2];  //I 
		}
	}

	std::vector<float> dctI;

	dctI.resize(point * point);

	std::vector<std::vector<double>> cos;
	std::vector<double> temp4;
	temp4.resize(point);
	for (int i = 0; i < point; i++) {
		cos.push_back(temp4);
	}

	double inv2N = 1.0 / (double)(point * 2);
	double M_PI = 3.14159265358979323846;
	for (int i = 0; i < point; i++) {
		for (int j = 0; j < point; j++) {
			cos[i][j] = std::cos(M_PI * i * (2.0 * j + 1) * inv2N);
		}
	}

	int percentCheck = (((iHeight / point) * (iWidth / point)) * point) / 10;
	int cnt = 0;
	int loadingPercent = 0;
	//Do each point x point block of pImg for DCT
	for (int i = 0; i < iHeight - point + 1; i += point) {
		for (int j = 0; j < iWidth - point + 1; j += point) {
			if (cnt % percentCheck < point) {
				_cprintf("Loading...%d%%\n", loadingPercent);
				loadingPercent += 10;
			}
			cnt += point;
			//DCT transform for the block on each level
			for (int x = 0; x < point; ++x) {
				for (int y = 0; y < point; ++y) {
					 
					for (int u = 0; u < point; ++u) {
						for (int v = 0; v < point; ++v) {
							float formula = cos[x][u] * cos[y][v];
							dctI[x * point + y] += formula * intensitiesI[(i + u) * iWidth + (j + v)];
						}
					}

					dctI[x * point + y] *= alpha(x, point) * alpha(y, point);

					//To visualize DCT image, erase brackets and comment after out
					if (i < iHeight && j < iWidth) {
						pImg[(i + x) * iWidth * 3 + (j + y) * 3 + 2] = dctI[x * point + y];
					}else {
						pImg[(i + (x - iHeight % point)) * iWidth * 3 + (j + (y - iWidth % point)) + 2] = dctI[x * point + y];
					}
				}
			}

			//OnDraw(GetDC());
			//reset intensities for IDCT
			for (int u = 0; u < point; ++u) {
				for (int v = 0; v < point; ++v) {
					for (int x = 0; x < point; ++x) {
						for (int y = 0; y < point; ++y) {
							intensitiesI[(i + u) * iWidth + (j + v)] = 0;
						}
					}
				}
			}

			if (DC) {
				for (int x = 0; x < point; ++x) {
					for (int y = 0; y < point; ++y) {
						if (!(x == 0 && y == 0)) {
							dctI[x * point + y] = 0;
						}
					}
				}
			}
			else if (lowestNine) {
				for (int x = 0; x < point; ++x) {
					for (int y = 0; y < point; ++y) {
						if (!(x < 3 && y < 3)) {
							dctI[x * point + y] = 0;
						}
					}
				}
			}


			//Create IDCT values
			for (int u = 0; u < point; ++u) {
				for (int v = 0; v < point; ++v) {
					for (int x = 0; x < point; ++x) {
						for (int y = 0; y < point; ++y) {
							float formula = alpha(x, point) * alpha(y, point) * cos[x][u] * cos[y][v];
							intensitiesI[(i + u) * iWidth + (j + v)] += dctI[x * point + y] * formula;
						}
					}
				}
			}

			//Apply IDCT values
			for (int x = i; x < i + point; x++) {
				for (int y = j; y < j + point; y++) {
					if (intensitiesI[x * iWidth + y] > 255) {
						intensitiesI[x * iWidth + y] = 255;
					}
					else if (intensitiesI[x * iWidth + y] < 0) {
						intensitiesI[x * iWidth + y] = 0;
					}
					pImg[x*iWidth * 3 + y * 3 + 2] = intensitiesI[x * iWidth + y];	//I 
				}
			}
		}
	}
} 

void CKingimageView::IDCTHelper(int point, BYTE* pImg, int iHeight, int iWidth) {
	_cprintf("Doing IDCT\n");
	int block = 0;
	for (int i = 0; i < (iHeight - point + 1); i += point) {
		for (int j = 0; j < (iWidth - point + 1); j += point) {
			for (int x = i; x < i + point; x++) {
				for (int y = j; y < j + point; y++) {
					pImg[i * iWidth * 3 + j * 3 + 2] = idctInfo[(x * iWidth + y)];	//I 
				}
			}
			
			//idctInfo.push_back(intensitiesI[x * iWidth + y]);
			block++;
		}
		
	}
	_cprintf("Done with IDCT\n");
}

void CKingimageView::DCT() {
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	DCTHelper2(8, pImg, iHeight, iWidth, true, false);
	OnDraw(GetDC());
}

double alpha(int i, int n){
	if (i == 0) {
		return sqrt(1.0 / (float) n);
	}
	return sqrt(2.0 / (float) n);
}

void CKingimageView::applyHSIToImage(std::vector<std::tuple<float, float, float>> hsi, int iHeight, int iWidth, BYTE* pImg) {
	int cnt = 0;
	for (int i = 0; i < iHeight; i++) {
		for (int j = 0; j < iWidth; j++) {
			float H = std::get<0>(hsi[cnt]);
			float S = std::get<1>(hsi[cnt]);
			float I = std::get<2>(hsi[cnt]);
			pImg[i * iWidth * 3 + j * 3] = H * (255.0/360.0);	//hue
			pImg[i * iWidth * 3 + j * 3 + 1] = S * 255.0;		//saturation
			pImg[i * iWidth * 3 + j * 3 + 2] = I;				//intensity
			if (cnt < hsi.size() - 1) {
				cnt++;
			}
		}
	}
}

std::vector<std::tuple<float, float, float>> CKingimageView::RGBtoHSIHelper(BYTE* pImg, int iHeight, int iWidth) {
	double M_PI = 3.14159265358979323846;
	std::vector<std::tuple<float, float, float>> hsi;
	for (int i = 0; i < iHeight; i++) {
		for (int j = 0; j < iWidth; j++) {
			float blue = pImg[i * iWidth * 3 + j * 3];
			float green = pImg[i * iWidth * 3 + j * 3 + 1];
			float red = pImg[i * iWidth * 3 + j * 3 + 2];

			float top = ((red - green) + (red - blue)) / 2;
			float bottom = sqrt(((red - green) * (red - green)) + (((red - blue) * (green - blue))));
			float theta = acos(top / bottom) * (180.0 / M_PI);

			float intensityAvg = (red + blue + green) / 3.0;
			float S = 1 - ((min(min(red, green), blue)) / intensityAvg);

			float H = 0;
			if (blue <= green) {
				H = theta;
			}
			else if (blue > green) {
				H = 360 - theta;
			}

			hsi.push_back(std::make_tuple(H, S, intensityAvg));
		}
	}
	return hsi;
}

void CKingimageView::HSIToRGBHelper(BYTE* pImg, int iHeight, int iWidth) {
	double M_PI = 3.14159265358979323846;

	for (int i = 0; i < iHeight; i++) {
		for (int j = 0; j < iWidth; j++) {
			float H = pImg[i * iWidth * 3 + j * 3] * (360.0 / 255.0);
			float HRad;
			float S = pImg[i * iWidth * 3 + j * 3 + 1] / 255.0;
			float I = pImg[i * iWidth * 3 + j * 3 + 2];
			float red = 0.;
			float blue = 0.;
			float green = 0.;
			float rad60 = 60.0 * (M_PI / 180.0);

			if (H >= 0 && H < 120) {
				HRad = H * (M_PI / 180.0);
				blue = I * (1 - S);
				red = I * (1 + ((S * cos(HRad) / (cos(rad60 - HRad)))));
				green = (3 * I) - (red + blue);
			}else if (H >= 120 && H < 240) {
				H -= 120;
				HRad = H * (M_PI / 180.0);
				red = I * (1 - S);
				green = I * (1 + ((S * cos(HRad) / (cos(rad60 - HRad)))));
				blue = (3 * I) - (red + green);
			}else if (H >= 240 && H < 360) {
				H -= 240;
				HRad = H * (M_PI / 180.0);
				green = I * (1 - S);
				blue = I * (1 + ((S * cos(HRad) / (cos(rad60 - HRad)))));
				red = (3 * I) - (green + blue);
			}

			int fRed = round(red);
			int fGreen = round(green);
			int fBlue = round(blue);

			if (fBlue > 255) {
				fBlue = 255;
			}else if (fBlue < 0) {
				fBlue = 0;
			}

			if (fRed > 255) {
				fRed = 255;
			}else if (fRed < 0) {
				fRed = 0;
			}

			if (fGreen > 255) {
				fGreen = 255;
			}else if (fGreen < 0) {
				fGreen = 0;
			}

			pImg[i * iWidth * 3 + j * 3] = fBlue;
			pImg[i * iWidth * 3 + j * 3 + 1] = fGreen;
			pImg[i * iWidth * 3 + j * 3 + 2] = fRed;
		}
	}
}

void CKingimageView::RGBtoHSI() {
	_cprintf("Starting RGB to HSI\n");
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	
	std::vector<std::tuple<float, float, float>> hsi = RGBtoHSIHelper(pImg, iHeight, iWidth);
	applyHSIToImage(hsi, iHeight, iWidth, pImg);
	
	OnDraw(GetDC());
	_cprintf("Done with RGB to HSI\n");
}

void CKingimageView::HSItoRGB() {
	_cprintf("Starting HSI to RGB\n");
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;

	HSIToRGBHelper(pImg, iHeight, iWidth);
	OnDraw(GetDC());
	_cprintf("Done with HSI to RGB\n");
}


void CKingimageView::freqDomain1() {
	_cprintf("Starting Frequency Domain 1\n");
	//Get image
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	//Convert to HSI
	RGBtoHSI();

	//Apply 8x8 DCT to HSI and call IDCT
	DCTHelper2(8, pImg, iHeight, iWidth, true, false);
	OnDraw(GetDC());
	//Apply 8x8 IDCT to HSI -> DCT image
	//IDCTHelper(8, pImg, iHeight, iWidth);
	//OnDraw(GetDC());
	//HSI to RGB image
	HSItoRGB();
	//OnDraw(GetDC());
	_cprintf("Done with Frequency Domain 1\n");
}

void CKingimageView::freqDomain2() {
	_cprintf("Starting Frequency Domain 2\n");
	//Get image
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;

	//Convert to HSI
	RGBtoHSI();

	//Apply 8x8 DCT to HSI
	DCTHelper2(8, pImg, iHeight, iWidth, false, true);

	//Apply 8x8 IDCT to HSI -> DCT image
	//IDCTHelper(8, pImg, iHeight, iWidth);

	//HSI to RGB image
	HSItoRGB();
	OnDraw(GetDC());
	_cprintf("Done with Frequency Domain 2\n");
}

void CKingimageView::IDCT() {
	_cprintf("Starting IDCT\n");
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	IDCTHelper(8, pImg, iHeight, iWidth);
	OnDraw(GetDC());
	_cprintf("Done with IDCT\n");
}

void CKingimageView::HoughTransform() {
	_cprintf("Starting Hough Transform\n");
	CKingimageDoc* pDoc = GetDocument();

	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;

	double pi = 3.14159265358979323846;
	double theta;

	double hough_h;
	if (iHeight > iWidth) {
		hough_h = (sqrt(2.0) * (double)iHeight) / 2.0;
	}else {
		hough_h = (sqrt(2.0) * (double)iWidth) / 2.0;
	}

	//Double hough_h to allow for negative numbers
	double accumulator_h = hough_h * 2.0;
	double accumulator_w = 180.0;

	int center_x = iWidth/2;
	int center_y = iHeight/2;

	std::vector<std::vector<int>> accumulator;
	std::vector<int> temp1;
	temp1.resize(accumulator_w);
	for (int i = 0; i < accumulator_h * 2; i++) {
		accumulator.push_back(temp1);
	}
	
	for (int i = 0; i < iHeight; i++) {
		for (int j = 0; j < iWidth; j++) {
			double imageAverage = (pImg[i * iWidth * 3 + j * 3] + pImg[i * iWidth * 3 + j * 3 + 1] + pImg[i * iWidth * 3 + j * 3 + 2]) / 3.0;
			if (imageAverage == 255) {
				for (int l = 0; l < 180; l++) {
					theta = l *(pi / 180.0);
					double r = ((i - center_x ) * cos(theta)) + ((j - center_y) * sin(theta));
					accumulator[(int)(r + hough_h)][l]++;
				}
			}
		}
	}
	
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> lines;
	for (int r = 0; r < accumulator_h; r++) {
		for (int t = 0; t < accumulator_w; t++) {
			if (accumulator[r][t] >= 150) {
				int max = accumulator[r][t];
				//check 9x9 box around to find local maximum
				for (int y = -4; y <= 4; y++) {
					for (int x = -4; x <= 4; x++) {
						if (((y + r >= 0) && (y + r < accumulator_h)) && ((x + t >= 0) && (x + t < accumulator_w))) {
							if (accumulator[r + y][t + x] > max) {
								max = accumulator[r + y][t + x];
								//resets to center of the 9x9
								y = 5;
								x = 5;
							}
						}
					}
				}
				if (max > (int)accumulator[r][t]) continue;

				int x1, x2, y1, y2, px, py;

				if (t >= 45 && t <= 135){
					x1 = 0;
					y1 = ((double)(r - (accumulator_h / 2)) - ((x1 - (iWidth / 2)) * cos(t * (pi / 180.0)))) / sin(t * (pi / 180.0)) + (iHeight / 2);
					x2 = iWidth;
					y2 = ((double)(r - (accumulator_h / 2)) - ((x2 - (iWidth / 2)) * cos(t * (pi / 180.0)))) / sin(t * (pi / 180.0)) + (iHeight / 2);
				}else{
					y1 = 0;
					x1 = ((double)(r - (accumulator_h / 2)) - ((y1 - (iHeight / 2)) * sin(t * (pi / 180.0)))) / cos(t * (pi / 180.0)) + (iWidth / 2);
					y2 = iHeight;
					x2 = ((double)(r - (accumulator_h / 2)) - ((y2 - (iHeight / 2)) * sin(t * (pi / 180.0)))) / cos(t * (pi / 180.0)) + (iWidth / 2);
				}

				lines.push_back(std::pair<std::pair<int, int>, std::pair<int, int>>(std::pair<int, int>(x1, y1), std::pair<int, int>(x2, y2)));
			}
		}
	}
	
	for (auto it = lines.begin(); it != lines.end(); ++it) {
		int x1, x2, y1, y2;
		x1 = it->first.first;
		y1 = it->first.second;
		x2 = it->second.first;
		y2 = it->second.second;

		const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
		if (steep){
			std::swap(x1, y1);
			std::swap(x2, y2);
		}

		if (x1 > x2){
			std::swap(x1, x2);
			std::swap(y1, y2);
		}

		const float dx = x2 - x1;
		const float dy = fabs(y2 - y1);

		float error = dx / 2.0f;
		const int ystep = (y1 < y2) ? 1 : -1;
		int y = y1;

		if (steep) {
			x1 = 0;
			x2 = iWidth - 1;
		}

		const int maxX = x2;

		for (int x = x1; x < maxX; x++){
			if (steep){
				if (y >= iHeight - 1) break;
				if (y < 0) y = 0;
				if (x < 0) x = 0;
				pImg[y * iWidth * 3 + x * 3] = 0;
				pImg[y * iWidth * 3 + x * 3 + 1] = 0;
				pImg[y * iWidth * 3 + x * 3 + 2] = 255;
			}else{
				if (x >= iHeight - 1) break;
				if (y < 0) y = 0;
				if (x < 0) x = 0;
				pImg[x * iWidth * 3 + y * 3] = 0;
				pImg[x * iWidth * 3 + y * 3 + 1] = 0;
				pImg[x * iWidth * 3 + y * 3 + 2] = 255;
			}

			error -= dy;
			if (error < 0){
				y += ystep;
				error += dx;
			}
		}
	}

	OnDraw(GetDC());
	_cprintf("Done with HoughTransform\n");
}

void CKingimageView::OnBinarize() {
	_cprintf("Starting Binarize\n");
	binarize();
	_cprintf("Done with Binzarize\n");
}

void CKingimageView::binarize() {
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;


	//Determine best threshold to make image binary
	int threshold1 = 127;
	int prevThreshold1 = 0;
	int passes = 0;

	while (prevThreshold1 != threshold1) {
		int avgPixAbove = 1;
		int avgPixBelow = 1;
		int avgAbove = 0;
		int avgBelow = 0;
		for (int i = 0; i < iHeight/4; i++) {
			for (int j = 0; j < iWidth/4; j++) {
				if (pImg[i * iWidth + j] < threshold1) {
					avgBelow += ((int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3])/3;
					avgPixBelow++;
				}else {
					avgAbove += ((int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3]) / 3;
					avgPixAbove++;
				}
			}
		}
		avgAbove /= avgPixAbove;
		avgBelow /= avgPixBelow;
		prevThreshold1 = threshold1;
		threshold1 = (avgAbove + avgBelow) / 2;
		passes++;
	}
	//_cprintf("Threshold1 = %d\n", threshold1);

	int threshold2 = 127;
	int prevThreshold2 = 0;
	//int passes = 0;

	while (prevThreshold2 != threshold2) {
		int avgPixAbove = 1;
		int avgPixBelow = 1;
		int avgAbove = 0;
		int avgBelow = 0;
		for (int i = iHeight / 4; i < iHeight / 2; i++) {
			for (int j = iWidth / 4; j < iWidth / 2; j++) {
				if (pImg[i * iWidth + j] < threshold2) {
					avgBelow += ((int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3]) / 3;
					avgPixBelow++;
				}
				else {
					avgAbove += ((int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3]) / 3;
					avgPixAbove++;
				}
			}
		}
		avgAbove /= avgPixAbove;
		avgBelow /= avgPixBelow;
		prevThreshold2 = threshold2;
		threshold2 = (avgAbove + avgBelow) / 2;
		passes++;
	}
	//_cprintf("Threshold2 = %d\n", threshold2);

	int threshold3 = 127;
	int prevThreshold3 = 0;
	//int passes = 0;

	while (prevThreshold3 != threshold3) {
		int avgPixAbove = 1;
		int avgPixBelow = 1;
		int avgAbove = 0;
		int avgBelow = 0;
		for (int i = iHeight / 2; i < 3 * (iHeight / 4); i++) {
			for (int j = iWidth / 2; j < 3 * (iWidth / 4); j++) {
				if (pImg[i * iWidth + j] < threshold3) {
					avgBelow += ((int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3]) / 3;
					avgPixBelow++;
				}
				else {
					avgAbove += ((int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3]) / 3;
					avgPixAbove++;
				}
			}
		}
		avgAbove /= avgPixAbove;
		avgBelow /= avgPixBelow;
		prevThreshold3 = threshold3;
		threshold3 = (avgAbove + avgBelow) / 2;
		passes++;
	}
	//_cprintf("threshold3 = %d\n", threshold3);

	int threshold4 = 127;
	int prevThreshold4 = 0;
	//int passes = 0;

	while (prevThreshold4 != threshold4) {
		int avgPixAbove = 1;
		int avgPixBelow = 1;
		int avgAbove = 0;
		int avgBelow = 0;
		for (int i = 3 * (iHeight / 4); i < iHeight; i++) {
			for (int j = 3* (iWidth / 4); j < iWidth; j++) {
				if (pImg[i * iWidth + j] < threshold4) {
					avgBelow += ((int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3]) / 3;
					avgPixBelow++;
				}
				else {
					avgAbove += ((int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3]) / 3;
					avgPixAbove++;
				}
			}
		}
		avgAbove /= avgPixAbove;
		avgBelow /= avgPixBelow;
		prevThreshold4 = threshold4;
		threshold4 = (avgAbove + avgBelow) / 2;
		passes++;
	}
	//_cprintf("threshold4 = %d\n", threshold4);

	//Manually set threshold because pigs spots are a problem
	std::vector<int> thresholds = {threshold1, threshold2, threshold3, threshold4};
	int avgThreshold = 0;
	for (int threshold : thresholds) {
		avgThreshold += (threshold / thresholds.size());
	}
	
	//_cprintf("Average threshold = %d\n", avgThreshold);

	//Need to weight thresholds that are much different than other by a certain percentage
	int finalThreshold = 0;
	int weight = 0;
	for (int threshold : thresholds) {
		if (threshold < avgThreshold) {
			//_cprintf("Current threshold = %d is less than average\n", threshold);
			finalThreshold += (threshold * 4);
			weight+=4;
		}
		else {
			finalThreshold += threshold;
			weight++;
		}
	}

	finalThreshold /= weight;

	_cprintf("Final threshold = %d\n", finalThreshold);
	for (int i = 0; i < iHeight; i++) {
		for (int j = 0; j < iWidth; j++) {
			int curPixAvg = ((int)pImg[i * iWidth * 3 + j * 3] + (int)pImg[i * iWidth * 3 + j * 3 + 1] + (int)pImg[i * iWidth * 3 + j * 3 + 2] )/ 3;
			if (curPixAvg >= finalThreshold) {
				pImg[i * iWidth * 3 + j * 3] = 255;
				pImg[i * iWidth * 3 + j * 3 + 1] = 255;
				pImg[i * iWidth * 3 + j * 3 + 2] = 255;
			}else {
				pImg[i * iWidth * 3 + j * 3] = 0;
				pImg[i * iWidth * 3 + j * 3 + 1] = 0;
				pImg[i * iWidth * 3 + j * 3 + 2] = 0;
			}
		}
	}
	OnDraw(GetDC());
}

void CKingimageView::OnErode() {
	_cprintf("Starting Erosion\n");
	erode();
	_cprintf("Done with Erosion\n");
}

void CKingimageView::erode() {
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;

	std::vector<int> copy;
	for (int i = 0; i < iHeight; i++) {
		for (int j = 0; j < iWidth; j++) {
			copy.push_back(pImg[i * iWidth * 3 + j * 3]);
			copy.push_back(pImg[i * iWidth * 3 + j * 3 + 1]);
			copy.push_back(pImg[i * iWidth * 3 + j * 3 + 2]);
		}
	}

	std::vector<std::vector<int>> structureElement = { { 0,1,0 },{ 1,1,1 },{ 0,1,0 } };
	int seWidth = structureElement.size();
	int seHeight = structureElement[0].size();
	int xOffset = (seWidth) / 2;
	int yOffset = (seHeight) / 2;
	int val = 0;
	for (int i = 0; i < iHeight - xOffset; i++) {
		for (int j = 0; j < iWidth - yOffset; j++){
			std::vector<int> image;
			val = 0;
			//get the neighborhood of this pixel 
			for (int x = (-1) * xOffset; x <= xOffset; x++) {
				for (int y = (-1) * yOffset; y <= yOffset; y++) {
					if (structureElement[x + xOffset][y + yOffset] == 1) {
						float curPixel = 0;
						if (!(i <= xOffset || j <= yOffset)) {
							curPixel = ((int)pImg[(i + x) * iWidth * 3 + (j + y) * 3] + (int)pImg[(i + x) * iWidth * 3 + (j + y) * 3] + (int)pImg[(i + x) * iWidth * 3 + (j + y) * 3]) / 3.0;
						}
						image.push_back((int)round(curPixel));
					}
				}
			}

			//erosion: set to zero if no 1 is present, one otherwise
			val = *std::min_element(image.begin(), image.end());

			//set output image pixel of copied image to prevent using recently updated values
			copy[i * iWidth * 3 + j * 3] = val;
			copy[i * iWidth * 3 + j * 3 + 1] = val;
			copy[i * iWidth * 3 + j * 3 + 2] = val;
		}
	}

	//Apply all of the erosions
	for (int i = 0; i < iHeight; i++) {
		for (int j = 0; j < iWidth; j++) {
			pImg[i * iWidth * 3 + j * 3] = copy[i * iWidth * 3 + j * 3];
			pImg[i * iWidth * 3 + j * 3 + 1] = copy[i * iWidth * 3 + j * 3 + 1];
			pImg[i * iWidth * 3 + j * 3 + 2] = copy[i * iWidth * 3 + j * 3 + 2];
		}
	}
	OnDraw(GetDC());
}


void CKingimageView::OnDilate() {
	_cprintf("Starting dilation\n");
	dilate();
	_cprintf("Done with dilation\n");
}

void CKingimageView::dilate() {
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;

	std::vector<int> copy;
	for (int i = 0; i < iHeight; i++) {
		for (int j = 0; j < iWidth; j++) {
			copy.push_back(pImg[i * iWidth * 3 + j * 3]);
			copy.push_back(pImg[i * iWidth * 3 + j * 3 + 1]);
			copy.push_back(pImg[i * iWidth * 3 + j * 3 + 2]);
		}
	}

	std::vector<std::vector<int>> structureElement = { { 1,1,1 },{ 1,1,1 },{ 1,1,1 } };
	int seWidth = structureElement.size();
	int seHeight = structureElement[0].size();
	int xOffset = (seWidth - 1) / 2;
	int yOffset = (seHeight - 1) / 2;
	int val = 0;
	for (int i = 0; i < iHeight - xOffset; i++) {
		for (int j = 0; j < iWidth - yOffset; j++) {
			std::vector<int> image;
			val = 0;
			//get the neighborhood of this pixel 
			for (int x = (-1) * xOffset; x <= xOffset; x++) {
				for (int y = (-1) * yOffset; y <= yOffset; y++) {
					if (structureElement[x + xOffset][y + yOffset] == 1) {
						float curPixel = 0;
						if (!(i <= xOffset || j <= yOffset)) {
							curPixel = ((int)pImg[(i + x) * iWidth * 3 + (j + y) * 3] + (int)pImg[(i + x) * iWidth * 3 + (j + y) * 3] + (int)pImg[(i + x) * iWidth * 3 + (j + y) * 3]) / 3.0;
						}
						image.push_back((int)round(curPixel));
					}
				}
			}

			//dilation: set to one if any 1 is present, zero otherwise
			val = *std::max_element(image.begin(), image.end());

			//set output image pixel of copied image to prevent using recently updated values
			copy[i * iWidth * 3 + j * 3] = val;
			copy[i * iWidth * 3 + j * 3 + 1] = val;
			copy[i * iWidth * 3 + j * 3 + 2] = val;
		}
	}

	//Apply all of the dilations
	for (int i = 0; i < iHeight; i++) {
		for (int j = 0; j < iWidth; j++) {
			pImg[i * iWidth * 3 + j * 3] = copy[i * iWidth * 3 + j * 3];
			pImg[i * iWidth * 3 + j * 3 + 1] = copy[i * iWidth * 3 + j * 3 + 1];
			pImg[i * iWidth * 3 + j * 3 + 2] = copy[i * iWidth * 3 + j * 3 + 2];
		}
	}
	OnDraw(GetDC());
}

void CKingimageView::onDoAll() {
	_cprintf("Starting all operations\n");
	binarize();

	for (int i = 0; i < 27; i++) {
		erode();
	}
	
	for (int i = 0; i < 5; i++) {
		dilate();
	}

	int pigCount = count();
	_cprintf("There are %d pigs in the image\n", pigCount);
	_cprintf("Done with all operations\n");
}

int CKingimageView::count() {
	//Essentially implement floodfill algorithm, count the average size of each object and those above threshold are a pig
	//If an object is very large, count as two, if it's too small ignore it because it could be noise
	CKingimageDoc* pDoc = GetDocument();
	int iBitPerPixel = pDoc->_bmp->bitsperpixel;
	int iWidth = pDoc->_bmp->width;
	int iHeight = pDoc->_bmp->height;
	BYTE *pImg = pDoc->_bmp->point;
	
	int objectCnt = 0;
	int curColor = 25;
	std::vector<std::vector<int>> shapes;
	for (int i = 0; i < iHeight; i++){
		for (int j = 0; j < iWidth; j++){
			if (pImg[i* iWidth * 3 + j * 3] == 255){ //Found first pixel of new region
				shapes.push_back(floodFillUtil24Bit(pImg, i, j, 255, curColor, iWidth, iHeight));
			}
		}
	}

	std::random_device rdev;
	std::mt19937 rgen(rdev());
	std::uniform_int_distribution<int> idist(0, 255);
	for (auto shape : shapes) {
		int color1 = idist(rgen);
		int color2 = idist(rgen);
		int color3 = idist(rgen);
		for (auto pixel : shape) {
			pImg[pixel] = color1;
			pImg[pixel + 1] = color2;
			pImg[pixel + 2] = color3;
		}
	}
	
	//To count the middle pig as two we need to check average pixel of each shape
	//If it's abnormally larger than the others, it's more likely to be two pigs
	int avgPixels = 0;
	for (auto shape : shapes) {
		for (auto pixel : shape) {
			avgPixels++;
		}
	}
	avgPixels /= shapes.size();
	//Uncomment this if running with a 14x erosion then 7x  dilation
	/*
	int objCnt = 0;
	for (auto shape : shapes) {
		//if the shape is extremely larger, like over 100% of the average
		if (shape.size() >= avgPixels + (avgPixels/2)) {
			objCnt += shape.size()/avgPixels;
			//If the shape is more than 50% larger than the average
			if (shape.size() % avgPixels > avgPixels / 2) {
				objCnt++;
			}
		}else{
			objCnt++;
		}
	}

	OnDraw(GetDC());
	return objCnt;
	*/
	//Returns the amount of pigs found in the image
	OnDraw(GetDC());
	return shapes.size();
}

std::vector<int> CKingimageView::floodFillUtil24Bit(BYTE * pImg, int i, int j, int prevC, int newC, int M, int N) {
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(i, j));
	std::vector<int> shape;
	while (!q.empty()) {
		int curCoordI = q.front().first;
		int curCoordJ = q.front().second;
		int curCoord = curCoordI * M * 3 + curCoordJ * 3;

		q.pop();
		if (curCoordI <= M * N && curCoordI >= 0 && curCoordJ <= M * N && curCoordJ >= 0 && pImg[curCoord] == prevC) {
			// Replace the color at (x, y) to mark found and push to shape vector
			shape.push_back(curCoord);
			pImg[curCoord] = newC;
			pImg[curCoord + 1] = newC;
			pImg[curCoord + 2] = newC;

			// Push for north, east, south and west pixels
			q.push(std::make_pair(curCoordI - 1, curCoordJ));
			q.push(std::make_pair(curCoordI + 1, curCoordJ));
			q.push(std::make_pair(curCoordI, curCoordJ + 1));
			q.push(std::make_pair(curCoordI, curCoordJ - 1));
		}
	}
	return shape;
}