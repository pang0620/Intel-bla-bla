#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct thread_p
{
    int iterate;
    char *msg;
};

void *thread_main(void *arg);

int main(int argc, char *argv[])
{
    pthread_t t_id;
    int thread_param = 5;
    void *thr_ret;

    struct thread_p thr_p;
    thr_p.iterate = 3;
    thr_p.msg = (char *)malloc(sizeof(char) * 50);
    strcpy(thr_p.msg, "Hello, I'am thread~ \n");

    if (pthread_create(&t_id, NULL, thread_main, (void *)&thr_p) != 0)
    {
        puts("pthread_create() error");
        return -1;
    };

    if (pthread_join(t_id, &thr_ret) != 0)
    {
        puts("pthread_join() error");
        return -1;
    };

    printf("Thread return message: %s \n", (char *)thr_ret);
    free(thr_ret);
    return 0;
}

void *thread_main(void *arg)
{
    int cnt = ((struct thread_p *)arg)->iterate;
    char *msg = ((struct thread_p *)arg)->msg;

    for (int i = 0; i < cnt; i++)
    {
        sleep(1);
        puts("running thread");
    }
    return (void *)msg;
}
