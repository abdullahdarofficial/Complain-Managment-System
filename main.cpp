#include <iostream>
#include "Person.h"
#include "Administer.h"
#include "Director.h"
#include "Teacher.h"
#include <windows.h>

using namespace std;

Person* Login() {

	Person* _person = NULL;
	int _input = 0;
	bool _endProgram = false;
	int _id = 0;

	Administer *_administer = new Administer;
	Director* _director = new Director;
	Teacher* _teacher = new Teacher;

	while (_endProgram == false) {
		cout << "Login Panel" << endl;
		if (_administer != NULL) {
			cout << "[1] ->> Administer" << endl;
		}
		if (_director != NULL) {
			cout << "[2] ->> Director" << endl;
		}
		if (_teacher != NULL) {
			cout << "[3] ->> Teacher" << endl;
		}
		cout << "[0] ->> Exit" << endl;

		cout << "Enter Here >> ";
		cin >> _input;
		if (_input == 0) {
			_endProgram = true;
		}
		else if (_input == 1) {
			cout << "Administer Selected" << endl;
			cout << "Enter the ID of Administer : ";
			cin >> _id;
			while(_id != _administer->getId()) {
				cout << "Invalid Administer Id" << endl;
				cout << "Enter Again >> ";
				cin >> _id;
			}
			cout << "Welcome Administer!" << endl;
			_person = _administer;
			_endProgram = true;
		} else if (_input == 3) {
			cout << "Teacher Selected" << endl;
			//teacher verification paused right now -----------
			/*cout << "Enter the ID of Teacher : ";
			cin >> _id;
			while (_id != _administer->getId()) {
				cout << "Invalid Administer Id" << endl;
				cout << "Enter Again >> ";
				cin >> _id;
			}*/
			cout << "Welcome Teacher!" << endl;
			_person = _teacher;
			_endProgram = true;
		}
		else {
			cout << "Invalid Entry Try Again!!." << endl;
			Sleep(1000);
			system("cls");
		}
	//	system("cls");
	}

	return _person;
}

int main() {


	while (true) {
		Person* _currentUser = Login();
		if (_currentUser == NULL) {
			break;
		}
		else {
			_currentUser->command();
			cout << "Administer Executed" << endl;
			Sleep(1000);
			system("cls");
		}
	}

	cout << "Program Terminated SuccessFully" << endl;
	return 0;
}

//last comments complaint not loading data corrctly print function of teacher not executed correclty 