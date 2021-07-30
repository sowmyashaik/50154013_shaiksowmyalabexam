#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

mqd_t mque;
struct mq_attr mque_attr;

int main(int argc, char const *argv[])
{
    mque_attr.mq_flags = 0;
    mque_attr.mq_maxmsg = 4;
    mque_attr.mq_msgsize = 128;
    mque_attr.mq_curmsgs = 0;

    mque = mq_open("/dictionary",O_WRONLY | O_CREAT ,S_IRUSR | S_IWUSR, &mque_attr);
    mq_send(mque,"Main\n",5,0);
    mq_send(mque,"Max\n",4,0);
    mq_close(mque);
    return 0;
}