#include"InventoryBook.h"
#include"Inventory.h"
#include "Module.h"

class RingUp : public Module
{
private:
	vector<InventoryBook> items;
    double taxrate;
	
public:
	RingUp(Inventory *, double tr);
	
	void getItem();
	void PerformOneIteration();
	void ringUpScreen();
};


//void cashier()
//{
//	cout << "\n\t\tCashier Module\n";
//char choice;
//
//
//
//RingUp transection;
//
//do
//{
//	transection.getItem(database);
//	cout << endl << "Do you want to ring up more books? (Y/N): ";
//	cin >> choice;
//	cin.ignore(80, '\n');
//
//	while ((choice != 'y') && (choice != 'Y') && (choice != 'n') && (choice != 'N')) {
//		cout << "Please enter 'Y' or 'N': ";
//		cin >> choice;
//		cin.ignore(80, '\n');
//	}
//
//
//} while ((choice == 'y') || (choice == 'Y'));
//
//transection.ringUpScreen();
//}