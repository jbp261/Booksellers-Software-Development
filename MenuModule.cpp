#include "MenuModule.h"


MenuModule::MenuModule(Inventory* db) : Module(db)
{
}


MenuModule::~MenuModule()
{
}

void MenuModule::PerformOneIteration()
{
	PrintMenu();
	ProcessUserInput();
}