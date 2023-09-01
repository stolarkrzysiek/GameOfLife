#include <iostream>
#include "field.hpp"
#include "board.hpp"
#include "CommandSource.hpp"
#include "UserCommand.hpp"
#include "AlwaysNextTurn.hpp"
#include "board_surface.hpp"
#include "board_roller.hpp"
#include "board_torus.hpp"
#include <fstream>
#include <string>

using namespace std;

int main()
{
    
    CommandSource* auto_command_source = new AlwaysNextTurn();
    CommandSource* choice_command = new UserCommand();

    string wybrana_mapa;
    string wybrany_tryb;
    cout << "Wybierz rodzaj planszy [surface, roller, torus]: ";
    cin >> wybrana_mapa; 
    
    int x=0, y=0;
    cout << "Podaj rozmiar planszy[wysokosc, szerokosc]\nwysokosc: ";
    cin >> x;
    cout<<"szerokosc: ";
    cin >> y;
    
    if(wybrana_mapa == "surface")
    {
        board *surface = new board_surface(x, y);
        
        cout<<"ile obiektow dodac?\n";
        int ile;
        cin>>ile;
        for(int i=0;i<ile;i++)
        {
            surface->addobject();
        }
        
        
        cout << "Wybierz źródło komend [user, auto]: ";
        cin >> wybrany_tryb; 
    
    
        if(wybrany_tryb == "user")
        {
            surface->play(choice_command, surface);
        
            delete choice_command;
        }
    else if(wybrany_tryb == "auto")
    {
        surface->play(auto_command_source, surface);
        
        delete auto_command_source;
    }
    delete surface;
        
        delete surface;
    }
    else if(wybrana_mapa == "roller")
    {
        board *surface = new board_roller(x, y);  
        
        cout<<"ile obiektow dodac?\n";
        int ile;
        cin>>ile;
        for(int i=0;i<ile;i++)
        {
            surface->addobject();
        }
         
         
    cout << "Wybierz źródło komend [user, auto]: ";
    cin >> wybrany_tryb; 
    
    
    if(wybrany_tryb == "user")
    {
        surface->play(choice_command, surface);
        
        delete choice_command;
    }
    else if(wybrany_tryb == "auto")
    {
        surface->play(auto_command_source, surface);
        
        delete auto_command_source;
    }
    delete surface;
         
        delete surface;   
    }
    else if(wybrana_mapa == "torus")
    {
        board *surface = new board_torus(x, y);
        
        cout<<"ile obiektow dodac?\n";
        int ile;
        cin>>ile;
        for(int i=0;i<ile;i++)
        {
            surface->addobject();
        }
        
        
    cout << "Wybierz źródło komend [user, auto]: ";
    cin >> wybrany_tryb; 
    
    
    if(wybrany_tryb == "user")
    {
        surface->play(choice_command, surface);
        
        delete choice_command;
    }
    else if(wybrany_tryb == "auto")
    {
        surface->play(auto_command_source, surface);
        
        delete auto_command_source;
    }
    delete surface;
        
        
    }

    
   
    return 0;
}

