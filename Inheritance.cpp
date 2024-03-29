// Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class Department {
public:
	void show() {
		cout << "You are in CS dept\n";
	}
	virtual void getData() = 0;
};

class Professor : public Department {
public:
	void getData() {
		Department::show();
		cout << "You are in Professor section\n";
	}
};

class Student : public Department {
public:
	void getData() {
		Department::show();
		cout << "You are in Students section\n";
	}
};


int main() {
	string s;
	std::cin >> s;
	Department *dept;
	Student student;
	if (s == "S") {
		// same as: Department *dept = new Student();
		// dept = &student;
		dept = new Student();
	}
	else {
		dept = new Professor();
	}
	dept->getData();
	return 0;
}

