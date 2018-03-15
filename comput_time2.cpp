#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
	// using clock to computer time
    clock_t t1, t2;
    double T0,T1;
    int i,j,k,N;
    double a=1.234,b=2.345,c=3.456;
    N=100000000;                  //calculate 10^8 times
    //printf("N=%1f\n",N );
    t1 = clock();
    for(i=1;i<N;i++){
    	
	}
    t2 = clock();
    T0=(t2-t1)/(double)(CLOCKS_PER_SEC);
    printf("(a,b,c)=%.3f %.3f %.3f\n",a,b,c);
	printf("empty time=%.3f\n", T0);
    
    k=0;
    t1 = clock();         //compute plus time
    for(i=0;i<N;i++){     //switch a,b,c
    	a=a+b+c;
		b=a-b-c;
		c=a-b-c;
		a=a-b-c;
	}
    t2 = clock();
    printf("(+,a,b,c)=%.3f %.3f %.3f\n",a,b,c);
    printf("plus time=%.3f\n",(t2-t1)/(double)(CLOCKS_PER_SEC)/8 );
    
    t1 = clock();         //compute mutiple time
    for(i=0;i<N;i++){     //switch a,b,c
    	a=a*b*c;    
		b=a/b/c;
		c=a/b/c;
		a=a/b/c;
	}
    t2 = clock();
    printf("(*,a,b,c)=%.3f %.3f %.3f\n",a,b,c);
    printf("mutiple time=%.3f\n",(t2-t1)/(double)(CLOCKS_PER_SEC)/8 );
    
    t1=clock();
    for(i=0;i<N;i++){
    	a= sin(c);
    	b= sin(a);
    	c= sin(b);
	}
	t2 = clock();
    printf("(sin,a,b,c)=%f %f %f\n",a,b,c);
    printf("sin time=%.3f\n",(t2-t1)/(double)(CLOCKS_PER_SEC)/3 );

    system("pause");
    return 0;
}
