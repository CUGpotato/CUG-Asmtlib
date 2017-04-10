#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>

#define M 50


typedef struct
{
	int num;			//��Ʒ���
	char name[20];			//��Ʒ����
	int stock;			//ԭʼ���
	int in;				//�����Ŀ
	int out;			//������Ŀ
	int amount;			//���տ��
	int warning_value;	//����ֵ
	int state;			//���״̬(�Ƿ���ھ���ֵ)
}goods;
goods s[M];				//���ڴ�Ż�Ʒ��Ϣ 
goods r[M];				//���ڴ������Ʒ��Ϣ 
goods t[M];				//���ڴ�ų����Ʒ��Ϣ 


void Re_file();
void Stock_in();
void Stock_out();
void Display();
void Estimate();
void Query();
void Sort();
void Printf_back();
void Modify();
void Statistics();
int Wr_file();




int N;
int P;


main()
{
	int sele;
	Re_file();    //��ȡ��Ʒ��Ϣ 
	sele=1;
	while(sele)
	{
		system("cls");
		printf("\n\n");
		printf("*********************************************\n");
		printf("*                                           *\n");
		printf("*       1.���              2.����          *\n");
		printf("*                                           *\n");
		printf("*       3.��ѯ              4.����          *\n");
		printf("*                                           *\n");
		printf("*       5.�޸�              6.ͳ��          *\n");
		printf("*                                           *\n");
		printf("*       7.�˳�                              *\n");
		printf("*                                           *\n");
		printf("*********************************************\n");
		printf("��ѡ�������:");
		scanf("%d",&sele);
		switch(sele)
		{
			case 1:Stock_in();Display();break;
			case 2:Stock_out();Display();break;
			case 3:Query();break;
			case 4:Sort();Display();break;
			case 5:Modify();Display();break;
			case 6:Statistics();break;
			case 7:exit(0);sele=0;break;
		}
		printf("\n\n�����������...\n");
		getch();
	}
	Wr_file();
}




void Re_file()		//����ԭʼ����ļ�
{
	FILE*fp;
	N=0;
	fp=fopen("goods.txt","r");
	while(fscanf(fp,"%d%s%d%d%d%d%d",&s[N].num,&s[N].name,&s[N].stock,&s[N].in,&s[N].out,&s[N].amount,&s[N].warning_value)!=EOF)N++;
	fclose(fp);
	P=N;
}


void Stock_in()		//��������ļ�
{
	FILE*fp;
	int i,j;
	N=0;
	fp=fopen("stockin.txt","r");
	while(fscanf(fp,"%d%d",&r[N].num,&r[N].in)!=EOF)N++;
	fclose(fp);
	for(i=0;i<P;i++)
	{
		for(j=0;j<N;j++)
		{
			if(r[i].num==s[j].num)
				s[j].in=r[j].in;
		}
	}
	for(i=0;i<P;i++)
	s[i].amount=s[i].stock+s[i].in;
}



void Stock_out()	//��������ļ�
{
	FILE*fp;
	int i,j;
	N=0;
	fp=fopen("stockout.txt","r");
	while(fscanf(fp,"%d%d",&t[N].num,&t[N].out)!=EOF)N++;
	fclose(fp);
	for(i=0;i<P;i++)
	{
		for(j=0;j<N;j++)
		{
			if(t[i].num==s[j].num)
				s[j].out=t[j].out;
		}
	}
	for(i=0;i<P;i++)
	s[i].amount=s[i].stock+s[i].in-s[i].out;
}





void Display()		//��ʾ������
{
	int i,j;
	system("cls");
	Estimate();
	printf("��Ʒ���  ��Ʒ����  ԭʼ���  �����Ŀ  ������Ŀ  ���տ��  ����ֵ\n");
	for(i=0,j=1;i<P;i++,j++)
	{
		if(s[i].state==1)		//���ֵС�ھ���ֵ������ʾ
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); 
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[i].num,s[i].name,s[i].stock,s[i].in,s[i].out,s[i].amount,s[i].warning_value);
			if(j%10==0&&j!=P)		//����ÿ����ʾʮ��
			{
				printf("�����������...");
				getch();
				puts("\n");
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
				printf("��Ʒ���  ��Ʒ����  ԭʼ���  �����Ŀ  ������Ŀ  ���տ��  ����ֵ\n");
			}
		}
		else if(s[i].state==0)	//���ֵ��С�ھ���ֵ������ʾ
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
			printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[i].num,s[i].name,s[i].stock,s[i].in,s[i].out,s[i].amount,s[i].warning_value);
			if(j%10==0&&j<P)
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
				printf("�����������...");
				getch();
				puts("\n");
				printf("��Ʒ���  ��Ʒ����  ԭʼ���  �����Ŀ  ������Ŀ  ���տ��  ����ֵ\n");
			}
		}
	}
}







void Estimate()		//�жϿ��ֵ�Ƿ�С�ھ���ֵ
{
	int i;
	for(i=0;i<P;i++)
	{
		if(s[i].amount>=s[i].warning_value)
			s[i].state=0;
		else if(s[i].amount<s[i].warning_value)
			s[i].state=1;
	}
}




void Query()      //��ѯ��Ʒ
{
	int k,m,i,j=-1;
	char n[20];
	system("cls");
	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*      1.��Ʒ���         2.��Ʒ����        *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	printf("\n\n�������ѯѡ��:");
	scanf("%d",&k);
	if(k==1)
	{
		printf("�������Ʒ���:");
		scanf("%d",&m);
		for(i=0;i<P;i++)
		{
			if(m==i)
			j=m-1;
		}
	}
	else if(k=2)
	{
		printf("�������Ʒ����:");
		scanf("%s",&n);
		for(i=0;i<P;i++)
		{
			if(strcmp(n,s[i].name)==0)
				j=i;
		}
	}
	Estimate();
	if(j==-1)
	{
		printf("\nû���ҵ�!\n");
		Printf_back();
	}
	else
	{
		if(s[j].state==1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); 
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("��Ʒ���  ��Ʒ����  ԭʼ���  �����Ŀ  ������Ŀ  ���տ��  ����ֵ\n");
			printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[j].num,s[j].name,s[j].stock,s[j].in,s[j].out,s[j].amount,s[j].warning_value);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE);
			Printf_back();
		}	
		else
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
			printf("��Ʒ���  ��Ʒ����  ԭʼ���  �����Ŀ  ������Ŀ  ���տ��  ����ֵ\n");
			printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[j].num,s[j].name,s[j].stock,s[j].in,s[j].out,s[j].amount,s[j].warning_value);
			Printf_back();
		}
	}
}







void Sort()    //��Ʒ���������С��������
{
	int i,j;
	goods t;
	for(i=0;i<P-1;i++)
		for(j=i+1;j<P;j++)
		{
			if(s[i].amount>s[j].amount)
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
	Display();
	Printf_back();
}





void Printf_back()     //�������˵�
{
	getch();
	main();
}




void Modify()        //�޸Ļ�Ʒ��Ϣ
{
	int k,m,i,j=-1,t,h;
	char n[20];
	system("cls");
	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*      1.��Ʒ���         2.��Ʒ����        *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	printf("\n\n�������޸�ѡ��:");
	scanf("%d",&k);
	if(k==1)
	{
		printf("�������Ʒ���:");
		scanf("%d",&m);
		for(i=0;i<P;i++)
		{
			if(m==i)
			j=m-1;
		}
	}
	else if(k==2)
	{
		printf("�������Ʒ����:");
		scanf("%s",&n);
		for(i=0;i<P;i++)
		{
			if(strcmp(n,s[i].name)==0)
				j=i;
		}
	}
	if(j==-1)
	{
		printf("\nû���ҵ�!\n");
		Printf_back();
	}
	else
	{
		printf("\n\n");
		printf("*********************************************\n");
		printf("*                                           *\n");
		printf("*       1.ԭʼ���          2.�����Ŀ      *\n");
		printf("*                                           *\n");
		printf("*       3.������Ŀ          4.����ֵ        *\n");
		printf("*                                           *\n");
		printf("*********************************************\n");
		printf("��ѡ���޸�ѡ��:");
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d",&h);
			s[j].stock=h;
		}
		else if(t==2)
		{
			scanf("%d",&h);
			s[j].in=h;
		}
		else if(t==3)
		{
			scanf("%d",&h);
			s[j].out=h;
		}
		else if(t==4)
		{
			scanf("%d",&h);
			s[j].warning_value=h;
		}
		s[j].amount=s[j].stock+s[j].in-s[j].out;
	}
	printf("��ȷ�Ϻ˶Ի�Ʒ��Ϣ:\n");
	Display();
}
	







void Statistics()       //ͳ����Ŀ
{
	int k,i,j,m=0,n=0;
	system("cls");
	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*      1.�������         2.���״̬        *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	printf("\n\n�������ѯѡ��:");
	scanf("%d",&k);
	if(k==1)
	{
		for(i=0;i<P;i++)
			m=m+s[i].amount;
		printf("�������Ϊ��%d",m);
	}
	else if(k==2)
	{
		Estimate();
		for(j=0;j<P;j++)
			if(s[j].state==1)
				n=n+1;
			printf("���ڿ�澯��ֵ����Ʒ����Ϊ:%d",n);
	}
	Wr_file();
}



int Wr_file()       //д����ļ�
{
	FILE*fp;
	int i;
	fp=fopen("amount.txt","w");
	for(i=0;i<P;i++)
		fprintf(fp,"%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[i].num,s[i].name,s[i].stock,s[i].in,s[i].out,s[i].amount,s[i].warning_value);
	fclose(fp);
	return 1;
}




