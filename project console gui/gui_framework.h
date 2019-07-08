#ifndef GUIFRAMEWORK_H
#define GUIFRAMEWORK_H
#include "chessprog.h"
#include "game_console.h"
#include "move.h"
#include "minimax.h"

#define num_of_slots 10


#define W_PAWN_W clip[22]
#define W_PAWN_B clip[20]
#define B_PAWN_W clip[21]
#define B_PAWN_B clip[23]

#define W_BISHOP_W clip[1]
#define W_BISHOP_B clip[2]
#define B_BISHOP_W clip[5]
#define B_BISHOP_B clip[0]

#define W_ROOK_W clip[10]
#define W_ROOK_B clip[11]
#define B_ROOK_W clip[8]
#define B_ROOK_B clip[9]

#define W_KNIGHT_W clip[18]
#define W_KNIGHT_B clip[19]
#define B_KNIGHT_W clip[17]
#define B_KNIGHT_B clip[16]

#define W_QUEEN_W clip[14]
#define W_QUEEN_B clip[15]
#define B_QUEEN_W clip[13]
#define B_QUEEN_B clip[12]

#define W_KING_W clip[3]
#define W_KING_B clip[4]
#define B_KING_W clip[7]
#define B_KING_B clip[6]

int gui(char board[BOARD_SIZE][BOARD_SIZE]);

void draw_board(char board[BOARD_SIZE][BOARD_SIZE]);

void print_white_squer(char piece, int i, int j);

void print_black_squer(char piece, int i, int j);

/*0 is black and 1 in white*/
int get_squer_color(int i, int j);

void set_main_menu(char board[BOARD_SIZE][BOARD_SIZE]);


void set_load_game(char board[BOARD_SIZE][BOARD_SIZE]);

void set_slots();

void set_player_selection(char board[BOARD_SIZE][BOARD_SIZE]);

void draw_setting_screen(char board[BOARD_SIZE][BOARD_SIZE]);

void set_save(char board[BOARD_SIZE][BOARD_SIZE]);

void choose_promotion(char prom[MAX_STR_LN]);

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);

void apply_surface2(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);

int init();

int load_files();

void clean_up();

void set_clip();


void set_setting(char board[BOARD_SIZE][BOARD_SIZE]);

SDL_Surface *load_image(char* filename);

void draw_mate(char board[BOARD_SIZE][BOARD_SIZE]);

void draw_check(char board[BOARD_SIZE][BOARD_SIZE]);

void draw_invalid_move(char board[BOARD_SIZE][BOARD_SIZE]);

void draw_not_your_piece(char board[BOARD_SIZE][BOARD_SIZE]);

void draw_empty_square(char board[BOARD_SIZE][BOARD_SIZE]);

void draw_not_in_board(char board[BOARD_SIZE][BOARD_SIZE]);


void game2(char board[BOARD_SIZE][BOARD_SIZE]);

void user_turn2(char board[BOARD_SIZE][BOARD_SIZE]);

int computer_turn2(char board[BOARD_SIZE][BOARD_SIZE], char* comp_color);

int make_move_user2(char board[BOARD_SIZE][BOARD_SIZE], char from[MAX_STR_LN], char to[MAX_STR_LN], char promotion[MAX_STR_LN]);

void restart2(char board[BOARD_SIZE][BOARD_SIZE]);

void save_game_gui(char board[BOARD_SIZE][BOARD_SIZE], char slot[MAX_STR_LN]);

int load2(char board[BOARD_SIZE][BOARD_SIZE], char x[200]);



int load2(char board[BOARD_SIZE][BOARD_SIZE], char str[200]);


void start_game(char board[BOARD_SIZE][BOARD_SIZE]);



extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int SCREEN_BPP;
extern const int def_x;
extern const int def_y;
extern int tot;
extern int second_click;


#endif