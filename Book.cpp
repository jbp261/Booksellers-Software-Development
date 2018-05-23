#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"
#include<iostream>

using namespace std;

/*
    Default constructor
    Set all members to NULL using strcpy
*/
Book::Book()
{ 
    strcpy(title, "");
    strcpy(isbn, "");
    strcpy(author, "");
    strcpy(publisher, "");
}