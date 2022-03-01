#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int n;

    printf("n = ");
    scanf("%d", &n);

    for(int i = 0 ;i < n+1 ;i++){ 
    int p = fork();
        if(p == 0){
            printf(" %d,", i);
            exit(0);
        }
    }
    for(int i=0 ;i < n+1 ;i++){
        wait(NULL);
    }

    return 0; 
}