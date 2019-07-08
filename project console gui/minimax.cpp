#include "stdafx.h"

#include "minimax.h"

int calulate_best(char board[BOARD_SIZE][BOARD_SIZE]){
	int comp_moves = 0, user_moves = 0;
	int white_moves = 0, black_moves = 0;
	int i, j, comp_turn=0;
	unsigned int counter = 0;
	int result = 1;

	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++){
			if (board[i][j] == WHITE_PAWN) white_moves += 3;
			else if (board[i][j] == WHITE_KNIGHT) white_moves += 8;
			else if (board[i][j] == WHITE_BISHOP) white_moves += 13;
			else if (board[i][j] == WHITE_ROOK) white_moves += 14;
			else if (board[i][j] == WHITE_QUEEN) white_moves += 27;
			else if (board[i][j] == WHITE_KING) white_moves += 8;
			else if (board[i][j] == BLACK_PAWN) black_moves += 3;
			else if (board[i][j] == BLACK_KNIGHT) black_moves += 8;
			else if (board[i][j] == BLACK_BISHOP) black_moves += 13;
			else if (board[i][j] == BLACK_ROOK) black_moves += 14;
			else if (board[i][j] == BLACK_QUEEN) black_moves += 27;
			else if (board[i][j] == BLACK_KING) black_moves += 8;
		}
	}

	if (strcmp(comp_color, "Black") == 0) {
		comp_moves = black_moves;
		user_moves = white_moves;
	}
	else {
		comp_moves = white_moves;
		user_moves = black_moves;
	}

	counter += comp_moves;

	while (1){
		if (comp_turn)
			counter *= comp_moves;
		else counter *= user_moves;
		comp_turn = (comp_turn + 1) % 2;
		if (counter <= 1000000) {
			result++;
		}
		else break;
	}

	return result;

}

int initial_minimax(char board[BOARD_SIZE][BOARD_SIZE]) {
	char new_board[BOARD_SIZE][BOARD_SIZE];
	char c = '\0';
	int r;
	node *moves = NULL, *head = NULL, *temp = NULL;



	int val, depth;
	char best_move[MAX_STR_LN] = "";
	int bestValue = INT_MIN;
	int alpha = INT_MIN, beta = INT_MAX;

	clear_board(new_board);

	if (minimax_depth == -1) {
		depth = calulate_best(board);
		if (depth < 4) depth = 4;
		/*depth = 5;*/
	}
	else depth = minimax_depth;

	make_new_board(board, new_board);



	if (strcmp(comp_color, "White") == 0) head = get_all_moves_white(board);
	else head = get_all_moves_black(board);

	head = reorder_list(board, head);

	moves = head;
	
	while (moves) {
		alpha = INT_MIN;
		beta = INT_MAX;



		c = eaten_from_string(new_board, moves->move);
		update_board_from_string(new_board, moves->move);


		
		val = minimax_int(new_board, depth - 1, alpha, beta, 0);
		

		if (val>bestValue){
			bestValue = val;
			strcpy(best_move, moves->move);
		}

		else if (val == bestValue){
			srand((unsigned int)time(NULL));
			r = rand() % 2;
			if (r){
				bestValue = val;
				strcpy(best_move, moves->move);
			}
		}
		reverse_update_board_from_string(new_board, moves->move, c);
		temp = moves;
		moves = moves->next;
		free(temp);

	}


	make_computer_move(board, best_move);
	/*free_linked_list(head);
	head = NULL;*/

	return 1;
}

int minimax_int(char board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, int maximizingPlayer) {
	char new_board[BOARD_SIZE][BOARD_SIZE];
	char c = ' ';
	int val = 0;
	node *moves = NULL, *head = NULL, *temp = NULL;

	clear_board(new_board);

	if (depth == 0) return get_board_score(board, maximizingPlayer, depth);

	if (maximizingPlayer) {
		if (strcmp(comp_color, "White") == 0) head = get_all_moves_white(board);
		else head = get_all_moves_black(board);
		if (head == NULL) return -1000;
	}
	else {
		if (strcmp(user_color, "White") == 0) head = get_all_moves_white(board);
		else head = get_all_moves_black(board);
		if (head == NULL) return 1000;
	}

	

	

	head = reorder_list(board, head);

	make_new_board(board, new_board);
	moves = head;

	if (maximizingPlayer) {    /*if comp*/
		
		while (moves) {


			c = eaten_from_string(new_board, moves->move);
			update_board_from_string(new_board, moves->move);



			val = minimax_int(new_board, depth - 1, alpha, beta, 0);
			alpha = max(alpha, val);


			reverse_update_board_from_string(new_board, moves->move, c);
			if (beta <= alpha) {
				free_linked_list(moves);
				head = NULL;
				break;
			}

			temp = moves;
			moves = moves->next;
			free(temp);


		}
		/*free_linked_list(head);
		head = NULL;*/
		return alpha;

	}

	else {     /*if user*/
		
		while (moves) {

			c = eaten_from_string(new_board, moves->move);
			update_board_from_string(new_board, moves->move);

			val = minimax_int(new_board, depth - 1, alpha, beta, 1);

			beta = min(beta, val);
			if (beta <= alpha){
				free_linked_list(moves);
				head = NULL;
				break;
			}
			reverse_update_board_from_string(new_board, moves->move, c);



			temp = moves;
			moves = moves->next;
			free(temp);



		}
		/*free_linked_list(head);
		head = NULL;*/
		return beta;

	}


}

int make_computer_move(char board[BOARD_SIZE][BOARD_SIZE], char move[MAX_STR_LN]) {


	printf("Computer: move ");
	printf("%s", move);
	printf("\n");
	update_board_from_string(board, move);

	return 1;
}



void update_board_from_string(char board[BOARD_SIZE][BOARD_SIZE], char move[MAX_STR_LN]) {
	char c;
	char promotion[MAX_STR_LN] = "";
	int from_col, from_row, to_col, to_row, len;

	len = strlen(move);

	from_col = move[1] - 'a';
	from_row = move[3] - '0' - 1;
	to_col = move[10] - 'a';
	to_row = move[12] - '0' - 1;
	c = board[from_col][from_row];
	board[from_col][from_row] = EMPTY;
	board[to_col][to_row] = c;

	if (len == 14) {
		if (c == 'm' && to_row == 7) {
			board[to_col][to_row] = 'q';
		}
		if (c == 'M' && to_row == 0) {
			board[to_col][to_row] = 'Q';
		}
	}
	else {
		memcpy(promotion, &move[15], len - 15);
		if (c == 'm' && strcmp(promotion, "queen") == 0) board[to_col][to_row] = 'q';
		else if (c == 'm' && strcmp(promotion, "rook") == 0) board[to_col][to_row] = 'r';
		else if (c == 'm' && strcmp(promotion, "knight") == 0) board[to_col][to_row] = 'n';
		else if (c == 'm' && strcmp(promotion, "bishop") == 0) board[to_col][to_row] = 'b';
		else if (c == 'M' && strcmp(promotion, "queen") == 0) board[to_col][to_row] = 'Q';
		else if (c == 'M' && strcmp(promotion, "rook") == 0) board[to_col][to_row] = 'R';
		else if (c == 'M' && strcmp(promotion, "knight") == 0) board[to_col][to_row] = 'N';
		else if (c == 'M' && strcmp(promotion, "bishop") == 0) board[to_col][to_row] = 'B';
	}

}

void reverse_update_board_from_string(char board[BOARD_SIZE][BOARD_SIZE], char move[MAX_STR_LN], char c) {
	int from_col, from_row, to_col, to_row;

	from_col = move[1] - 'a';
	from_row = move[3] - '0' - 1;
	to_col = move[10] - 'a';
	to_row = move[12] - '0' - 1;

	board[from_col][from_row] = board[to_col][to_row];
	board[to_col][to_row] = c;


}

char eaten_from_string(char board[BOARD_SIZE][BOARD_SIZE], char move[MAX_STR_LN]) {
	int to_col, to_row;

	to_col = move[10] - 'a';
	to_row = move[12] - '0' - 1;
	return board[to_col][to_row];

}

int get_board_score(char board[BOARD_SIZE][BOARD_SIZE], int comp_turn, int depth) {
	int i, j;
	node* head;
	char c;
	int score_white = 0, score_black = 0;

	if (depth == 0) {
		if (comp_turn) {
			if (strcmp(comp_color, "White") == 0) head = get_all_moves_white(board);
			else head = get_all_moves_black(board);
			if (head == NULL) return -1000;
			else free_linked_list(head);
		}
		else {
			if (strcmp(user_color, "White") == 0) head = get_all_moves_white(board);
			else head = get_all_moves_black(board);
			if (head == NULL) return 1000;
			else free_linked_list(head);
		}
	}

	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			c = board[j][i];
			if (c == EMPTY) continue;
			else if (c == 'm') score_white += 1;
			else if (c == 'b') score_white += 3;
			else if (c == 'n') score_white += 3;
			else if (c == 'r') score_white += 5;
			else if (c == 'q') score_white += 9;
			else if (c == 'k') score_white += 400;
			else if (c == 'M') score_black += 1;
			else if (c == 'B') score_black += 3;
			else if (c == 'N') score_black += 3;
			else if (c == 'R') score_black += 5;
			else if (c == 'Q') score_black += 9;
			else if (c == 'K') score_black += 400;

		}
	}

	if (strcmp(comp_color, "White") == 0)
		return score_white - score_black;
	return score_black - score_white;

}

int k_on_board(char board[BOARD_SIZE][BOARD_SIZE]) {
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			if (board[j][i] == 'k') return 1;
		}
	}
	return 0;
}

int K_on_board(char board[BOARD_SIZE][BOARD_SIZE]) {
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			if (board[j][i] == 'K') return 1;
		}
	}
	return 0;
}

node* reorder_list(char board[BOARD_SIZE][BOARD_SIZE], node *head){
	int from_col, from_row, to_col, to_row;
	node *tail = NULL, *new_head = NULL, *temp = NULL;

	while (head){
		temp = head;
		head = head->next;
		temp->next = NULL;
		from_col = temp->move[1] - 'a';
		from_row = temp->move[3] - '0' - 1;
		to_col = temp->move[10] - 'a';
		to_row = temp->move[12] - '0' - 1;

		if (new_head == NULL && tail == NULL) {
			new_head = temp;
			tail = temp;
		}

		else if ((check_if_pos_is_black(board[from_col][from_row]) && check_if_pos_is_white(board[to_col][to_row])) || (check_if_pos_is_white(board[from_col][from_row]) && check_if_pos_is_black(board[to_col][to_row])) || strlen(temp->move)>14) {
			temp->next = new_head;
			new_head = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}
	return new_head;
}




int start_minimax(char board[BOARD_SIZE][BOARD_SIZE]) {
	char new_board[BOARD_SIZE][BOARD_SIZE], eaten;
	node *head = NULL, *temp = NULL;
	int best_value = INT_MIN, val, r;
	char best_move[MAX_STR_LN] = "\0";




	if (strcmp(comp_color, "White") == 0) head = get_all_moves_white(board);
	else head = get_all_moves_black(board);



	clear_board(new_board);
	make_new_board(board, new_board);

	head = reorder_list(board, head);

	while (head) {
		temp = head;
		head = head->next;
		eaten = eaten_from_string(board, temp->move);
		update_board_from_string(new_board, temp->move);
		val = minimax_pruning(new_board, minimax_depth - 1, INT_MIN, INT_MAX, 0);
		/*printf("The move is : %s in depth:%d and the score is: %d\n", temp->move, minimax_depth - 1, val);*/
		if (val > best_value) {
			strcpy(best_move, temp->move);
			best_value = val;
		}

		else if (val == best_value){
			srand((unsigned int)time(NULL));
			r = rand() % 2;
			if (r){
				best_value = val;
				strcpy(best_move, temp->move);
			}
		}

		reverse_update_board_from_string(new_board, temp->move, eaten);
		free(temp);

	}

	make_computer_move(board, best_move);
	return 1;


}


int minimax_pruning(char board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, int maximazingPlayer) {
	char new_board[BOARD_SIZE][BOARD_SIZE], eaten;
	node *head = NULL, *temp = NULL;
	int val;




	if (maximazingPlayer) {
		if (strcmp(comp_color, "White") == 0) head = get_all_moves_white(board);
		else head = get_all_moves_black(board);
		if (head == NULL) return -1000;
	}
	else {
		if (strcmp(user_color, "White") == 0) head = get_all_moves_white(board);
		else head = get_all_moves_black(board);
		if (head == NULL) return 1000;
	}

	if (depth == 0) return get_board_score(board, maximazingPlayer, depth);

	make_new_board(board, new_board);

	head = reorder_list(board, head);


	if (maximazingPlayer) {
		while (head) {
			temp = head;
			head = head->next;
			eaten = eaten_from_string(new_board, temp->move);
			update_board_from_string(new_board, temp->move);
			val = minimax_pruning(new_board, depth - 1, alpha, beta, 0);
			/*printf("The move is : %s in depth:%d and the score is: %d\n", temp->move, depth - 1, val);*/
			alpha = max(alpha, val);
			reverse_update_board_from_string(new_board, temp->move, eaten);
			if (beta <= alpha) {
				free(temp);
				free_linked_list(head);
				return alpha;

			}
			free(temp);
		}
		return alpha;
	}
	else {
		while (head) {
			temp = head;
			head = head->next;
			eaten = eaten_from_string(new_board, temp->move);
			update_board_from_string(new_board, temp->move);
			val = minimax_pruning(new_board, depth - 1, alpha, beta, 1);
			/*printf("The move is : %s in depth:%d and the score is: %d\n", temp->move, depth - 1, val);*/
			beta = min(beta, val);
			if (beta <= alpha) {
				free(temp);
				free_linked_list(head);
				return beta;
			}
			reverse_update_board_from_string(new_board, temp->move, eaten);
			free(temp);
		}
		return beta;
	}

}