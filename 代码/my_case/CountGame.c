#include<stdio.h>
#include <time.h>
#define N 30  //����һ��ʱ����sΪ��λ 

/*
  ��������������Ϸ 
  ʱ�䣺2020.12.24 
  �����ˣ�Bsheepcoder 
  ���ݣ� �û����ڹ涨ʱ���ھ����ܶ�����⣬
         ��Ŀ�������������10��������Ӻ���� ��           
*/ 
struct  tm  * GetTime( time_t  *t)    //����һ����ȡʱ��Ľṹָ�� 
{
	struct  tm  * loctm ;
	time  (t);                //��ȡUnixʱ�����
	loctm = localtime  (t);   //תΪʱ��ṹ��
}

void NewNumber(int *p1, int *p2);  //��������10��������� 
int Sum(int a , int b);            //������ 
int Minus(int a , int b);          //������ľ���ֵ
void Judge(int sum,int a,int minus,int b,int *k);   //�ж��û�����Ľ���Ƿ���ȷ 
int TimeCnt( struct  tm  * localtime,struct  tm   begintime); //����ʣ�����ʱ�� 
int InTime(struct  tm  * lt1 ,time_t  t , int *pn, int *pk);  //����ʱ���ڵĲ����������������� 
int OutTime()

int main()
{

	int cnt = 0, k = 0;
     printf("|��������%dsʱ�䣬׼����ʼ����?��������|\n",N);
     printf("|��������enter ��ʼ������������ֵ�˳���|\n",N);
     if(getchar() == '\n')
     {
     	time_t  T;         //����һ��ʱ����� 
        struct  tm  * lt1;//����һ��ʱ��ṹ��ָ�� 
        struct  tm  begin;
        int time;          //����һ��ʱ��� 
     	lt1 =  GetTime(&T);    //ָ��ָ���ʱʱ�� 
     	begin = * lt1;     //��¼��ʼ��ʱ��ָ�� 
		while(1)
		{
			time =  TimeCnt(lt1,begin);   //���뿪ʼʱ�� ������ʣ��ʱ�� 
			printf("|������������>> ����ʱ %ds <<������������|\n",time);
			if(time >= 0)
			{
                InTime(lt1,T,&cnt,&k);    
			}else{
			    printf("|��������������ͣ��ʱ�䵽�ˣ�����������|\n");
			    printf("|��������������%d�⣬ ����%d�⡪������|\n",cnt,k);
			    printf("|����������������������˳�������������|\n",N);
			    getchar();           //��ֹ�������� 
				break; 
			}
		} 
	 }
	return 0;
}

void NewNumber(int *p1, int *p2)
{
	int born ;
	srand((unsigned)time(NULL));
	*p1 = (rand()+2 * rand())%10;   //ȡһ������� p1 
	*p2 = (rand() * rand()+rand())%10;   // ȡһ������� p2 
}
int Sum(int a , int b)   //������ 
{
	int sum;
	sum = a + b;
	return sum;
}

int Minus(int a , int b)   //������ľ���ֵ 
{
	int minus;
	if(a < b){
		minus = b - a;
	}else
	{
		minus = a - b;
	}
	return minus;
}

void Judge(int sum,int a,int minus,int b,int *k)
{

	if(a == sum && b == minus)
        {
           printf("��ȷ��\n");
           *k = *k + 1;
		}else
		{
		    printf("����\n");
	    }
}

int TimeCnt( struct  tm  * localtime,struct  tm   begintime) //����
{
	int  minus;
	if(localtime->tm_min > begintime.tm_min)
	{
		minus = localtime->tm_sec + 60 - begintime.tm_sec ;
	}else
	{
		minus = localtime->tm_sec - begintime.tm_sec ;
	}
	return (N - minus) ;
}

int Intime(struct  tm  * lt1 ,time_t  t , int *pn, int *pk)
{
		int new1, new2, answer1, answer2;
       	int i,sum, begin , minus;
	    NewNumber(&new1,&new2);
		sum = Sum(new1,new2);
		minus = Minus(new1,new2);
		printf("|����������>> %d  +/- %d = ? <<����������|\n",new1 ,new2);
		*pn++;
		scanf("%d %d",&answer1, &answer2);
		Judge(sum,answer1,minus,answer2,pk);
		lt1 =  GetTime(&t);
}
