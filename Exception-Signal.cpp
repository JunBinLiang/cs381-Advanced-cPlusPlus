// Exception-Signal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
#include <csignal> 
using namespace std;

void signal_handler(int signal_num) {
	cout << "Interrupt signal is (" << signal_num << ").\n";
	// terminate program   
	
	cout << "without exit->Infinite Loop" << endl;
	//exit(signal_num);
}

int main() {
	int count = 0;
	signal(SIGSEGV, signal_handler);
	// register signal SIGSEGV and signal handler   

	while (++count) {
		cout << "I liked jiejie" << endl;
		if (count == 5)
			raise(SIGSEGV);
	}
	return 0;
}
