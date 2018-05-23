#pragma once
#include "Module.h"

class MenuModule : public Module
{
public:
	MenuModule(Inventory* db);
	~MenuModule();
	virtual void PrintMenu() = 0;
	virtual void ProcessUserInput() = 0;
	void PerformOneIteration();
};

