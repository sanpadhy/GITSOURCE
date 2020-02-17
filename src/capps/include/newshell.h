/*
 * newshell.h
 *
 *  Created on: 28-Dec-2019
 *      Author: santosh
 */

#ifndef NEWSHELL_H_
#define NEWSHELL_H_

#include "common.h"

#define MAX_ARGS  256

enum PipeRedirect {PIPE, REDIRECT, NEITHER};

// pipeRedirector parseCommand(int argc, char **argv, char **cmd1, char **cmd2);
// void pipeCmd(char **cmd1, char **cmd2);

extern int readArgs(char **argv);

// void redirectCmd(char **cmd, char **file);
// void runCmd(int argc, char **argv);


#endif /* NEWSHELL_H_ */
