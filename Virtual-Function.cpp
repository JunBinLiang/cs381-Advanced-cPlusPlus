// Virtual-Function.cpp : Defines the entry point for the console application.
//





/*
#include <iostream>
using namespace std;

class Base {
	public:
	void show() {
	cout << "Base\n";
	}
};

class Derv1: public Base {
	public:
	void show() {
	cout << "Derv1\n";
	}
};


class Derv2: public Base {
	public:
	void show() {
	cout << "Derv2\n";
	}
};


int main() {
	Derv1 derv1;
	Derv2 derv2;
	Base *ptr;
	ptr = &derv1;
	ptr -> show();
	ptr = &derv2;
	ptr -> show();
	return 0;
}


//output:
//Base
//Base

*/

#include "stdafx.h"
#include <iostream>
using namespace std;

class Base {
public:
	virtual void show() {
		cout << "Base\n";
	}
};

class Derv1 : public Base {
public:
	void show() {
		cout << "Derv1\n";
	}
};


class Derv2 : public Base {
public:
	void show() {
		cout << "Derv2\n";
	}
};

int main() {
	Derv1 derv1;
	Derv2 derv2;
	Base *ptr;
	ptr = &derv1;
	ptr->show();
	ptr = &derv2;
	ptr->show();
	return 0;
}

