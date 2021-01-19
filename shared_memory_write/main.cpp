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
    int pid; 
    std::array<double,5> array;
 
    for(int i = 0; i < 5; i++)
    {
	array[i] = i;
	printf("array \n");
	printf("%lf",array[i]);
    }
    printf("\n");

    double *cal_num; 
    double *shared_memory;
 
    shmid = shmget((key_t)1234, sizeof(array), 0666|IPC_CREAT); 
 
    if (shmid == -1) 
    { 
        perror("shmget failed : "); 
        exit(0); 
    } 
 
    shared_memory = (double*)shmat(shmid, NULL, 0);
 
    if (shared_memory == (void *)-1) 
    { 
        perror("shmat failed : "); 
        exit(0); 
    } 
 
    for(int i = 0; i <5; i++)
    {
	shared_memory[i] = array[i];

	printf("shared_memory[i]");
	printf("%lf",shared_memory[i]);

	printf("%d",sizeof(array));
    }

    cal_num = (double*)shared_memory; 

    while(1) 
    { 
            cal_num[0] = cal_num[0] + 1; 

	    printf("arrayWrite1\n");
            printf("%lf\n", cal_num[0]);
	    printf("arrayWrite2\n"); 
            printf("%lf\n", cal_num[1]);
	    printf("arrayWrite3\n");           
 	    printf("%lf\n", cal_num[2]);
	    printf("arrayWrite4\n");
            printf("%lf\n", cal_num[3]);
	    printf("arrayWrite5\n");           
 	    printf("%lf\n", cal_num[4]); 
  
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
