#pragma once
#include "stdafx.h"
#include "ScanlineFillfunc.h"
#include <cmath>
#define round(x)((x>0)?(int)(x+0.5):(int)(x-0.5))
struct edge{
	int ymax;
	float xi;//��������ߵĽ���
	float m;//��б�ʵĵ���
	struct edge * next;
};
struct line{
	int x1, x2, y1, y2;
}Line[1000];

void insert_et(struct edge * anedge, struct edge * * p_edges)
{
	struct edge * p;
	p = *p_edges;
	*p_edges = anedge;
	anedge->next = p;
}

short insert_aet(struct edge * p, struct edge * * p_aet)
{
	struct edge * q, *k, *l;
	if (!(q = new struct edge))
	{
		AfxMessageBox(_T("\nNO ENOUGH MEMORY\n"));
		return 0;
	}
	q->ymax = p->ymax; q->xi = p->xi; q->m = p->m; q->next = NULL;
	if (!(*p_aet) || (*p_aet)->xi > q->xi || (((*p_aet)->xi == q->xi) && ((*p_aet)->m > q->m)))
	{
		l = *p_aet; *p_aet = q; q->next = l;
	}
	else
	{
		l = *p_aet; k = l->next;
		while (k && (k->xi < q->xi))
		{
			l = k; k = k->next;
		}
		if (k && (k->xi == q->xi) && (k->m < q->m))
		{
			l = k; k = k->next;
		}
		l->next = q; q->next = k;
	}
	return 1;
}

void poly_fill(CDC*pDC, int numpoint, int *points, int distance, int angle)
{
	struct edge * * et = NULL, *aet, *anedge, *p, *q = NULL;
	int i, j, maxy, miny, x1, y1, x2, y2, yi, znum;
	int dist = 0, linenum = 0;
	//�������ת���涨�ĽǶ�
	for (int i = 0; i < 2 * numpoint; i += 2)
		rotate(&points[i], &points[i + 1], angle);
	maxy = miny = points[1]; znum = 2 * numpoint;
	for (i = 3; i < znum; i++)
	{
		if (maxy < points[i]) maxy = points[i];
		else if (miny>points[i]) miny = points[i];
		i++;
	}
	//�����߱�ET
	if (!(et = new struct edge *[maxy - miny + 1]))
	{
		AfxMessageBox(_T("\n OUT MEMORY IN CONSTRUCTING ET\n"));
		return;
	}
	for (i = 0; i <(maxy - miny + 1); i++)
		et[i] = NULL;
	x1 = points[znum - 2]; y1 = points[znum - 1];
	//�����������бߣ�Ϊÿ��ˮƽ�߽���һ���߼�¼����������뵽ET��ĺ���λ��
	for (i = 0; i < znum; i += 2)
	{
		x2 = points[i]; y2 = points[i + 1];
		//ֻ���Ƿ�ˮƽ��
		if (y1 != y2)
		{
			if (!(anedge = new struct edge))
			{
				AfxMessageBox(_T("\n OUT MEMORY IN CONSTRUCTING EDGE RECORD\n"));
				goto quit;
			}
			anedge->m = (float)(x2 - x1) / (y2 - y1);
			anedge->next = NULL;
			//���������
			if (y2 > y1)
			{
				j = i + 1;
				//����Թ�����ˮƽ��
				do{
					if ((j += 2) >= znum) j -= znum;
				} while (points[j] == y2);
				if (points[j] > y2) anedge->ymax = y2 - 1;
				else anedge->ymax = y2;
				anedge->xi = x1;
				insert_et(anedge, &et[y1 - miny]);
			}
			else
			{
				j = i + 1;
				do{
					if ((j -= 2) < 0) j += znum;
				} while (points[j] == y1);
				if (points[j]>y1) anedge->ymax = y1 - 1;
				else anedge->ymax = y1;
				anedge->xi = x2;
				insert_et(anedge, &et[y2 - miny]);
			}
		}
		x1 = x2; y1 = y2;
	}
	//��ʼ����Ч�߱�AET
	aet = NULL;
	for (yi = miny; yi <= maxy; yi++, dist++)
	{
		p = et[yi - miny];
		while (p)
		{
			if (!insert_aet(p, &aet)) goto quit;
			p = p->next;
		}
		p = aet;
		//����ȡ��AET�и���¼��xi����ֵ��������ԣ���ÿ��xi֮�������������Ҫ�����ɫ
		if (dist == distance + 1)
		{
			while (p)
			{
				Line[linenum].x1 = round(p->xi); Line[linenum].y1 = yi;
				Line[linenum].x2 = round(p->next->xi); Line[linenum++].y2 = yi;
				p = p->next->next;
			}
			dist = 0;
		}
		//��ATE��ÿ����¼��������ymax==yi����ɾ���ü�¼
		//������xi+m����
		p = aet;
		while (p && (p->ymax == yi))
		{
			aet = p->next; delete p; p = aet;
		}
		while (p)
		{
			if (p->ymax == yi)
			{
				q->next = p->next; delete p; p = q->next;
			}
			else
			{
				p->xi += p->m; q = p; p = p->next;
			}
		}
	}
	//����Чɨ�������ת�ع涨�ĽǶ�
	for (i = 0; i < linenum; i++)
	{
		rotate(&Line[i].x1, &Line[i].y1, 0 - angle); rotate(&Line[i].x2, &Line[i].y2, 0 - angle);
	}
	//�������ת��ԭ���ĽǶȣ��ص�ԭ����λ��
	/*for (i = 0; i < 2 * linenum; i += 2)
	rotate(&points[i], &points[i + 1], 0 - angle);*/
	//������Чɨ�������
	for (i = 0; i < linenum; i++)
	{
		pDC->MoveTo(Line[i].x1, Line[i].y1);
		pDC->LineTo(Line[i].x2, Line[i].y2);
	}
	linenum = 0;
quit:
	//�ͷŶ�̬�����ڴ�
	if (et){
		for (yi = miny; yi <= maxy; yi++)
		{
			q = p = et[yi - miny];
			while (p)
			{
				q = p->next; delete p; p = q;
			}
		}
		delete[] et;
	}
}
void rotate(int *X, int *Y, int angle)
{
	int x, y;
	double ang = (double)angle / 180 * 3.14;
	x = (*X)*cos(ang) - (*Y)*sin(ang); y = (*X)*sin(ang) + (*Y)*cos(ang);
	(*X) = x; (*Y) = y;
}
