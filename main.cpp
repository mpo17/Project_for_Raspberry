#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    system("rm /etc/ntp.conf");
    FILE *fd = fopen("/etc/ntp.conf", "w");
    if (strcmp(argv[1], "server") == 0)
    {
        fprintf(fd, "%s %s", "server", argv[2]);
    }
    else if (strcmp(argv[1], "client") == 0)
    {
        fprintf(fd, "%s %s", "restrict", argv[2]);
    }
    else
    {
        fprintf(fd, "%s %s", "server", "0.europe.pool.ntp.org");
    }



    fclose(fd);
    system("systemctl restart ntp");
    system("systemctl status ntp");
    return 0;
}
