#define _CRT_SECURE_NO_WARNINGS

/*
   Test Build 2014.06.20

   -Added Report class
   -Added InventoryBook class
   -Minor changes to base Book class
   -Added ctime library functions
   -Removed date strings from sample_books.txt
   -Modified Inventory class to use InventoryBook objects
   -Edit and delete functions of Inventory need to be rewritten
   -Currently does not compile with VS 2010

   2014.06.24

   -Added RingUp class for cashier module functionality
   -Fixed text file encoding in sample_books.txt
*/

#include <iostream>
#include <string>
#include "Inventory.h"
#include "MainModule.h"
using namespace std;


int main(void)
{
    Inventory database;
    MainModule m(&database);
    m.Run();
    database.writeToFile();

    return 0;
}
