/**
 * Project Untitled
 */

#include <string>
#include "Person.h"
#include "Complaint.h"
#include <Windows.h>
#include <fstream>
#include <functional>
#include <sstream>
#include <vector>


using namespace std;

#ifndef _TEACHER_H
#define _TEACHER_H

class Teacher: virtual public Person {

private:
    int id;
    string name;
    vector<Complaint>* _complaint;
public:

    Teacher();

    Teacher(int ID, string Name);

    int getId() const;

    string getName() const;
    
    void command();

    void CheckComplaintStatus();

    void MakeComplain();

    void PrintComplains();

    void RecordFeedback();

    void LoadAllComplaints();

    void SaveALLComplaints();

};

#endif //_TEACHER_H