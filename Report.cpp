#define _CRT_SECURE_NO_WARNINGS

#include "Report.h"

Report::Report(Inventory *ptr) : MenuModule(ptr)
{

}

void Report::sortByAge()
{
  InventoryBook temp;
  int min_i;
  
  for (int i = 0; i < database->books.size() - 1; i++)
  {
      min_i = i;
      
      for (int j = i + 1; j < database->books.size(); j++)
      {
          if (database->books.at(j).getDate() < database->books.at(min_i).getDate())
              min_i = j;
      }
      
      temp = database->books.at(min_i);
      database->books.at(min_i) = database->books.at(i);
      database->books.at(i) = temp;
  }
  
  return;
}

void Report::sortByQuantity()
{
  int max_i;
  for (int i = 0; i < database->books.size(); i++) {
      max_i = i;
      for (int j = i + 1; j < database->books.size(); j++) {
          if (database->books[j].getQuantity() > database->books[max_i].getQuantity())
              max_i = j;
      }
      InventoryBook tmp;
      tmp = database->books[max_i];
      database->books[max_i] = database->books[i];
      database->books[i] = tmp;
  }
  
  return;
}

void Report::sortByWholCost()
{
  InventoryBook temp;
  int min_i;
  
  for (int i = 0; i < database->books.size() - 1; i++)
  {
      min_i = i;
      
      for (int j = i + 1; j < database->books.size(); j++)
      {
          if (database->books.at(j).getWholCost() < database->books.at(min_i).getWholCost())
              min_i = j;
      }
      
      temp = database->books.at(min_i);
      database->books.at(min_i) = database->books.at(i);
      database->books.at(i) = temp;
  }
  
  return;
}

void Report::listByQuantity()
{
  sortByQuantity();
  cout << *database;
  
  return;
}

void Report::listByAge()
{
  sortByAge();
  cout << *database;
  
  return;
}

void Report::listByWholCost()
{
  sortByWholCost();
  cout << *database;
      
  return;
}

// Updated to display quantity and total value as quantity * value
void Report::listTotalWholValue()
{
    double total = 0.0;

    cout << "\nWholesale value listing of all the books in inventory\n";

    cout << "------------------------------------------------------------\n\n";

    for (int i = 0; i < database->books.size(); i++)
    {
        cout << "\nTitle: " << database->books[i].getTitle() << endl;
        cout << "Wholesale Value: $" << setprecision(2) << fixed << database->books[i].getWholCost() << endl;
        cout << "Quantity: " << database->books[i].getQuantity() << endl;
        total += (database->books[i].getWholCost() * database->books[i].getQuantity());
    }

    cout << "\nTotal Wholesale Value: $" << setprecision(2) << fixed << total << endl;
  
  return;
}

// Updated to display quantity and total value as quantity * value
void Report::listTotalRetValue()
{
    double total = 0.0;

    cout << "\nRetail value listing of all the books in inventory\n";

    cout << "------------------------------------------------------------\n\n";

    for (int i = 0; i < database->books.size(); i++)
    {
        cout << "\nTitle: " << database->books[i].getTitle() << endl;
        cout << "Retail Value: $" << setprecision(2) << fixed << database->books[i].getRetCost() << endl;
        cout << "Quantity: " << database->books[i].getQuantity() << endl;
        total += (database->books[i].getRetCost() * database->books[i].getQuantity());
    }

    cout << "\nTotal Retail Value: $" << setprecision(2) << fixed << total << endl;
  
  return;
}

void Report::PrintMenu() {
	cout << "\n1. Display Inventory by Quantity";
	cout << "\n2. Display Inventory by Date Added";
	cout << "\n3. Display Inventory by Wholesale Value";
	cout << "\n4. Display Total Wholesale Value";
	cout << "\n5. Display Total Retail Value";
	cout << "\n6. Exit to previous menu\n";
}

void Report::ProcessUserInput()
{
	string userInput;
	getline(cin, userInput);
	if (userInput.length() > 1)
		throw "Invalid input";
	InventoryBook *temp;
	switch (userInput[0])
    {
	case '1':
		listByQuantity();
		break;
	case '2':
		listByAge();
		break;
	case '3':
		listByWholCost();
		break;
	case '4':
		listTotalWholValue();
		break;
	case '5':
		listTotalRetValue();
		break;
	case '6':
		is_terminated = true;
		break;
	default:
		throw "Invalid input";
		break;
	}
}