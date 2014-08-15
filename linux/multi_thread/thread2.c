/*
 * Linux 线程之间的同步 synchronization
 * 参考： Beginning Linux Programmnig 4th edition
 * chatper 12
 * 同步方法：信号量semaphore, 互斥锁 mutexes
 *
 * 主线程得到用户输入，然后子线程计算用户输入了多少字符。
 * */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <string.h>

#define MSG_MAX 128
char buff[MSG_MAX]; 
sem_t sem_buff;

void * thread_fun(void *);

int main()
{
	pthread_t tid;
	void *ret;

	// 初始化信号量
	if(sem_init(&sem_buff, 0, 0) != 0){ //第一个0表示信号量在线程间share，初始值为0
		perror("sem_init");
		exit(EXIT_FAILURE);
	}

	// 创建线程
	if(pthread_create(&tid, NULL, thread_fun, NULL) != 0){ // 启动线程，tid保存线程id，thread_fun为线程函数, 属性为NULL，msg为传给线程的参数
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	
	fgets(buff, MSG_MAX, stdin);
	while(strncmp("end", buff, 3) != 0){
		sem_post(&sem_buff);
		fgets(buff, MSG_MAX, stdin);
	}
	sem_post(&sem_buff);

	pthread_join(tid,&ret); //等待线程结束
	printf("return value from thread:%s\n", (char *)ret); // 得到线程返回值
	return 0;
}

void * thread_fun(void *arg)
{
	sem_wait(&sem_buff);

	while(strncmp("end", buff, 3) != 0){
		printf("you input %d character\n", strlen(buff) - 1);
		sem_wait(&sem_buff);
	}
	pthread_exit("return value from thread"); //返回值
}


