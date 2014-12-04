/**
 *  Filename: readpasswd.c
 *   Created: 2014-12-05 00:08:12
 *      Desc:
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */
#include "readpasswd.h"
#define min(v1, v2)  ((v1 > v2) ? (v2) : (v1))

static void readline(char *passwd, int len)
{
    int            r_len;

    len  = (min(MAX_PASSWD_LEN, len) - 1);
    fgets(passwd, len, stdin);
    r_len = strlen(passwd) - 1;
    if (passwd[r_len] == '\n' || passwd[r_len] == '\r')
        passwd[r_len] = '\0';

    return;
}

int readpasswd(char *passwd, int len)
{
	struct termios oldact, newact;

    tcgetattr(fileno(stdin), &oldact);
    newact          = oldact;
    newact.c_lflag &= ~ECHO;

	printf("Enter password: ");
    if (tcsetattr(fileno(stdin), TCSAFLUSH, &newact) != 0) {
        fprintf(stderr, "tcsetattr: %m\n");
        return -1;
    }

    readline(passwd, len);

    if (tcsetattr(fileno(stdin), TCSANOW, &oldact) != 0) {
        fprintf(stderr, "tcsetattr: %m\n");
        return -1;
    }

    putchar('\n');

	return 0;
}
