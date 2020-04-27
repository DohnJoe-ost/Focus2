//
// Created by david on 27/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "game_Init.h"

void initialize_players(player players[PLAYERS_NUM])
{


    for (int i = 0; i < PLAYERS_NUM; i++)
    {
        printf("\nName: Enter player %d name: ", i);
        scanf("%s", &players[i].name);

        printf("\nColour: Press 1 for Red or 2 for Green: ", i);
        scanf("%d", &players[i].player_color);

        while (players[0].player_color == players[1].player_color)
        {
            printf("\nColour already chosen, select different colour: \n");
            scanf("%d", &players[1].player_color);
        }

    }

}


//Set Invalid Squares (where it is not possible to place stacks)
set_invalid(square * s){
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
set_empty(square * s){
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
set_red(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){

    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }


    }


}


struct square * push(int value, struct square *top){
    struct square *curr = top;
    top = malloc(sizeof(square));
    top->num_pieces = value;
    top->stack = curr;
    return top;
}

struct square * pop(struct square *top){
    struct square *curr = top;
    if(curr!=NULL){
        top = curr->stack;
        //printf("Stack Data: %d\n", curr->num_pieces);
        free(curr);
    }
    return top;
}


//void stack_size(square size[BOARD_SIZE][BOARD_SIZE], int a, int b, int c, int d)
//{
//
//
//    //pointer to the top of the stack
//    struct square *top = NULL;
//    //pointer to the current element of the stack
//    struct square *curr = NULL;
//
//    char column[4] = {'R', 'o', 'w', 's', '\0'};
//
//    printf("\n~~ Number of pieces in each square ~~\n\n  Columns  ");
//    printf("\n  0   1   2   3   4   5   6   7\n");  // prints number of each column
//
//
//    for(int i = 0; i < BOARD_SIZE; i++)
//    {
//        for (int j = 0; j < BOARD_SIZE; j++)
//        {
//            if(size[i][j].type == VALID)
//            {
//                if(size[i][j].stack == NULL)
//                    printf("|   ");
//
//                else{
//                    if (size[i][j].stack->p_color == GREEN)
//                    {
//                        top = push(1, top);
//
//                        if (size[a][b].type == VALID)
//                            top = pop(top);
//                        if (size[c][d].type == VALID)
//                            top = push(2, top);
//
//
//                        printf("| %d ", top->num_pieces);
//                    }
//                    else if (size[i][j].stack->p_color == RED)
//                    {
//                        top = push(1, top);
//
//                        if (size[a][b].type == VALID)
//                            top = pop(top);
//                        if (size[c][d].type == VALID)
//                            top = push(2, top);
//
//                        printf("| %d ", top->num_pieces);
//                    }
//                }
//            }
//            else
//                printf("| - ");
//        }
//        printf("|  %d   %c\n", i, column[i]);   // prints edge of board and number of rows
//
//    }
//
//
//}


void numb_pieces(square size[BOARD_SIZE][BOARD_SIZE], int a, int b, int c, int d)
{
    int numPiece[7];
    for(int i = 0; i <7; i++)  // initialize array to 0
    {
        numPiece[i] = 0;
    }
    printf("\n");



    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if(size[i][j].type == VALID)
            {
                if(size[i][j].stack == NULL)
                    printf("|   ");

                else{
                    if (size[i][j].stack->p_color == GREEN)
                    {
                        //size[i][j].number[i] = 1;

                        if (size[a][b].type == VALID)
                            size[a][b].number[i] = 0;
                        if (size[c][d].type == VALID)
                            size[c][d].number[i] = i+1;


                        printf("| %d ", size[i][j].number[i]);
                    }
                    else if (size[i][j].stack->p_color == RED)
                    {
                        //size[i][j].number[i] = 1;

                        if (size[a][b].type == VALID)
                            size[a][b].number[i] = 0;
                        if (size[c][d].type == VALID)
                            size[c][d].number[i] = i+1;

                        printf("| %d ", size[i][j].number[i]);
                    }
                }
            }
            else
                printf("| - ");
        }
        printf("|  %d\n", i);   // prints edge of board and number of rows

    }
}


/* This function places the first pieces onto
 * the board */

void first_pieces(square board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n");

    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j].type == VALID)
            {
                if(board[i][j].stack == NULL)
                    printf("|   ");

                else{
                    if (board[i][j].stack->p_color == GREEN)
                    {
                        board[i][j].number[i] = 1;



                        printf("| %d ", board[i][j].number[i]);
                    }
                    else if (board[i][j].stack->p_color == RED)
                    {
                        board[i][j].number[i] = 1;


                        printf("| %d ", board[i][j].number[i]);
                    }
                }
            }
            else
                printf("| - ");
        }
        printf("|  %d\n", i);   // prints edge of board and number of rows

    }
}

