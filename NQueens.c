#include <stdio.h>
#define N 4

int board[N];

int isSafe(int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        if(board[i] == col ||
           board[i] - i == col - row ||
           board[i] + i == col + row)
            return 0;
    }
    return 1;
}

int solveNQueens(int row)
{
    if(row == N)
        return 1;

    for(int col = 0; col < N; col++)
    {
        if(isSafe(row, col))
        {
            board[row] = col;

            if(solveNQueens(row + 1))
                return 1;
        }
    }
    return 0;
}

void printBoard()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main()
{
    if(solveNQueens(0))
    {
        printf("Solution exists:\n");
        printBoard();
    }
    else
    {
        printf("No solution exists\n");
    }

    return 0;
}
