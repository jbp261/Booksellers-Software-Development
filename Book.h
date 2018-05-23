#define _CRT_SECURE_NO_WARNINGS

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>
using namespace std;

/*
    Book Class

    Protected member variables:
        C-strings for title, ISBN, author, and publisher

    Public member functions:
        get and set for each member variable
*/
class Book
{
protected:
  char title[100];
  char isbn[11];
  char author[30];
  char publisher[20];

public:
  Book();
  char *getIsbn() { return isbn; }
  char *getTitle() { return title; }
  char *getAuthor() { return author; }
  char *getPublisher() { return publisher; }
  void setTitle(const char *t) { strncpy(title, t, 100); }
  void setIsbn(const char *i) { strncpy(isbn, i, 16); }
  void setAuthor(const char *a) { strncpy(author, a, 30); }
  void setPublisher(const char *p) { strncpy(publisher, p, 20); }
};



#endif