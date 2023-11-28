/**
 * Project Untitled
 */

#include "Person.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include "Person.h"

using namespace std;

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

class Employee: virtual public Person{
private:
    int id;
    string name;

public:

    Employee();

    Employee(int ID, string Name);

    int getId() const;

    void command();

    void updateSystem();

    string getName() const;
};

#endif //_EMPLOYEE_H