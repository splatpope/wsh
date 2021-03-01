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

void cd(std::string line, std::string args) {
    char* home = strcat(home_path, username);
    if (line == "cd" || line == "cd ") {
        chdir(home);
    } else if (line == "cd " || args != "") {
        chdir(args.c_str());
    }
}

int main()
{
    std::string line;
    std::string args;
    //for (int i = 3; i <= line.length(); i++) {
    //    args.push_back(line[i]);
    //}
    while(true) {
        gethostname(hostname, 1024);
        std::cout << username << "@" << hostname << " ~ $ ";
        std::cin >> line;
        if (line == "exit") {
            return 1;
            break;
        } else if(line == "help") {
            help();
        } else if (line == "cd" || args != "") {
            for (int i = 3; i < line.length(); i++) {
                args.push_back(line[i]);
            }
            cd(line, args);
        } else {
            std::system(line.c_str());
        }
    }

    return 0;
}
