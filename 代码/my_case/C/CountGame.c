#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#define N 20  //����һ��ʱ����sΪ��λ��Ҫ��ʱ�����ٹ���5��

/*
  ��������������Ϸ 
  ʱ�䣺2020.12.24 
  �����ˣ�Bsheepcoder 
  ���ݣ� �û����ڹ涨ʱ���ھ����ܶ�����⣬
         ��Ŀ�������������10��������Ӻ������           
*/ 
struct  tm  * GetTime( time_t  *t)    //����һ����ȡʱ��Ľṹָ�� 
{
	struct  tm  * loctm;
	time (t);                //��ȡUnixʱ�����
	loctm = localtime  (t);   //תΪʱ��ṹ��
}

void NewNumber(int *p1, int *p2);  //��������10��������� 
int Sum(int a , int b);            //������ 
int Minus(int a , int b);          //������ľ���ֵ
void Judge(int sum,int a,int minus,int b,int *k);   //�ж��û�����Ľ���Ƿ���ȷ 
int TimeCnt( struct  tm  *localtime,struct  tm  begintime); //����ʣ�����ʱ��
int InTime(struct  tm  *lt1 ,time_t  t , int *pn, int *pk); //����ʱ���ڵĲ����������������� 
int AwardLangurage(int *cnt,int *k);

int main(void)
{

	 time_t  T;  
	 int cnt = 0, k = 0 ;  //
     printf(">>  %dsʱ�䣬׼����ʼ����?\n",N);
     printf(">>  ��enter ��ʼ  ||  ������ֵ�˳�\n",N);
     if(getchar() == '\n')
     {
     	       //����һ��ʱ����� 
        struct  tm  *lt1;   //����һ��ʱ��ṹ��ָ�� 
        struct  tm  begin;
        int time;          //����һ��ʱ��� 
     	lt1 =  GetTime(&T);    //ָ��ָ���ʱʱ�� 
     	begin = * lt1;     //��¼��ʼ��ʱ��ָ���ʱ�� 
		while(1)
		{
			time =  TimeCnt(lt1,begin);   //���뿪ʼʱ�� ������ʣ��ʱ�� 
			printf(">����������ʣ�� %ds������������<\t\n",time);
			if(time >= 0)
			{
                InTime(lt1,T,&cnt,&k);    
			}else{
				
			    printf(">>  ͣ��ʱ�䵽��\t\n");
			    printf(">>  �� %d �⣬ ��� %d ��\t\n",cnt,k);
			   switch (AwardLangurage(&cnt,&k))
			   {
			    case 0: printf("��ȫ��ȷ����̫�����ˣ�");
				   break;
			    case 1: printf("���㣡�ҿ����㣡");
				   break;
			    case 2: printf("���ã������Ǳ����");
				   break;
			    case 3: printf("һ�㣬����Ҫ����ϰ��");
				   break;
				case 4: printf("���ͣ���Ҫ������");
				   break;
				case 5: printf("�������Ķ������ȷ�𰸣�");
				break;
				case 6: break;
			   default:
				   break;
			   };
			    printf(">>  ��������˳�\t\n",N);
				break; 
			}
		} 
		getchar();
		getchar(); //��ֹ�������� 
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
           printf(" ��ȷ��\n");
           *k = *k + 1;
		}else
		{
		    printf(" ����\n");
	    }
}
/*
   ���ܣ��ж�ʱ���Դ�Ϊ�����˳�ѭ��
   ������ʱ��ṹָ�롢��ʼʱ��
*/
int TimeCnt( struct  tm  *localtime,struct  tm   begintime) //����
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
/*
   ���ܣ��涨ʱ���ڵĶ���
   ������ʱ��ṹָ�롢ʱ����������������ƴ������
*/
int InTime(struct  tm  *lt1 ,time_t  t , int *pn, int *pk)  
{
		 int new1, new2, answer1, answer2;
       	 int i,sum, begin , minus;
	     NewNumber(&new1,&new2);
		 sum = Sum(new1,new2);
		 minus = Minus(new1,new2);
		 printf("   >>  %d  +/- %d = ?\t\n",new1 ,new2);
		 *pn = *pn + 1;
		 scanf("%d %d",&answer1, &answer2);
		 Judge(sum,answer1,minus,answer2,pk);
		 lt1 =  GetTime(&t);
		 return 0;
}
/*
   ���ܣ��ô����������ж�����
   ��������������Ե�����
*/
int AwardLangurage(int *cnt,int *k)    
 {
	int LangurageStand;
	int error =  *cnt - *k ; // ���������
	if(*cnt > 10)
	{
		if (error == 0 )     //0%����
		{ 
			LangurageStand = 0;
		}else if(error < (*cnt)/5)  //20%
		{
			LangurageStand = 1;
		}else if(error < 2*(*cnt)/5)  //40%
		{
			LangurageStand = 2;
		}else if(error < 4*(*cnt)/5)   //80%
		{
			LangurageStand = 3;
		}else if(error < *cnt)         //100%
		{
			LangurageStand = 4;
		}else
		{
			LangurageStand = 5;
		}
		
	}else   //  5��������
	{
		if (error == 0 )     
		{ 
              printf("��ȫ��ȷ����̫�����ˣ�");
		}else if(error < *cnt)
		{
			  printf("����Ŭ����");
		}else
		{
			  printf("����Ҫ������ϰ��");
		}
		LangurageStand = 6;
	}
	return LangurageStand;
}			   