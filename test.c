/**
 *  Filename: test.c
 *   Created: 2014-12-05 00:22:13
 *      Desc:
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */
#include "readpasswd.h"

int main(void)
{
	char passwd[33];
	readpasswd(passwd, sizeof(passwd));
    printf("passwd: %s\n", passwd);

	return 0;
}
