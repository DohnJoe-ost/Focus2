//
// Created by david on 27/03/2020.
//
#include <stdio.h>
#include "game_IO.h"


void print_board(square board[BOARD_SIZE][BOARD_SIZE])
{

    printf("\n****** The Board ******\n");

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
        printf("|\n");
    }
}