- Student Name: [Zhenhao Zhao]
- Student CIS ID: [cvhm34]

**Please ask any questions you have about the coursework in the message board under Assessment in LearnUltra. This will be used as a sort of FAQ, i.e. please check if your question has already been answered before posting.**

# Courswork 2
## Langton's Ant

![ant](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/CA3061-81k7.png/1024px-CA3061-81k7.png)

Langton's ant is a two-dimensional [universal Turing machine](https://web.mit.edu/manoli/turing/www/turing.html) that can demonstrate complex emergent behavior based on a very simple set of rules. First created by Chris Langton in 1986, Langton's ant runs on a square lattice of black and white cells. In this coursework, you will implement a generalisation of Langton's ant in C.

## Background

The original Langton's ant progresses by colouring squares on a plane either black or white. One square is first determined to be the "ant" arbitrarily. This ant can then travel in any of the four cardinal directions at each iteration (step) of the game. The movement of the ant is controlled by the following simple rules:

* When at a white square, turn 90° clockwise, flip the color of the square to black and then move forward one unit.
* When at a black square, turn 90° counter-clockwise, flip the color of the square to white and then move forward one unit.

Following these rules, the ant will move in simple symmetric patterns for the first few hundred iterations of the game, after which chaotic irregular patterns of black and white squares appear. Towards the end, the ant will start steadily moving away from the starting location in a diagonal corridor about 10 cells wide. The ant can then be conceptually moving away infinitely.

An extension to Langton's Ant involves more general *n*-state ants. This is also known as the multi-colour version of Langton's Ant. The squares can be in states 1 through *n* and for each state (sometimes demonstrated with different colours), "L" or "R" is used to indicate whether a left or right turn is taken by the ant. For instance, in LRRRRRLLR, the ant will turn left on visiting squares in states 1, 7 and 8 and will turn right on squares in states 2, 3, 4, 5, 6 and 9. 

When the ant arrives at an "L" square, it turns left and when it arrives at an "R" square, it turns right. After the ant has left a square at state *i*, the square's state changes to *i+1*.

Further details of this can be found in the corresponding paper (https://arxiv.org/pdf/math/9501233.pdf). You do not need this paper to solve the coursework, but you may find it interesting. In order to understand the problem, you may also want to view an online demonstration of Langton's ant at http://www.langtonant.com/

## Assignment

As part of this assignment, you will have to construct a dynamically-linked library libant.so which implements  Langton's ant, and a program ant that calls the library for all its key functionality.

- Your code should run on Linux. In particular, you should compile & test it on **Mira**. 
- You may not use any external libraries aside from [ncurses](https://linux.die.net/man/3/ncurses).

Your code should use the existing files and data structures already contained in the repository. You may add additional folder structure if you want, but it is not necessary. If you do ensure that the CI and Makefile continue to work or you will lose marks.

## Visualiser

The repository already contains functionality for visualising the result using the [ncurses](https://en.wikipedia.org/wiki/Ncurses) library. In order to use it you need to link it at compile time using -lncurses.

All functions relating to visualisation are contained in visualiser.c and visualiser.h. For the generalisation you will need to add additional "colors" (may be represented as letters) to the visualiser.

- Pressing any key (except q) will advance the ant and pressing "q" will close the window.

## Functionality

Fill in the empty functions provided in langton.c. Make sure to use the data-structures provided in langton.h. Marks will be lost if you do not use the enums and structs as given.

Since you cannot use infinite memory, you will implement the ant on a finite rectangular grid (the “universe”). One approach is to give the grid the topology of a torus: the grid wraps around, so if you go one row higher than the top row, you reach the bottom row, and if you go to the column one row to the leftmost column, you reach the rightmost column etc. Modify the macro `cell_at()` to achieve this behaviour.

**Hint**: Before you get started familiarise yourself with the existing functions and data-structures provided, particularly the main loop of the program. Do not try to get the full functionality running in one go. Build it up carefully, checking that the test for each function passes before moving to the next.

For the advanced functionality you may need to extend the existing data-structures and add additional functions.

Once you have implemented the functionality turn it into a dynamically linked library. You will need to link it at the appropriate points in the Makefile. Modify main.c and test.c to call your new library.

## Testing

The tests in test.c are run whenever you push to github by executing `make test`. Ensure that your Makefile contains a target `test` which compiles AND runs the tests. Each of the basic functions in langton.h are tested. We recommend (but don't require) that you add additional tests to ensure correctness of your solution.


## Submission specifications

- Add your name and CIS ID to this file.
- When you push to the project this will be automatically checked by github's CI. As long as `make test` has been written, if you see a small green check mark next to your commit everything is fine, if not, click on the red x to see what has gone wrong.
- You will need to write a Makefile for the project in Makefile. This makefile should ideally automate finding and linking files so that the addition of new files does not "break" the makefile. It should have the following options:
    - all: create an executable called **ant** that takes the variant of the game (e.g. LLRR) as the input and runs the game.
    - library: compile the dynamically-linked library libant.so
    - clean: remove all executables and library files
    - test: manually run the tests in test
  You may find this [Makefile Tutorial](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) helpful.

# Marking

The marks for this assignment will be awarded as follows: 

- **Basic functionality** of the program: **30**
    - This means that the basic two-color variant should run successfully and the ant should behave as expected.

- **Dynamically-linked library**: **10**
    - This refers to successfully creating a dynamically-linked library, called **libant.so** which implements Langton's Ant. The program "ant" should call this library for its key functionalities.

- **Makefile**: **10**
    - The Makefile should automate finding and linking files so that the addition of new files does not "break" the makefile. It should have the "all", "library", "clean" and "test" options, as set out in the "submission specifications" section

- **Code and documentation**: **20**
    - Clear, readable, well-documented (with sufficient comments) and well-presented program source code. Your name and CIS ID have been added to this file.

- **Arbitrary colours**: **30**
    - This more advanced portion of the assignment will have the program receive a string of Rs and Ls as the input (e.g. LRRRRRLLR) and your program should be able to generalise to *any* multi-colour variant of Langton's Ant described by this string.

**Total marks: 100**

## Plagiarism

You must not plagiarise your work. Automated software tools (e.g. https://theory.stanford.edu/~aiken/moss/) may be used to initially detect cases of potential source code plagiarism in this assignment which will include automatic code comparison with any available code online. Attempts to hide plagiarism by simply changing comments/variable names will be detected. You should make yourself aware of the Durham University policy on plagiarism.

## Deadline

The assignment must be submitted by deadline, which is **2pm (UK time) on 7th February 2022**.

**Reminder**: You must commit and push your final changes before the deadline.

Note that late submissions will be penalized following departmental policy.
