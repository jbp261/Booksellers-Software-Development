#pragma once
#include "MenuModule.h"
#include "RingUp.h"
#include "Report.h"
#include "InventoryModule.h"

class MainModule : public MenuModule
{
private:
	RingUp* c;
	InventoryModule* i;
	Report* r;
public:
	MainModule(Inventory* db);
	~MainModule();
	void PrintMenu();
	void ProcessUserInput();
};

