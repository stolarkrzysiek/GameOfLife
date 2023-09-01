#include "UserCommand.hpp"
#include <chrono>
#include <thread> 
using namespace std;
std::string UserCommand::next_command()
{
    do
    {
    //std::this_thread::sleep_for(200ms);
    
    cout<<endl<<"wybor:";
    cin>>choice;
   
    }while(choice!='n' && choice!='s');
     std::system("clear");
    if(choice=='n') return "next";
    else return "quit";
    
}
