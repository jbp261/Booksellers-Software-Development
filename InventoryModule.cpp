#include "InventoryModule.h"


InventoryModule::InventoryModule(Inventory* db) : MenuModule(db)
{
}


InventoryModule::~InventoryModule()
{
}

void InventoryModule::PrintMenu()
{
	cout << "\n1. Search By Partial ISBN";
	cout << "\n2. Search By Partial Title";
	cout << "\n3. Add Book";
	cout << "\n4. Edit Book";
	cout << "\n5. Delete Book";
	cout << "\n6. Exit to previous menu\n";
}

void InventoryModule::ProcessUserInput()
{
	string userInput;
	getline(cin, userInput);
	
    if (userInput.length() > 1)
		throw "Invalid input";
	
    InventoryBook *temp;
	
    switch (userInput[0])
    {
	    case '1':
		    cout << "Enter search string: ";
		    getline(cin, userInput);
		    if (temp = database->searchBookByPartialIsbn(userInput.c_str()))
			    cout << *temp;
		    break;
	    case '2':
		    cout << "Enter search string: ";
		    getline(cin, userInput);
		    if (temp = database->searchBookByPartialTitle(userInput.c_str()))
			    cout << *temp;
		    break;
	    case '3':
		    temp = new InventoryBook();
		    temp->getData();
		    database->addBook(*temp);
		    delete temp;
		    break;
	    case '4':
		    cout << "Searching by title. Enter search string: ";
		    getline(cin, userInput);
		    if (temp = database->searchBookByPartialTitle(userInput.c_str()))
			    database->editBook(temp);
		    break;
	    case '5':
		    cout << "Searching by title. Enter search string: ";
		    getline(cin, userInput);
		    if (temp = database->searchBookByPartialTitle(userInput.c_str()))
			    database->deleteBook(temp);
		    break;
	    case '6':
		    is_terminated = true;
		    break;
	    default:
		    throw "Invalid input";
		    break;
	}
}