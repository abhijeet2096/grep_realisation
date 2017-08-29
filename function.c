#include "function.h"

clock_t start, end;
double cpu_time_used;

void findInFile(FILE *fp , char* p)
{
  start = clock(); //starting clock
  char buffer[1500];
    int lineNumber = 0;
    int lineMatched=0;
    int i=0,j=0,a=0,flag=0;
  while(fgets(buffer,1500,fp) != NULL)
  {
    i=0;
    lineNumber++;
    while(buffer[i]!='\n')
     {
       j=0;
       a=i;
       if(buffer[a]==p[j] || p[j]=='?')
       {
         j++;
         a=a+1;
         if(p[j]=='\0')
          flag=1;
         else
         {
           while(p[j]!='\0')
           {
              if(buffer[a]==p[j] || p[j]=='?')
              {
                a++;
                j++;
                flag=1;
                continue;
              }
              else
              {
                flag=0;
                break;
              }
           }
         }
         if(flag)
         {
            printf("%c%d%c %s",'<',lineNumber,'>',buffer);
            lineMatched++;
            break;
         }
       }
       i++;
     }
  }
  end = clock();
  fclose(fp);
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("\n%d of lines matched time-taken-for-execution is %f (in sec)\n",lineMatched,cpu_time_used);
}

void findinString(char *p){
    start = clock(); //starting clock
char buffer[1500];

  int lineNumber = 0;
  int lineMatched=0;
  int i=0,j=0,a=0,flag=0;
    while(fgets(buffer,1500,stdin))
    {
      i=0;
      lineNumber++;
      while(buffer[i]!='\0')
       {
         j=0;
         a=i;
         if(buffer[a]==p[j] || p[j]=='?')
         {
           j++;
           a=a+1;
           if(p[j]=='\0')
            flag=1;
           else
           {
             while(p[j]!='\0')
             {
                if(buffer[a]==p[j] || p[j]=='?')
                {
                  a++;
                  j++;
                  flag=1;
                  continue;
                }
                else
                {
                  flag=0;
                  break;
                }
             }
           }
           if(flag)
           {
              printf("%c%d%c %s",'<',lineNumber,'>',buffer);
                lineMatched++;
              break;
           }
         }
         i++;
       }
    }
      end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n%d of lines matched time-taken-for-execution is %f  (in sec)\n",lineMatched,cpu_time_used);
}
