/* Authors: Rohan Amin and Alex Luo 
   createdataA.c */
#include <stdlib.io>
#include "miniassembler.h"

int main(void) {
   FILE *psFile;
   int i;
   unsigned int mov, adr, strb, branch;
   unsigned long movLocation; 
   psFile = fopen("dataA", "w");
   fputs("Rohan Alex",psFile);

   for (i = 0; i < 22; i++)
      putc('\0', psFile);
   
   mov = MiniAssembler_mov(0, 'A');
   adr = MiniAssembler_adr(1,0x420044,0x42007c) ;
   strb = MiniAssembeler_strb(0, 1); 
   branch = MiniAssembler_b(0x400864,0x420084);
   movLocation = 0x420078
   fwrite(&mov, sizeof(unsigned int), 1, psFile);
   fwrite(&adr, sizeof(unsigned int), 1, psFile);
   fwrite(&strb, sizeof(unsigned int), 1, psFile);
   fwrite(&branch, sizeof(unsigned int), 1, psFile);
   fwrite (&movLocation, sizeof(unsigned long), 1, psFile); 
   fclose(psFile);
   return 0; 

}
