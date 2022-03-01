#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>

int isprime(int n){
	int d=3;
	int prime=0;
	int limit=sqrt(n);
	
	if(n<2)
		prime=0;
	else if(n==2)
		prime=1;
	else if(n%2==0)
		prime=0;
	else
	{
		while(d<=limit && n%d)
			d+=2;
		prime=d>limit;
	}
	return(prime);
}


int main(){
    int prime_count = 0;
    int initial, final;

    long long start_ts;
	long long stop_ts;
	long long elapsed_time;
    struct timeval ts;

    printf("Enter initial value: \n");
	scanf("%d", &initial);
	printf("Enter final number: \n");
	scanf("%d", &final);

    gettimeofday(&ts, NULL);
	start_ts = ts.tv_sec; // Tiempo inicial

    for(int i = initial;i < final; i++){
        if(isprime(i)){
            prime_count++;
        }
    }
    printf("%d\n", prime_count);

    gettimeofday(&ts, NULL);
	stop_ts = ts.tv_sec; // Tiempo final
	elapsed_time = stop_ts - start_ts;

    printf("------------------------------\n");
	printf("TIEMPO TOTAL, %lld segundos\n",elapsed_time);

    return 0;
}
