#pragma once 
#include <vector>
#include "AlwaysNextTurn.hpp"
#include "CommandSource.hpp"
#include "field.hpp"
//#include "board_surface.hpp"

class board
{
    private:
        std::vector <field> Board;
        int width, height;
    public:
        board(int width, int height);
        void print();//wyswietlanie planszy
        void change(int x, int y);//zmiana stanu pola
        //funkcje do rysowania 
        virtual void block(int x, int y);//wspolrzedne lewego gornego rogu
        virtual void tub(int x, int y);//wspolrzedne lewego rogu
        virtual void blinker(int x, int y); //wspolrzedne lewego elementu
        virtual void beacon(int x, int y);//wspolrzedne lewego gornego rogu
        void addobject();//generuje obiekty na planszy
        int get_width();
        int get_height();
        //
        //virtual int countalivefields(int row, int col);//funkcja zwraca ilosc zywych sasiadow
        //int countalivefields(int row, int col);
        void nextcondition();
        void play(CommandSource* command, board* b);
        bool getField(int x, int y); 
        
        virtual ~board() {};
        virtual int countalivefields(int row, int col) = 0;
};

