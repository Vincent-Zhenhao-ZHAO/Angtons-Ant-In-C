// header files
#include <stdlib.h>
#include <string.h>
#include "langton.h"

// Set the ants direction so that it turns left
void turn_left(struct ant *ant)
{
   // ^ -> <
   if (ant->direction == UP)
   {
      ant->direction = LEFT;
   }
   // v -> >
   else if (ant->direction == DOWN)
   {
      ant->direction = RIGHT;
   }
   // > -> ^
   else if (ant->direction == RIGHT)
   {
      ant->direction = UP;
   }
   // < -> v
   else if (ant->direction == LEFT)
   {
      ant->direction = DOWN;
   }
}

// Set the ants direction so that it turns right
void turn_right(struct ant *ant)
{
   // ^ -> >
   if (ant->direction == UP)
   {
      ant->direction = RIGHT;
   }
   // v -> <
   else if (ant->direction == DOWN)
   {
      ant->direction = LEFT;
   }
   // > -> v
   else if (ant->direction == RIGHT)
   {
      ant->direction = DOWN;
   }
   // < -> ^
   else if (ant->direction == LEFT)
   {
      ant->direction = UP;
   }
}
// Actually move the ant forward based on it's current direction
// Should only be called after turn_left or turn_right

/*
   y -> UP and Down -> Up: minus, Down: plus
   x -> Left and Right -> Left: minus, Right: plus
*/
void move_forward(struct ant *ant)
{

   if (ant->direction == UP)
   {
      ant->y -= 1;
   }
   else if (ant->direction == DOWN)
   {
      ant->y += 1;
   }
   else if (ant->direction == LEFT)
   {
      ant->x -= 1;
   }
   else if (ant->direction == RIGHT)
   {
      ant->x += 1;
   }
}

// Do not modify
// define four directions.
const char *direction_to_s(enum direction d)
{
   return UP == d ? "^" : DOWN == d ? "v"
                      : LEFT == d   ? "<"
                                    :
                                  /* else */ ">";
}

/*
   apply rules for different situation:

   Situation A: has user input(user rule) -> follow what user input

   Situation B: has not user input(user rule) -> follow BLACK and WHITE rule

*/
void apply_rule(enum colour *colour, struct ant *ant)
{
   /*
      doublecheck is to check if has input or not;
      this step is to ensure doublecheck has clear variable;

      nonInput is what we get in main.c;
      but if we run test.c, there is no nonInput value;
      in this case, we set doublecheck as T -> no input
   */
   ant->doublecheck = 'F';

   // if nonInput has input 'F', means has input
   if (ant->nonInput == 'F')
   {
      ant->doublecheck = 'F';
   }
   // otherwise, means no input
   else
   {
      ant->doublecheck = 'T';
   }

   // If non input, run Black and White rule:
   if (ant->doublecheck == 'T')
   {
      // When at a white square, turn 90° clockwise(right), flip the color of the square to black.
      if (*colour == WHITE)
      {
         turn_right(ant);
         //mark as Black
         *colour = BLACK;
      }
      // When at a black square, turn 90° counter-clockwise(left), flip the color of the square to white.
      else
      {
         turn_left(ant);
         *colour = WHITE;
      }
   }
   // If has input, run user rule(only accept L or R, if has other input will end the program):
   else if (ant->doublecheck == 'F')
   {
      /* 
         rules: where the instruction follows, we use it like a hashtable.
         maxinput: the number of rules(colours), cause colour starts from 0, so we do minus one in here.
      */
      char *rules = ant->instructions;
      int maxinput = strlen(rules) - 1;

      // if in this point, rule is R, then turn right.
      if (rules[*colour] == 'R')
      {
         turn_right(ant);
      }
      // if in this point, rule is L, then turn left.
      else if (rules[*colour] == 'L')
      {
         turn_left(ant);
      }
      // if input not L or R, then exit.
      else
      {
         exit(1);
      }
      /*
         change colour to next state before it moves
         when meet the maximum rules(colours), go back to 0.
      */
      if (*colour == maxinput)
      {
         *colour = 0;
      }
      else
      {
         *colour += 1;
      }
   }
}
