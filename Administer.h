/**
 * Project Untitled
 */
#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <functional>
#include <sstream>
#include <vector>
#include "Person.h"
#include "Employee.h"
#include "Teacher.h"
#include "Manager.h"
#include <cstdio>

using namespace std;

#ifndef _ADMINISTER_H
#define _ADMINISTER_H

class Administer: virtual public Person{
private:

    int id;
    string name;
    vector<Employee>* _employee;
    vector<Manager>* _manager;
    vector<Teacher>* _teacher;

public:

    Administer(); 

    //Administer(vector<Employee>&e, vector<Manager>&m, vector<Teacher>&t);

    int getId() const;
    
    void populateEmployeeData();

    void populateManagerData();

    void populateTeacherData();
    
    template<typename Temp>
    void LoadDataFromFile(string file, vector<Temp>& _vector);

    template<typename Temp>
    void SaveDataToFile(const std::string& file, const std::vector<Temp>& _vector);

     
    void PrintEmployeeData() const;

    void PrintManagerData() const;

    void PrintTeacherData() const;

    void command();

    void AddEmployee();

    void AddManager();

    void AddTeacher();

    void RemoveEmployee();

    void RemoveManager();

    void RemoveTeacher();
};


#endif //_ADMINISTER_H


template<typename Temp>
inline void Administer::LoadDataFromFile(string file, vector<Temp>& _vector)
{
    ifstream inputFile(file);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file: " << file << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int id;
        string name;

        // Assuming the data is formatted as "ID Name"
        if (ss >> id >> name) {
            Temp temp{ id, name };
            _vector.push_back(temp);
        }
        else {
            cerr << "Error: Invalid data format in file: " << file << endl;
        }
    }

    inputFile.close();
}

template<typename Temp>
inline void Administer::SaveDataToFile(const std::string& file, const std::vector<Temp>& _vector)
{

    ofstream outputFile(file);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file for writing: " << file << std::endl;
        return;
    }

    for (const auto& item : _vector) {
        outputFile << item.getId() << ' ' << item.getName() << '\n';
    }

    outputFile.close();
} 
