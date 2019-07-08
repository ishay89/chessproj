#ifndef CHESSPROG_H
#define CHESSPROG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#include "SDL.h"


#define WHITE_PAWN 'm'
#define BLACK_PAWN 'M'
#define WHITE_BISHOP 'b'
#define BLACK_BISHOP 'B'
#define WHITE_ROOK 'r'
#define BLACK_ROOK 'R'
#define WHITE_KNIGHT 'n'
#define BLACK_KNIGHT 'N'
#define WHITE_QUEEN 'q'
#define BLACK_QUEEN 'Q'
#define WHITE_KING 'k'
#define BLACK_KING 'K'
#define EMPTY ' '


#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))


#define BOARD_SIZE 8
#define MAX_STR_LN 50



#define WRONG_MINIMAX_DEPTH "Wrong value for minimax depth. The value should be between 1 to 4\n"
#define WRONG_MINIMAX_FORMAT "Wrong format for minimax depth. The second argument should be best or depth\n"
#define WRONG_GAME_MODE "Wrong game mode\n"
#define WRONG_POSITION "Invalid position on the board\n"
#define NO_DICS "The specified position does not contain your piece\n"
#define ILLEGAL_COMMAND "Illegal command, please try again\n"
#define ILLEGAL_MOVE "Illegal move\n"
#define WROND_BOARD_INITIALIZATION "Wrong board initialization\n"
#define perror_message(func_name) (perror("Error: standard function %s has failed", func_name));
#define print_message(message) (printf("%s", message));

typedef struct node_t{
	char move[MAX_STR_LN];
	struct node_t* next;
} node;




int main(int argc, char* args[]);

int console(char board[BOARD_SIZE][BOARD_SIZE]);

int gui(char board[BOARD_SIZE][BOARD_SIZE]);

void clear_board(char board[BOARD_SIZE][BOARD_SIZE]);

void print_line();

void print_board_(char board[BOARD_SIZE][BOARD_SIZE]);

void init_board_(char board[BOARD_SIZE][BOARD_SIZE]);

void rm(char new_board[BOARD_SIZE][BOARD_SIZE], int col, int row);

int file_exist(char* str);

void make_new_board(char old_board[BOARD_SIZE][BOARD_SIZE], char new_board[BOARD_SIZE][BOARD_SIZE]);

int check_if_pos_is_black(char c);

int check_if_pos_is_white(char c);

node* make_new_node();

void alloc_check(const void *pointer);


void free_linked_list(node* head);


extern int minimax_depth;
extern char* user_color;
extern char* comp_color;
extern char* curr_turn;
extern unsigned int game_still_on;
extern unsigned int game_mode;


#endif
