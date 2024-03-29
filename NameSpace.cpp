// NameSpace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<vector>
using namespace std;

namespace space1 {
	class myclass {
		public:
			myclass() {
				cout << "space1 myclass" << endl;
			}

	};

}
namespace space2 {
	class myclass {
		public:
			myclass() {
				cout << "space2 myclass" << endl;
			}

	};
}
using namespace space1;
using namespace space2;


void aFunc() {
	using namespace std; // using directive
						 //...
	//int vector = 12; // a poorly named local variable...
	vector<int> a; // error! std::vector is hidden               
	std::vector<int> b; // OK, can use explicit qualification
						//...
}

namespace {
	int one = 10;
	int two = 20;
}


int main()
{
	using std::cout;
	space1::myclass my1;
	space2::myclass my2;
	//myclass m3;	compiler:my class is ambiguous


	//withous using and scope specifier
	cout << one << endl;
    return 0;
}

