
#include"Afxwin.h"

void insert_et(struct edge *anedge, struct edge* *p_edges);
//��һ���߼�¼����߼�¼���ɵ������ͷ
short insert_aet(struct edge *p, struct edge* *p_aet);
//����һ���߼�¼������Ч�߱�ά����Ч�߱��������

void poly_fill(CDC *pDC, int numpoint, int *points, int distance, int angle);
//ɨ������亯��
void rotate(int *X, int *Y, int angle);
//�����ά��ת


