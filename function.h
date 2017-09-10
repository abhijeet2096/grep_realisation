#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>


void findinString(char *p);//specific funtion for searching input on the go
void findInFile(FILE *fp , char* p,int choice,FILE *fp1); // specific function for searching in FILE
void *findInFileThread(void *arg1);

struct argumentList{
  int choice;
  FILE* fp;
  FILE* fr;
  char pattern[100];
};
#endif
