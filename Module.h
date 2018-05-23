#include "Inventory.h"

#pragma once
class Module
{
protected:
	bool is_terminated;
	Inventory* database;
public:
	Module(Inventory* db);
	~Module();
	virtual void Run();
	virtual void PerformOneIteration() = 0;
	virtual bool IsTerminated();
};