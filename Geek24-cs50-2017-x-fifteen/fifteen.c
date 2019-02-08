/**
 * fifteen.c

CS 50

Chris Edwards
Beverly, MA
Dec 14, 2017

 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];
int zerox = 0;
int zeroy = 0;

// dimensions
int d;
int row;
int col;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void search();
void swap();

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}
////////////////////////////////////////////////////////////////

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(1000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
   int n = d*d;
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            if (d % 2 > 0){
                n--;
                board[i][j] = n;
            } else if (d % 2 < 1){
                     n--;
                    board[i][j] = n;
                    if (board[i][j] == 2){
                        board[i][j] = 1;
                        board[i][j+1] = 2;
                        return;
                    }
                }
            }
        }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
     for (int i = 0; i< d; i++){
        for (int j = 0; j<d; j++){

            if (board[i][j] == 0){
                printf("  _");
                zerox = i;
                zeroy = j;
            } else if (board[i][j] >= 10){
                printf("%3d", board[i][j]);
            } else {
                printf("%3d", board[i][j]);
            }


            if (j == d-1){
                printf("\n");

            }
        }
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
     // check if tile actually exists
     if (tile > d*d || tile < 1){
         return false;
     }
     // Linear search for the tile user gives us
     search(tile);

     // Once tile has been found see if blank tile is adjacent to it and swap positions.
   if (row - 1 >=0 && board[row-1][col] == 0){
       swap(&board[row][col], &board[zerox][zeroy]);
       return true;

   } if (row +1 < d && board[row+1][col] == 0){
        swap(&board[row][col], &board[zerox][zeroy]);
        return true;

   } if (col - 1 >= 0 && board[row][col-1] == 0){
       swap(&board[row][col], &board[zerox][zeroy]);
      return true;

   } if (col + 1 < d && board[row][col+1] == 0) {
       swap(&board[row][col], &board[zerox][zeroy]);
       return true;
   } else {
       return false;
   }

    // Check if adjacent tile is a legit tile, then check if is blank
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int counter = 1;
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            if (board[i][j]== counter){
                counter++;

            }

        }
    }
    if (counter == d*d && board[d-1][d-1] == 0){
        return true;
    } else {
    return false;
    }
}

void swap(int *a, int *b)
{
    /*This function swaps the inputs. Note this uses pointers, thus the value at the
    address of the variable being passed is changed*/
    int o = *a;
    *a = *b;
    *b = o;
}

void search(int tile){
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            if (tile == board[i][j]){
                row = i;
                col = j;
            } if (board[i][j] == 0){
                zerox = i;
                zeroy = j;
            }
        }
    }
}