#define _CRT_SECURE_NO_WARNINGS

#ifndef INVENTORYBOOK_H
#define INVENTORYBOOK_H

#include "Book.h"
#include <iostream>
#include <iomanip>
#include <string>

/*
    InventoryBook Class derived from public Book Class

    Private member variables:
        int for quantity on hand and last amount purchased
        double for wholesale cost and retail cost
        time_t representing the time the InventoryBook was added to the inventory

    Public member functions:
        get and set for all member variables
        sale to decrease the quantity on hand
        overrides for the << and == operators
*/

class InventoryBook : public Book
{
private:
  int quantity;
  int lastPurchase;
  double wholCost;
  double retCost;
  time_t dateAdded;
  
public:
  InventoryBook();
  void getData();
  time_t getDate() const { return dateAdded; }
  int getQuantity() const { return quantity; }
  int getLastPurchase() const { return lastPurchase; }
  double getWholCost() const { return wholCost; }
  double getRetCost() const { return retCost; }
  bool sale(int s);
  void setDate() { time(&dateAdded); }
  void setQuantity(int q) { quantity = q; }
  void setLastPurchase(int p) { lastPurchase = p; }
  void setWholCost(double w) { wholCost = w; }
  void setRetCost(double r) { retCost = r; }
  friend ostream& operator<< (ostream &outstream, InventoryBook &ib);
  bool operator== (const InventoryBook &right);
};

#endif