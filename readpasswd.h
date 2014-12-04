/**
 *  Filename: readpasswd.h
 *   Created: 2014-12-05 00:08:57
 *      Desc:
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */
#ifndef READ_PASSWD_H
#define READ_PASSWD_H
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <errno.h>

#define MAX_PASSWD_LEN 256

int readpasswd(char *passwd, int size);

#endif /* end of include guard: READ_PASSWD_H */
