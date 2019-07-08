#include "stdafx.h"

#include "move.h"


/*if has no moves returns NULL*/
node* get_all_moves_black(char board[BOARD_SIZE][BOARD_SIZE]) {
	char c;
	int i, j;
	node* head = NULL;
	node* temp = NULL;
	node* curr = NULL;

	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			if (check_if_pos_is_black(board[j][i])){
				c = board[j][i];
				if (c == 'M') curr = get_moves_M(board, j, i, "Black");
				else if (c == 'B') curr = get_moves_b(board, j, i, "Black");
				else if (c == 'R') curr = get_moves_r(board, j, i, "Black");
				else if (c == 'N') curr = get_moves_n(board, j, i, "Black");
				else if (c == 'Q') curr = get_moves_q(board, j, i, "Black");
				else if (c == 'K') curr = get_moves_k(board, j, i, "Black");

				if (head == NULL && curr != NULL) {
					head = curr;
					temp = head;
				}

				else if (curr != NULL && head != NULL) {
					while (temp->next != NULL && strcmp(temp->next->move, " "))
						temp = temp->next;
					free(temp->next);
					temp->next = curr;
				}

				else {
					free(curr);
					curr = NULL;
				}
			}
		}
	}

	return head;

}



/*if has no moves returns NULL*/
node* get_all_moves_white(char board[BOARD_SIZE][BOARD_SIZE]) {
	char c;
	int i, j;
	node* head = NULL;
	node* temp = NULL;
	node* curr = NULL;

	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			if (check_if_pos_is_white(board[j][i])){
				c = board[j][i];
				if (c == 'm') curr = get_moves_m(board, j, i, "White");
				else if (c == 'b') curr = get_moves_b(board, j, i, "White");
				else if (c == 'r') curr = get_moves_r(board, j, i, "White");
				else if (c == 'n') curr = get_moves_n(board, j, i, "White");
				else if (c == 'q') curr = get_moves_q(board, j, i, "White");
				else if (c == 'k') curr = get_moves_k(board, j, i, "White");

				if (head == NULL && curr != NULL) {
					head = curr;
					temp = head;
				}

				else if (curr != NULL && head != NULL) {
					while (temp->next != NULL && strcmp(temp->next->move, " "))
						temp = temp->next;
					free(temp->next);
					temp->next = curr;
				}

				else {
					free(curr);
					curr = NULL;
				}

			}
		}
	}

	return head;
}



/*if has no moves returns null*/
node* get_moves_m(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color){
	char new_board[BOARD_SIZE][BOARD_SIZE];
	char c, eaten;
	node* head = NULL, *curr = NULL;

	clear_board(new_board);

	head = make_new_node();
	curr = head;
	c = board[col][row];

	make_new_board(board, new_board);
	rm(new_board, col, row);

	if (row + 1 < 8) {             /*check if can go up*/
		eaten = new_board[col][row + 1];
		new_board[col][row + 1] = c;
		if (board[col][row + 1] == EMPTY && !check_if_white_in_check(new_board)){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' + 1);
			curr->next = make_new_node();
			curr = curr->next;
			if (row + 1 == 7) {
				sprintf(curr->move, "<%c,%c> to <%c,%c> queen", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> bishop", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> rook", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> knight", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
			}
		}
		rm(new_board, col, row + 1);
		new_board[col][row + 1] = eaten;

	}

	if (col + 1 < 8 && row + 1 < 8) {
		eaten = new_board[col + 1][row + 1];
		new_board[col + 1][row + 1] = c;         /*check if can eat up+right*/
		if (check_if_pos_is_black(board[col + 1][row + 1]) && !check_if_white_in_check(new_board)){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' + 1);
			curr->next = make_new_node();
			curr = curr->next;
			if (row + 1 == 7) {
				sprintf(curr->move, "<%c,%c> to <%c,%c> queen", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> bishop", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> rook", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> knight", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
			}
		}
		rm(new_board, col + 1, row + 1);
		new_board[col + 1][row + 1] = eaten;
	}

	if (col - 1 >= 0 && row + 1 < 8) {
		eaten = new_board[col - 1][row + 1];
		new_board[col - 1][row + 1] = c;          /*check if can eat up+left*/
		if (check_if_pos_is_black(board[col - 1][row + 1]) && !check_if_white_in_check(new_board)){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' + 1);
			curr->next = make_new_node();
			curr = curr->next;
			if (row + 1 == 7) {
				sprintf(curr->move, "<%c,%c> to <%c,%c> queen", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> bishop", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> rook", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> knight", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' + 1);
				curr->next = make_new_node();
				curr = curr->next;
			}
		}
		rm(new_board, col - 1, row + 1);
		new_board[col - 1][row + 1] = eaten;
	}

	if (strcmp(head->move, " ") == 0) {
		free(head);
		head = NULL;
	}

	else {
		curr = head;
		while (strcmp(curr->next->move, " "))
			curr = curr->next;
		free(curr->next);
		curr->next = NULL;
	}

	return head;

}


/*if has no moves returns null*/
node* get_moves_M(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color){
	char new_board[BOARD_SIZE][BOARD_SIZE];
	char c, eaten;
	node* head = NULL, *curr = NULL;

	clear_board(new_board);

	head = make_new_node();
	curr = head;
	c = board[col][row];

	make_new_board(board, new_board);
	rm(new_board, col, row);
	if (row - 1 >= 0){
		eaten = new_board[col][row - 1];
		new_board[col][row - 1] = c;           /*check if can go down*/
		if (board[col][row - 1] == EMPTY && !check_if_black_in_check(new_board)){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' - 1);
			curr->next = make_new_node();
			curr = curr->next;
			if (row - 1 == 0) {
				sprintf(curr->move, "<%c,%c> to <%c,%c> queen", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> bishop", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> rook", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> knight", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
			}
		}
		rm(new_board, col, row - 1);
		new_board[col][row - 1] = eaten;
	}
	if (row - 1 >= 0 && col + 1<8){
		eaten = new_board[col + 1][row - 1];
		new_board[col + 1][row - 1] = c;           /*check if can eat down+right*/
		if (check_if_pos_is_white(board[col + 1][row - 1]) && !check_if_black_in_check(new_board)){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' - 1);
			curr->next = make_new_node();
			curr = curr->next;
			if (row - 1 == 0) {
				sprintf(curr->move, "<%c,%c> to <%c,%c> queen", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> bishop", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> rook", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> knight", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
			}
		}
		rm(new_board, col + 1, row - 1);
		new_board[col + 1][row - 1] = eaten;
	}

	if (col - 1 >= 0 && row - 1 >= 0){
		eaten = new_board[col - 1][row - 1];
		new_board[col - 1][row - 1] = c;                /*check if can eat down+left*/
		if (check_if_pos_is_white(board[col - 1][row - 1]) && !check_if_white_in_check(new_board)){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' - 1);
			curr->next = make_new_node();
			curr = curr->next;
			if (row - 1 == 0) {
				sprintf(curr->move, "<%c,%c> to <%c,%c> queen", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> bishop", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> rook", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
				sprintf(curr->move, "<%c,%c> to <%c,%c> knight", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' - 1);
				curr->next = make_new_node();
				curr = curr->next;
			}
		}
		rm(new_board, col - 1, row - 1);
		new_board[col - 1][row - 1] = eaten;
	}

	if (strcmp(head->move, " ") == 0) {
		free(head);
		head = NULL;
	}

	else {
		curr = head;
		while (strcmp(curr->next->move, " "))
			curr = curr->next;
		free(curr->next);
		curr->next = NULL;
	}

	return head;

}


/*if has no moves returns null*/
node* get_moves_b(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color){
	char new_board[BOARD_SIZE][BOARD_SIZE], c, eaten;
	int i;
	node* head = NULL, *curr = NULL;

	clear_board(new_board);

	head = make_new_node();
	curr = head;

	c = board[col][row];
	make_new_board(board, new_board);
	rm(new_board, col, row);

	for (i = 1; i < BOARD_SIZE; i++) {        /*check if can go up+right*/
		if (col + i>7 || row + i > 7) break;
		else if ( (strcmp(color, "White") == 0 && check_if_pos_is_white(board[col + i][row + i])) || (strcmp(color, "Black") == 0 && check_if_pos_is_black(board[col + i][row + i]))) break;
		eaten = new_board[col + i][row + i];
		new_board[col + i][row + i] = c;
		if (strcmp(color, "Black") == 0 && check_if_pos_is_white(board[col + i][row + i]) && !check_if_black_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + i, row + 1 + '0' + i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col + i][row + i] = eaten;
			break;

		}
		else if (strcmp(color, "White") == 0 && check_if_pos_is_black(board[col + i][row + i]) && !check_if_white_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + i, row + 1 + '0' + i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col + i][row + i] = eaten;
			break;
		}
		else if ((strcmp(color, "White") == 0 && !check_if_white_in_check(new_board)) || (strcmp(color, "Black") == 0 && !check_if_black_in_check(new_board))){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + i, row + 1 + '0' + i);
			curr->next = make_new_node();
			curr = curr->next;


		}
		new_board[col + i][row + i] = eaten;
	}

	for (i = 1; i < BOARD_SIZE; i++) {     /*check if can go up+left*/
		if (col - i < 0 || row + i > 7) break;
		else if ( (strcmp(color, "White") == 0 && check_if_pos_is_white(board[col - i][row + i])) || (strcmp(color, "Black") == 0 && check_if_pos_is_black(board[col - i][row + i]))) break;
		eaten = new_board[col - i][row + i];
		new_board[col - i][row + i] = c;
		if (strcmp(color, "Black") == 0 && check_if_pos_is_white(board[col - i][row + i]) && !check_if_black_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - i, row + 1 + '0' + i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col - i][row + i] = eaten;
			break;

		}
		else if (strcmp(color, "White") == 0 && check_if_pos_is_black(board[col - i][row + i]) && !check_if_white_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - i, row + 1 + '0' + i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col - i][row + i] = eaten;
			break;
		}
		else if ((strcmp(color, "White") == 0 && !check_if_white_in_check(new_board)) || (strcmp(color, "Black") == 0 && !check_if_black_in_check(new_board))){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - i, row + 1 + '0' + i);
			curr->next = make_new_node();
			curr = curr->next;


		}
		new_board[col - i][row + i] = eaten;
	}

	for (i = 1; i < BOARD_SIZE; i++) {          /*check if can go down+left*/
		if (col - i < 0 || row - i < 0) break;
		else if ( (strcmp(color, "White") == 0 && check_if_pos_is_white(board[col - i][row - i])) || (strcmp(color, "Black") == 0 && check_if_pos_is_black(board[col - i][row - i]))) break;
		eaten = new_board[col - i][row - i];
		new_board[col - i][row - i] = c;
		if (strcmp(color, "Black") == 0 && check_if_pos_is_white(board[col - i][row - i]) && !check_if_black_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - i, row + 1 + '0' - i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col - i][row - i] = eaten;
			break;

		}
		else if (strcmp(color, "White") == 0 && check_if_pos_is_black(board[col - i][row - i]) && !check_if_white_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - i, row + 1 + '0' - i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col - i][row - i] = eaten;
			break;
		}
		else if ((strcmp(color, "White") == 0 && !check_if_white_in_check(new_board)) || (strcmp(color, "Black") == 0 && !check_if_black_in_check(new_board))){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - i, row + 1 + '0' - i);
			curr->next = make_new_node();
			curr = curr->next;


		}
		new_board[col - i][row - i] = eaten;
	}

	for (i = 1; i < BOARD_SIZE; i++) {     /*check if can go down+right*/
		if (col + i > 7 || row - i < 0) break;
		else if ((strcmp(color, "White") == 0 && check_if_pos_is_white(board[col + i][row - i])) || (strcmp(color, "Black") == 0 && check_if_pos_is_black(board[col + i][row - i]))) break;
		eaten = new_board[col + i][row - i];
		new_board[col + i][row - i] = c;
		if (strcmp(color, "Black") == 0 && check_if_pos_is_white(board[col + i][row - i]) && !check_if_black_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + i, row + 1 + '0' - i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col + i][row - i] = eaten;
			break;

		}
		else if (strcmp(color, "White") == 0 && check_if_pos_is_black(board[col + i][row - i]) && !check_if_white_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + i, row + 1 + '0' - i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col + i][row - i] = eaten;
			break;
		}
		else if ((strcmp(color, "White") == 0 && !check_if_white_in_check(new_board)) || (strcmp(color, "Black") == 0 && !check_if_black_in_check(new_board))){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + i, row + 1 + '0' - i);
			curr->next = make_new_node();
			curr = curr->next;


		}
		new_board[col + i][row - i] = eaten;
	}


	if (strcmp(head->move, " ") == 0) {
		free(head);
		head = NULL;
	}

	else {
		curr = head;
		while (strcmp(curr->next->move, " "))
			curr = curr->next;
		free(curr->next);
		curr->next = NULL;
	}



	return head;

}


/*if has no moves returns null*/
node* get_moves_r(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color){
	char new_board[BOARD_SIZE][BOARD_SIZE], c, eaten;
	int i;
	node* head = NULL, *curr = NULL;

	clear_board(new_board);

	head = make_new_node();
	curr = head;
	c = board[col][row];
	make_new_board(board, new_board);
	rm(new_board, col, row);

	for (i = 1; i < BOARD_SIZE; i++) {          /*check if can go up*/
		if (row + i > 7) break;
		else if ( (strcmp(color, "White") == 0 && check_if_pos_is_white(board[col][row + i])) || (strcmp(color, "Black") == 0 && check_if_pos_is_black(board[col][row + i]))) break;
		eaten = new_board[col][row + i];
		new_board[col][row + i] = c;
		if (strcmp(color, "Black") == 0 && check_if_pos_is_white(board[col][row + i]) && !check_if_black_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' + i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col][row + i] = eaten;
			break;

		}
		else if (strcmp(color, "White") == 0 && check_if_pos_is_black(board[col][row + i]) && !check_if_white_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' + i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col][row + i] = eaten;
			break;
		}
		else if ((strcmp(color, "White") == 0 && !check_if_white_in_check(new_board)) || (strcmp(color, "Black") == 0 && !check_if_black_in_check(new_board))){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' + i);
			curr->next = make_new_node();
			curr = curr->next;

		}
		new_board[col][row + i] = eaten;
	}

	for (i = 1; i < BOARD_SIZE; i++) {     /*check if can go left*/
		if (col - i < 0) break;
		else if ( (strcmp(color, "White") == 0 && check_if_pos_is_white(board[col - i][row])) || (strcmp(color, "Black") == 0 && check_if_pos_is_black(board[col - i][row]))) break;
		eaten = new_board[col - i][row];
		new_board[col - i][row] = c;
		if (strcmp(color, "Black") == 0 && check_if_pos_is_white(board[col - i][row]) && !check_if_black_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - i, row + 1 + '0');
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col - i][row] = eaten;
			break;

		}
		else if (strcmp(color, "White") == 0 && check_if_pos_is_black(board[col - i][row]) && !check_if_white_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - i, row + 1 + '0');
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col - i][row] = eaten;
			break;
		}
		else if ((strcmp(color, "White") == 0 && !check_if_white_in_check(new_board)) || (strcmp(color, "Black") == 0 && !check_if_black_in_check(new_board))){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - i, row + 1 + '0');
			curr->next = make_new_node();
			curr = curr->next;


		}
		new_board[col - i][row] = eaten;
	}

	for (i = 1; i < BOARD_SIZE; i++) {          /*check if can go down*/
		if (row - i < 0) break;
		else if ( (strcmp(color, "White") == 0 && check_if_pos_is_white(board[col][row - i])) || (strcmp(color, "Black") == 0 && check_if_pos_is_black(board[col][row - i]))) break;
		eaten = new_board[col][row - i];
		new_board[col][row - i] = c;
		if (strcmp(color, "Black") == 0 && check_if_pos_is_white(board[col][row - i]) && !check_if_black_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' - i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col][row - i] = eaten;
			break;

		}
		else if (strcmp(color, "White") == 0 && check_if_pos_is_black(board[col][row - i]) && !check_if_white_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' - i);
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col][row - i] = eaten;
			break;
		}
		else if ((strcmp(color, "White") == 0 && !check_if_white_in_check(new_board)) || (strcmp(color, "Black") == 0 && !check_if_black_in_check(new_board))){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' - i);
			curr->next = make_new_node();
			curr = curr->next;

		}
		new_board[col][row - i] = eaten;
	}

	for (i = 1; i < BOARD_SIZE; i++) {       /*check if can go right*/
		if (col + i > 7) break;
		else if ( (strcmp(color, "White") == 0 && check_if_pos_is_white(board[col + i][row])) || (strcmp(color, "Black") == 0 && check_if_pos_is_black(board[col + i][row]))) break;
		eaten = new_board[col + i][row];
		new_board[col + i][row] = c;
		if (strcmp(color, "Black") == 0 && check_if_pos_is_white(board[col + i][row]) && !check_if_black_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + i, row + 1 + '0');
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col + i][row] = eaten;
			break;

		}
		else if (strcmp(color, "White") == 0 && check_if_pos_is_black(board[col + i][row]) && !check_if_white_in_check(new_board)) {
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + i, row + 1 + '0');
			curr->next = make_new_node();
			curr = curr->next;
			new_board[col + i][row] = eaten;
			break;
		}
		else if ((strcmp(color, "White") == 0 && !check_if_white_in_check(new_board)) || (strcmp(color, "Black") == 0 && !check_if_black_in_check(new_board))){
			sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + i, row + 1 + '0');
			curr->next = make_new_node();
			curr = curr->next;


		}
		new_board[col + i][row] = eaten;
	}

	if (strcmp(head->move, " ") == 0) {
		free(head);
		head = NULL;
	}

	else {
		curr = head;
		while (strcmp(curr->next->move, " "))
			curr = curr->next;
		free(curr->next);
		curr->next = NULL;
	}

	return head;

}


/*if has no moves returns null*/
node* get_moves_n(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color){
	char c, eaten, new_board[BOARD_SIZE][BOARD_SIZE];
	node* head = NULL, *curr = NULL;

	clear_board(new_board);

	head = make_new_node();
	curr = head;
	c = board[col][row];
	make_new_board(board, new_board);
	rm(new_board, col, row);


	if (strcmp(color, "White") == 0) {
		if (col + 1 < 8 && row + 2 < 8) {
			if ((board[col + 1][row + 2] == EMPTY || check_if_pos_is_black(board[col + 1][row + 2]))) {     /*check if can go 2up+1right*/
				eaten = new_board[col + 1][row + 2];
				new_board[col + 1][row + 2] = c;
				if (!check_if_white_in_check(new_board)) {
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' + 2);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 1][row + 2] = eaten;
			}
		}
		if (col + 2 < 8 && row + 1 < 8) {
			if ((board[col + 2][row + 1] == EMPTY || check_if_pos_is_black(board[col + 2][row + 1]))) {     /*check if can go 1up+2right*/
				eaten = new_board[col + 2][row + 1];
				new_board[col + 2][row + 1] = c;
				if (!check_if_white_in_check(new_board)) {
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 2, row + 1 + '0' + 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 2][row + 1] = eaten;
			}
		}

		if (col - 1 >= 0 && row + 2 < 8) {
			if ((board[col - 1][row + 2] == EMPTY || check_if_pos_is_black(board[col - 1][row + 2]))) {      /*check if can go 2up+1left*/
				eaten = new_board[col - 1][row + 2];
				new_board[col - 1][row + 2] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' + 2);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 1][row + 2] = eaten;
			}
		}

		if (col - 2 >= 0 && row + 1 < 8) {
			if ((board[col - 2][row + 1] == EMPTY || check_if_pos_is_black(board[col - 2][row + 1]))) {      /*check if can go 1up+2left*/
				eaten = new_board[col - 2][row + 1];
				new_board[col - 2][row + 1] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 2, row + 1 + '0' + 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 2][row + 1] = eaten;
			}
		}

		if (col - 1 >= 0 && row - 2 >= 0) {
			if ((board[col - 1][row - 2] == EMPTY || check_if_pos_is_black(board[col - 1][row - 2]))) {         /*check if can go 2down+1left*/
				eaten = new_board[col - 1][row - 2];
				new_board[col - 1][row - 2] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' - 2);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 1][row - 2] = eaten;
			}
		}

		if (col - 2 >= 0 && row - 1 >= 0) {
			if ((board[col - 2][row - 1] == EMPTY || check_if_pos_is_black(board[col - 2][row - 1]))) {         /*check if can go 1down+2left*/
				eaten = new_board[col - 2][row - 1];
				new_board[col - 2][row - 1] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 2, row + 1 + '0' - 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 2][row - 1] = eaten;
			}
		}

		if (col + 1 < 8 && row - 2 >= 0) {
			if ((board[col + 1][row - 2] == EMPTY || check_if_pos_is_black(board[col + 1][row - 2]))) {       /*check if can go 2down+1right*/
				eaten = new_board[col + 1][row - 2];
				new_board[col + 1][row - 2] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' - 2);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 1][row - 2] = eaten;
			}
		}

		if (col + 2 < 8 && row - 1 >= 0) {
			if ((board[col + 2][row - 1] == EMPTY || check_if_pos_is_black(board[col + 2][row - 1]))) {       /*check if can go 1down+2right*/
				eaten = new_board[col + 2][row - 1];
				new_board[col + 2][row - 1] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 2, row + 1 + '0' - 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 2][row - 1] = eaten;
			}
		}
	}

	if (strcmp(color, "Black") == 0) {
		if (col + 1 < 8 && row + 2 < 8) {
			if ((board[col + 1][row + 2] == EMPTY || check_if_pos_is_white(board[col + 1][row + 2]))) {       /*check if can go 2up+1right*/
				eaten = new_board[col + 1][row + 2];
				new_board[col + 1][row + 2] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' + 2);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 1][row + 2] = eaten;
			}
		}

		if (col + 2 < 8 && row + 1 < 8) {
			if ((board[col + 2][row + 1] == EMPTY || check_if_pos_is_white(board[col + 2][row + 1]))) {       /*check if can go 1up+2right*/
				eaten = new_board[col + 2][row + 1];
				new_board[col + 2][row + 1] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 2, row + 1 + '0' + 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 2][row + 1] = eaten;
			}
		}

		if (col - 1 >= 0 && row + 2 < 8) {
			if ((board[col - 1][row + 2] == EMPTY || check_if_pos_is_white(board[col - 1][row + 2]))) {         /*check if can go 2up+1left*/
				eaten = new_board[col - 1][row + 2];
				new_board[col - 1][row + 2] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' + 2);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 1][row + 2] = eaten;
			}
		}

		if (col - 2 >= 0 && row + 1 < 8) {
			if ((board[col - 2][row + 1] == EMPTY || check_if_pos_is_white(board[col - 2][row + 1]))) {         /*check if can go 1up+2left*/
				eaten = new_board[col - 2][row + 1];
				new_board[col - 2][row + 1] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 2, row + 1 + '0' + 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 2][row + 1] = eaten;
			}
		}

		if (col - 1 >= 0 && row - 2 >= 0) {
			if ((board[col - 1][row - 2] == EMPTY || check_if_pos_is_white(board[col - 1][row - 2]))) {      /*check if can go 2down+1left*/
				eaten = new_board[col - 1][row - 2];
				new_board[col - 1][row - 2] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' - 2);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 1][row - 2] = eaten;
			}
		}

		if (col - 2 >= 0 && row - 1 >= 0) {
			if ((board[col - 2][row - 1] == EMPTY || check_if_pos_is_white(board[col - 2][row - 1]))) {      /*check if can go 1down+2left*/
				eaten = new_board[col - 2][row - 1];
				new_board[col - 2][row - 1] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 2, row + 1 + '0' - 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 2][row - 1] = eaten;
			}
		}

		if (col + 1 < 8 && row - 2 >= 0) {
			if ((board[col + 1][row - 2] == EMPTY || check_if_pos_is_white(board[col + 1][row - 2]))) {          /*check if can go 2down+1right*/
				eaten = new_board[col + 1][row - 2];
				new_board[col + 1][row - 2] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' - 2);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 1][row - 2] = eaten;
			}
		}

		if (col + 2 < 8 && row - 1 >= 0) {
			if ((board[col + 2][row - 1] == EMPTY || check_if_pos_is_white(board[col + 2][row - 1]))) {          /*check if can go 1down+2right*/
				eaten = new_board[col + 2][row - 1];
				new_board[col + 2][row - 1] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 2, row + 1 + '0' - 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 2][row - 1] = eaten;
			}
		}

	}

	if (strcmp(head->move, " ") == 0) {
		free(head);
		head = NULL;
	}

	else {
		curr = head;
		while (strcmp(curr->next->move, " "))
			curr = curr->next;
		free(curr->next);
		curr->next = NULL;
	}

	return head;

}


/*if has no moves returns null*/
node* get_moves_q(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color){
	node* head = NULL, *curr = NULL;

	head = get_moves_b(board, col, row, color);
	curr = head;
	if (curr != NULL) {
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = get_moves_r(board, col, row, color);
	}
	else head = get_moves_r(board, col, row, color);
	return head;
}


/*if has no moves returns null*/
node* get_moves_k(char board[BOARD_SIZE][BOARD_SIZE], int col, int row, char* color){
	char c, new_board[BOARD_SIZE][BOARD_SIZE];
	node* head = NULL, *curr = NULL;
	char eaten = ' ';

	clear_board(new_board);

	head = make_new_node();
	curr = head;
	c = board[col][row];
	make_new_board(board, new_board);
	rm(new_board, col, row);


	if (strcmp(color, "White") == 0) {
		if (col + 1 < 8 && row + 1 < 8) {
			if ((board[col + 1][row + 1] == EMPTY || check_if_pos_is_black(board[col + 1][row + 1]))) {         /*check if can go up+right*/
				eaten = new_board[col + 1][row + 1];
				new_board[col + 1][row + 1] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' + 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 1][row + 1] = eaten;
			}
		}

		if (col - 1 >= 0 && row + 1 < 8) {
			if ((board[col - 1][row + 1] == EMPTY || check_if_pos_is_black(board[col - 1][row + 1]))) {     /*check if can go up+left*/
				eaten = new_board[col - 1][row + 1];
				new_board[col - 1][row + 1] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' + 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 1][row + 1] = eaten;
			}
		}

		if (col - 1 >= 0 && row - 1 >= 0) {
			if ((board[col - 1][row - 1] == EMPTY || check_if_pos_is_black(board[col - 1][row - 1]))) {     /*check if can go down+left*/
				eaten = new_board[col - 1][row - 1];
				new_board[col - 1][row - 1] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' - 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 1][row - 1] = eaten;
			}
		}

		if (col + 1 < 8 && row - 1 >= 0) {
			if ((board[col + 1][row - 1] == EMPTY || check_if_pos_is_black(board[col + 1][row - 1]))) {        /*check if can go down+right*/
				eaten = new_board[col + 1][row - 1];
				new_board[col + 1][row - 1] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' - 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 1][row - 1] = eaten;
			}
		}

		if (row - 1 >= 0) {
			if ((board[col][row - 1] == EMPTY || check_if_pos_is_black(board[col][row - 1]))) {          /*check if can go down*/
				eaten = new_board[col][row - 1];
				new_board[col][row - 1] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' - 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col][row - 1] = eaten;
			}
		}

		if (row + 1 < 8) {
			if ((board[col][row + 1] == EMPTY || check_if_pos_is_black(board[col][row + 1]))) {      /*check if can go up*/
				eaten = new_board[col][row + 1];
				new_board[col][row + 1] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' + 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col][row + 1] = eaten;
			}
		}

		if (col - 1 >= 0) {
			if ((board[col - 1][row] == EMPTY || check_if_pos_is_black(board[col - 1][row]))) {        /*check if can go left*/
				eaten = new_board[col - 1][row];
				new_board[col - 1][row] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0');
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 1][row] = eaten;
			}
		}

		if (col + 1 < 8) {
			if ((board[col + 1][row] == EMPTY || check_if_pos_is_black(board[col + 1][row]))) {         /*check if can go right*/
				eaten = new_board[col + 1][row];
				new_board[col + 1][row] = c;
				if (!check_if_white_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0');
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 1][row] = eaten;
			}
		}




	}

	if (strcmp(color, "Black") == 0) {
		if (col + 1 < 8 && row + 1 < 8) {
			if ((board[col + 1][row + 1] == EMPTY || check_if_pos_is_white(board[col + 1][row + 1]))) {       /*check if can go up+right*/
				eaten = new_board[col + 1][row + 1];
				new_board[col + 1][row + 1] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' + 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 1][row + 1] = eaten;
			}
		}

		if (col - 1 >= 0 && row + 1 < 8) {
			if ((board[col - 1][row + 1] == EMPTY || check_if_pos_is_white(board[col - 1][row + 1]))) {       /*check if can go up+left*/
				eaten = new_board[col - 1][row + 1];
				new_board[col - 1][row + 1] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' + 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 1][row + 1] = eaten;
			}
		}

		if (col - 1 >= 0 && row - 1 >= 0) {
			if ((board[col - 1][row - 1] == EMPTY || check_if_pos_is_white(board[col - 1][row - 1]))) {       /*check if can go down+left*/
				eaten = new_board[col - 1][row - 1];
				new_board[col - 1][row - 1] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0' - 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 1][row - 1] = eaten;
			}
		}

		if (col + 1 < 8 && row - 1 >= 0) {
			if ((board[col + 1][row - 1] == EMPTY || check_if_pos_is_white(board[col + 1][row - 1]))) {        /*check if can go down+right*/
				eaten = new_board[col + 1][row - 1];
				new_board[col + 1][row - 1] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0' - 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 1][row - 1] = eaten;
			}
		}

		if (row - 1 >= 0) {
			if ((board[col][row - 1] == EMPTY || check_if_pos_is_white(board[col][row - 1]))) {        /*check if can go down*/
				eaten = new_board[col][row - 1];
				new_board[col][row - 1] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' - 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col][row - 1] = eaten;
			}
		}

		if (row + 1 < 8) {
			if ((board[col][row + 1] == EMPTY || check_if_pos_is_white(board[col][row + 1]))) {        /*check if can go up*/
				eaten = new_board[col][row + 1];
				new_board[col][row + 1] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a', row + 1 + '0' + 1);
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col][row + 1] = eaten;
			}
		}

		if (col - 1 >= 0) {
			if ((board[col - 1][row] == EMPTY || check_if_pos_is_white(board[col - 1][row]))) {          /*check if can go left*/
				eaten = new_board[col - 1][row];
				new_board[col - 1][row] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' - 1, row + 1 + '0');
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col - 1][row] = eaten;
			}
		}

		if (col + 1 < 8) {
			if ((board[col + 1][row] == EMPTY || check_if_pos_is_white(board[col + 1][row]))) {        /*check if can go right*/
				eaten = new_board[col + 1][row];
				new_board[col + 1][row] = c;
				if (!check_if_black_in_check(new_board)){
					sprintf(curr->move, "<%c,%c> to <%c,%c>", col + 'a', row + 1 + '0', col + 'a' + 1, row + 1 + '0');
					curr->next = make_new_node();
					curr = curr->next;
				}
				new_board[col + 1][row] = eaten;
			}
		}




	}

	if (strcmp(head->move, " ") == 0) {
		free(head);
		head = NULL;
	}

	else {
		curr = head;
		while (strcmp(curr->next->move, " "))
			curr = curr->next;
		free(curr->next);
		curr->next = NULL;
	}

	return head;

}



int check_if_white_in_check(char board[BOARD_SIZE][BOARD_SIZE]) {
	int col, row, i, j;
	int res = 0;

	col = row = -1;

	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++){
			if (board[j][i] == WHITE_KING){
				row = i;
				col = j;
				break;
			}
		}
	}

	if (col == -1 || row == -1) {
		return 1;
	}

	if (!res) res += check_if_white_in_check_from_M(board, col, row);
	if (!res) res += check_if_white_in_check_from_R(board, col, row);
	if (!res) res += check_if_white_in_check_from_B(board, col, row);
	if (!res) res += check_if_white_in_check_from_N(board, col, row);
	if (!res) res += check_if_white_in_check_from_Q(board, col, row);
	if (!res) res += check_if_white_in_check_from_K(board, col, row);
	return res;
}


int check_if_black_in_check(char board[BOARD_SIZE][BOARD_SIZE]) {
	int col, row, i, j;
	int res = 0;

	col = row = -1;

	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++){
			if (board[j][i] == BLACK_KING){
				row = i;
				col = j;
				break;
			}
		}
	}

	if (col == -1 || row == -1) {
		return 1;
	}


	res += check_if_black_in_check_from_m(board, col, row);
	if (!res) res += check_if_black_in_check_from_r(board, col, row);
	if (!res) res += check_if_black_in_check_from_b(board, col, row);
	if (!res) res += check_if_black_in_check_from_n(board, col, row);
	if (!res) res += check_if_black_in_check_from_q(board, col, row);
	if (!res) res += check_if_black_in_check_from_k(board, col, row);
	return res;
}


int check_if_white_in_check_from_M(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){
	if (col + 1 < 8 && row + 1 < 8) {
		if ((board[col + 1][row + 1] == 'M' ))
			return 1;
	}
	if (col - 1 >= 0 && row + 1 < 8) {
		if (board[col - 1][row + 1] == 'M')
			return 1;
	}
	return 0;
}


int check_if_white_in_check_from_R(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){
	int i;

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row + i>7) break;
		else if (board[col][row + i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col][row + i])) break;
		else if (check_if_pos_is_black(board[col][row + i]) && board[col][row + i] != 'R') break;
		else if (board[col][row + i] == 'R') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row - i<0) break;
		else if (board[col][row - i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col][row - i])) break;
		else if (check_if_pos_is_black(board[col][row - i]) && board[col][row - i] != 'R') break;
		else if (board[col][row - i] == 'R') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col - i<0) break;
		else if (board[col - i][row] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col - i][row])) break;
		else if (check_if_pos_is_black(board[col - i][row]) && board[col - i][row] != 'R') break;
		else if (board[col - i][row] == 'R') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col + i>7) break;
		else if (board[col + i][row] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col + i][row])) break;
		else if (check_if_pos_is_black(board[col + i][row]) && board[col + i][row] != 'R') break;
		else if (board[col + i][row] == 'R') return 1;
	}

	return 0;
}


int check_if_white_in_check_from_B(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){
	int i;


	for (i = 1; i < BOARD_SIZE; i++) {
		if (row + i>7 || col + i > 7) break;
		else if (board[col + i][row + i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col + i][row + i])) break;
		else if (check_if_pos_is_black(board[col + i][row + i]) && board[col + i][row + i] != 'B') break;
		else if (board[col + i][row + i] == 'B') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row - i < 0 || col - i < 0) break;
		else if (board[col - i][row - i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col - i][row - i])) break;
		else if (check_if_pos_is_black(board[col - i][row - i]) && board[col - i][row - i] != 'B') break;
		else if (board[col - i][row - i] == 'B') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col - i<0 || row + i >7) break;
		else if (board[col - i][row + i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col - i][row + i])) break;
		else if (check_if_pos_is_black(board[col - i][row + i]) && board[col - i][row + i] != 'B') break;
		else if (board[col - i][row + i] == 'B') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col + i>7 || row - i < 0) break;
		else if (board[col + i][row - i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col + i][row - i])) break;
		else if (check_if_pos_is_black(board[col + i][row - i]) && board[col + i][row - i] != 'B') break;
		else if (board[col + i][row - i] == 'B') return 1;
	}

	return 0;
}


int check_if_white_in_check_from_N(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){
	if (col + 1 < 8 && row + 2 < 8) {
		if (board[col + 1][row + 2] == 'N' ) 
			return 1;
	}

	if (col - 1 >= 0 && row + 2 < 8) {
		if (board[col - 1][row + 2] == 'N') return 1;
	}

	if (col + 2 < 8 && row + 1 < 8) {
		if (board[col + 2][row + 1] == 'N') 
			return 1;
	}

	if (col - 2 >= 0 && row + 1 < 8) {
		if (board[col - 2][row + 1] == 'N') return 1;
	}

	if (col + 1 < 8 && row - 2 >= 0) {
		if (board[col + 1][row - 2] == 'N') return 1;
	}

	if (col - 1 >= 0 && row - 2 >= 0) {
		if (board[col - 1][row - 2] == 'N') return 1;
	}

	if (col + 2 < 8 && row - 1 >= 0) {
		if (board[col + 2][row - 1] == 'N') return 1;
	}

	if (col - 2 >= 0 && row - 1 >= 0) {
		if (board[col - 2][row - 1] == 'N') return 1;
	}

	return 0;
}


int check_if_white_in_check_from_Q(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){
	int i;


	for (i = 1; i < BOARD_SIZE; i++) {
		if (row + i>7 || col + i > 7) break;
		else if (board[col + i][row + i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col + i][row + i])) break;
		else if (check_if_pos_is_black(board[col + i][row + i]) && board[col + i][row + i] != 'Q') break;
		else if (board[col + i][row + i] == 'Q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row - i < 0 || col - i < 0) break;
		else if (board[col - i][row - i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col - i][row - i])) break;
		else if (check_if_pos_is_black(board[col - i][row - i]) && board[col - i][row - i] != 'Q') break;
		else if (board[col - i][row - i] == 'Q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col - i<0 || row + i >7) break;
		else if (board[col - i][row + i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col - i][row + i])) break;
		else if (check_if_pos_is_black(board[col - i][row + i]) && board[col - i][row + i] != 'Q') break;
		else if (board[col - i][row + i] == 'Q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col + i>7 || row - i < 0) break;
		else if (board[col + i][row - i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col + i][row - i])) break;
		else if (check_if_pos_is_black(board[col + i][row - i]) && board[col + i][row - i] != 'Q') break;
		else if (board[col + i][row - i] == 'Q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row + i>7) break;
		else if (board[col][row + i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col][row + i])) break;
		else if (check_if_pos_is_black(board[col][row + i]) && board[col][row + i] != 'Q') break;
		else if (board[col][row + i] == 'Q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row - i<0) break;
		else if (board[col][row - i] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col][row - i])) break;
		else if (check_if_pos_is_black(board[col][row - i]) && board[col][row - i] != 'Q') break;
		else if (board[col][row - i] == 'Q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col - i<0) break;
		else if (board[col - i][row] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col - i][row])) break;
		else if (check_if_pos_is_black(board[col - i][row]) && board[col - i][row] != 'Q') break;
		else if (board[col - i][row] == 'Q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col + i>7) break;
		else if (board[col + i][row] == EMPTY) continue;
		else if (check_if_pos_is_white(board[col + i][row])) break;
		else if (check_if_pos_is_black(board[col + i][row]) && board[col + i][row] != 'Q') break;
		else if (board[col + i][row] == 'Q') return 1;
	}

	return 0;
}


int check_if_white_in_check_from_K(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){
	if (col - 1 >= 0 && row - 1 >= 0){
		if (board[col - 1][row - 1] == 'K') return 1;
	}

	if (col + 1 < 8 && row + 1 < 8){
		if (board[col + 1][row + 1] == 'K') return 1;
	}

	if (col - 1 >= 0 && row + 1 < 8){
		if (board[col - 1][row + 1] == 'K') return 1;
	}

	if (col + 1 < 8 && row - 1 >= 0){
		if (board[col + 1][row - 1] == 'K') return 1;
	}

	if (row - 1 >= 0){
		if (board[col][row - 1] == 'K') return 1;
	}

	if (row + 1 < 8){
		if (board[col][row + 1] == 'K') return 1;
	}

	if (col - 1 >= 0){
		if (board[col - 1][row] == 'K') return 1;
	}

	if (col + 1 < 8){
		if (board[col + 1][row] == 'K') return 1;
	}

	return 0;
}


int check_if_black_in_check_from_m(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){
	if (col - 1 >= 0 && row - 1 >= 0){
		if (board[col - 1][row - 1] == 'm') return 1;
	}

	if (row - 1 >= 0 && col + 1 < 8){
		if (board[col + 1][row - 1] == 'm') return 1;
	}

	return 0;
}


int check_if_black_in_check_from_r(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){
	int i;
	for (i = 1; i < BOARD_SIZE; i++) {
		if (row + i>7) break;
		else if (board[col][row + i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col][row + i])) break;
		else if (check_if_pos_is_white(board[col][row + i]) && board[col][row + i] != 'r') break;
		else if (board[col][row + i] == 'r') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row - i<0) break;
		else if (board[col][row - i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col][row - i])) break;
		else if (check_if_pos_is_white(board[col][row - i]) && board[col][row - i] != 'r') break;
		else if (board[col][row - i] == 'r') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col - i<0) break;
		else if (board[col - i][row] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col - i][row])) break;
		else if (check_if_pos_is_white(board[col - i][row]) && board[col - i][row] != 'r') break;
		else if (board[col - i][row] == 'r') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col + i>7) break;
		else if (board[col + i][row] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col + i][row])) break;
		else if (check_if_pos_is_white(board[col + i][row]) && board[col + i][row] != 'r') break;
		else if (board[col + i][row] == 'r') return 1;
	}

	return 0;
}


int check_if_black_in_check_from_b(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){
	int i;

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row + i>7 || col + i > 7) break;
		else if (board[col + i][row + i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col + i][row + i])) break;
		else if (check_if_pos_is_white(board[col + i][row + i]) && board[col + i][row + i] != 'b') break;
		else if (board[col + i][row + i] == 'b') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row - i < 0 || col - i < 0) break;
		else if (board[col - i][row - i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col - i][row - i])) break;
		else if (check_if_pos_is_white(board[col - i][row - i]) && board[col - i][row - i] != 'b') break;
		else if (board[col - i][row - i] == 'b') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col - i<0 || row + i >7) break;
		else if (board[col - i][row + i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col - i][row + i])) break;
		else if (check_if_pos_is_white(board[col - i][row + i]) && board[col - i][row + i] != 'b') break;
		else if (board[col - i][row + i] == 'b') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col + i>7 || row - i < 0) break;
		else if (board[col + i][row - i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col + i][row - i])) break;
		else if (check_if_pos_is_white(board[col + i][row - i]) && board[col + i][row - i] != 'b') break;
		else if (board[col + i][row - i] == 'b') return 1;
	}

	return 0;
}


int check_if_black_in_check_from_n(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){

	if (col - 1 >= 0 && row + 2 < 8){
		if (board[col - 1][row + 2] == 'n') return 1;
	}

	if (col + 1 < 8 && row + 2 < 8){
		if (board[col + 1][row + 2] == 'n') return 1;
	}

	if (col - 2 >= 0 && row + 1 < 8){
		if (board[col - 2][row + 1] == 'n') return 1;
	}

	if (col + 2 < 8 && row + 1 < 8){
		if (board[col + 2][row + 1] == 'n') return 1;
	}

	if (col - 1 >= 0 && row - 2 >= 0){
		if (board[col - 1][row - 2] == 'n') return 1;
	}

	if (col + 1 < 8 && row - 2 >= 0){
		if (board[col + 1][row - 2] == 'n') return 1;
	}

	if (col - 2 >= 0 && row - 1 >= 0){
		if (board[col - 2][row - 1] == 'n') return 1;
	}

	if (col + 2 < 8 && row - 1 >= 0){
		if (board[col + 2][row - 1] == 'n') return 1;
	}


	return 0;
}


int check_if_black_in_check_from_q(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){
	int i;

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row + i>7 || col + i > 7) break;
		else if (board[col + i][row + i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col + i][row + i])) break;
		else if (check_if_pos_is_white(board[col + i][row + i]) && board[col + i][row + i] != 'q') break;
		else if (board[col + i][row + i] == 'q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row - i < 0 || col - i < 0) break;
		else if (board[col - i][row - i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col - i][row - i])) break;
		else if (check_if_pos_is_white(board[col - i][row - i]) && board[col - i][row - i] != 'q') break;
		else if (board[col - i][row - i] == 'q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col - i<0 || row + i >7) break;
		else if (board[col - i][row + i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col - i][row + i])) break;
		else if (check_if_pos_is_white(board[col - i][row + i]) && board[col - i][row + i] != 'q') break;
		else if (board[col - i][row + i] == 'q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col + i>7 || row - i < 0) break;
		else if (board[col + i][row - i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col + i][row - i])) break;
		else if (check_if_pos_is_white(board[col + i][row - i]) && board[col + i][row - i] != 'q') break;
		else if (board[col + i][row - i] == 'q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row + i>7) break;
		else if (board[col][row + i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col][row + i])) break;
		else if (check_if_pos_is_white(board[col][row + i]) && board[col][row + i] != 'q') break;
		else if (board[col][row + i] == 'q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (row - i<0) break;
		else if (board[col][row - i] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col][row - i])) break;
		else if (check_if_pos_is_white(board[col][row - i]) && board[col][row - i] != 'q') break;
		else if (board[col][row - i] == 'q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col - i<0) break;
		else if (board[col - i][row] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col - i][row])) break;
		else if (check_if_pos_is_white(board[col - i][row]) && board[col - i][row] != 'q') break;
		else if (board[col - i][row] == 'q') return 1;
	}

	for (i = 1; i < BOARD_SIZE; i++) {
		if (col + i>7) break;
		else if (board[col + i][row] == EMPTY) continue;
		else if (check_if_pos_is_black(board[col + i][row])) break;
		else if (check_if_pos_is_white(board[col + i][row]) && board[col + i][row] != 'q') break;
		else if (board[col + i][row] == 'q') return 1;
	}

	return 0;
}


int check_if_black_in_check_from_k(char board[BOARD_SIZE][BOARD_SIZE], int col, int row){

	if (col - 1 >= 0 && row - 1 >= 0){
		if (board[col - 1][row - 1] == 'k') return 1;
	}
	if (col + 1 < 8 && row + 1 < 8){
		if (board[col + 1][row + 1] == 'k') return 1;
	}
	if (col - 1 >= 0 && row + 1 < 8){
		if (board[col - 1][row + 1] == 'k') return 1;
	}
	if (col + 1 < 8 && row - 1 >= 0){
		if (board[col + 1][row - 1] == 'k') return 1;
	}
	if (row - 1 >= 0){
		if (board[col][row - 1] == 'k') return 1;
	}
	if (row + 1 < 8){
		if (board[col][row + 1] == 'k') return 1;
	}
	if (col - 1 >= 0){
		if (board[col - 1][row] == 'K') return 1;
	}
	if (col + 1 < 8){
		if (board[col + 1][row] == 'k') return 1;
	}

	return 0;
}

void print_moves(node* head){
	while (head) {
		printf("%s", head->move);
		printf("\n");
		head = head->next;
	}
}

void check_get_moves(char board[BOARD_SIZE][BOARD_SIZE]){
	char c;
	int col, row;
	node* head = NULL;
	char x[50] = "";

	if (1 != scanf("%s", x)){
		printf("Error: standard function scanf has failed\n");
		exit(0);
	}

	col = x[1] - 'a';
	row = x[3] - 1 - '0';
	if (col<0 || col>7 || row<0 || row>7) {
		printf(WRONG_POSITION);
		return;
	}
	else if ((check_if_pos_is_white(board[col][row]) && strcmp(curr_turn, "Black") == 0) || board[col][row] == EMPTY) {
		printf(NO_DICS);
		return;
	}

	else if ((check_if_pos_is_black(board[col][row]) && strcmp(curr_turn, "White") == 0) || board[col][row] == EMPTY) {
		printf(NO_DICS);
		return;
	}

	else c = board[col][row];

	if (c == 'm') head = get_moves_m(board, col, row, curr_turn);
	else if (c == 'M') head = get_moves_M(board, col, row, curr_turn);
	else if (c == 'b' || c == 'B') head = get_moves_b(board, col, row, curr_turn);
	else if (c == 'r' || c == 'R') head = get_moves_r(board, col, row, curr_turn);
	else if (c == 'n' || c == 'N') head = get_moves_n(board, col, row, curr_turn);
	else if (c == 'q' || c == 'Q') head = get_moves_q(board, col, row, curr_turn);
	else if (c == 'k' || c == 'K') head = get_moves_k(board, col, row, curr_turn);

	print_moves(head);
	free_linked_list(head);
	head = NULL;


}
