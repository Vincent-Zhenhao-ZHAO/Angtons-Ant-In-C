#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "visualiser.h"

/* set the grid boundry
   main idea: when x or y out of the boundry(lower than 0 or bigger than maximum), do module(x or y) base on the maximum x or y.
   the idea to do module in c programming is to use a formula on website:
   website: https://stackoverflow.com/questions/3417183/modulo-of-negative-numbers
   formula: ((i % i_max) + i_max) % i_max
   orginal formula for boundry: y*max_x + x -> y: (((y % max_y) + max_y) % max_y), x: ((x % max_x) + max_x) % max_x)
*/ 

#define cell_at(y,x) cells[(((x % max_x) + max_x) % max_x) + (((y % max_y) + max_y) % max_y)*max_x]
#define cell_under_ant cell_at(ant->y, ant->x)
cell *cells;

/* 
   start to setup visulisation:
   set postion of ant at (max_x/2,max_y/2)
   set default direction as Right
*/
void start_visualisation(struct ant* ant) {
   setlocale(LC_ALL, "");
   initscr();
   curs_set(FALSE);
   max_x = getmaxx(stdscr);
   max_y = getmaxy(stdscr);
   cells = calloc(max_y*max_x, sizeof(cell));
   ant->x = max_x/2;
   ant->y = max_y/2;
   ant->direction = RIGHT;
}

/*
   hashtable: find the corresponding letter in this state in string type.
   currentStateAsString[2] -> char to represent the string.
   baseState is 64 is because 65 = A and we added one before.
   offset is where state we are.
   baseState + offset -> which letter should be presented
   currentStateAsString -> ['A','\0'] -> string
*/
char currentStateAsString[2];

char* hashtable(cell offset) {

   char baseState = 64;

   char currentState = baseState + offset;

   currentStateAsString[0] = currentState;
   currentStateAsString[1] = '\0';

   return currentStateAsString;

}
// apply the rule and print letter in the grid.
void visualise_and_advance(struct ant* ant) {
      /* Draw cells and ant */
      for (int y=0; y<max_y; y++)
      {
         for (int x=0; x<max_x; x++)
         {
            mvprintw(y,x,
               ant_is_at(y,x)
                 ? direction_to_s(ant->direction)
                 : cell_at(y,x)
                    ? hashtable(cell_at(y,x))
                    : " " // print blank when colour(state) is 0.
            );
         }
      }
      refresh();
      
      /* Advance to next step */
      // apply rule -> turn around + change colour
      apply_rule(&cell_under_ant, ant);
      // we move forward after each turned.
      move_forward(ant);
}

// Check if the user has input "q" to quit
bool not_quit() {
   return 'q' != getch();
}
// end the program.
void end_visualisation() {
   free(cells);
   endwin();
}

