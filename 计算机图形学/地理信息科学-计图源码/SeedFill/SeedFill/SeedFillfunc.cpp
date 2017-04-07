#include"stdafx.h"
#include"SeedFillFunc.h"

short SeedFill(CDC* pDC, CPoint Seed, COLORREF OldClr, COLORREF NewClr)
{

	P_STACK stack;
	CPoint point;
	int i, left, right; short flgUpNewSeg, flgDwNewSeg;


	if (OldClr == NewClr)
	{
		AfxMessageBox(_T("\nNEW color must be NOT equal to old color!\n"));
		return 0;
	}

	InitStack(&stack);

	if (!PushStack(Seed, &stack))
	{
		AfxMessageBox(_T("\nStack Overflow!\n"));
		return 0;
	}

	

	while (!IsStackEmpty(stack))
	{
		
		if (!PopStack(&stack, &Seed))
		{
			AfxMessageBox(_T("\nPop element when stack is empty!\n"));
			return 0;
		}

	
			

		if (pDC->GetPixel(Seed.x, Seed.y) == NewClr)continue;

		left = right = Seed.x;
		while (pDC->GetPixel(left - 1, Seed.y) == OldClr)
			left--;
		while (pDC->GetPixel(right + 1, Seed.y) == OldClr)
			right++;

		flgUpNewSeg = flgDwNewSeg = 0;

		for (i = left; i <= right; i++)
		{
			pDC->SetPixel(i, Seed.y, NewClr);

			if (pDC->GetPixel(i, Seed.y + 1) == OldClr)
				flgUpNewSeg = 1;
			else if (flgUpNewSeg)
			{
				point.x = i - 1;
				point.y = Seed.y + 1;
				if (!PushStack(point, &stack))
				{
					AfxMessageBox(_T("\nStack Overflow!\n"));
					return 0;
				}
				flgUpNewSeg = 0;
			}

			if (pDC->GetPixel(i, Seed.y - 1) == OldClr)
				flgDwNewSeg = 1;
			else if (flgDwNewSeg)
			{
				point.x = i - 1;
				point.y = Seed.y - 1;
				if (!PushStack(point, &stack))
				{
					AfxMessageBox(_T("\nStack Overflow!\n"));
					return 0;
				}
				flgDwNewSeg = 0;
			}
		}

		if (flgUpNewSeg)
		{
			point.x = right;
			point.y = Seed.y + 1;
			if (!PushStack(point, &stack))
			{
				AfxMessageBox(_T("\nStack Overflow!\n"));
				return 0;
			}
		}

		if (flgDwNewSeg)
		{
			point.x = right;
			point.y = Seed.y -1;
			if (!PushStack(point, &stack))
			{
				AfxMessageBox(_T("\nStack Overflow!\n"));
				return 0;
			}
		}

	}
	return 1;
}


void InitStack(P_STACK *stack)
{
	(*stack).top = -1;
}

short PushStack(CPoint p, P_STACK *stack)
{
	if (IsStackFull(*stack))return 0;
	(*stack).top++;
	(*stack).element[(*stack).top].x = p.x;
	(*stack).element[(*stack).top].y = p.y;
	return 1;
}

short IsStackEmpty(P_STACK stack)
{
	if (stack.top < 0)
		return 1;
	else
		return 0;
}

short IsStackFull(P_STACK stack)
{
	if (stack.top >= 5000 - 1)
		return 1;
	else
		return 0;
}

short PopStack(P_STACK *stack, CPoint *p)
{
	if (IsStackEmpty(*stack))
		return 0;
	(*p).x = (*stack).element[(*stack).top].x;
	(*p).y = (*stack).element[(*stack).top].y;
	(*stack).top--;
	return 1;
}




