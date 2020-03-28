#include <iostream>
#include <ctime>

int getDays(tm *dat1,tm *dat2){
    
    int a = dat1->tm_mday - dat2->tm_mday;
    //int b = dat1->tm_mon - dat2->tm_mon;
    //b = b*30;
    //int z = a + b;
    return a;
}

int main(int argc, char const *argv[])
{
    tm *dat1,*dat2;
    dat1->tm_mday = 15;
    dat1->tm_mon = 4;
    dat2->tm_mday = 3;
    dat2->tm_mon = 2;

    std::cout << getDays(dat1,dat2) << std::endl;
    return 0;
}
