#include<stdio.h> 
#include<math.h>
#include<stdlib.h>
long fact(int n);

int main()
{
	double x, q, sum1 = 1, sum2 = 0 ;
	int cnt = 0, fact = 1;
	scanf("%lf %lf",&x ,&q);
	printf("%lf",q);
    do {
	    cnt++ ;
		sum2 = sum2 +pow(x, cnt - 1)/fact;
    	fact = fact * cnt ;
    	sum1 = sum1 + pow(x, cnt)/fact ;
    	
    	
    }while(fabs(sum1 - sum2) > q);
    
    printf("%d",cnt);
    return 0 ;
}
