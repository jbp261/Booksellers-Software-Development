#include "Module.h"


Module::Module(Inventory* db)
{
	database = db;
	is_terminated = false;
}


Module::~Module()
{
}

void Module::Run()
{
    if (IsTerminated()) is_terminated = false;

	while (!IsTerminated())
    {
		try
        {
			PerformOneIteration();
		}
		catch (char* e)
        {
			cout << e << endl;
		}
	}
}

bool Module::IsTerminated()
{
	return is_terminated;
}
