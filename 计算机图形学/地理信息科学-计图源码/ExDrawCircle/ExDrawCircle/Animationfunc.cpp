#include"stdafx.h"
#include"Animationfunc.h"

void ellipseMidpoint(CDC *pDC, int xCenter, int yCenter, int rx, int ry, COLORREF color)
{
	int rx2 = rx*rx, ry2 = ry*ry;
	int tworx2 = 2 * rx2, twory2 = 2 * ry2;
	int p, x = 0, y = ry, px = 0, py = tworx2*y;
	ellipsePlotPoints(pDC, xCenter, yCenter, x, y, color);
	p = (int)((ry2 -( rx2*ry) + 0.25*rx2) + 0.5);

	while (px < py)
	{
		x++; px += twory2;
		if (p < 0)p += ry2 + px ;
		else
		{
			y--;
			py -= tworx2;
			p += ry2 + px - py;
		}
		ellipsePlotPoints(pDC, xCenter, yCenter, x, y, color);
	}
	p = (int)((ry2*(x + 0.5)*(x + 0.5) + rx2*(y - 1)*(y - 1) - rx2*ry2) + 0.5);
	while (y > 0)
	{
		y--;
		py -= tworx2;
		if (p>0)
			p += rx2 - py;
		else
		{
			x++; px += twory2; p += rx2 - py + px;
		}
		ellipsePlotPoints(pDC, xCenter, yCenter, x, y, color);
	}
}

void ellipsePlotPoints(CDC *pDC, int xCenter, int yCenter, int x, int y, COLORREF color)
{
	pDC->SetPixel(xCenter + x, yCenter + y, color);
	pDC->SetPixel(xCenter - x, yCenter + y, color);
	pDC->SetPixel(xCenter + x, yCenter - y, color);
	pDC->SetPixel(xCenter - x, yCenter - y, color);
}