#include"stdafx.h"
#include<math.h>
#include"DrawlineAlgorithms.h"

//中点绘线算法
void Middlepoint(CDC *pDC, int p0_x, int p0_y, int p1_x, int p1_y, COLORREF color)
{
	float k = 2;
	int d, d1, d2, xp, yp, i, temp, a1 = p0_x, b1 = p0_y, a2 = p1_x, b2 = p1_y;

	if (p0_x >= p1_x)
	{
		temp = a1; a1 = a2; a2 = temp;
		temp = b1; b1 = b2; b2 = temp;
	}

	if (p1_x != p0_x)
		k = 1.0*(p1_y - p0_y) / (p1_x - p0_x);

	xp = a1; yp = b1;
	pDC->SetPixel(xp, yp, color);

	if (k <= 1 && k >= 0){//while k <= 1&&k>=0
		d = (b2 - b1)*(2 * a1 + 2) + 2 * (a2*b1 - a1*b2) - (a2 - a1)*(2 * b1 + 1);
		d1 = 2 * (b2 - b1) - 2 * (a2 - a1);
		d2 = 2 * (b2 - b1);
		for (int i = 0; i < (a2 - a1); i++){
			if (d>0){
				d = d + d1; pDC->SetPixel(++xp, ++yp, color);
			}
			else{
				d = d + d2; pDC->SetPixel(++xp, yp, color);
			}
		}
	}
	if (k >= -1 && k < 0){//while k >=-1&&k<0
		d = (b2 - b1)*(2 * a1 + 2) + 2 * (a2*b1 - a1*b2) - (a2 - a1)*(2 * b1 - 1);
		d1 = 2 * (b2 - b1) + 2 * (a2 - a1);
		d2 = 2 * (b2 - b1);
		for (int i = 0; i < (a2 - a1); i++){
			if (d<0){
				d = d + d1; pDC->SetPixel(++xp, --yp, color);
			}
			else{
				d = d + d2; pDC->SetPixel(++xp, yp, color);
			}
		}
	}
	if (k>1)
	{//whilek>1
		d = (a2 - a1)*(2 * b1 + 2) - 2 * (a2*b1 - a1*b2) - (b2 - b1)*(2 * a1 + 1);
		d1 = 2 * (a2 - a1) - 2 * (b2 - b1);
		d2 = 2 * (a2 - a1);
		for (int i = 0; i < (b2 - b1); i++){
			if (d>0){
				d = d + d1; pDC->SetPixel(++xp, ++yp, color);
			}
			else{
				d = d + d2; pDC->SetPixel(xp, ++yp, color);
			}
		}
	}
	if (k<-1)
	{
		d = (a2 - a1)*(2 * b1 - 2) - 2 * (a2*b1 - a1*b2) - (b2 - b1)*(2 * a1 + 1);
		d1 = -2 * (a2 - a1) - 2 * (b2 - b1);
		d2 = -2 * (a2 - a1);
		for (int i = 0; i < (b1 - b2); i++){
			if (d<0){
				d = d + d1; pDC->SetPixel(++xp, --yp, color);
			}
			else{
				d = d + d2; pDC->SetPixel(xp, --yp, color);
			}
		}
	}
}

void DDA(CDC *pDC, int p0_x, int p0_y, int p1_x, int p1_y, COLORREF color)
{
	int dx = p1_x - p0_x, dy = p1_y - p0_y, steps, k;
	float xIncrement, yIncrement, xp = p0_x, yp = p0_y;
	if (abs(dx)>abs(dy))
		steps = abs(dx);
	else steps = abs(dy);

	xIncrement = ((float)dx) / steps;
	yIncrement = ((float)dy) / steps;
	pDC->SetPixel((int)(xp + 0.5), (int)(yp + 0.5), color);
	for (k = 0; k < steps; k++)
	{
		xp += xIncrement;
		yp += yIncrement;
		pDC->SetPixel((int)(xp + 0.5), (int)(yp + 0.5), color);
	}
}

void Bresenham(CDC *pDC, int p0_x, int p0_y, int p1_x, int p1_y, COLORREF color)
{
	int dx, dy, xp, yp, e, temp;
	if (p1_x - p0_x < 0)
	{
		temp = p0_x; p0_x = p1_x; p1_x = temp;
		temp = p0_y; p0_y = p1_y; p1_y = temp;
	}
	xp = p0_x; yp = p0_y;
	dx = p1_x - p0_x; dy = p1_y - p0_y;
	e = (abs(dx) >= abs(dy)) ? (dy - dx / 2) : (dx - dy / 2);

	if (dy >= 0)
	{
		if (dx >= dy)
		{
			while (xp <= p1_x)
			{
				pDC->SetPixel(xp, yp, color);
				if (e > 0)
				{
					yp += 1;
					e -= dx;
				}
				xp += 1; e += dy;
			}
		}
		else
		{
			while (yp < p1_y)
			{
				pDC->SetPixel(xp, yp, color);
				if (e > 0)
				{
					xp += 1;
					e -= dy;
				}
				yp += 1; e += dx;
			}
		}
	}
	else
	{
		dy = -dy;
		if (dx >= dy)
		{
			while (xp <= p1_x)
			{
				pDC->SetPixel(xp, yp, color);
				if (e > 0)
				{
					yp -= 1;
					e -= dx;
				}
				xp += 1; e += dy;
			}
		}
		else
		{
			while (yp >= p1_y)
			{
				pDC->SetPixel(xp, yp, color);
				if (e > 0)
				{
					xp += 1;
					e -= dy;
				}
				yp -= 1; e += dx;
			}
		}
	}
}