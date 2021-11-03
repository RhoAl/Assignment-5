/*
Name: Alex Rhoads
Class: CS361
Program: Assignment 5
Description: An MVP, that archives and saves an archival list. Meant to be in Python, but this version is in C++ to save time. Initial data structure is a stack. 
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include<fstream>

using namespace std;

const int MAX = 201;

struct node
{
	bool verifyW;	//If the word exists, this equals true
	bool verifyN;	//If the number exists, this equals true
	double num;	//Any number value
	char * word;	//Any string value
	node * next;
};



class stack
{
	//Class for the stack

	public:
		stack();
		~stack();
		void push(bool verifyN, bool verifyW, double num, char word []);	
		bool pop();
		void add();	//Adds an item to the list
		void remove();	//Removes an item from the list
		void display();	//Outputs list
		bool readfile();	//Reads from a file
		bool writefile();	//Writes to a file

	private:
		node * head;
		ifstream infile;
		ofstream outfile;
		void exPush(node * head, node *& temp);	//A seperate push process
};