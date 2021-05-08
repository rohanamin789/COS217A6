/* Authors: Rohan Amin and Alex Luo 
   createdataA.c */
#include <stdlib.io>
#include "miniassembler.h"

int main(void) {
   FILE *psFile;
   int i;
   unsigned long mov, adr, strb, branch; 
   psFile = fopen("dataA", "w");
   fputs("Rohan Alex",psFile);

   for (i = 0; i < 22; i++)
      putc('\0', psFile);
   
   mov = MiniAssembler_mov(0, 'A');
   adr = MiniAssembler_adr(1,0x420044,0x42007c) ;
   strb = MiniAssembeler_strb(0, 1); 
   branch = MiniAssembler_b(0x400864,0x420084);
   
   fwrite(&mov, sizeof(unsigned int), 1, psFile);
   fwrite(&adr, sizeof(unsigned int), 1, psFile);
   fwrite(&strb, sizeof(unsigned int), 1, psFile);
   fwrite(&branch, sizeof(unsigned int), 1, psFile); 
   fclose(psFile);
   return 0; 

}
