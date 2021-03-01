#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>

char home_path[] = "/home/";

char command[100];
char hostname[1024];
char* username = getlogin();

void help() {
    std::cout << "This shell rewrite to a2p1k02" << std::endl;
}

int main() {
    std::string line;
    std::string args = line.substr(3, line.find(" "));
    while(true) {
        gethostname(hostname, 1024);
        std::cout << username << "@" << hostname << " ~ $ ";
        std::cin >> line;
        if (line == "exit") {
            return 1;
            break;
        } else if(line == "help") {
            help();
        } else {
            std::system(line.c_str());
        }
    }

    return 0;
}
