#include "mvp.h"

//Implement Stack Class

stack::stack()
{
	//Constructer
	head = NULL;
	//infile = new ifstream;
	//outfile = new ofstream;
}



stack::~stack()
{
	//Destructor;

	//Deallocating items
/*
	if (infile != NULL)	
	{
		delete infile;
		infile = NULL;
	}

	if (outfile != NULL)
	{
		delete outfile;
		outfile = NULL;
	}
*/
	//Loop through the list until everything is deallocated
	do
	{
		node * temp = head;	//Temporary pointer to head, so it can be deleted as head goes down the list
		head = head->next;

		if(temp)
		{
			if (temp->word != NULL)
				delete [] temp->word;
			delete temp;
		}
	}while(head != NULL);
}



void stack::push(bool verifyN, bool verifyW, double num, char word [])
{
	//Push a node into the stack

	//Allocation
	node * temp = new node;
	temp->verifyN = verifyN;
	temp->verifyW = verifyW;
	temp->num = num;
	if(word != NULL)
		temp->word = new char [MAX];

	//Copying
	if(word != NULL)
	{
		strcpy(temp->word, word);
	}
	else
	{
		temp->word = NULL;	//There is no text attatched to the node
	}

	//Placement
	temp->next = head;
	head = temp;
}



bool stack::pop()
{
	//Delete from the front of the list
	if (head != NULL)	
	{
		//Moving down
		node * temp = head;
		head = head->next;

		//deletion
		if(temp->word != NULL)
			delete [] temp->word;
		delete temp;

		return true;	//Success
	}

	else
	{
		return false;
	}
}

void stack::add()
{
	//Adds an item to the list

	//Checks for what to add
	bool checkW = false;	//Check for the word
	bool checkN = false;	//Check for the number
	char ans [MAX];	//Answer

	//The stuff to add;
	bool verifyN = false;
	bool verifyW = false;
	double num = 0;
	char word [MAX];

	//Asks what the user wants to add to the list
	cout << "Would you like to add a number? Yes or no? ";
	cin.get(ans, MAX, '\n');
	cin.ignore(1000, '\n');
	if (toupper(ans[0]) == 'Y')
		checkN = true;
	else
		checkN = false;

	cout << "Would you like to add some text? Yes or no? ";
	cin.get(ans, MAX, '\n');
	cin.ignore(1000, '\n');
	if (toupper(ans[0]) == 'Y')
		checkW = true;
	else
		checkW = false;


	//Adding the number
	if(checkN == true)
	{
		cout << "Please enter the number: ";
		cin >> num;
		cin.ignore(100, '\n');

		verifyN = true;	//This is what allows for the number to be displayed
	}

	//Adding the word
	if(checkW == true)
	{
		cout << "Please enter your text: ";
		cin.get(word, MAX, '\n');
		cin.ignore(1000, '\n');

		verifyW = true;
	}

	push(verifyN, verifyW, num, word);	//Actual creation of the node
}



void stack::remove()
{
	//Removes a node
	bool check = pop();

	if (check == true)
		cout << "\nNode removed.\n";
	else
		cout << "\nError, node does not exist.\n";
}



void stack::display()
{
	//Outputs list

	node * temp = head;	//node for transveral

	while(temp)
	{
		//Loop until end of the list

		if (temp->verifyN == true)
			cout << "Number: " << temp->num << endl;

		if (temp->verifyW == true)
			cout << "Word: " << temp->word << endl;

		cout << endl;
		temp = temp->next;
	}
}



void stack::exPush(node * head, node *& temp)
{
	//External push

	if(!head)
	{
		return;
	}

	else
	{
		node * current = new node;

		current->verifyN = head->verifyN;
		current->verifyW = head->verifyW;
		current->num = head->num;
		if(head->word != NULL)
			current->word = new char [MAX];

		//Copying
		if(head->word != NULL)
		{
			strcpy(current->word, head->word);
		}
		else
		{
			current->word = NULL;	//There is no text attatched to the node
		}

		//Placement
		current->next = temp;
		temp = current;

		exPush(head->next, temp);
	}

}



bool stack::readfile()
{
	//Reads an external file

	infile.open("list.txt");

	if(!infile)
	{
		return false;	//The file does not exist
	}

	else
	{
		//Stuff to copy into the list

		while(!infile.eof())
		{
			bool verifyW = false;
			bool verifyN = false;
			double num = 0;
			char word [MAX] = "a";

			if (infile)
			{
				//Reading from file
				infile >> verifyW;
				infile.ignore(100, '\n');
				infile >> verifyN;
				infile.ignore(100, '\n');
				infile >> num;
				infile.ignore(100, '\n');
				infile.getline(word, MAX);

				if (verifyN != false || verifyW != false)
					push(verifyN, verifyW, num, word);	//Puts the data into the list
			}
		}

		infile.close();
		return true;
	}
}



bool stack::writefile()
{
	//Writes to an external file

	outfile.open("list.txt");

	if (!outfile)
	{
		return false;
	}

	else
	{
		node * temp = NULL;
		exPush(head, temp);

		while(temp != NULL)
		{
			if(temp)
			{
				outfile << temp->verifyW << endl;
				outfile << temp->verifyN << endl;
				outfile << temp->num << endl;
				outfile << temp->word << endl;

				temp = temp->next;
			}

		}

		outfile.close();
		return true;
	}
}