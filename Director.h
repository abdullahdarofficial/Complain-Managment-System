/**
 * Project Untitled
 */

#include <string>
#include "Person.h"

using namespace std;

#ifndef _DIRECTOR_H
#define _DIRECTOR_H

class Director : virtual public Person {
private:
    int id;
    string name;

public:
    int getId() const;
 
    void command();

    void Complains_in_Depts();

    void ComplainsSummary();

    void ComplainDetails();
};

#endif //_DIRECTOR_H