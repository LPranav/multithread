#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sched.h>

///////////////////

//////////////////

typedef void*(*f_pointer)(void*);
f_pointer f_arr[5];	//array of funcyion pointer

void* fun0(void *);
void* fun1(void *);
void* fun2(void *);
void* fun3(void *);
void* fun4(void *);

//---------------------------------
int main()
{
pthread_t tid[5];
pthread_attr_t a[5];
struct sched_param param;
int i;

for(i=0;i<5;i++)
	if(pthread_attr_init(&a[i])==-1){
	perror("init a[i]");printf("i=%d\n",i);exit(0);
	}

f_arr[0]=fun0;
f_arr[1]=fun1;
f_arr[2]=fun2;
f_arr[3]=fun3;
f_arr[4]=fun4;


for (i=0;i<5;i++)
{	pthread_create(&tid[i],&a[i],f_arr[i],NULL);
	perror("create");printf("i=%d\n",i);

}
printf("--------------------------\n");
int rc[5];
for(i=0;i<5;i++)
{ rc[i]=pthread_attr_getschedparam(&a[i],&param);
	printf("rc[%d]= %d\n ",i,rc[i]);

}



int ret_attr;
param.sched_priority=5;
ret_attr=pthread_attr_setschedparam(&a[1],&param);
printf("ret_arrr=%d\n",ret_attr);













}
//---------------------------------------
void * fun0(void*vp)
{
     printf("in 0 thread\n");
       // char d;
       // printf("print ahar in 2\n");
       // scanf(" %c",&d);
       // i=i+1;
       // printf("scan compltere in 2 i=%d\n",i);
        return NULL;

}

void * fun1(void*vp)
{
 printf("in 1 thread\n"); return NULL;  

}
void * fun2(void*vp)
{
 printf("in 2 thread\n"); return NULL;  

}

void * fun3(void*vp)
{
 printf("in 3 thread\n"); return NULL;  

}
void * fun4(void*vp)
{
 printf("in 4 thread\n"); return NULL;  

}
