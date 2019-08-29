#include <iostream>

/*
CreateEvent -> pthread_cond_init

CloseHandle -> pthread_cond_destroy

WaitForSingleObject -> pthread_cond_wait or pthread_cond_timedwait

SetEvent -> pthread_cond_signal or pthread_cond_broadcast
*/


int main(int argc, char const *argv[])
{
    pthread_cond_init(nullptr,nullptr);
    return 0;
}
