#include "print.c"

void printboard(int **board, int config);
void horizontal(int **board, int state); // left right
void vertical(int **board, int state); // up down

void horizontal(int **board, int state)
{
    int row = 0;
    int col = 0;
    int dir;

    if (state == 0) // left
        dir = 1;
    else if (state == 1) // right
    {
        dir = -1;
    }
    while (row < 4)
    {
        while (col < 3)
        {
            if (board[row][col] != board[row][col + dir] && board[row][col + dir] != 0)
            {
                col++;
            }
            else if (board[row][col + dir] == 0)
            {
                board[row][col + dir] = board[row][col];
                board[row][col] = 0;
            }
            else if (board[row][col] == board[row][col + dir])
            {
                board[row][col + dir] *= 2;
                board[row][col] = 0;
                while (col + dir != 3)
                {
                    board[row][col + dir] = board[row][col];
                    board[row][col] = 0;
                    col++;
                }
                break;
            }
            col++;
        }
        row++;
        col = 0;
    }
}

void vertical(int **board, int state)
{

}

int main()
{
    int **board;
    board = (int **) malloc (4 * sizeof(int *)); //malloc array of pointers
    for (int i = 0; i < 4; i++)
    {
        board[i] = (int *) malloc (4 * sizeof(int)); //malloc pointers
    }

    board[0][0] = 8;
    board[0][1] = 4;
    board[0][2] = 2;
    board[0][3] = 2;

    board[1][0] = 2;
    board[1][1] = 2;
    board[1][2] = 4;
    board[1][3] = 8;

    board[2][0] = 8;
    board[2][1] = 0;
    board[2][2] = 8;
    board[2][3] = 0;

    board[3][0] = 64;
    board[3][1] = 2;
    board[3][2] = 0;
    board[3][3] = 64;
    printf("before\n");
    printboard(board, 1);
    horizontal(board, 0);
    printf("after\n");
    printboard(board, 1);
    return (0);
}
