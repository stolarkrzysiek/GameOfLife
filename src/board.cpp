#include <iostream>
#include <vector>
#include "board.hpp"



using namespace std;

board::board(int width, int height)
{
    for(int i=0; i<width*height; i++)
            {
               field f;
               
               Board.push_back(f);
            }
            
    this->width=width;
    this->height=height;
    
    
}

int board::get_width()
{
    return this->width;
}

int board::get_height()
{
    return this->height;
}

void board::print()
{
    
    for(int i=0; i<(width*height); i++) 
        {  
            if(i%width==0 && i!=0) cout<<endl;
            
            if(Board[i].conditioncheck()) cout<<"O";
            else cout<<" ";
            
        }
     cout<<endl;

}

void board::change(int x, int y) //zmiana wartosci pola
{
    Board[(x*width)+y].change();   
}

void  board::block(int x, int y)
{

    this->change(x, y);
    this->change(x+1, y);
    this->change(x, y+1);
    this->change(x+1, y+1);
}

void  board::tub(int x, int y)
{
    this->change(x, y);
    this->change(x-1, y+1);
    this->change(x, y+2);
    this->change(x+1, y+1);
}

void  board::blinker(int x, int y)
{
    this->change(x, y);
    this->change(x, y+1);
    this->change(x, y+2);
}

void  board::beacon(int x, int y)
{
    this->change(x, y);
    this->change(x, y+1);
    this->change(x+1, y);
    
    this->change(x+3, y+2);
    this->change(x+3, y+3);
    this->change(x+2, y+3);
}


void board::nextcondition()
{
    vector<int>tab;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
            {
                tab.push_back(0);
            }
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
            {
                if(this->countalivefields(i, j)==3 && Board[width*(i)+j].conditioncheck()==false)
                {
                    tab[width*(i)+j]=1;
                }
                else if( Board[width*(i)+j].conditioncheck()==true && (this->countalivefields(i, j)==3 || this->countalivefields(i, j)==2))
                {
                    continue;
                }
                else if( Board[width*(i)+j].conditioncheck()==true && (this->countalivefields(i, j)!=3 || this->countalivefields(i, j)!=2))
                {
                    tab[width*(i)+j]=1;
                }
            }
    }
    
     for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
            {
                if(tab[width*(i)+j]==1)
                {
                    Board[width*(i)+j].change();
                }
            }
    }
    
    
}

void board::play(CommandSource* command, board* b)
{
    while(command->next_command()=="next")
    {
        //b.nextcondition();
        //b.print();
        b->nextcondition();
        b->print();
    }
    
   
    
}

bool board::getField(int x, int y)
{
    return Board[(x*width)+y].conditioncheck();

}

void board::addobject()//zrobić blokade przed wpisywaniem złych wartości 
{
    int x=0, y=0, choice=0;
    cout<<"podaj wspolrzedne[x,y]\nx: ";
    cin>>x;
    cout<<"y: ";
    cin>>y;
    cout<<"1.block\n2.tub\n3.blinker\n4.beacon\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
            this->block(x, y);
            break;
        case 2:
            this->tub(x, y);
            break;
        case 3:
            this->blinker(x, y);
            break;
        case 4:
            this->beacon(x, y);
            break;
        default:
            cout<<"brak struktury\n";
            break;
    }
    
}



/*
int board::countalivefields(int row, int col) 
{

    int licznik=0;
    
    if(row<0||row>height-1||col<0||col>width-1) return -1;
    
    //sprawdzanie rogow
    if(row==0&&col==0)
    {
        if(Board[1].conditioncheck()==true) licznik++;
        if(Board[width].conditioncheck()==true) licznik++;
        if(Board[width+1].conditioncheck()==true) licznik++;
    }
    else if(row==0&&col==width-1)
    {
        if(Board[width-2].conditioncheck()==true) licznik++;
        if(Board[2*width-2].conditioncheck()==true) licznik++;
        if(Board[2*width-1].conditioncheck()==true) licznik++;
    }
    else if(row==height-1&&col==0)
    {
        if(Board[width*(height-2)].conditioncheck()==true) licznik++;
        if(Board[width*(height-2)+1].conditioncheck()==true) licznik++;
        if(Board[width*(height-1)+1].conditioncheck()==true) licznik++;
    }
    else if(row==height-1&&col==0)
    {
        if(Board[width*(height-2)].conditioncheck()==true) licznik++;
        if(Board[width*(height-2)+1].conditioncheck()==true) licznik++;
        if(Board[width*(height-1)+1].conditioncheck()==true) licznik++;
    }
    else if(row==height-1&&col==width-1)
    {
        if(Board[width*(height-1)+width-2].conditioncheck()==true) licznik++;
        if(Board[width*(height-1)+width-1].conditioncheck()==true) licznik++;
        if(Board[width*height-2].conditioncheck()==true) licznik++;
    }
    else if(row==0)
    {
        for(int i=-1;i<2;i=i+2)
    {
        if(Board[col+i].conditioncheck()==true) licznik++;
    } 
        for(int i=-1;i<2;i++)
    {
        if(Board[width+col+i].conditioncheck()==true) licznik++;
    } 
    }
    else if(row==height-1)
    {
        for(int i=-1;i<2;i++)
    {
        if(Board[width*(height-2)+col+i].conditioncheck()==true) licznik++;
    } 
        for(int i=-1;i<2;i=i+2)
    {
        if(Board[width*(height-1)+col+i].conditioncheck()==true) licznik++;
    } 
    }
    else if(col==0)
    {
        if(Board[(row-1)*width].conditioncheck()==true) licznik++;
        if(Board[(row-1)*width+1].conditioncheck()==true) licznik++;
        if(Board[row*width+1].conditioncheck()==true) licznik++;
        if(Board[(row+1)*width].conditioncheck()==true) licznik++;
        if(Board[(row+1)*width+1].conditioncheck()==true) licznik++;
    }
    else if(col==width-1)
    {
        if(Board[width*(row-1)+col-1].conditioncheck()==true) licznik++;
        if(Board[width*(row-1)+col].conditioncheck()==true) licznik++;
        if(Board[width*row+col-1].conditioncheck()==true) licznik++;
        if(Board[width*(row+1)+col-1].conditioncheck()==true) licznik++;
        if(Board[width*(row+1)+col].conditioncheck()==true) licznik++;
    }
    //reszta
    else{
    for(int i=-1;i<2;i++)
    {
        if(Board[(row-1)*width+col+i].conditioncheck()==true) licznik++;
    }
    for(int i=-1;i<2;i=i+2)
    {
        if(Board[row*width+col+i].conditioncheck()==true) licznik++;
    }
    for(int i=-1;i<2;i++)
    {
        if(Board[(row+1)*width+col+i].conditioncheck()==true) licznik++;
    }
    }
    return licznik;
    }*/






