#pragma once 
#include "board.hpp"

#include <vector>



class board_surface : public board 
{
public:
    
    board_surface(int width, int height) : board(width,height){}
    ~board_surface() {};
    int countalivefields(int row, int col) override;
    
private:

    //std::vector <field> Board;
    int width, height;
    
};
