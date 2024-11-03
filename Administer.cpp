#include "Administer.h"

using namespace std;

 /**
  * Administer implementation
  */

Administer::Administer() {
	id = 0;
	name = "Administer";
	_employee = new vector<Employee>();
	_manager = new vector<Manager>();  
	_teacher = new vector<Teacher>();  
	populateEmployeeData();
	populateManagerData();  
	populateTeacherData(); 

	////Printing the data for administer that i have loaded.
	//PrintEmployeeData();
	//PrintManagerData();  
	//PrintTeacherData();  
}

int Administer::getId() const
{
	return 0;
}

void Administer::populateEmployeeData() {
	LoadDataFromFile<Employee>("employees.txt", *_employee);
}

void Administer::populateManagerData()
{
	LoadDataFromFile<Manager>("managers.txt", *_manager);
}

void Administer::populateTeacherData()
{
	LoadDataFromFile<Teacher>("teachers.txt", *_teacher);
}

void Administer::PrintEmployeeData() const {
	cout << "Employee Data:" << endl;
	for (const auto& employee : *_employee) {
		cout << "ID: " << employee.getId() << ", Name: " << employee.getName() << endl;
	}
}

void Administer::PrintManagerData() const {
	cout << "Manager Data:" << endl;
	for (const auto& manager : *_manager) {
		cout << "ID: " << manager.getId() << ", Name: " << manager.getName() << endl;
	}
}

void Administer::PrintTeacherData() const {
	cout << "Teacher Data:" << endl;
	for (const auto& teacher : *_teacher) {
		cout << "ID: " << teacher.getId() << ", Name: " << teacher.getName() << endl;
	}
}

void Administer::command() {
	int choice;
	do {
		Sleep(1500);
		system("cls");
		cout << "Administer Command Function:" << endl;
		cout << "1. Add new employee" << endl;
		cout << "2. Remove an employee" << endl;
		cout << "3. Show all employees" << endl;
		cout << "4. Add new manager" << endl;
		cout << "5. Remove a manager" << endl;
		cout << "6. Show all managers" << endl;
		cout << "7. Add new teacher" << endl;
		cout << "8. Remove a teacher" << endl;
		cout << "9. Show all teachers" << endl;
		cout << "0. Exit" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			AddEmployee();
			break;
		case 2:
			RemoveEmployee();
			break;
		case 3:
			PrintEmployeeData();  
			break;
		case 4:
			AddManager();
			break;
		case 5:
			RemoveManager();
			break;
		case 6:
			PrintManagerData();  
			break;
		case 7:
			AddTeacher();
			break;
		case 8:
			RemoveTeacher();
			break;
		case 9:
			PrintTeacherData();   
			break;
		case 0:
			cout << "Exiting Administer Command Function." << endl;
			break;
		default:
			cout << "Invalid choice. Please enter a valid option." << endl;
		}

		// Wait for the user to press any key before going back for cases 3, 6, and 9
		if (choice == 3 || choice == 6 || choice == 9) {
			cout << "Press Enter key to go back...";
			getchar(); // Wait for the user to press any key
			getchar(); // Consume the newline character from the previous input
		}

	} while (choice != 0);
}

void Administer::AddEmployee() {
	int newId;
	string newName;

	// Get user input for ID
	cout << "Enter Employee ID: ";
	cin >> newId;

	// Check if the ID is already taken
	for (const auto& employee : *_employee) {
		if (employee.getId() == newId) {
			cout << "Error: Employee ID already taken. Please choose a different ID." << endl;
			return;  // Exit the function if ID is already taken
		}
	}

	// Get user input for name
	cout << "Enter Employee Name: ";
	cin.ignore();  // Clear the input buffer
	getline(cin, newName);

	// Create a new Employee object
	Employee newEmployee(newId, newName);

	// Add the new Employee to the vector
	_employee->push_back(newEmployee);

	// Update the file with the new employee information
	SaveDataToFile("employees.txt", *_employee);


	// Optionally, you can print a message to confirm the addition
	cout << "Employee added successfully. ID: " << newEmployee.getId() << ", Name: " << newEmployee.getName() << endl;
}

void Administer::AddManager() {
	int newId;
	string newName;

	// Get user input for ID
	cout << "Enter Manager ID: ";
	cin >> newId;

	// Check if the ID is already taken
	for (const auto& manager : *_manager) {
		if (manager.getId() == newId) {
			cout << "Error: Manager ID already taken. Please choose a different ID." << endl;
			return;  // Exit the function if ID is already taken
		}
	}

	// Get user input for name
	cout << "Enter Manager Name: ";
	cin.ignore();  // Clear the input buffer
	getline(cin, newName);

	// Create a new Manager object
	Manager newManager(newId, newName);

	// Add the new Manager to the vector
	_manager->push_back(newManager);

	// Update the file with the new manager information
	SaveDataToFile("managers.txt", *_manager);


	cout << "Manager added successfully. ID: " << newManager.getId() << ", Name: " << newManager.getName() << endl;
}

void Administer::AddTeacher() {
	int newId;
	string newName;

	// Get user input for ID
	cout << "Enter Teacher ID: ";
	cin >> newId;

	// Check if the ID is already taken
	for (const auto& teacher : *_teacher) {
		if (teacher.getId() == newId) {
			cout << "Error: Teacher ID already taken. Please choose a different ID." << endl;
			return;  // Exit the function if ID is already taken
		}
	}

	// Get user input for name
	cout << "Enter Teacher Name: ";
	cin.ignore();  // Clear the input buffer
	getline(cin, newName);

	// Create a new Teacher object
	Teacher newTeacher(newId, newName);

	// Add the new Teacher to the vector
	_teacher->push_back(newTeacher);

	// Update the file with the new teacher information
	SaveDataToFile("teachers.txt", *_teacher);

	cout << "Teacher added successfully. ID: " << newTeacher.getId() << ", Name: " << newTeacher.getName() << endl;
}

void Administer::RemoveEmployee() {
	int idToRemove;

	// Get user input for the ID to remove
	cout << "Enter the ID of the employee to remove: ";
	cin >> idToRemove;

	// Find the iterator for the employee with the specified ID
	auto it = find_if(_employee->begin(), _employee->end(),
		[idToRemove](const Employee& emp) { return emp.getId() == idToRemove; });

	// Check if the employee with the specified ID was found
	if (it != _employee->end()) {
		// Erase the employee from the vector
		_employee->erase(it);

		// Update the file after removing the employee
		SaveDataToFile("employees.txt", *_employee);


		cout << "Employee with ID " << idToRemove << " removed successfully." << endl;
	}
	else {
		cout << "Error: Employee with ID " << idToRemove << " not found." << endl;
	}
}

void Administer::RemoveManager() {
	int idToRemove;

	// Get user input for the ID to remove
	cout << "Enter the ID of the manager to remove: ";
	cin >> idToRemove;

	// Find the iterator for the manager with the specified ID
	auto it = find_if(_manager->begin(), _manager->end(),
		[idToRemove](const Manager& mgr) { return mgr.getId() == idToRemove; });

	// Check if the manager with the specified ID was found
	if (it != _manager->end()) {
		// Erase the manager from the vector
		_manager->erase(it);

		// Update the file after removing the manager
		SaveDataToFile("managers.txt", *_manager);


		cout << "Manager with ID " << idToRemove << " removed successfully." << endl;
	}
	else {
		cout << "Error: Manager with ID " << idToRemove << " not found." << endl;
	}
}

void Administer::RemoveTeacher() {
	int idToRemove;

	// Get user input for the ID to remove
	cout << "Enter the ID of the teacher to remove: ";
	cin >> idToRemove;

	// Find the iterator for the teacher with the specified ID
	auto it = find_if(_teacher->begin(), _teacher->end(),
		[idToRemove](const Teacher& tchr) { return tchr.getId() == idToRemove; });

	// Check if the teacher with the specified ID was found
	if (it != _teacher->end()) {
		// Erase the teacher from the vector
		_teacher->erase(it);

		// Update the file after removing the teacher
		SaveDataToFile("teachers.txt", *_teacher);

		cout << "Teacher with ID " << idToRemove << " removed successfully." << endl;
	}
	else {
		cout << "Error: Teacher with ID " << idToRemove << " not found." << endl;
	}
}