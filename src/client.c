#include <syslog.h>
#include "../include/inet_sockets.h"
#include "../include/tlpi_hdr.h"

#define SERVICE "echo"

#define BUF_SIZE 500

int
main(int argc, char *argv[])
{
    int sfd, j;
    size_t len;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if (argc < 2 || strcmp(argv[1], "--help") == 0) {
        usageErr("%s: host msg...\n", argv[0]);
    }

    sfd = inetConnect(argv[1], SERVICE, SOCK_STREAM);
    if (sfd == -1) {
        fatal("could not connect server socket");
    }

    for (j = 2; j < argc; j++) {
        len = strlen(argv[j]);
        if (write(sfd, argv[j], len) != len) {
            fatal("write");
        }

        numRead = read(sfd, buf, BUF_SIZE);
        if (numRead == -1) {
            errExit("read");
        }

        printf("[%ld bytes] %.*s\n", (long) numRead, (int) numRead, buf);
    }

    exit(EXIT_SUCCESS);
}