//
// Created by david on 27/03/2020.
//

#ifndef PROJECT2_GAME_INIT_H
#define PROJECT2_GAME_INIT_H

#endif //PROJECT2_GAME_INIT_H


#define BOARD_SIZE 8
#define PLAYERS_NUM 2

//colors that a piece can have
typedef enum color {
    RED,
    GREEN
}color;


// Square types
//INVALID: squares that are on the sides and where no piece can be placed
//VALID: squares where it is possible to place a piece or a stack
typedef enum square_type {
    VALID,
    INVALID
}square_type;


//Player
typedef struct player{
    //the color associated with the player
    color player_color;

    char name[20];

    int captured;

    int kept;

}player;


// A piece
typedef struct piece {
    //the color associated with a piece
    color p_color;

    // This is a pointer to the next pieces
    // to create a stack. For this lab you do not have to think too much about it.
    struct piece * next;

}piece;


// A Square of the board
typedef struct square {

    square_type type;       // type of the square (VALID/INVALID)

    piece * stack;      //the piece or the top piece on the stack

    int num_pieces;    //number of pieces on the square

}square;



//Function to create the players
void initialize_players(player players[PLAYERS_NUM]);

//Function to create the board
void initialize_board(square board[BOARD_SIZE][BOARD_SIZE]);


void stack_size(piece size[BOARD_SIZE]);


