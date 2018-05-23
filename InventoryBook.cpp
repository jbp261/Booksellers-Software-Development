#define _CRT_SECURE_NO_WARNINGS

#include "InventoryBook.h"

/*
    Default constructor, calls base class Book default constructor

    Set all member variables to 0
    Set dateAdded using the time function
*/
InventoryBook::InventoryBook() : Book()
{
    quantity = wholCost = retCost = lastPurchase = 0;
    time(&dateAdded);
}

/*
    getData

    Prompt user for each member variable
    Set member variables using strncpy to avoid overflow
    Throw exceptions for invalid numerical input
*/
void InventoryBook::getData()
{
    string userInput;
  
    cout << "Enter book title: ";
    getline(cin, userInput);
    strncpy(title, userInput.c_str(), 100);

    cout << "Enter ISBN no. : ";
    getline(cin, userInput);
    strncpy(isbn, userInput.c_str(), 11);

    cout << "Enter author's name: ";
    getline(cin, userInput);
    strncpy(author, userInput.c_str(), 30);

    cout << "Enter publisher's name: ";
    getline(cin, userInput);
    strncpy(publisher, userInput.c_str(), 20);
  
    cout << "Enter quantity: ";
    getline(cin, userInput);
    try
    {
        quantity = stol(userInput);
    }
    catch (invalid_argument)
    {
        cout << "Invalid argument.\n";
        return;
    }
    catch (out_of_range)
    {
        cout << "Number is too large.\n";
        return;
    }
  
    cout << "Enter wholesale price: ";
    getline(cin, userInput);
    try
    {
        wholCost = stod(userInput);
    }
    catch (invalid_argument)
    {
        cout << "Invalid argument.\n";
        return;
    }
    catch (out_of_range)
    {
        cout << "Number is too large.\n";
        return;
    }
  
    cout << "Enter retail price: ";
    getline(cin, userInput);
    try
    {
        retCost = stod(userInput);
    }
    catch (invalid_argument)
    {
        cout << "Invalid argument.\n";
        return;
    }
    catch (out_of_range)
    {
        cout << "Number is too large.\n";
        return;
    }

    setDate();
  
    return;
}

/*
    operator<<

    Construct a time string using localtime and asctime functions of the ctime library
    Return an ostream object with properly formatted data
*/
ostream& operator<< (ostream &outstream, InventoryBook &ib)
{
    struct tm *timeinfo = localtime(&ib.dateAdded);
  
    outstream << ib.isbn << endl;
    outstream << ib.title << endl;
    outstream << ib.author << endl;
    outstream << "Quantity: " << ib.quantity << endl;
    outstream << "Wholesale Cost: $" << setprecision(2) << fixed << ib.wholCost << endl;
    outstream << "Retail Cost: $" << setprecision(2) << fixed << ib.retCost << endl;
    outstream << "Added On: " << asctime(timeinfo) << endl << endl;
  
    return outstream;
}

/*
    operator==

    If 2 InventoryBook objects have the same ISBN
        Return true
    Else
        Return false
*/
bool InventoryBook::operator== (const InventoryBook &right)
{
    if (strcmp(isbn, right.isbn) == 0)
        return true;
    else
        return false;
}

/*
    sale

    If the quantity sold is greater than or equal to the quantity on hand
        Subtract the quantity sold
        Return true
    Else
        Display an error for the user
        Return false
*/
bool InventoryBook::sale(int s)
{
	if (quantity >= s)
    {
		quantity -= s;
		return true;
	}
	else
    {
		cout << "The quantity exceeds number of available books" << endl;
        return false;
	}
}