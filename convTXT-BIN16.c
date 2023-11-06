#include <stdio.h>

int main () {
   FILE *fp;
   int i,c;
   unsigned short sum=0;
  
   fp = fopen(fichTXT,"r");
   fpBin = fopen(ficBIN,"wb");
   if(fp == NULL) {
      perror("Error in opening file");
      return(-1);
   }
   
   while(1) {
      sum = 0;
	  i = 0;
	  while(i < 16){
         c = fgetc(fp);
         if( feof(fp) ) { 
            break ;
         }
	     if(c=='0' || c == '1'){ 
            sum += (c-30)*pow(2.0,15-i);
		    i++;
         }
      }
	  fwrite(&sum, unsigned short, 1, fpBIN);
   }
   fclose(fp);
   fclose(fpBIN);
   
   return(0);
}