#define _CRT_SECURE_NO_WARNINGS

#ifndef REPORT_H
#define REPORT_H

#include "Inventory.h"
#include "MenuModule.h"

class Report : public MenuModule
{
private:
  void sortByQuantity();
  void sortByAge();
  void sortByWholCost();

public:
  Report(Inventory *ptr);
  void listByQuantity();
  void listByAge();
  void listByWholCost();
  void listTotalWholValue();
  void listTotalRetValue();
  void PrintMenu();
  void ProcessUserInput();
};


#endif