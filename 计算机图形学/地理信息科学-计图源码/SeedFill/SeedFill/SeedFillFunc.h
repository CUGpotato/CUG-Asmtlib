#include"Afxwin.h"

typedef struct tagSTACK
{
	int top;
	CPoint element[5000];
}P_STACK;

short SeedFill(CDC* PDC, CPoint Seed, COLORREF OldClr, COLORREF NewClr);
//…®√Ëœﬂ÷÷◊”ÃÓ≥‰

void InitStack(P_STACK *stack);
short PushStack(CPoint p, P_STACK *stack);
short IsStackEmpty(P_STACK stack);
short IsStackFull(P_STACK stack);
short PopStack(P_STACK *stack, CPoint *p);
