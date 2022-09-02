
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../ant.h"


// Test turn left by performing a full rotation of the ant
void test_turn_left()
{
    struct ant ant;
    ant.direction = RIGHT;
    turn_left(&ant);
    assert(ant.direction == UP);
    turn_left(&ant);
    assert(ant.direction == LEFT);
    turn_left(&ant);
    assert(ant.direction == DOWN);
    turn_left(&ant);
    assert(ant.direction == RIGHT);
}

// Test turn right by performing a full rotation of the ant
void test_turn_right()
{
    struct ant ant;
    ant.direction = RIGHT;
    turn_right(&ant);
    assert(ant.direction == DOWN);

    turn_right(&ant);
    assert(ant.direction == LEFT);
    turn_right(&ant);
    assert(ant.direction == UP);
    turn_right(&ant);
    assert(ant.direction == RIGHT);
}

// Test move forward for all 4 directions
void test_move_forward()
{
    struct ant ant;
    ant.x = 5;
    ant.y = 5;
    ant.direction = RIGHT;
    move_forward(&ant);
    assert(ant.x == 6 && ant.y == 5);
    ant.direction = LEFT;
    move_forward(&ant);
    assert(ant.x == 5 && ant.y == 5);
    ant.direction = UP;
    move_forward(&ant);
    assert(ant.x == 5 && ant.y == 4);
    ant.direction = DOWN;
    move_forward(&ant);
    assert(ant.x == 5 && ant.y == 5);
}

// Test apply rule
void test_apply_rule()
{
    struct ant ant;
    ant.x = 5;
    ant.y = 5;
    ant.direction = RIGHT;
    cell c = WHITE;
    apply_rule(&c, &ant);
    assert(ant.direction == DOWN);
    c = BLACK;
    apply_rule(&c, &ant);
    assert(ant.direction == RIGHT);
}

int main()
{
    test_turn_right();
    test_turn_left();
    test_move_forward();
    test_apply_rule();
}
