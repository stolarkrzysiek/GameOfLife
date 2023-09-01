#include <iostream>
#include "field.hpp"
using namespace std;



field::field()
{
    this->condition=false;

}

void field::change()
{
    if(this->condition==true) this->condition=false;
    else this->condition=true;
}

bool field::conditioncheck()
{
    if(this->condition==true) return true;
    else return false;
}
