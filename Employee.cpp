/**
 * Project Untitled
 */


#include "Employee.h"
#include <string>
using namespace std;


 /**
  * Employee implementation
  */


Employee::Employee()
{
	id = -1;
	name = "";
}


Employee::Employee(int id, string name)
{
	this->id = id;
	this->name = name;
}


int Employee::getId() const {
	return id;
}
 


void Employee::command()
{
}

void Employee::updateSystem() {

}

string Employee::getName() const
{
	return name;
}
