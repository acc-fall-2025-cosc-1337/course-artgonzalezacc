//cpp
#include "tic_tac_toe.h"

using std::cout;

bool TicTacToe::game_over()
{
    if(check_column_win() || check_row_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    else if (check_board_full())
    {
        winner = "C";
        return true;
    }
    else
    {
        return false;
    }
}

void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::display_board() const
{
    for(long unsigned int i=0; i < pegs.size(); i+=3)
    {
        cout<<pegs[i]<<"|"<<pegs[i+1]<<"|"<<pegs[i+2]<<"\n";
    }
}

void TicTacToe::set_next_player()
{
    if(player == "X") 
    {
        player = "O";
    }
    else 
    {
        player = "X";
    }
}

bool TicTacToe::check_board_full()
{
    auto full = true;

    for(auto &peg: pegs)
    {
        if(peg == " ")
        {
            full = false;
            break;
        }
    }

    return full;
}

void TicTacToe::clear_board()
{
    for(auto &peg: pegs)
    {
        peg = " ";
    }
}

bool TicTacToe::check_column_win()
{
    for(int col=0; col < 3; col++)
    {
        if(pegs[col] == pegs[col + 3] && pegs[col] == pegs[col + 6] && pegs[col] != " ")
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_row_win()
{
    for(int row=0; row < 9; row+=3)
    {
        if(pegs[row] == pegs[row + 1] && pegs[row] == pegs[row + 2] && pegs[row] != " ")
        {
            return true;
        }
    }
    return false;
}   

bool TicTacToe::check_diagonal_win()
{
    if((pegs[0] == pegs[4] && pegs[0] == pegs[8] && pegs[0] != " ") ||
       (pegs[2] == pegs[4] && pegs[2] == pegs[6] && pegs[2] != " "))
    {
        return true;
    }
    return false;
}   

void TicTacToe::set_winner()
{
    if(player == "X")
    {
    
        winner = "O";
    }
    else
    {
        winner = "X";
    }
}
