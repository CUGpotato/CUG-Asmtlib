#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>

#define M 50


typedef struct
{
	int num;			//货品编号
	char name[20];			//货品名称
	int stock;			//原始库存
	int in;				//入库数目
	int out;			//出库数目
	int amount;			//最终库存
	int warning_value;	//警戒值
	int state;			//库存状态(是否低于警戒值)
}goods;
goods s[M];				//用于存放货品信息 
goods r[M];				//用于存放入库货品信息 
goods t[M];				//用于存放出库货品信息 


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
	Re_file();    //读取货品信息 
	sele=1;
	while(sele)
	{
		system("cls");
		printf("\n\n");
		printf("*********************************************\n");
		printf("*                                           *\n");
		printf("*       1.入库              2.出库          *\n");
		printf("*                                           *\n");
		printf("*       3.查询              4.排序          *\n");
		printf("*                                           *\n");
		printf("*       5.修改              6.统计          *\n");
		printf("*                                           *\n");
		printf("*       7.退出                              *\n");
		printf("*                                           *\n");
		printf("*********************************************\n");
		printf("请选择功能序号:");
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
		printf("\n\n按任意键继续...\n");
		getch();
	}
	Wr_file();
}




void Re_file()		//读入原始库存文件
{
	FILE*fp;
	N=0;
	fp=fopen("goods.txt","r");
	while(fscanf(fp,"%d%s%d%d%d%d%d",&s[N].num,&s[N].name,&s[N].stock,&s[N].in,&s[N].out,&s[N].amount,&s[N].warning_value)!=EOF)N++;
	fclose(fp);
	P=N;
}


void Stock_in()		//读入入库文件
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



void Stock_out()	//读入出库文件
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





void Display()		//显示库存情况
{
	int i,j;
	system("cls");
	Estimate();
	printf("货品编号  货品名称  原始库存  入库数目  出库数目  最终库存  警戒值\n");
	for(i=0,j=1;i<P;i++,j++)
	{
		if(s[i].state==1)		//库存值小于警戒值红字显示
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); 
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[i].num,s[i].name,s[i].stock,s[i].in,s[i].out,s[i].amount,s[i].warning_value);
			if(j%10==0&&j!=P)		//控制每次显示十行
			{
				printf("按任意键继续...");
				getch();
				puts("\n");
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
				printf("货品编号  货品名称  原始库存  入库数目  出库数目  最终库存  警戒值\n");
			}
		}
		else if(s[i].state==0)	//库存值不小于警戒值白字显示
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
			printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[i].num,s[i].name,s[i].stock,s[i].in,s[i].out,s[i].amount,s[i].warning_value);
			if(j%10==0&&j<P)
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
				printf("按任意键继续...");
				getch();
				puts("\n");
				printf("货品编号  货品名称  原始库存  入库数目  出库数目  最终库存  警戒值\n");
			}
		}
	}
}







void Estimate()		//判断库存值是否小于警戒值
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




void Query()      //查询货品
{
	int k,m,i,j=-1;
	char n[20];
	system("cls");
	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*      1.货品编号         2.货品名称        *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	printf("\n\n请输入查询选项:");
	scanf("%d",&k);
	if(k==1)
	{
		printf("请输入货品编号:");
		scanf("%d",&m);
		for(i=0;i<P;i++)
		{
			if(m==i)
			j=m-1;
		}
	}
	else if(k=2)
	{
		printf("请输入货品名称:");
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
		printf("\n没有找到!\n");
		Printf_back();
	}
	else
	{
		if(s[j].state==1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); 
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("货品编号  货品名称  原始库存  入库数目  出库数目  最终库存  警戒值\n");
			printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[j].num,s[j].name,s[j].stock,s[j].in,s[j].out,s[j].amount,s[j].warning_value);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE);
			Printf_back();
		}	
		else
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
			printf("货品编号  货品名称  原始库存  入库数目  出库数目  最终库存  警戒值\n");
			printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[j].num,s[j].name,s[j].stock,s[j].in,s[j].out,s[j].amount,s[j].warning_value);
			Printf_back();
		}
	}
}







void Sort()    //商品库存总量从小到大排序
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





void Printf_back()     //返回主菜单
{
	getch();
	main();
}




void Modify()        //修改货品信息
{
	int k,m,i,j=-1,t,h;
	char n[20];
	system("cls");
	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*      1.货品编号         2.货品名称        *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	printf("\n\n请输入修改选项:");
	scanf("%d",&k);
	if(k==1)
	{
		printf("请输入货品编号:");
		scanf("%d",&m);
		for(i=0;i<P;i++)
		{
			if(m==i)
			j=m-1;
		}
	}
	else if(k==2)
	{
		printf("请输入货品名称:");
		scanf("%s",&n);
		for(i=0;i<P;i++)
		{
			if(strcmp(n,s[i].name)==0)
				j=i;
		}
	}
	if(j==-1)
	{
		printf("\n没有找到!\n");
		Printf_back();
	}
	else
	{
		printf("\n\n");
		printf("*********************************************\n");
		printf("*                                           *\n");
		printf("*       1.原始库存          2.入库数目      *\n");
		printf("*                                           *\n");
		printf("*       3.出库数目          4.警戒值        *\n");
		printf("*                                           *\n");
		printf("*********************************************\n");
		printf("请选择修改选项:");
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
	printf("请确认核对货品信息:\n");
	Display();
}
	







void Statistics()       //统计数目
{
	int k,i,j,m=0,n=0;
	system("cls");
	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*      1.库存总数         2.库存状态        *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	printf("\n\n请输入查询选项:");
	scanf("%d",&k);
	if(k==1)
	{
		for(i=0;i<P;i++)
			m=m+s[i].amount;
		printf("库存总数为：%d",m);
	}
	else if(k==2)
	{
		Estimate();
		for(j=0;j<P;j++)
			if(s[j].state==1)
				n=n+1;
			printf("低于库存警戒值的商品种数为:%d",n);
	}
	Wr_file();
}



int Wr_file()       //写输出文件
{
	FILE*fp;
	int i;
	fp=fopen("amount.txt","w");
	for(i=0;i<P;i++)
		fprintf(fp,"%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[i].num,s[i].name,s[i].stock,s[i].in,s[i].out,s[i].amount,s[i].warning_value);
	fclose(fp);
	return 1;
}




