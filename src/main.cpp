#include <iostream>
#include <cstring>
#include <unistd.h>

char command[100];
char hostname[1024];

void help() {
    std::cout << "This shell rewrite to a2p1k02" << std::endl;
}

int main()
{
    std::string line;
    while(true) {
        gethostname(hostname, 1024);
        std::cout << getlogin() << "@" << hostname << " ~ $ ";
        std::cin >> line;
        if (line == "exit") {
            return 1;
            break;
        } else if(line == "help") {
            help();
        } else {
            std::strcpy(command, line.c_str());
            std::system(command);
        }
    }

    return 0;
}
