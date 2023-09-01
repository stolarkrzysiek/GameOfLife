#include <iostream>
#include <vector>
#include "board_roller.hpp"

using namespace std;

void board_roller::block(int x, int y)
{
    
    
    
    if(y==(this->get_width()-1))
    {
        
        this->change(x, y);
        this->change(x+1, y);
        this->change(x, 0);
        this->change(x+1, 0);

    }
    else
    {
        
        this->change(x, y);
        this->change(x+1, y);
        this->change(x, y+1);
        this->change(x+1, y+1);
    
    }

}

void board_roller::tub(int x, int y)
{
    
    if((y+2)==(this->get_width()))
    {
        
        this->change(x, y);
        this->change(x-1, y+1);
        this->change(x+1, y+1);
        this->change(x, 0);

    }
    else if((y+2)>(this->get_width()))
    {
        
        this->change(x, y);
        this->change(x-1, 0);
        this->change(x+1, 0);
        this->change(x, 1);

    }
    else
    {
        
        this->change(x, y);
        this->change(x-1, y+1);
        this->change(x, y+2);
        this->change(x+1, y+1);
    
    }

}

void board_roller::blinker(int x, int y)
{
    if((y+2)==(this->get_width()))
    {
        
        this->change(x, y);
        this->change(x, y+1);
        this->change(x, 0);
    }
    else if((y+2)>(this->get_width()))
    {
        
        this->change(x, y);
        this->change(x, 0);
        this->change(x, 1);
    }
    else
    {
        this->change(x, y);
        this->change(x, y+1);
        this->change(x, y+2);
    }
    
}

void board_roller::beacon(int x, int y)
{
    if((y+3)==(this->get_width()))
    {
        this->change(x, y);
        this->change(x, y+1);
        this->change(x+1, y);
        this->change(x+1, y+1);
        this->change(x+2, y+2);
        this->change(x+3, y+2);
        this->change(x+2, 0);
        this->change(x+3, 0);
        
    }
    else if((y+2)==(this->get_width()))
    {
        this->change(x, y);
        this->change(x, y+1);
        this->change(x+1, y);
        this->change(x+1, y+1);
        this->change(x+2, 0);
        this->change(x+3, 0);
        this->change(x+2, 1);
        this->change(x+3, 1);
        
    }
    else if((y+1)==(this->get_width()))
    {
        this->change(x, y);
        this->change(x+1, y);
        this->change(x, 0);
        this->change(x+1, 0);
        this->change(x+2, 1);
        this->change(x+3, 1);
        this->change(x+2, 2);
        this->change(x+3, 2);
        
    }
    else
    {
        this->change(x, y);
        this->change(x, y+1);
        this->change(x+1, y);
        this->change(x+1, y+1);
        this->change(x+2, y+2);
        this->change(x+2, y+3);
        this->change(x+3, y+2);
        this->change(x+3, y+3);
    }


}


int board_roller::countalivefields(int row, int col) 
{
    
    
    
        
    int licznik=0;
    
    //if(row<0||row>height-1||col<0||col>width-1) return -1;
    
    
    //sprawdzanie rogow
    if(row==0&&col==0)
    {
        if(this->getField(0, 1)==true) licznik++;
        if(this->getField(1, 0)==true) licznik++;
        if(this->getField(1, 1)==true) licznik++;
        if(this->getField(0, this->get_width()-1)==true) licznik++;
        if(this->getField(1, this->get_width()-1)==true) licznik++;
    }
    else if(row==0&&col==this->get_width()-1)
    {
        if(this->getField(0, this->get_width()-2)==true) licznik++;
        if(this->getField(1, this->get_width()-2)==true) licznik++;
        if(this->getField(1, this->get_width()-1)==true) licznik++;
        if(this->getField(0, 0)==true) licznik++;
        if(this->getField(1, 0)==true) licznik++;
    }
    else if(row==this->get_height()-1&&col==0)
    {  
        if(this->getField(height-2, 0)==true) licznik++;
        if(this->getField(height-2, 1)==true) licznik++;
        if(this->getField(height-1, 1)==true) licznik++;
        if(this->getField(height-2, this->get_width()-1)==true) licznik++;
        if(this->getField(height-1, this->get_width()-1)==true) licznik++;
    }

    else if(row==this->get_height()-1&&col==this->get_width()-1)
    {
        if(this->getField(this->get_height()-1, this->get_width()-2)==true) licznik++;
        if(this->getField(this->get_height()-2, this->get_width()-2)==true) licznik++;
        if(this->getField(this->get_height()-2, this->get_width()-1)==true) licznik++;
        if(this->getField(this->get_height()-2, 0)==true) licznik++;
        if(this->getField(this->get_height()-1, 0)==true) licznik++;
    }
    else if(row==0)
    {
        
        for(int i=-1;i<2;i=i+2)
    {
        if(this->getField(row, col+i)==true) licznik++;
    } 
        for(int i=-1;i<2;i++)
    {
        if(this->getField(row+1, col+i)==true) licznik++;
    } 
    }
    else if(row==this->get_height()-1)
    {
        for(int i=-1;i<2;i++)
    {
        if(this->getField(row-1, col+i)==true) licznik++;
    } 
        for(int i=-1;i<2;i=i+2)
    {
        if(this->getField(row, col+i)==true) licznik++;
    } 
    }
    else if(col==0)
    {
        if(this->getField(row-1, this->get_width()-1)==true) licznik++;
        if(this->getField(row-1, col)==true) licznik++;
        if(this->getField(row-1, col+1)==true) licznik++;
        if(this->getField(row, col+1)==true) licznik++;
        if(this->getField(row, this->get_width()-1)==true) licznik++;
        if(this->getField(row+1, this->get_width()-1)==true) licznik++;
        if(this->getField(row+1, col)==true) licznik++;
        if(this->getField(row+1, col+1)==true) licznik++;
    }
    else if(col==this->get_width()-1)
    {
        if(this->getField(row-1, col-1)==true) licznik++;
        if(this->getField(row-1, col)==true) licznik++;
        if(this->getField(row-1, 0)==true) licznik++;
        if(this->getField(row, col-1)==true) licznik++;
        if(this->getField(row, 0)==true) licznik++;
        if(this->getField(row+1, col-1)==true) licznik++;
        if(this->getField(row+1, col)==true) licznik++;
        if(this->getField(row+1, 0)==true) licznik++;
    }
    //reszta
    else{
    for(int i=-1;i<2;i++)
    {
        if(this->getField(row-1, col+i)==true) licznik++;
    }
    for(int i=-1;i<2;i=i+2)
    {
        if(this->getField(row, col+i)==true) licznik++;
    }
    for(int i=-1;i<2;i++)
    {
        if(this->getField(row+1, col+i)==true) licznik++;
    }
    }
    //std::cout<<licznik;
    return licznik;
}
