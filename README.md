# Classes
The goal of the work is to master the methods of designing interfaces and implementing class methods.
3.1. Theoretical information.
3.2. Job assignment
Job assignment. (01.12.2020).

Changing the interface is prohibited.
Option 1.
Construct a MultiString class to define a vector of strings with the following interface:
/*!
  * file: MultiString.h
  * MultiString class definition
  * written: 01/05/2012
  * Copyright (c) 2012 by Yu. Zorin
  */
#pragma once
#include <string.h>
#include <stdio.h>

class MultiString{
public:
//constructors destructor
MultiString();
MultiString(int );
~MultiString();

//methods
MultiString & operator=(const MultiString &ms){};
char * operator[] (int nindex) const;
MultiString & operator+=(const MultiString &);
void MergeMultiStringexclusive(const MultiString &);
int Find(const char *pszsub ) const;
int GetLength( ) const;
bool Isempty()const{ return str_nmb == 0;};
void Empty();
void Setat( int nindex, const char* str );
void Printstr(int nindex) const;
private:
//forbidden copy constructor
MultiString ( const MultiString & ms){};

//attributes
char **buf;//pointer to vector
int str_nmb;//strings number
};

Methods.
MultiString ( ) – creates an empty vector.
MultiString ( const MultiString & ) – copy constructor.
MultiString(MultiStrings(int n ) - creates a vector of n empty strings.

char * operator[] (int nindex) cons – returns a pointer to a COPY of the string with index indx.
MultiString & operator+=(const MultiString &src) – performs sequential concatenation of the vector with which this operator is called and the src vector.
MultiString MergeMultiStringexcl(const MultiString &src) - merges two vectors excluding duplicate elements and returns the resulting object.
int Find( const char *pszsub ) const – returns the index of pszsub in the vector.
int Getlength( ) const – returns the length of the vector.
bool Isempty()const – returns true if the vector is empty.
void Empty() – clears the vector.
void SetAt( int nindex, const char* str ) – replaces the string with the nindex index into the string str in the vector.
void PrintStr(int nindex) const – outputs a line with the index nindex to the console.
