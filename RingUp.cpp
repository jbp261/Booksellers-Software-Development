#include"RingUp.h"

//const double TAX_RATE = 0.08;

RingUp::RingUp(Inventory *ptr, double tr) : Module(ptr)
{
    taxrate = tr;
    database = ptr;
}

void RingUp::getItem()
{
	string searchString;
	int qty;
    InventoryBook *temp;

	cout << "Enter a full or partial title of the book your are looking for: ";
	getline(cin, searchString);

	// We should check if pointer is NULL before using it
	if (!(temp = database->searchBookByPartialTitle(searchString.c_str())))
    {
		return;
	}

	cout << "Enter the purchase quantity: ";
	// Reading input in this way is better since we don't need to clear cin after the previous input
	string userInput;
	getline(cin, userInput);
	qty = stol(userInput);

	if (!temp->sale(qty))
    {
		return;
	}
    temp->setLastPurchase(qty);

	items.push_back(*temp);
	return;
}

void RingUp::ringUpScreen()
{
	double subtotal = 0.0, tax, total;
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);

	cout << "Serendipity Booksellers\n\n";
	cout << asctime(timeinfo) << endl;
	cout << left;
	cout << setw(7) << "Qty"
		<< setw(17) << "ISBN"
		<< setw(28) << "Title"
		<< setw(10) << "Price"
		<< setw(10) << "Total"
		<< endl;

	
	cout.fill('-');
	cout << setw(72) << "-" << endl;
	cout.fill(' ');


	
	for (int j = 0; j < items.size(); j++)
		subtotal = subtotal + (static_cast<double> (items[j].getLastPurchase()) * items[j].getRetCost());
	tax = subtotal * taxrate;
	total = subtotal + tax;

	for (int i = 0; i < items.size(); i++)
	{
		cout << setprecision(2) << fixed << showpoint;
		cout << setw(7) << items[i].getLastPurchase()
			<< setw(17) << items[i].getIsbn()
			<< setw(24) << items[i].getTitle()
			<< right << setw(3) << "$" << right << setw(6) << items[i].getRetCost()
			<< right << setw(4) << "$" << right << setw(6) << items[i].getLastPurchase() * items[i].getRetCost()
			<< left << endl;

	}
	

	cout << endl << endl;
	cout << setprecision(2) << fixed << showpoint;

	cout << setw(24) << ' '
		<< setw(36) << left << "Subtotal"
		<< "$" << right << setw(6) << subtotal
		<< endl;
	cout << setw(24) << ' '
		<< setw(36) << left << "Tax"
		<< "$" << right << setw(6) << tax
		<< endl;
	cout << setw(24) << ' '
		<< setw(36) << left << "Total"
		<< "$" << right << setw(6) << total
		<< endl;

	cout << endl << "Thank You for Shopping at Serendipity!"
		<< endl;

}

void RingUp::PerformOneIteration()
{
	cout << "Do you want to purchase a book?\nHit Y to select a book or N to proceed to checkout." << endl;
	string userInput;
	getline(cin, userInput);
	
    if (userInput.length() > 1)
		throw "Invalid input";
	if (userInput[0] == 'Y' || userInput[0] == 'y')
    {
		getItem();
	}
	else if (userInput[0] == 'N' || userInput[0] == 'n')
    {
		if (items.size() > 0)
        {
			ringUpScreen();
		}
		else
        {
			cout << "You have no books selected" << endl;
		}
		is_terminated = true;
	}
	else
    {
		throw "Invalid input";
	}
}