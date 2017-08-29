#include "function.h"

void findInFile(FILE *fp , char* p)
{  char buffer[1500];
    int lineNumber = 0;
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
         while(p[j]!='\0'){
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
         if(flag)
            printf("%c%d%c %s",'<',lineNumber,'>',buffer);
       }
       i++;
     }
  }
  fclose(fp);
}

void findinString(char *p){
//To do
}
