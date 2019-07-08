#ifndef MOVE_H
#define MOVE_H


#include "chessprog.h"



node* get_all_moves_black(char board[BOARD_SIZE][BOARD_SIZE]);




node* get_all_moves_white(char board[BOARD_SIZE][BOARD_SIZE]);




node* get_moves_m(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color);


node* get_moves_M(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color);


node* get_moves_b(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color);


node* get_moves_r(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color);


node* get_moves_n(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color);



node* get_moves_q(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color);



node* get_moves_k(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color);



int check_if_white_in_check(char board[BOARD_SIZE][BOARD_SIZE]);


int check_if_black_in_check(char board[BOARD_SIZE][BOARD_SIZE]);


int check_if_white_in_check_from_M(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);


int check_if_white_in_check_from_R(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);


int check_if_white_in_check_from_B(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);


int check_if_white_in_check_from_N(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);


int check_if_white_in_check_from_Q(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);


int check_if_white_in_check_from_K(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);


int check_if_black_in_check_from_m(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);


int check_if_black_in_check_from_r(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);


int check_if_black_in_check_from_b(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);


int check_if_black_in_check_from_n(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);


int check_if_black_in_check_from_q(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);


int check_if_black_in_check_from_k(char board[BOARD_SIZE][BOARD_SIZE], int col, int row);

void print_moves(node* head);

void check_get_moves(char board[BOARD_SIZE][BOARD_SIZE]);

int k_on_board(char board[BOARD_SIZE][BOARD_SIZE]);

int K_on_board(char board[BOARD_SIZE][BOARD_SIZE]);



#endif