#include "MainModule.h"


MainModule::MainModule(Inventory* db) : MenuModule(db)
{
	c = new RingUp(db, 0.08);
	i = new InventoryModule(db);
	r = new Report(db);
}


MainModule::~MainModule()
{
	delete c;
	delete i;
	delete r;
}

void MainModule::PrintMenu()
{
	cout << "\n1. Cashier Module";
	cout << "\n2. Inventory Database Module";
	cout << "\n3. Report Module";
	cout << "\n4. Quit\n";
}

void MainModule::ProcessUserInput()
{
	string userInput;
	getline(cin, userInput);
	if (userInput.length() > 1)
		throw "Invalid input";
	switch (userInput[0])
    {
		case '1':
			c->Run();
			break;
		case '2':
			i->Run();
			break;
		case '3':
			r->Run();
			break;
		case '4':
			is_terminated = true;
			break;
		default:
			throw "Invalid input";
			break;
	}
}
