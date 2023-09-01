#include <iostream>
#include <vector>
#include "board_surface.hpp"

/*board_surface::board_surface(int width, int height)
{
    for(int i=0; i<width*height; i++)
            {
               field f;
               Board.push_back(f);
            }
            Board[10].change();
    this->width=width;
    this->height=height;
    
    
}*/



int board_surface::countalivefields(int row, int col) 
{
    

    
    int licznik=0;
    
    //if(row<0||row>height-1||col<0||col>width-1) return -1;
    
    
    //sprawdzanie rogow
    if(row==0&&col==0)
    {
        if(this->getField(0, 1)==true) licznik++;
        if(this->getField(1, 0)==true) licznik++;
        if(this->getField(1, 1)==true) licznik++;
    }
    else if(row==0&&col==width-1)
    {
        if(this->getField(0, width-2)==true) licznik++;
        if(this->getField(1, width-2)==true) licznik++;
        if(this->getField(1, width-1)==true) licznik++;
    }
    else if(row==height-1&&col==0)
    {  
        if(this->getField(height-2, 0)==true) licznik++;
        if(this->getField(height-2, 1)==true) licznik++;
        if(this->getField(height-1, 1)==true) licznik++;
    }

    else if(row==height-1&&col==width-1)
    {
        if(this->getField(height-1, width-2)==true) licznik++;
        if(this->getField(height-2, width-2)==true) licznik++;
        if(this->getField(height-2, width-1)==true) licznik++;
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
    else if(row==height-1)
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
        if(this->getField(row-1, col)==true) licznik++;
        if(this->getField(row-1, col+1)==true) licznik++;
        if(this->getField(row, col+1)==true) licznik++;
        if(this->getField(row+1, col)==true) licznik++;
        if(this->getField(row+1, col+1)==true) licznik++;
    }
    else if(col==width-1)
    {
        if(this->getField(row-1, col-1)==true) licznik++;
        if(this->getField(row-1, col)==true) licznik++;
        if(this->getField(row, col-1)==true) licznik++;
        if(this->getField(row+1, col)==true) licznik++;
        if(this->getField(row+1, col-1)==true) licznik++;
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
