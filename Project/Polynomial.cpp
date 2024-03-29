// Polynomial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class Node {

	public:
		double coeeficient;
		double power;
		Node* next;
		char mathOperator='+';
		Node(double c,double p) {
			this->coeeficient = c;
			this->power = p;
			this->next = NULL;
		}


		Node(double c, double p, char mathOperator) {
			this->mathOperator = mathOperator;
			if (mathOperator == '+') {
				this->coeeficient = c;
				this->power = p;
				this->next = NULL;
			}
			if (mathOperator == '-') {
				this->coeeficient = 0 - c;
				this->power = p;
				this->next = NULL;
			
			}

		
		}

		void print() {
			// output the x form
			if (this->coeeficient == 0) {
				return;
			}


			if (power == 0) {
				cout  << coeeficient ;
			}
			else {
			
				if (coeeficient > 0) {
					if (coeeficient == 1) {
						cout << mathOperator << "X^" << power ;
						return;
					}
					cout << mathOperator << coeeficient << "X^" << power;
				}
				else {
					cout  << coeeficient << "X^" << power ;
				}
				//cout << mathOperator << coeeficient << "X^" << power << endl;
			}
			
		}

};

class LinkedList {
	private:
		//Node * dummyhead;
		int size = 0;

	public:
		Node * dummyhead;
		LinkedList() {
			dummyhead = new Node(0,0);
		}


		void minusInsert(Node* newNode) {
			if (dummyhead->next == NULL) {
				dummyhead->next = newNode;
				return;
			}
			Node* current = dummyhead->next;
			while (current != NULL) {
				if (current->power == newNode->power) {
					current->coeeficient = current->coeeficient - newNode->coeeficient;
					delete newNode;
					return;
				}
				current = current->next;
			}
			current = dummyhead;
			while (current->next != NULL)
			{
				if (newNode->power < current->next->power) {
					newNode->next = current->next;
					current->next = newNode;
					return;
				}
				current = current->next;
			}
			current->next = newNode;

		
		}


		//////////////////can not use vector

		LinkedList* productInsert(LinkedList* otherList) {

			LinkedList* copyList = new LinkedList();
			Node* current1 = this->dummyhead->next;
			
			while (current1 != NULL) {
				Node *newNode = new Node(current1->coeeficient, current1->power);
				copyList->insert(newNode);
				current1 = current1->next;
			}
			//LinkedList* old=
			LinkedList* result = new LinkedList();


			Node* otherCurrent = otherList->dummyhead->next;
			while (otherCurrent != NULL) {
				Node* copyCurrent = copyList->dummyhead->next;
				while (copyCurrent != NULL) {
					Node* newNode = new Node(copyCurrent->coeeficient*otherCurrent->coeeficient,copyCurrent->power+otherCurrent->power);
					result->insert(newNode);
					copyCurrent = copyCurrent->next;
				}

				otherCurrent = otherCurrent->next;
			
			}

			//result->print();
			delete copyList;
			return result;
		}

		/////////////////////////////////////////////////////////////

		// can also use in plus
		void insert(Node* newNode) {
			if (dummyhead->next == NULL) {
				dummyhead->next = newNode;
				return;
			}
			Node* current = dummyhead->next;
			//linear search, if they have the same power
			while (current != NULL) {
				if (current->power == newNode->power) {
					current->coeeficient = current->coeeficient + newNode->coeeficient;
					delete newNode;
					return;
				}
				current = current->next;
			}

			current = dummyhead;
			while (current->next != NULL) 
			{
				if (newNode->power < current->next->power) {
					newNode->next = current->next;
					current->next = newNode;
					return;
				}
				current = current->next;
			}
			current->next = newNode;
		
		}

		// LinkedList must support sum, difference and product operator


		void print() {
			Node* current = dummyhead->next;
			while (current != NULL) {
				current->print();
				current = current->next;
			}
			cout << endl;
		}


		~LinkedList() {
			while (dummyhead != NULL) {
				Node* old = dummyhead;
				dummyhead = dummyhead->next;
				delete old;
			}
		}
};


class Polynomial {
	private:
		string expression;
		LinkedList* list; //list for the polnomial
	
	public:
		Polynomial() {
			list = new LinkedList();
		}

		Polynomial(string s) {
			this->expression = s;
			list = new LinkedList();
			conversion();
			list->print();
			
		}
		// convert the expression into the linkedlist
		
		void conversion() {
			char mathOperator;
			int i = 0;
			
			while (i < expression.size())
			{
				
				if (expression[i] == '(' || expression[i] == ')') {
					continue; //skip, since they are only addtion and subtration in polnomian, they have the same order
				}

				
				//////////////////////////////////////////////////

				if (i == 0&& expression[i]!='+'&&expression[i]!='-')
				{
				
					if (expression[i] == 'x') 
					{ //coeeficient=1
						int coeeficient = 1;
						int power = 0;
						if (expression[i + 1] != '^') 
						{
							//cout << "first x" << endl;
							power = 1;
							Node* newNode = new Node(coeeficient, power, '+');
							this->list->insert(newNode);
							i++;
							continue;
						}

						else {
							int coeeficient = 1;
							int power = 0;
							bool negativePower = false;
							i++;
							i++;
							if (expression[i] == '-') {
								negativePower = true;
								i++;
							}
							while (isdigit(expression[i])) {
								power = power * 10 + (expression[i] - 48);
								i++;
							}
							if (negativePower) {
								power = -power;
								Node* newNode = new Node(coeeficient, power, '+');
								list->insert(newNode);
							}
							else {
								Node* newNode = new Node(coeeficient, power, '+');
								list->insert(newNode);
							}
							continue;
						}

					}
					//start with a number
					else {
						int coeeficient = 0;
						int power = 0;
						while (isdigit(expression[i])) 
						{
							coeeficient = coeeficient * 10 + (expression[i] - 48);
							i++;
						}
						if (expression[i] != 'x') {
							power = 0;
							Node* newNode = new Node(coeeficient, power, '+');
							list->insert(newNode);
							continue;
						}
						else
						{
							bool negativePower = false;
							if (expression[i + 1] != '^') {
								power = 1;
								Node* newNode = new Node(coeeficient, power, '+');
								list->insert(newNode);
								continue;
							}
							i++;
							i++;
							if (expression[i] == '-') {
								negativePower = true;
								i++;
							}
							while (isdigit(expression[i])) {
								power = power * 10 + (expression[i] - 48);
								i++;
							}
							if (negativePower) {
								power = -power;
								Node* newNode = new Node(coeeficient, power, '+');
								list->insert(newNode);
							}
							else {
								Node* newNode = new Node(coeeficient, power, '+');
								list->insert(newNode);
							}
							continue;
						}

					
					
					}
					continue;
				}//i=0





				if (expression[i] == '+' || expression[i] == '-') 
				{

					mathOperator = expression[i];
					// get the number
					i++;
					int coeeficient = 0;
					int power = 0;
					
					while (isdigit(expression[i])) {
						coeeficient = coeeficient * 10 + (expression[i] - 48);
						i++;
					}
					if (coeeficient == 0) {
						coeeficient = 1;
					}
					
					if (expression[i] != 'x') {
						power = 0;
						Node* newNode = new Node(coeeficient, power, mathOperator);
						list->insert(newNode);
						continue;
					}
					else
					{
						//out << " equal x" << endl;
						bool negativePower = false;
						if (expression[i + 1] != '^') {
							power = 1;
							Node* newNode = new Node(coeeficient, power, mathOperator);
							list->insert(newNode);
							continue;
						}
						i++;
						i++;
						if (expression[i] == '-') {
							negativePower = true;
							i++;
						}
						while (isdigit(expression[i])) {
							power = power * 10 + (expression[i] - 48);
							i++;
						}
						if (negativePower) {
							power = -power;
							Node* newNode = new Node(coeeficient, power, mathOperator);
							list->insert(newNode);
						}
						else {
							Node* newNode = new Node(coeeficient, power, mathOperator);
							list->insert(newNode);
						}
						continue;
					}
					continue;
				}
				i++;
			}
		
		}

		LinkedList* getList() {
			return this->list;
		
		}

		void print() {
			this->list->print();
		}

		Polynomial* operator+(Polynomial* other) {
			Polynomial* result = new Polynomial();
			Node* current1 = this->list->dummyhead->next;
			while (current1) {
				Node* newNode = new Node(current1->coeeficient, current1->power);
				result->getList()->insert(newNode);
				current1 = current1->next;
			}

			Node* current2 = other->getList()->dummyhead->next;
			while (current2) {
				Node* newNode = new Node(current2->coeeficient, current2->power);
				result->getList()->insert(newNode);
				current2 = current2 -> next;
			}
			result->print();
			return result;
		
		}

		Polynomial* operator-(Polynomial* other) 
		{
			Polynomial* result = new Polynomial();
			Node* current1 = this->list->dummyhead->next;
			while (current1) {
				Node* newNode = new Node(current1->coeeficient, current1->power);
				result->getList()->insert(newNode);
				current1 = current1->next;
			}

			Node* current2 = other->getList()->dummyhead->next;
			while (current2) {
				Node* newNode = new Node(current2->coeeficient, current2->power);
				result->getList()->minusInsert(newNode);
				current2 = current2->next;
			}
			result->print();
			return result;
		}

		void setList(LinkedList* copy) {
			LinkedList* old = this->list;
			this->list = copy;
			delete old;
		
		}

		Polynomial* operator*(Polynomial* other)
		{
			Polynomial* result = new Polynomial();
			Node* current1 = this->list->dummyhead->next;
			while (current1) {
				Node* newNode = new Node(current1->coeeficient, current1->power);
				result->getList()->insert(newNode);
				current1 = current1->next;
			}  //insert the first one first

			LinkedList* resultList= result->getList()->productInsert(other->getList());
			result->setList(resultList);
			result->print();
			return result;
		}



		~Polynomial() {
			delete list; // call the destructor of the list
		}

};




int main()
{
	
	LinkedList list;
	Node* node1 = new Node(10, 2);
	Node* node2 = new Node(10, 1);
	Node* node3 = new Node(11, 2);
	Node* node4 = new Node(11, 3);
	list.insert(node1);
	list.insert(node2);
	list.insert(node3);
	list.insert(node4);
	//list.print();

	ifstream input;
	input.open("input.txt");

	string line1;
	string line2;
	input >> line1;
	input >> line2;
	Polynomial *p1=new Polynomial(line1);
	Polynomial *p2 = new Polynomial(line2);
	(*p1) + p2;
	(*p1) - p2;
	cout << endl;
	(*p1) * p2;

    return 0;
}

