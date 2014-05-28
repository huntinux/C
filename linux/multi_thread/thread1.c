/*
 * Linux创建线程
 * 参考： Beginning Linux Programmnig 4th edition
 * chatper 12
 *
 * */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MSG_MAX 128

char global_msg[MSG_MAX] = "msg from main";

void * thread_fun(void *);

int main()
{
	pthread_t tid;
	void *ret;

	if(pthread_create(&tid, NULL, thread_fun, global_msg) != 0){ // 启动线程，tid保存线程id，thread_fun为线程函数, 属性为NULL，msg为传给线程的参数
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	pthread_join(tid,&ret); //等待线程结束
	printf("return value from thread:%s\n", (char *)ret); // 得到线程返回值
	return 0;
}

void * thread_fun(void *arg)
{
	printf("thread running, arg from main is:%s\n", (char *)arg); // 获得传入的参数
	snprintf(global_msg, MSG_MAX, "%s", "modified by thread"); // 修改全局变量
	pthread_exit("return value from thread"); //返回值
}

/*
It’s important to be clear about the difference between the fork system call and the creation of
new threads. When a process executes a fork call, a new copy of the process is created with its
own variables and its own PID. This new process is scheduled independently, and (in general)
executes almost independently of the process that created it. When we create a new thread in a
process, in contrast, the new thread of execution gets its own stack (and hence local variables) but
shares global variables, file descriptors, signal handlers, and its current directory state with the
process that created it.
 */
