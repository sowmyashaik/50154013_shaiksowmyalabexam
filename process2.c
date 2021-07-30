#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdlib.h>
#include <string.h>

mqd_t mque;
struct mq_attr mque_attr;
char buffer[128];
int msge_prio;

int main(int argc, char const *argv[])
{
    mque_attr.mq_flags = 0;
    mque_attr.mq_maxmsg = 4;
    mque_attr.mq_msgsize = 128;
    mque_attr.mq_curmsgs = 0;

    mque = mq_open("/dictionary",O_RDONLY | O_CREAT ,S_IRUSR | S_IWUSR, &mque_attr);
    mq_receive(mque,buffer,128,&msge_prio);
    printf("%s\n",buffer);
    printf("length of the string is: %ld\n",strlen(buffer));
    mq_close(mque);
    return 0;
}