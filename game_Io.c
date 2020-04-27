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
 * like to move onto other users piece and controls
 * the iterations of each turn */

void make_move(square board[BOARD_SIZE][BOARD_SIZE], player players[PLAYERS_NUM])
{
    int a, b, c, d;
    players->kept=18;  // each player has 18 pieces

    while(players->captured < 18)  // while number of pieces captured is less than 18, play game
    {
        for (int i=0; i<PLAYERS_NUM; i++)
        {
            printf("\n~~~~~~~~~~~~~~~\n%s's turn\n~~~~~~~~~~~~~~~\nState Row and Column of Piece to move:  ", players[i].name);
            printf("\nRow: ");
            scanf("%d", &a);
            printf("Column: ");
            scanf("%d", &b);

            if (board[a][b].type == INVALID)  // if user enters invalid or pieces thats not theirs, print error
            {
                printf("\nInvalid Square!\n");
            }
            if (board[a][b].play.player_color != players[i].player_color)
            {
                printf("\nWrong Colour!\n");
            }
            print_board(board);


            printf("\n~~~~~~~~~~~~~\n%s's turn\n~~~~~~~~~~~~~\nWhere do you want to move Piece to?:  ", players[i].name);
            printf("\nRow: ");
            scanf("%d", &c);
            printf("Column: ");
            scanf("%d", &d);

            players[i].captured++;  // increment captured pieces by 1
            players[i+1].kept--;

            printf("\n%d Pieces Captured\n", players[i].captured);
            printf("\n%d Pieces Kept\n", players[i].kept);



            if (board[c][d].type == INVALID)  // if user enters invalid or pieces thats not theirs, print error
            {
                printf("\nInvalid Square!\n");
            }
//            if (board[a][b].num_pieces == 1)
//            {
//                if (board[c][d].stack = (board[a+1][b].stack || board[a-1][b].stack || board[a][b+1].stack || board[a][b-1].stack))
//                {
//                    printf("\nCorrect Move");
//                    stack_size(board, a, b, c, d);
//
//                }
//                else
//                    {
//                        printf("\nCan Only Move Up, Down, Left Or Right");
//                    }
//            }


            //stack_size(board, a, b, c, d);#
            numb_pieces(board, a, b, c, d);
        }
        if (players->captured == 18)    // if player captures 18 pieces they win the game
        {
            printf("\n%s Has Won The Game!", players->name);
        }

    }
}
