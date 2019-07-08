#ifndef MINIMAX_H
#define MINIMAX_H


#include "chessprog.h"



#include "move.h"

int calulate_best(char board[BOARD_SIZE][BOARD_SIZE]);

int initial_minimax(char board[BOARD_SIZE][BOARD_SIZE]);

int minimax_int(char board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, int maximizingPlayer);

int make_computer_move(char board[BOARD_SIZE][BOARD_SIZE], char move[MAX_STR_LN]);

void update_board_from_string(char board[BOARD_SIZE][BOARD_SIZE], char move[MAX_STR_LN]);

void reverse_update_board_from_string(char board[BOARD_SIZE][BOARD_SIZE], char move[MAX_STR_LN], char c);

char eaten_from_string(char board[BOARD_SIZE][BOARD_SIZE], char move[MAX_STR_LN]);

int get_board_score(char board[BOARD_SIZE][BOARD_SIZE], int comp_turn, int depth);


int k_on_board(char board[BOARD_SIZE][BOARD_SIZE]);

int K_on_board(char board[BOARD_SIZE][BOARD_SIZE]);

int start_minimax(char board[BOARD_SIZE][BOARD_SIZE]);

int minimax_pruning(char board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, int maximazingPlayer);

node* reorder_list(char board[BOARD_SIZE][BOARD_SIZE], node *head);

#endif