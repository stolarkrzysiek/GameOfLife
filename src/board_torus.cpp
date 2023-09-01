#include <iostream>
#include <vector>
#include "board_torus.hpp"

using namespace std;

void board_torus::block(int x, int y)
{
    if((x==(this->get_height()-1)) && (y==(this->get_width()-1)))
    {
        this->change(x, y);
        this->change(0, 0);
        this->change(0, this->get_width()-1);
        this->change(this->get_height()-1, 0);
    }
    else if((x==0) && (y==(this->get_width()-1)))
    {
        this->change(x, y);
        this->change(0, 0);
        this->change(this->get_height()-1, 0);
        this->change(this->get_height()-1, this->get_width()-1);
    }
    else if(y==(this->get_width()-1))
    {
        this->change(x, y);
        this->change(x+1, y);
        this->change(x, 0);
        this->change(x+1, 0);
    }
    else if(x==(this->get_height()-1))
    {
        this->change(x, y);
        this->change(x, y+1);
        this->change(0, y);
        this->change(0, y+1);
    }
    else 
    {
        this->change(x, y);
        this->change(x+1, y);
        this->change(x, y+1);
        this->change(x+1, y+1);
    }

}


void board_torus::blinker(int x, int y)
{
    
    if(y==(this->get_width()-1))
    {
        this->change(x, y);
        this->change(x, 0);
        this->change(x, 1);
    }
    else if(y==(this->get_width()-2))
    {
        this->change(x, y);
        this->change(x, y+1);
        this->change(x, 0);
    }
    else
    {
        this->change(x, y);
        this->change(x, y+1);
        this->change(x, y+2);
    }
}
void board_torus::tub(int x, int y)
{
    if((x==(this->get_height()-1)) && (y==(this->get_width()-1)))
    {
        this->change(x, y);
        this->change(x, 1);
        this->change(x-1, 0);
        this->change(0, 0);
    }
    else if((x==0) && (y==(this->get_width()-1)))
    {
        this->change(x, y);
        this->change(x, 1);
        this->change(x+1, 0);
        this->change(this->get_height()-1, 0);
    }
    else if(y==(this->get_width()-1))
    {
        this->change(x, y);
        this->change(x, 1);
        this->change(x-1, 0);
        this->change(x+1, 0);
    }
    else if((x==(this->get_height()-1)) && (y==(this->get_width()-2)))
    {
        this->change(x, y);
        this->change(x, 0);
        this->change(x-1, y+1);
        this->change(0, y+1);
    }
    else if((x==0) && (y==(this->get_width()-2)))
    {
        this->change(x, y);
        this->change(0, 0);
        this->change(x+1, y+1);
        this->change(this->get_height()-1, y+1);
    }
    else if(y==(this->get_width()-2))
    {
        this->change(x, y);
        this->change(x, 0);
        this->change(x-1, y+1);
        this->change(x+1, y+1);
    }
    else
    {
        this->change(x, y);
        this->change(x-1, y+1);
        this->change(x, y+2);
        this->change(x+1, y+1);
    }
}

void board_torus::beacon(int x, int y)
{
    if((x==(this->get_height()-1)) && (y==(this->get_width()-1)))
    {
        this->change(x, y);
        this->change(0, 0);
        this->change(0, this->get_width()-1);
        this->change(this->get_height()-1, 0);
        this->change(1, 1);
        this->change(1, 2);
        this->change(2, 1);
        this->change(2, 2);
    }
    else if((x==0) && (y==(this->get_width()-1)))
    {
        this->change(x, y);
        this->change(x+1, y);
        this->change(0, 0);
        this->change(1, 0);
        this->change(2, 1);
        this->change(2, 2);
        this->change(3, 1);
        this->change(3, 2);
    }
    else if((x==(this->get_height()-2)) && (y==(this->get_width()-1)))
    {
        this->change(x, y);
        this->change(x+1, y);
        this->change(this->get_height()-1, 0);
        this->change(this->get_height()-2, 0);
        this->change(0, 1);
        this->change(0, 2);
        this->change(1, 1);
        this->change(1, 2);
    }
    else if((x==(this->get_height()-3)) && (y==(this->get_width()-1)))
    {
        this->change(x, y);
        this->change(x+1, y);
        this->change(this->get_height()-2, 0);
        this->change(this->get_height()-3, 0);
        this->change(this->get_height()-1, 1);
        this->change(this->get_height()-1, 2);
        this->change(0, 1);
        this->change(0, 2);
    }
    else if(x==(this->get_height()-1))
    {
       this->change(x, y);
        this->change(x, y+1);
        this->change(0, y);
        this->change(0, y+1);
        this->change(1, y+2);
        this->change(2, y+2);
        this->change(1, y+3);
        this->change(2, y+3);
    }
    else if(x==(this->get_height()-2))
    {
        this->change(x, y);
        this->change(x, y+1);
        this->change(x+1, y);
        this->change(x+1, y+1);
        this->change(0, y+2);
        this->change(0, y+3);
        this->change(1, y+2);
        this->change(1, y+3);
    }
    
    else if(y==(this->get_width()-1))
    {
        this->change(x, y);
        this->change(x+1, y);
        this->change(x, 0);
        this->change(x+1, 0);
        this->change(x+2, 1);
        this->change(x+2, 2);
        this->change(x+3, 1);
        this->change(x+3, 2);
    }
    
    else if((x==(this->get_height()-1)) && (y==(this->get_width()-2)))
    {
        this->change(x, y);
        this->change(x, y+1);
        this->change(0, y);
        this->change(0, y+1);
        this->change(1, 0);
        this->change(2, 0);
        this->change(1, 1);
        this->change(2, 1);
    }
    else if((x==0) && (y==(this->get_width()-2)))
    {
        this->change(x, y);
        this->change(x, y+1);
        this->change(x+1, y);
        this->change(x+1, y+1);
        this->change(x+2, 0);
        this->change(x+2, 1);
        this->change(x+3, 0);
        this->change(x+3, 1);
    }
    else if(y==(this->get_width()-2))
    {
        this->change(x, y);
        this->change(x+1, y);
        this->change(x, y+1);
        this->change(x+1, y+1);
        this->change(x+2, 0);
        this->change(x+2, 1);
        this->change(x+3, 0);
        this->change(x+3, 1);
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


int board_torus::countalivefields(int row, int col) 
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
        if(this->getField(this->get_height()-1, 0)==true) licznik++;
        if(this->getField(this->get_height()-1, 1)==true) licznik++;
        if(this->getField(this->get_height()-1, this->get_width()-1)==true) licznik++;
    }

    else if(row==0&&col==this->get_width()-1)
    {
        if(this->getField(0, this->get_width()-2)==true) licznik++;
        if(this->getField(1, this->get_width()-2)==true) licznik++;
        if(this->getField(1, this->get_width()-1)==true) licznik++;
        if(this->getField(0, 0)==true) licznik++;
        if(this->getField(1, 0)==true) licznik++;
        if(this->getField(this->get_height()-1, 0)==true) licznik++;
        if(this->getField(this->get_height()-1, this->get_width()-2)==true) licznik++;
        if(this->getField(this->get_height()-1, this->get_width()-1)==true) licznik++;
    }

    else if(row==this->get_height()-1&&col==0)
    {  
        if(this->getField(0, 0)==true) licznik++;
        if(this->getField(0, 1)==true) licznik++;
        if(this->getField(0, this->get_width()-1)==true) licznik++;
        if(this->getField(this->get_height()-2, 0)==true) licznik++;
        if(this->getField(this->get_height()-2, 1)==true) licznik++;
        if(this->getField(this->get_height()-1, 1)==true) licznik++;
        if(this->getField(this->get_height()-1, this->get_width()-1)==true) licznik++;
        if(this->getField(this->get_height()-2, this->get_width()-1)==true) licznik++;
    }

    else if(row==this->get_height()-1&&col==this->get_width()-1)
    {
        if(this->getField(0, 0)==true) licznik++;
        if(this->getField(0, this->get_width()-2)==true) licznik++;
        if(this->getField(0, this->get_width()-1)==true) licznik++;
        if(this->getField(this->get_height()-2, 0)==true) licznik++;
        if(this->getField(this->get_height()-1, 0)==true) licznik++;
        if(this->getField(this->get_height()-1, this->get_width()-2)==true) licznik++;
        if(this->getField(this->get_height()-2, this->get_width()-2)==true) licznik++;
        if(this->getField(this->get_height()-2, this->get_width()-1)==true) licznik++;
    }
    
    else if(row==0)
    {
        
        for(int i=-1;i<2;i=i+2)
        {
        if(this->getField(row, col+i)==true) licznik++;
        } 
        
        for(int i=-1;i<2;i++)
        {
        if(this->getField(this->get_height()-1, col+i)==true) licznik++;
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
        if(this->getField(0, col+i)==true) licznik++;
        } 
        
        for(int i=-1;i<2;i=i+2)
        {
        if(this->getField(row, col+i)==true) licznik++;
        } 
        
        for(int i=-1;i<2;i++)
        {
        if(this->getField(row-1, col+i)==true) licznik++;
        } 
    }
    else if(col==0)
    {
        if(this->getField(row-1, col)==true) licznik++;
        if(this->getField(row-1, col+1)==true) licznik++;
        if(this->getField(row, col+1)==true) licznik++;
        if(this->getField(row+1, col)==true) licznik++;
        if(this->getField(row+1, col+1)==true) licznik++;
        if(this->getField(row-1, this->get_width()-1)==true) licznik++;
        if(this->getField(row, this->get_width()-1)==true) licznik++;
        if(this->getField(row+1, this->get_width()-1)==true) licznik++;
    }

    else if(col==this->get_width()-1)
    {
        if(this->getField(row-1, 0)==true) licznik++;
        if(this->getField(row, 0)==true) licznik++;
        if(this->getField(row+1, 0)==true) licznik++;
        if(this->getField(row-1, col-1)==true) licznik++;
        if(this->getField(row-1, col)==true) licznik++;
        if(this->getField(row, col-1)==true) licznik++;
        if(this->getField(row+1, col-1)==true) licznik++;
        if(this->getField(row+1, col)==true) licznik++;
    }
    
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
    
    
    return licznik;
}
