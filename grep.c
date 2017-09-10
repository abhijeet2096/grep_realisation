//ABhijeet sharma
//version 1.1
//dated :: 29-08-2017


#include "function.h"

clock_t start, end;
double cpu_time_used;

void merger(char ** finalcat){
  freopen("output.txt","w",stdout);
  execvp("/bin/cat",finalcat);
}



int main(int argc, char *argv[]){
  int i;
  FILE *fr;
  FILE *fp;
  char file[50];
  char file_copy[50];
  char file_copy2[50];
  char file_copy3[50];
    char file_copy4[50];
      char file_copy5[50];
  char file_output[50];
  struct stat st = {0};
  int cnt=0;

  if((argc == 6 && !strcmp(argv[1],"-d") && !strcmp(argv[2],"-t")&& !strcmp(argv[3],"-m"))){
          DIR *d,*e,*f;
        int no_output =0;
          struct dirent *dir;
          strcpy(file,argv[5]);
          strcat(file,"/");
          strcpy(file_copy2,file);
          strcat(file_copy2,"Output");
          strcpy(file_copy4,file_copy2);
          d = opendir(argv[5]);

          if(d==NULL){
            printf ("Cannot open directory '%s'\n", argv[4]);
             return 1;
          }
          if (stat(file_copy2, &st) == -1)
          {
            mkdir(file_copy2, 0700);
            printf("\nMaking Output directory");
          }

          struct argumentList *ptr_arg = (struct argumentList*)malloc(sizeof(struct argumentList));

          f = opendir(argv[5]);
          if(f==NULL){
            printf ("Cannot open directory '%s'\n", file_copy4);
             return 1;
          }
          if (f)
           {
               while ((dir = readdir(f)) != NULL)
               {
                  if(strstr(dir->d_name,".txt"))
                  {
                    cnt++;
                  }
               }
           }
           closedir(f);
           pthread_t *tid = (pthread_t *)malloc(cnt*sizeof(pthread_t));

           FILE *fr_t[cnt];
           FILE *fp_t[cnt];
           int jk = 0;
          strcat(file_copy2,"/Result_");
          if (d)
           {
             start = clock();
               while ((dir = readdir(d)) != NULL)
               {

                 if(strstr(dir->d_name,".txt")){
                   strcpy(file_copy,file);
                   strcat(file_copy,dir->d_name);
                    strcpy(file_copy3,file_copy2);
                    strcat(file_copy3,dir->d_name);
                      no_output++;



                        fr_t[jk] = fopen(file_copy, "r");
                        fp_t[jk] = fopen(file_copy3, "wb");
                        fprintf(fp_t[jk],"%c%s%c\n",'<', dir->d_name,'>');
                        //alocating space to pointer


                        //passing argument in structure :
                        ptr_arg->choice = 1;
                        strcpy(ptr_arg->pattern,argv[4]);
                        ptr_arg->fp = fp_t[jk];
                        ptr_arg->fr = fr_t[jk];
                        //findInFile(fr,argv[4],1,fp);
                        int r = pthread_create(&tid[jk], NULL,&findInFileThread,ptr_arg);
                        if(r)
                          {
                            printf("\n threading error !");
                          }
                        // pthread_join(tid[jk],NULL);


                        jk++;
                        //_exit(0);
                 }
               }



           }
           closedir(d);
           for (jk = 0; jk < cnt; jk++)
           {
              pthread_join(tid[jk],NULL);
              fclose(fr_t[jk]);
              fclose(fp_t[jk]);
           }
          end = clock();
         cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

         printf("\n time-taken-for-execution  in threaded is %f  (in sec)\n",cpu_time_used);


          pthread_exit(NULL);
           /*
            char  **finalcat = (char**)malloc(sizeof(char*)*(no_output+1));;
            for (int km = 0; km < no_output+1; km++) {
             finalcat[km] = (char *)malloc(50*sizeof(char));
            }
             e = opendir(file_copy4);

             if(e==NULL){
               printf ("Cannot open directory '%s'\n", file_copy4);
                return 1;
             }
           if(e)
            {
              dir = readdir(e);
              cnt = 0;
              strcpy(finalcat[cnt],"cat");
              cnt++;
                while((dir = readdir(e)) != NULL)
                {

                  if(strstr(dir->d_name,".txt"))
                  {
                      strcpy(file_copy5,file_copy4);
                     strcat(file_copy5,"/");
                      strcat(file_copy5,dir->d_name);
                       strcpy(finalcat[cnt],file_copy5);
                       cnt++;
                  }
                }
                finalcat[cnt]=NULL;

              for (int km = 0; km < no_output; km++) {
                  printf("\n%s",finalcat[km]);
              }
               pid_t  pid =fork();
                if(pid < 0){
                  printf("\nMerging Failed !\n");
                  abort();
                }
                else if(pid==0){
                  merger(finalcat);
                  _exit(0);
                }
                else{
                    wait(NULL);
                    closedir(e);
                    printf("\nMerging Done !");
                }

              }*/

     }



      else if((argc == 6 && !strcmp(argv[1],"-d") && !strcmp(argv[2],"-p")&& !strcmp(argv[3],"-m"))||(argc == 6 && !strcmp(argv[1],"-p") && !strcmp(argv[2],"-d")&& !strcmp(argv[3],"-m"))){
              DIR *d,*e;
            int no_output =0;
              struct dirent *dir;
              strcpy(file,argv[5]);
              strcat(file,"/");
              strcpy(file_copy2,file);
              strcat(file_copy2,"Output");
              strcpy(file_copy4,file_copy2);
              d = opendir(argv[5]);

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
                          no_output++;
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
                            findInFile(fr,argv[4],1,fp);

                            fclose(fr);
                            fclose(fp);
                            _exit(0);
                         }
                        else
                        {
                          printf("\nDone !");
                        }
                     }
                   }
                   closedir(d);
               }
                char  **finalcat = (char**)malloc(sizeof(char*)*(no_output+1));;
                for (int km = 0; km < no_output+1; km++) {
                 finalcat[km] = (char *)malloc(50*sizeof(char));
                }
                 e = opendir(file_copy4);

                 if(e==NULL){
                   printf ("Cannot open directory '%s'\n", file_copy4);
                    return 1;
                 }
               if(e)
                {
                  dir = readdir(e);
                  int cnt = 0;
                  strcpy(finalcat[cnt],"cat");
                  cnt++;
                    while((dir = readdir(e)) != NULL)
                    {

                      if(strstr(dir->d_name,".txt"))
                      {
                          strcpy(file_copy5,file_copy4);
                         strcat(file_copy5,"/");
                          strcat(file_copy5,dir->d_name);
                           strcpy(finalcat[cnt],file_copy5);
                           cnt++;
                      }
                    }
                    finalcat[cnt]=NULL;

                  for (int km = 0; km < no_output; km++) {
                      printf("\n%s",finalcat[km]);
                  }
                   pid_t  pid =fork();
                    if(pid < 0){
                      printf("\nMerging Failed !\n");
                      abort();
                    }
                    else if(pid==0){
                      merger(finalcat);
                      _exit(0);
                    }
                    else{
                        wait(NULL);
                        closedir(e);
                        printf("\nMerging Done !");
                    }

                  }

         }
        else if((argc == 5 && !strcmp(argv[1],"-d") && !strcmp(argv[2],"-p"))||(argc == 5 && !strcmp(argv[1],"-p") && !strcmp(argv[2],"-d"))){
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
                    //sleep(1);
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
     printf("\n\n\n2. -d -p : searches pattern in that directory with parelel processing using fork() methord !");
     printf("\n\n\n3. -d -p -m : searches pattern in that directory with parelel processing using fork() methord and calling merger");
     printf("\n\n\n4. -d -t -m : searches pattern in that directory with parelel processing using Pthread methord and calling merger");
     printf("\n\nEnd Of Manual !");
   }

  return 0;
}
