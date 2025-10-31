#include "tic_tac_toe.h"

using std::string;
using std::cin;
using std::cout;

int main() 
{
	TicTacToe tic_tac_toe;

	string first_player = "X";

	cout<<"Enter first player (X or O)";
	cin>>first_player;

	tic_tac_toe.start_game(first_player);

	while(!tic_tac_toe.game_over())
	{
		auto position = 0;
		cout<<"Enter position: ";
		cin>>position;

		tic_tac_toe.mark_board(position);
		tic_tac_toe.display_board();
	}

	

	return 0;
}