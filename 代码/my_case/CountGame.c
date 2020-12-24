#include<stdio.h>
#include <time.h>
#define N 30  //定义一个时间以s为单位 

/*
  程序名：算数游戏 
  时间：2020.12.24 
  制作人：Bsheepcoder 
  内容： 用户需在规定时间内尽可能多的做题，
         题目内容是完成两个10以内数相加和相减 。           
*/ 
struct  tm  * GetTime( time_t  *t)    //声明一个获取时间的结构指针 
{
	struct  tm  * loctm ;
	time  (t);                //获取Unix时间戳。
	loctm = localtime  (t);   //转为时间结构。
}

void NewNumber(int *p1, int *p2);  //生成两个10以内随机数 
int Sum(int a , int b);            //两数和 
int Minus(int a , int b);          //两数差的绝对值
void Judge(int sum,int a,int minus,int b,int *k);   //判断用户输入的结果是否正确 
int TimeCnt( struct  tm  * localtime,struct  tm   begintime); //返回剩余答题时间 
int InTime(struct  tm  * lt1 ,time_t  t , int *pn, int *pk);  //答题时间内的操作，输入两个数， 
int OutTime()

int main()
{

	int cnt = 0, k = 0;
     printf("|————%ds时间，准备开始了吗?————|\n",N);
     printf("|———按enter 开始———输任意值退出—|\n",N);
     if(getchar() == '\n')
     {
     	time_t  T;         //定义一个时间变量 
        struct  tm  * lt1;//定义一个时间结构体指针 
        struct  tm  begin;
        int time;          //定义一个时间差 
     	lt1 =  GetTime(&T);    //指针指向此时时间 
     	begin = * lt1;     //记录开始的时间指针 
		while(1)
		{
			time =  TimeCnt(lt1,begin);   //传入开始时间 ，返回剩余时间 
			printf("|——————>> 倒计时 %ds <<——————|\n",time);
			if(time >= 0)
			{
                InTime(lt1,T,&cnt,&k);    
			}else{
			    printf("|———————停！时间到了！—————|\n");
			    printf("|——————共%d题， 你答对%d题————|\n",cnt,k);
			    printf("|———————按任意键退出——————|\n",N);
			    getchar();           //防止程序闪退 
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
	*p1 = (rand()+2 * rand())%10;   //取一个随机数 p1 
	*p2 = (rand() * rand()+rand())%10;   // 取一个随机数 p2 
}
int Sum(int a , int b)   //两数和 
{
	int sum;
	sum = a + b;
	return sum;
}

int Minus(int a , int b)   //两数差的绝对值 
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
           printf("正确！\n");
           *k = *k + 1;
		}else
		{
		    printf("错误！\n");
	    }
}

int TimeCnt( struct  tm  * localtime,struct  tm   begintime) //传入
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
		printf("|—————>> %d  +/- %d = ? <<—————|\n",new1 ,new2);
		*pn++;
		scanf("%d %d",&answer1, &answer2);
		Judge(sum,answer1,minus,answer2,pk);
		lt1 =  GetTime(&t);
}
