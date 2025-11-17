#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test is game over with a vector that has 9 pegs with value of space")
{
	TicTacToe tic_tac_toe;

	REQUIRE(false == tic_tac_toe.game_over());
}

TEST_CASE("Test is first player set correctly when starting the game")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	REQUIRE(tic_tac_toe.get_player() == "X");
}

TEST_CASE("Test if board is full - game over ")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");
	REQUIRE(tic_tac_toe.get_player() == "X");

	tic_tac_toe.mark_board(1);
	REQUIRE(tic_tac_toe.get_player() == "O");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(2);
	REQUIRE(tic_tac_toe.get_player() == "X");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(3);
	REQUIRE(tic_tac_toe.get_player() == "O");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(6);
	REQUIRE(tic_tac_toe.get_player() == "X");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(4);
	REQUIRE(tic_tac_toe.get_player() == "O");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(7);
	REQUIRE(tic_tac_toe.get_player() == "X");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(5);
	REQUIRE(tic_tac_toe.get_player() == "O");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(9);
	REQUIRE(tic_tac_toe.get_player() == "X");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(8);
	REQUIRE(tic_tac_toe.get_player() == "O");
	REQUIRE(true  ==  tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "C");

}

TEST_CASE("Test first player set to X")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	REQUIRE(tic_tac_toe.get_player() == "X");	
}

TEST_CASE("Test first player set to O")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("O");

	REQUIRE(tic_tac_toe.get_player() == "O");	
}	

TEST_CASE("Test win by first column")	
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(4); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(5); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(7); //X

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}		

TEST_CASE("Test win by second column")	
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("O");

	tic_tac_toe.mark_board(2); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(1); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(5); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(4); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(8); //O

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "O");
}	

TEST_CASE("Test win by third column")	
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(3); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(1); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(6); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(4); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(9); //X

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}	

TEST_CASE("Test win by first row")	
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("O");

	tic_tac_toe.mark_board(1); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(4); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(5); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(3); //O

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "O");
}		

TEST_CASE("Test win by second row")	
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(4); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(1); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(5); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(6); //X

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by third row")	
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("O");

	tic_tac_toe.mark_board(7); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(1); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(8); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(9); //O

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "O");
}

TEST_CASE("Test win by diagonal from left to right")	
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(5); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(3); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(9); //X

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by diagonal from right to left")	
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("O");

	tic_tac_toe.mark_board(3); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(1); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(5); //O
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); //X
	REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(7); //O

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "O");
}