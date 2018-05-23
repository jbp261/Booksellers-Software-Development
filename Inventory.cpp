#define _CRT_SECURE_NO_WARNINGS

#include "Inventory.h"

/*
    Default Constructor

    Open a binary file called "inventory.dat"
    Read InventoryBook objects from the file into the vector member
    Close the file
*/
Inventory::Inventory()
{
   strcpy(fileName, "inventory.dat");
   
   dataFile.open(fileName, ios::in | ios::binary);

   InventoryBook temp;
   while (dataFile.read(reinterpret_cast<char *>(&temp), sizeof(InventoryBook)))
       addBook(temp);
   
   dataFile.close();
}

/*
    Constructor with C-string parameter

    Open a binary file where its name is the parameter

    If the file cannot be opened
        Throw InvalidFile exception class

    Read InventoryBook objects from the file into the vector member
    Close the file
*/
Inventory::Inventory(char *f)
{
   strncpy(fileName, f, 128);
   
   dataFile.open(fileName, ios::in | ios::binary);
   
   if (!dataFile)
       throw InvalidFile();

   InventoryBook temp;
   while (dataFile.read(reinterpret_cast<char *>(&temp), sizeof(InventoryBook)))
       addBook(temp);
   
   dataFile.close();
}

/*
    addBook

    Push the InventoryBook parameter to the back of the InventoryBook vector
*/
void Inventory::addBook(InventoryBook &b)
{
   books.push_back(b);
   return;
}

/*
    searchBookByPartialIsbn

    returning pointer to the book which has this isbn
*/
InventoryBook* Inventory::searchBookByPartialIsbn(const char *partial_isbn) 
{
    int book_num = 1;
    vector<int> found_books;
    for (int i = 0; i < books.size(); i++)
    {
        if (strstr (books[i].getIsbn(), partial_isbn))
        {  // partial isbn exists in book's isbn
            found_books.push_back(i);
            cout << book_num << ") " << books[i].getIsbn() << " " << books[i].getTitle() << endl;
            book_num++;
        }
    }
    string answer;
    if (found_books.size() > 0)
    {
        if (found_books.size() == 1)
        {
            return &books[found_books[0]];
        }
        
        cout << "Enter the number of book you are interested in" << endl;
        getline(cin, answer);
        
        if (stol(answer) > 0 && stol(answer) <= found_books.size())
        {
            return &books[found_books[stol(answer) - 1]];
        }
    }
    else
        cout << "Nothing matches." << endl;
    
    return NULL;
}

/*
    to_lower

    converts a string to all lowercase characters
*/
string to_lower(string s)
{
	for (int i = 0; i < s.length(); i++)
    {
		// If any element is upper case, we lower it down.
		if (s[i] <= 'Z' && s[i] >= 'A')
        {
			s[i] = s[i] + 'a' - 'A';
		}
	}
	return s;
}

/*
    searchBookByPartialTitle

    returning pointer to the book which has this isbn
*/
InventoryBook* Inventory::searchBookByPartialTitle(const char *partial_title)
{
    int book_num = 1;
    vector<int> found_books;
    for (int i = 0; i < books.size(); i++)
    {
	    string s1 = books[i].getTitle();
	    string s2 = partial_title;
	    s1 = to_lower(s1);
	    s2 = to_lower(s2);
	    if (strstr(s1.c_str(), s2.c_str())) {  // partial title exists in book's title
            found_books.push_back(i);
            cout << book_num << ") " << books[i].getIsbn() << " " << books[i].getTitle() << endl; // Add author?
            book_num++;
        }
    }
    string answer;
    if (found_books.size() > 0)
    {
        if (found_books.size() == 1)
        {
            return &books[found_books[0]];
        }
        cout << "Enter the number of book you are interested in" << endl;
        getline(cin, answer);
        if (stol(answer) > 0 && stol(answer) <= found_books.size())
        {
            return &books[found_books[stol(answer) - 1]];
        }
    }
    else
        cout << "Nothing matches." << endl;
    return NULL;
    }

    void Inventory::writeToFile()
    {
    dataFile.open(fileName, ios::out | ios::binary);
   
    for (int i = 0; i < books.size(); i++)
        dataFile.write(reinterpret_cast<char *>(&books.at(i)), sizeof(InventoryBook));
   
    dataFile.close();
   
    return;
}

/*
    editBook

    Prompt user for option to edit InventoryBook member variable

    Display current value
    Read in new value
*/
void Inventory::editBook(InventoryBook *bookPtr)
{
	int choice;
	
	do {
		cout << "Enter the number of the field to edit (1-8):\n"
			<< "   1=title, 2=isbn, 3=author, 4=publisher,\n"
			<< "   5=quantity,  5=wholesale, 7=retail, 8=exit\n"
			<< "Enter choice: ";
		string userInput;
		try
        {
			getline(cin, userInput);
			if (userInput.length() > 1)
				throw "Invalid input";
			choice = userInput[0];
			if (choice < '1' || choice > '9')
            {
				throw "Invalid input";
			}
		}
		catch (char *e)
        {
			cout << e;
			continue;
		}
		switch (choice) {
		case '1':
			char temp[100];
			cout << "Existing title : " << bookPtr->getTitle() << endl;
			cout << "Enter new title: ";
			cin.getline(temp, 100);
		    bookPtr->setTitle(temp);
			break;
		case '2':
			char temp1[10];
			cout << "Existing isbn : " << bookPtr->getIsbn() << endl;
			cout << "Enter new isbn: ";
			cin.getline(temp1, 10);
			bookPtr->setIsbn(temp1);
			break;
		case '3':
			char temp2[30];
			cout << "Existing author : " << bookPtr->getAuthor() << endl;
			cout << "Enter new author: ";
			cin.getline(temp2, 30);
			bookPtr->setAuthor(temp2);
			break;
		case '4':
			char temp3[20];
			cout << "Existing publisher : " << bookPtr->getPublisher() << endl;
			cout << "Enter new publisher: ";
			cin.getline(temp3, 20);
			bookPtr->setPublisher(temp3);
			break;
		case '5':
			int temp5;
			cout << "Existing Qty-On-Hand : " << bookPtr->getQuantity() << endl;
			cout << "Enter new quantity: ";
			cin >> temp5;
			cin.ignore(80, '\n');
			bookPtr->setQuantity(temp5);
			break;
		case '6':
			double temp6;
			cout << "Existing wholesale : " << bookPtr->getWholCost() << endl;
			cout << "Enter new wholesale: ";
			cin >> temp6;
			cin.ignore(80, '\n');
			bookPtr->setWholCost(temp6);
			break;
		case '7':
			double temp7;
			cout << "Existing retail : " << bookPtr->getRetCost()<< endl;
			cout << "Enter new retail: ";
			cin >> temp7;
			cin.ignore(80, '\n');
			bookPtr->setRetCost(temp7);
			break;
		case '8':
			cout << "Edit complete.\n\n";
			break;
		}

	} while (choice != '8');

    return;
}

/*
    deleteBook

    Copy all InventoryBook objects in vector to new vector except parameter
    Prompt for confirmation of deletion
*/
void Inventory::deleteBook(InventoryBook *partial_search)
{
	vector<InventoryBook> temp;
	vector<InventoryBook> *ptr = &books;
    string userInput;

	for (int i = 0; i < books.size(); i++)
	{
		if (books.at(i) == *partial_search)
			continue;
		else
			temp.push_back(books.at(i));
	}
	
    cout << "\nConfirm Deletion of " << partial_search->getTitle() << " (Y/N): ";

	try
    {
		getline(cin, userInput);
		if (userInput.length() > 1)
			throw "Invalid input";
		if (userInput[0] != 'n' && userInput[0] != 'N' && userInput[0] != 'y' && userInput[0] != 'Y')
        {
			throw "Invalid input";
		}
	}
	catch (char *e)
    {
		cout << e << endl;
		return;
	}
    
    if (userInput[0] == 'y' || userInput[0] == 'Y')
    {
        books.clear();
	    temp.swap(books);
	    cout << "\nDELETED!";
    }
    else
        cout << partial_search->getTitle() << " not deleted.\n";

    return;
}

/*
    operator<<

    Return ostream object containing all InventoryBook objects from vector
*/
ostream& operator<< (ostream &out, Inventory &database)
{
   for (int i = 0; i < database.books.size(); i++)
       out << database.books.at(i);
   
   return out;
}

