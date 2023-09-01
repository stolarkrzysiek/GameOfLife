#pragma once 
#include "board.hpp"

#include <vector>



class board_roller: public board 
{
public:
    
    board_roller(int width, int height) : board(width,height){}
    ~board_roller() {};
    int countalivefields(int row, int col) override;
    void block(int x, int y) override;
    void tub(int x, int y) override;
    void blinker(int x, int y) override;
    void beacon(int x, int y) override;
    
    
private:

    
    int width, height;
    
};
