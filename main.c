#include <stdlib.h>
#include <string.h>
#include "ant.h"

int main(int argc, char **argv)
{
   struct ant ant;
   /*
      check if user input is NULL.
      - NULL: set noninput as T
      - otherwise: copy the input to instructions, and set noninput to F
   */
   if (argv[1] == NULL)
   {
      ant.nonInput = 'T';
   }
   else
   {
      // copy string into the ant.structions.
      strcpy(ant.instructions, argv[1]);
      ant.nonInput = 'F';
   }
   // start running
   start_visualisation(&ant);

   /*
      apply the rules when user click any keys.
      quite when user click q (not Q).
   */
   do
   {
      visualise_and_advance(&ant);
   }

   while (not_quit());

   end_visualisation();

   return 0;
}
