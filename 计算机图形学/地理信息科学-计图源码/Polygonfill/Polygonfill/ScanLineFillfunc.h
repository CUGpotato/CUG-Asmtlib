
#include"Afxwin.h"

void insert_et(struct edge *anedge, struct edge* *p_edges);
//将一条边记录插入边记录构成的链表表头
short insert_aet(struct edge *p, struct edge* *p_aet);
//复制一条边记录插入有效边表，维持有效边表的有序性

void poly_fill(CDC *pDC, int numpoint, int *points, int distance, int angle);
//扫描线填充函数
void rotate(int *X, int *Y, int angle);
//顶点二维旋转


