#ifndef langton_h
#define langton_h

// directions
enum direction { UP, DOWN, LEFT, RIGHT };

/* 
   ant's Properties
   x,y: position
   instructions: rules by user input
   direction: directions above
   nonInput: first if check input is None in main.c
   doublecheck: second check if nonInput is None in langton.c -> test.c use
*/
struct ant
{
   char x;
   char y;
   char instructions[26];
   enum direction direction;
   char nonInput;
   char doublecheck;
};

#define ant_is_at(y,x) ((y) == (((ant->y % max_y) + max_y) % max_y) && (x) == (((ant->x % max_x) + max_x) % max_x))

// coulour(state)
enum colour {WHITE,BLACK};

// define funtions
void turn_left(struct ant *ant);
void turn_right(struct ant *ant);
void move_forward(struct ant *ant);
const char* direction_to_s(enum direction d);
void apply_rule(enum colour *colour, struct ant *ant);
#endif
