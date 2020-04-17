//
// Created by david on 27/03/2020.
//
#include <stdio.h>
#include "game_Io.h"


void print_board(square board[BOARD_SIZE][BOARD_SIZE])
{

    printf("\n****** The Board ******\n");
    printf("\n  1   2   3   4   5   6   7   8\n");  // prints number of each column

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
        printf("|  %d\n", i+1);   // prints edge of board and number of rows
    }
}

void make_move(square board[BOARD_SIZE][BOARD_SIZE], player players[PLAYERS_NUM])
{
    int a;
    while(1)
    {
        for (int i=0; i<PLAYERS_NUM; i++)
        {
            printf("\n%s's turn ", players[i].name);
            scanf("%d", &a);
        }

    }
}