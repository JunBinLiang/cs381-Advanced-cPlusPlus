// Casting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


class shape { public:virtual ~shape() {} };
class circle :public shape {};
class square :public shape {};

int main()
{
	//no casting
	cout << "No casting" << endl;
	int num1 = 10;
	int num2 = 20;
	double ans = num1 / num2;  
	cout << ans<<endl<<endl;

	//c-style casting
	cout << "c casting" << endl;
	ans = (double)(num1) / num2;
	cout << ans << endl<<endl;
	
	//static casting
	cout << "static casting" << endl;
	ans = static_cast<double>(num1) / num2;
	cout << ans << endl << endl;


	//const casting
	cout << "const casting" << endl;
	const int a = 10;
	int *b = const_cast<int*>(&a);    // int *b=&a will cause compile error
	cout << *b << endl << endl;


	//dynamic casting
	cout << "dynamic casting" << endl;

	shape *b1 = new circle; //Upcasting
	square* s = dynamic_cast<square*> (b1);//downcasting to incorrect type
	(s != NULL) ? cout << "Right cast1" << endl : cout << "Wrong cast1" << endl;
	circle *c = dynamic_cast<circle*> (b1);//downcasting to correct type
	(c != NULL) ? cout << "Right cast2" << endl : cout << "Wrong cast2" << endl;
	cout << endl;


	//reinterpret_cast
	cout << "reinterpret_cast" << endl;
	cout << "This is unsafe. It can convert int to pointer and any class pointer to any class pointer." << endl;
	/*
	   //error will occur
	   int a = 0x1233254;
	   char *ptr = reinterpret_cast<char*> (a);
       *ptr = 3;
	   cout<<*pte;
       return 0;
	*/

    return 0;
}

