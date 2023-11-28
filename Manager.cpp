/**
 * Project Untitled
 */


#include "Manager.h"

 /**
  * Manager implementation
  */


Manager::Manager()
{
    id = -1;
    name = "";
}

Manager::Manager(int ID, string Name)
{
    this->id = ID;
    this->name = Name;
}

int Manager::getId() const
{
    return id;
}

string Manager::getName() const
{
    return name;
}

void Manager::command()
{
}

void Manager::ReviewRequest() {

}

void Manager::AssignJob() {

}

void Manager::ReviewJob() {

}