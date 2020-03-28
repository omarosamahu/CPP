#include <iostream>
#include <bits/stdc++.h>

int main(int argc, char const *argv[])
{
    std::string str = "dmesg";
    const char * command = str.c_str();
    std::cout << "Execute " << command <<" command\n";
    std::system(command);
    return 0;
}
