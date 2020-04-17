// Created by David Skerritt

#include <stdio.h>
#include "game_Io.h"


void print_board(square board[BOARD_SIZE][BOARD_SIZE])
{

    printf("\n****** The Board ******\n");
    printf("\n  0   1   2   3   4   5   6   7\n");  // prints number of each column

    for(int i = 0; i < BOARD_SIZE; i ++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j].type == VALID)
            {
                if(board[i][j].stack == NULL)
                    printf("|   ");

                else{
                    if (board[i][j].stack->p_color == GREEN)
                        printf("| G ");
                    else printf("| R ");
                }
            }
            else
                printf("| - ");
        }
        printf("|  %d\n", i);   // prints edge of board and number of rows
    }
}

/* This function asks users what piece they would
 * like to move onto other users piece */

void make_move(square board[BOARD_SIZE][BOARD_SIZE], player players[PLAYERS_NUM])
{
    int a, b, c, d;

    while(1)
    {
        for (int i=0; i<PLAYERS_NUM; i++)
        {
            printf("\n%s's turn\nState Row and Column of Piece to move:  ", players[i].name);
            printf("\nRow: ");
            scanf("%d", &a);
            printf("Column: ");
            scanf("%d", &b);

            if (board[a][b].type == INVALID)  // if user enters invalid or pieces thats not theirs, print error
            {
                printf("\nInvalid Square!\n");
            }
//            if (board[a][b].colour != players->player_color)
//            {
//                printf("\nWrong Colour!\n");
//            }
            print_board(board);


            printf("\n%s's turn\nWhere do you want to move Piece to?:  ", players[i].name);
            printf("\nRow: ");
            scanf("%d", &c);
            printf("Column: ");
            scanf("%d", &d);

            if (board[c][d].type == INVALID)  // if user enters invalid or pieces thats not theirs, print error
            {
                printf("\nInvalid Square!\n");
            }

            stack_size(board, a, b, c, d);





        }

    }
}
