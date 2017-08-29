//ABhijeet sharma
//version 1.1
//dated :: 29-08-2017
#include <stdio.h>
#include <dirent.h>
#include "function.h"
#include <string.h>


int main(int argc, char *argv[]){
  int i;
  FILE *fr;
  char file[50];
  char file_copy[50];

   if(argc == 4 && !strcmp(argv[1],"-f")){
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
                // printf("\n%s",file_copy);
                  //printf("%s\n", dir->d_name);
                  fr = fopen(file_copy, "r");
                 printf("%c%s%c\n",'<', dir->d_name,'>');
                  findInFile(fr,argv[2]);
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
       findInFile(fr,argv[1]);
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
