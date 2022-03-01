#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int n = 4;

    for(int i = 1 ;i < n+1 ;i++){ 
    int p = fork();
        if(p == 0){
            printf("Proceso hijo %d\n", i);
            exit(0);
        }
    }
    sleep(20);
    for(int i=0 ;i<n ;i++){
        wait(NULL);
    }
    printf("FIN\n");

    return 0; 
}