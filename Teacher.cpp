#include "Teacher.h"

 /**
  * Teacher implementation
  */


Teacher::Teacher()
{
	id = -1;
	name = "";
}

Teacher::Teacher(int ID, string Name)
{
	this->id = ID;
	this->name = Name;
}

int Teacher::getId() const
{
	return id;
}

string Teacher::getName() const
{
	return name;
}

void Teacher::command() {
    int choice = 1000;

    while (choice != 0) {
        cout << "Teacher Command Function:" << endl;
        cout << "1. Make a complaint" << endl;
        cout << "2. Check status of a complaint" << endl;
        cout << "3. Record feedback" << endl;
        cout << "4. Print all complaints" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            MakeComplain();
            break;
        case 2:
            CheckComplaintStatus();
            break;
        case 3:
            RecordFeedback();
            break;
        case 4:
            PrintComplains();
            break;
        case 0:
            cout << "Exiting Teacher Command Function." << endl;
            return;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}

void Teacher::CheckComplaintStatus() {
    int complaintId;

    cout << "Enter the complaint ID to check status: ";
    cin >> complaintId;

    // Find the complaint with the given ID
    for (const Complaint& complaint : *_complaint) {
        if (complaint.getId() == complaintId) {
            cout << "Complaint ID: " << complaint.getId() << ", Status: " << complaint.CurrentState() << endl;
            return;
        }
    }

    cout << "Complaint with ID " << complaintId << " not found." << endl;
}

void Teacher::MakeComplain() {
    // Ask user for complaint details
    cout << "Enter complaint query: ";
    string query;
    cin.ignore(); // Ignore the newline character from the previous input
    getline(cin, query);

    cout << "Enter department: ";
    string department;
    getline(cin, department);

    // Create a new complaint with the entered details
    // Assuming teacher_id is a member variable in the Teacher class
    Complaint newComplaint(_complaint->size() + 1, query, department, id, "active");

    // Add the new complaint to the vector
    _complaint->push_back(newComplaint);

    // Save all complaints to the file after adding a new complaint
    SaveALLComplaints();

    cout << "Complaint added successfully!" << endl;
}

void Teacher::PrintComplains() {
    for (const Complaint& complaint : *_complaint) {
        complaint.PrintDetails(id);
        cout << "----------------------" << endl;
    }
}

void Teacher::RecordFeedback() {

}

void Teacher::LoadAllComplaints() {
    ifstream file("complaints.txt");

    if (file.is_open()) {
        int id;
        string desc, dept, status;
        int teacher_id;

        while (file >> id >> desc >> dept >> teacher_id >> status) {
            // Assuming you have a constructor in Complaint class that takes these parameters
            Complaint newComplaint(id, desc, dept, teacher_id, status);

            // Add the loaded complaint to the vector
            _complaint->push_back(newComplaint);
        }

        file.close();
    }
    else {
        cout << "Unable to open file 'complaints.txt'" << endl;
    }
}

void Teacher::SaveALLComplaints() {
    ofstream file("complaints.txt");

    if (file.is_open()) {
        for (const Complaint& complaint : *_complaint) {
            file << complaint.getId() << " "
                << complaint.getComplaintDesc() << " "
                << complaint.getComplaintDept() << " "
                << complaint.getComplaintTeacherId() << " "
                << complaint.CurrentState() << endl;
        }

        file.close();
        cout << "Complaints saved successfully!" << endl;
    }
    else {
        cout << "Unable to open file 'complaints.txt' for writing." << endl;
    }
}