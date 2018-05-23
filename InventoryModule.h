#pragma once
#include "MenuModule.h"

class InventoryModule : public MenuModule
{
public:
	InventoryModule(Inventory* db);
	~InventoryModule();
	void PrintMenu();
	void ProcessUserInput();
};

