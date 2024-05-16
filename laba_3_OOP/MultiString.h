/************************************************************************
 * file: MultiString.h
 * MultiString class definition
 * written: 01/05/2012
 * Copyright (c) 2012 by Yu.Zorin
*************************************************************************/

#ifndef LABA_3_OOP_MULTISTRING_H
#define LABA_3_OOP_MULTISTRING_H

#include <iostream>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using std::cout;
using std::endl;

class MultiString {
public:
	//constructors destructor
	MultiString();
	MultiString(const MultiString &ms);
	MultiString(int);
	~MultiString();

	//methods
	MultiString &operator=(const MultiString &ms) {};
	char *operator[](int nindex) const;
	MultiString &operator+=(const MultiString &src);
	MultiString MergeMultiStringexclusive(const MultiString &src);
	int Find(const char *pszsub) const;
	int Getlength() const;
	bool Isempty() const;
	void Empty();
	void Setat(int nindex, const char *str);
	void Printstr(int nindex) const;

private:
	/*
	forbidden copy constructor
	MultiString(const MultiString &ms) {};
	*/
	//attributes
	char **buf; //pointer to vector
	int str_nmb; //strings number
};

#endif //LABA_3_OOP_MULTISTRING_H
