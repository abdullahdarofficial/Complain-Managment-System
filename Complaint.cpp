/**
 * Project Untitled
 */


#include "Complaint.h"

 /**
  * Complaint implementation
  */

  // Default constructor
Complaint::Complaint() {
    id = 0;
    description = "";
    dept = "";
    teacher_id = 0;
    status = "";
}

// Overloaded constructor
Complaint::Complaint(int ID, string desc, string dept, int t_id, string stat) {
    id = ID;
    description = desc;
    this->dept = dept;
    teacher_id = t_id;
    status = stat;
}

string Complaint::CurrentState() const {
    return status;
}

int Complaint::getId() const
{
    return id;
}

string Complaint::getComplaintDesc() const
{
    return description;
}

string Complaint::getComplaintDept() const
{
    return dept;
}

int Complaint::getComplaintTeacherId() const
{
    return teacher_id;
}

void Complaint::ChangeState(string newStatus) {
    status = newStatus;
}

void Complaint::PrintDetails() const {
    cout << "Complaint ID: " << id << ", Description: " << description
        << ", Department: " << dept << ", Teacher ID: " << teacher_id
        << ", Status: " << status << endl;
}

void Complaint::PrintDetails(int teacherID) const
{
    if (teacherID == teacher_id) {
        cout << "Complaint ID: " << id << ", Description: " << description
            << ", Department: " << dept << ", Teacher ID: " << teacher_id
            << ", Status: " << status << endl;
    }
}
 