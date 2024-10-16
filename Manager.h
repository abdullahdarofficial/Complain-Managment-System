/**
 * Project Untitled
 */

#include "Person.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

#ifndef _MANAGER_H
#define _MANAGER_H

class Manager : virtual public Person {
private:
    int id;
    string name;

public:
    Manager();

    Manager(int ID, string Name);

    int getId() const;

    string getName() const;

    void command();

    void ReviewRequest();

    void AssignJob();

    void ReviewJob();
};

#endif //_MANAGER_H