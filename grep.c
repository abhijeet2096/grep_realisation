//ABhijeet sharma
//version 1.1
//dated :: 29-08-2017
#include <stdio.h>
#include <dirent.h>
#include "function.h"
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
  int i;
  FILE *fr;
  FILE *fp;
  char file[50];
  char file_copy[50];
  char file_copy2[50];
  char file_copy3[50];
  char file_output[50];
  struct stat st = {0};

  if((argc == 5 && !strcmp(argv[1],"-d") && !strcmp(argv[2],"-p"))||(argc == 5 && !strcmp(argv[1],"-p") && !strcmp(argv[2],"-d"))){
        DIR *d,*e;
        //printf("\nmaking directory");
        struct dirent *dir;
        strcpy(file,argv[4]);
        strcat(file,"/");
        strcpy(file_copy2,file);
        strcat(file_copy2,"/Output");
        d = opendir(argv[4]);
        e = opendir(file_copy2);
        if(d==NULL){
          printf ("Cannot open directory '%s'\n", argv[4]);
           return 1;
        }
        if (stat(file_copy2, &st) == -1)
        {
          mkdir(file_copy2, 0700);
          printf("\nMaking Output directory");
        }

        strcat(file_copy2,"/Result_");
        if (d)
         {
             while ((dir = readdir(d)) != NULL)
             {

               if(strstr(dir->d_name,".txt")){
                 strcpy(file_copy,file);
                 strcat(file_copy,dir->d_name);
                  strcpy(file_copy3,file_copy2);
                  strcat(file_copy3,dir->d_name);
                 pid_t pid =fork();

                  if(pid < 0)
                  {
                    printf("\nForking Failed !\n");
                    abort();
                  }
                  else  if(pid==0)
                   {
                      fr = fopen(file_copy, "r");
                      fp = fopen(file_copy3, "wb");
                      fprintf(fp,"%c%s%c\n",'<', dir->d_name,'>');
                      findInFile(fr,argv[3],1,fp);
                      fclose(fr);
                      fclose(fp);
                      _exit(0);
                   }
                  else
                  {
                    sleep(1);
                    printf("\nDone !");
                  }
               }
             }
             closedir(d);
         }
   }
   else if(argc == 4 && !strcmp(argv[1],"-d")){
         DIR *d;
         struct dirent *dir;
         strcpy(file,argv[3]);
         strcat(file,"/");
         d = opendir(argv[3]);
         if(d==NULL){
           printf ("Cannot open directory '%s'\n", argv[3]);
            return 1;
         }
         if (d)
          {
              while ((dir = readdir(d)) != NULL)
              {

                if(strstr(dir->d_name,".txt")){
                  strcpy(file_copy,file);
                  strcat(file_copy,dir->d_name);
                  fr = fopen(file_copy, "r");
                  printf("%c%s%c\n",'<', dir->d_name,'>');
                  findInFile(fr,argv[2],0,fp);
                  fclose(fr);
                }
              }
              closedir(d);
          }
    }
   else if(argc == 3)
   {
       fr = fopen (argv[2], "r");
       printf("%c%s%c\n",'<',argv[2],'>');
       findInFile(fr,argv[1],0,fp);
   }
   else if(argc == 2)
   {
       findinString(argv[1]);
   }
   else
   {
     printf("Please follow the instructions !");
     printf("\nUsage :: ");
     printf("\n\n\n$./grep.c <if any flag> <pattern> <filename(input)/optional/directory if flaged>");
     printf("\nfor example : $./grep.c -d p?o input.txt");
     printf("\n\nListed flags for this program !");
     printf("\n\n\n1. -d : searches pattern in that directory");
     printf("\n\nEnd Of Manual !");
   }

  return 0;
}
