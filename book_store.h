//***************************************************************************
//
//  book.h
//  CSCI 241 Assignment 5
//
//  Created by Aaron Hall (z1980019)
//
//***************************************************************************

#pragma once
#include "book.h"
#include <string>
#define SIZE 30
using namespace std;

class book_store
{
private:
	book arr[SIZE];
	int elements;
	int binarySearch(char*);
	void sort();
	int count;

public:
	book_store();
	void read_book_data(string);
	void process_orders(string);
	void print();
};