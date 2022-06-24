#include <stdio.h>
#include <stdlib.h>

void printboard(int **board, int config);
void printsep(void);
void printmid(void);
void printnum(int **board, int row);

void printboard(int **board, int config)
{
    // config = 0, clean board
    // config = 1, current board
    if (config == 0)
    {
        int n = 0;
        while (n++ < 4)
        {
            printsep();
            printmid();
            printmid();
            printmid();
        }
        printsep();
    }
    else if (config == 1)
    {
        int n = 0;
        int row = 0;
        while (n++ < 4)
        {
            printsep();
            printmid();
            printnum(board, row++);
            printmid();
        }
        printsep();
    }
}

void printsep(void)
{
    printf("#------#------#------#------#\n");
}

void printmid(void)
{
    printf("|      |      |      |      |\n");
}

void printnum(int **board, int row)
{
    int col = 0;
    printf("|  %d  ",board[row][col++]);
    printf("|  %d  ",board[row][col++]);
    printf("|  %d  ",board[row][col++]);
    printf("|  %d  ",board[row][col]);
    printf("|\n");
}

int main()
{
    int **board;
	board = (int **) malloc (4 * sizeof(int *));
	for (int i = 0; i < 4; i++)
	{
		board[i] = (int *) malloc (4 * sizeof(int));
	}

    board[0][0] = 2;
    board[0][1] = 0;
    board[0][2] = 16;
    board[0][3] = 1024;

    board[1][0] = 2;
    board[1][1] = 2048;
    board[1][2] = 16;
    board[1][3] = 8;

    board[2][0] = 2;
    board[2][1] = 0;
    board[2][2] = 16;
    board[2][3] = 0;

    board[3][0] = 64;
    board[3][1] = 0;
    board[3][2] = 4;
    board[3][3] = 2;

    printboard(board, 1);
    return (0);
}
