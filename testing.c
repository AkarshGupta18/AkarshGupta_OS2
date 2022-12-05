#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

#define SYS_kernel_2Dcpy 451

int main(){
    float MAT1[4][4]={{1.0,2.0,3.0,4.0},{3.0,4.0,5.0,7.0},{5.0,6.0,7.0,0.0},{7.0,8.0,9.0,8.0}};
    float MAT2[4][4];

    printf("Initial Matrix is \n");

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%lf ",MAT1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int res=syscall(SYS_kernel_2Dcpy,MAT2,MAT1,4);

    if(res < 0){
        printf("ERROR! Could not perform system call.");
    }

    printf("Final Matrix is \n");

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%lf",MAT2[i][j]);
        }
       printf("\n"); 
    }
    
  return 0;
}