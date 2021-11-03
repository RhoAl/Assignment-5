#include "mvp.h"

int main ()
{
	int option = 0;	//option for a menu
	bool checkRead = false;
	bool checkWrite = false;
	stack archive;

	checkRead = archive.readfile();
	if(checkRead == true)
	{
		cout << "File read was successful" << endl;
	}
	else
	{
		cout << "File read failed" << endl;
	}

	do
	{
		//Main Menu
		cout << "\nPlease select an option" << endl;
		cout << "1 - Display the archive" << endl;
		cout << "2 - Add to the archve" << endl;
		cout << "3 - Delete from the archive" << endl;
		cout << "4 - Quit" << endl;

		//Input
		cout << "Option: ";
		cin >> option;
		cin.ignore(100, '\n');

		//Output
		switch (option)
		{
			case 1:
				cout << endl;
				archive.display();
				break;
			case 2:
				archive.add();
				break;
			case 3:
				archive.remove();
				break;
			case 4:
				break;
			default:
				cout << "Error: Selected option out of range" << endl;
				break;
		}
	}while(option != 4);

	checkWrite = archive.writefile();
	if(checkWrite == true)
	{
		cout << "File write was successful" << endl;
	}
	else
	{
		cout << "File write failed" << endl;
	}

	return 0;
}