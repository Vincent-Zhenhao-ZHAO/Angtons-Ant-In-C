#ifndef visualiser_h
#define visualiser_h

#include "langton.h"
#include <stdbool.h>

// maximum of x and y.
static int max_x;
static int max_y;

// cell
typedef enum colour cell;

cell cell_under_ant(struct ant ant);

// function to start and process
void start_visualisation();

void visualise_and_advance();

// bool to end the program after enter q.
bool not_quit();

cell cell_at_fct(int y, int x);

// function to end the program.
void end_visualisation();

#endif
