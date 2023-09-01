#pragma once 
#include "board.hpp"

class board_torus: public board 
{
public:
    
    board_torus(int width, int height) : board(width,height){}
    ~board_torus() {};
    int countalivefields(int row, int col) override;
    void block(int x, int y) override;
    void tub(int x, int y) override;
    void blinker(int x, int y) override;
    void beacon(int x, int y) override;
    
    
private:

    
    int width, height;
    
};
