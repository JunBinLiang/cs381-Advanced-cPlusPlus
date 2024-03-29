// Lambda.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <functional>
#include <vector>
using namespace std;


/*	Danger Lambda

danger, since the lambda refer to the local variable that will dead after the function return
void addDivisorFilter()
{
	auto calc1 = computeSomeValue1();
	auto calc2 = computeSomeValue2();
	auto divisor = computeDivisor(calc1, calc2);
	filters.emplace_back( // danger!
	[&divisor](int value) { return value % divisor == 0; } // ref to
	); // divisor
}
*/


//[=]  default by value copy


/*
wrong! Captures apply only to non-static local variables (including parameters) visible inthe scope where the lambda is created. In the body of Widget::addFilter, divisor
is not a local variable, it’s a data member of the Widget class.

only local variavle or parameter can be capture into the lambda

class Widget {
	public:
		void addFilter() const; // add an entry to filters
	private:
		int divisor; // used in Widget's filter
};

void Widget::addFilter() const
{
	filters.emplace_back(
	[=](int value) { return value % divisor == 0; }
);
}

*/



/*

[]	Capture nothing (or, a scorched earth strategy?)
[&]	Capture any referenced variable by reference
[=]	Capture any referenced variable by making a copy
[=, &foo]	Capture any referenced variable by making a copy, but capture variable foo by reference
[bar]	Capture bar by making a copy; don't copy anything else
[this]	Capture the this pointer of the enclosing class

*/


class Foo
{
public:
	Foo() : _x(3) {}
	void func()
	{
		// a very silly, but illustrative way of printing out the value of _x
		[this]() { cout << _x<<endl; } ();

		//[]() { cout << _x<<endl; } (); compling error
	}

private:
	int _x;
};


//another example about    how to pass lambda  (lambda's type)
class AddressBook
{
	public:
		std::vector<string> findMatchingAddresses(std::function<bool(const string&)> func)
		{
			std::vector<string> results;
			for (auto itr = _addresses.begin(), end = _addresses.end(); itr != end; ++itr)
			{
				// call the function passed into findMatchingAddresses and see if it matches
				if (func(*itr))
				{
					results.push_back(*itr);
				}
			}
			return results;
		}

	private:
		std::vector<string> _addresses;
};



//standard callback example


class EmailProcessor
{
public:
	void receiveMessage(const std::string& message)
	{
		if (_handler_func)
		{
			_handler_func(message);
		}
		// other processing
	}
	void setHandlerFunc(std::function<void(const std::string&)> handler_func)
	{
		_handler_func = handler_func;
	}

private:
	std::function<void(const std::string&)> _handler_func;
};




int main()
{
	// In C++11, if the compiler can deduce the return value of the lambda function, it will do it rather than force you to include it
	auto func = []() { cout << "Bsic Lambda syntax"<<endl<<endl; };
	func(); // now call the function


	[] { cout << "Example of lambda without argument list"<<endl<<endl; }();

	//putting [&] for the capture specification, rather than []. The empty [] 
	//tells the compiler not to capture any variables, whereas the   [&] specification tells the compiler to perform variable capture.
	
	Foo f;
	f.func();

    return 0;
}

