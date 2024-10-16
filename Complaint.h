/**
 * Project Untitled
 */

#include <iostream>
#include <string>
using namespace std;

#ifndef _COMPLAINT_H
#define _COMPLAINT_H

class Complaint {
private:
    int id;
    string description;
    string dept;
    int teacher_id;
    string status;

public:
    Complaint();

    Complaint(int ID, string desc, string dept, int t_id, string stat);

    string CurrentState() const;

    int getId() const;

    string getComplaintDesc() const;

    string getComplaintDept() const;

    int getComplaintTeacherId()  const;

    void ChangeState(string newStatus);

    void PrintDetails() const;

    void PrintDetails(int teacherID) const;
};

#endif //_COMPLAINT_H