#define _CRT_SECURE_NO_WARNINGS

#ifndef INVENTORY_H
#define INVENTORY_H

#include "InventoryBook.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

/*
    Inventory Class

    Private member variables:
        fstream object for the data file
        C-string for the file name
        Vector of InventoryBook objects

    Public member functions:
        Default constructor and constructor with C-string parameter
        Exception class InvalidFile
        addBook with InventoryBook pointer parameter
        Search by partial title and partial ISBN
*/
class Inventory
{
private:
  fstream dataFile;
  char fileName[128];
  vector<InventoryBook> books;
  
public:
  Inventory();
  Inventory(char *f);
  class InvalidFile {};
  void addBook(InventoryBook &b);
  InventoryBook *searchBookByPartialIsbn(const char *partial_isbn);
  InventoryBook *searchBookByPartialTitle(const char *partial_title);
  void writeToFile();
  friend ostream& operator<< (ostream &out, Inventory &database);
  friend class Report;
  friend class RingUp;
  void editBook(InventoryBook *bookPtr);
  void deleteBook(InventoryBook *partial_search);
};

#endif