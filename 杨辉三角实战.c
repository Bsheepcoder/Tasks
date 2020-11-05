#include<stdio.h> 
int main(void)
{
	int n, i, j, t, t1, t2, t3;
	scanf("%d",&n);
	for(i = 1; i <= n+1 ; i++)
	{
		int k = i;
	    while( k < n)
	    {
	    	printf("  ");
	    	k++ ;
	    }
	    t1 = 1;
	    t2 = 1;
	    t3 = 1;
	    for(j = 1 ; j < i; j++)
	    {
	    	t1 = t1 * i;
	    	t2 = t2 * j;
	    	t3 = t3 * (i - j);
	    	t = t1/t2*t3;
	    	printf("   %d",t);
	    }

		printf("\n");
	}
	return 0;
}
