#ifndef GAMECONSOLE_H
#define GAMECONSOLE_H


#include "chessprog.h"


#include "move.h"
#include "minimax.h"




int console(char board[BOARD_SIZE][BOARD_SIZE]);

void set_minimax_depth();

void set_game_mode();

void set_user_color();

int load(char board[BOARD_SIZE][BOARD_SIZE]);

void save_game(char board[BOARD_SIZE][BOARD_SIZE]);

int restart(char board[BOARD_SIZE][BOARD_SIZE]);

void set_place(char board[BOARD_SIZE][BOARD_SIZE]);

void start(char board[BOARD_SIZE][BOARD_SIZE]);

void game(char board[BOARD_SIZE][BOARD_SIZE]);

int computer_turn(char board[BOARD_SIZE][BOARD_SIZE], char* comp_color);

void user_turn(char board[BOARD_SIZE][BOARD_SIZE]);

int make_move_user(char board[BOARD_SIZE][BOARD_SIZE], char from[MAX_STR_LN], char to[MAX_STR_LN], char promotion[MAX_STR_LN]);


int check_if_valid_position(char x[50]);

int check_if_valid_input(char x[50]);




#endif