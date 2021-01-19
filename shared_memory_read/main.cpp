#include <sys/ipc.h>  
#include <sys/shm.h>  
#include <string.h>  
#include <unistd.h>  
#include <stdio.h>
#include <stdlib.h>
#include <array>

#define dd 8;
   
int main() 
{ 
    int shmid; 
    double *shared_memory1;
    double *cal_num1;
std::array<double,5> array;

    shmid = shmget((key_t)1234, sizeof(array), 0666|IPC_CREAT); 
 
    if (shmid == -1) 
    { 
        perror("shmget failed : "); 
        exit(0); 
    } 
 
    shared_memory1 = (double*)shmat(shmid, NULL, 0);

    cal_num1 = (double*)shared_memory1; 
 
    while(1) 
    { 
	printf("arrayRead1\n");
        printf("%lf\n", cal_num1[0]);
	printf("arrayRead2\n"); 
        printf("%lf\n", cal_num1[1]);
	printf("arrayRead3\n");           
 	printf("%lf\n", cal_num1[2]);
	printf("arrayRead4\n");
        printf("%lf\n", cal_num1[3]);
	printf("arrayRead5\n");           
 	printf("%lf\n", cal_num1[4]); 
        sleep(1); 
     } 
/*
    if (shmid == -1)
    {
	perror("shmget failed : ");
	exit(0);
    }

    if ( -1 == shmctl( shmid, IPC_RMID, 0))
    {
	printf( "공유 메모리 제거 실패\n");
	return -1;
    }
    else
    {
	printf( "공유 메모리 제거 성공\n");
    }
    return 0;*/
} 
