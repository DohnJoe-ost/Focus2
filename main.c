#include <stdio.h>

#include "game_Io.h"



int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    print_board(board);

    stack_size(board);

    make_move(board, players);

    return 0;
}


