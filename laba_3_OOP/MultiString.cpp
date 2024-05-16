/************************************************************************
*file: Multistring.cpp
*These methods are declared in the include file "scanner.h".
*author: Vlad Seletkov
*written: 29/11/2020
*last modified: 01/12/2020
************************************************************************/

#include "Multistring.h"
#pragma warning(disable : 6001)
#pragma warning(disable : 6385)
#pragma warning(disable : 6386)

//contructors 
/*
creates empty vector
*/
MultiString::MultiString() {
	this->buf = nullptr;
	this->str_nmb = 0;
}

/*
copy constructor
*/
MultiString::MultiString(const MultiString &ms) {
	if (ms.buf == nullptr) {
		this->buf = nullptr;
		this->str_nmb = ms.str_nmb;
	}
	else {
		this->str_nmb = ms.str_nmb;
		this->buf = new char *[this->str_nmb];
		for (int i = 0; i < this->str_nmb; i++) {
			if (ms.buf[i] == nullptr)
				this->buf[i] = nullptr;
			else {
				this->buf[i] = new char [strlen(ms.buf[i]) + 1];
				strcpy(this->buf[i], ms.buf[i]);
				//strcpy(*(this->buf + i), *(ms.buf + i));
			}
		}
	}
}

/*
creates a vector of n empty lines
*/
MultiString::MultiString(int n) {
	if (n <= 0) {
		this->buf = nullptr;
		this->str_nmb = 0;
	}
	else {
		this->str_nmb = n;
		this->buf = new char *[n];
		for (int i = 0; i < n; i++)
			this->buf[i] = nullptr;
	}
}

/*
destructor 
*/
MultiString::~MultiString() {
	if (this->buf != nullptr) {
		for (int i = 0; i < this->str_nmb; i++) 
			if (this->buf[i] != nullptr)
				delete[] this->buf[i];
		delete[] this->buf;
	}
}

//methods
/*
replaces in the vector the string with the index nindex on the string str
*/
void MultiString::Setat(int nindex, const char *str) {
	if (nindex < 0 || nindex >= this->str_nmb) {
		cout << "nindex error void MultiString::Setat" << endl;
		return;
	}
	if (str != nullptr && this->buf[nindex] != nullptr) {
		delete[] this->buf[nindex];
		this->buf[nindex] = nullptr;
		this->buf[nindex] = new char[strlen(str) + 1];
		strcpy(this->buf[nindex], str);
	}
	else if (str != nullptr && this->buf[nindex] == nullptr) {
		this->buf[nindex] = new char[strlen(str) + 1];
		strcpy(this->buf[nindex], str);
	}
	else if (this->buf[nindex] != nullptr && str == nullptr) {
		delete[] this->buf[nindex];
		this->buf[nindex] = nullptr;
	}
}

/*
displays a string with nindex on the console
*/
void MultiString::Printstr(int nindex) const {
	if (nindex < 0 || nindex >= this->str_nmb) {
		cout << "nindex error void MultiString::Printstr" << endl;
		return;
	}
	if (this->buf[nindex] == nullptr) {
		cout << "this->buf[nindex] == nullptr error void MultiString::Printstr()" << endl;
		return;
	}
	cout << this->buf[nindex] << endl;
}

/*
cleans vector
*/
void MultiString::Empty() {
	if (this->buf == nullptr || this->str_nmb <= 0) {
		cout << "this->buf == nullptr || this->str_nmb <= 0 error void MultiString::Empty()" << endl;
		return;
	}
	for (int i = 0; i < this->str_nmb; i++) {
		if (this->buf[i] != nullptr) 
			delete[] this->buf[i];
	}
	delete[] this->buf;
	this->buf = nullptr;
	this->str_nmb = 0;
}

/*
returns true if the vector is empty
*/
bool MultiString::Isempty() const {
	if (this->Getlength() == 0) {
		return true;
	}
	else
		return false;
}

/*
returns the length of the vector
*/
int MultiString::Getlength() const {
	if (this->buf == nullptr)
		return 0;
	int count = 0;
	for (int i = 0; i < this->str_nmb; i++)
		if (this->buf[i] != nullptr)
			count += strlen(this->buf[i]) + 1;
	return count;
}

/*
returns the pszsub index in vector
*/
int MultiString::Find(const char *pszsub) const {
	if (pszsub == NULL || this->buf == nullptr) {
		cout << "pszsub == NULL || this->buf == nullptr error int MultiString::Find()";
		return -1;
	}
	for (int i = 0; i < this->str_nmb; i++)
		if (this->buf[i] != nullptr)
			if (strcmp(this->buf[i], pszsub) == 0)
				return i;
	cout << "not found error int MultiString::Find()";
	return -1;
}

/*
returns a pointer to a COPY of a line with index indx
*/
char *MultiString::operator[](int nindex) const {
	if (nindex < 0 || nindex >= this->str_nmb) {
		cout << "nindex error char *MultiString::operator[]()" << endl;
		return nullptr;
	}
	if (this->buf[nindex] == nullptr) {
		cout << "this->buf[nindex] == nullptr error char *MultiString::operator[]()" << endl;
		return nullptr;
	}
	char *copy_buf = new char [strlen(this->buf[nindex]) + 1];
	strcpy(copy_buf, this->buf[nindex]);
	return copy_buf;
}

/*
performs a merge of two vectors with the exception of 
repeating elements and returns the resulting object
*/
MultiString MultiString::MergeMultiStringexclusive(const MultiString &src) {
	if (src.buf == nullptr)
		return *this;
	else if (this->buf == nullptr) {
		this->str_nmb = src.str_nmb;
		this->buf = new char* [this->str_nmb];
		for (int i = 0; i < this->str_nmb; i++) {
			if (src.buf[i] == nullptr)
				this->buf[i] = nullptr;
			else {
				this->buf[i] = new char[strlen(src.buf[i]) + 1];
				strcpy(this->buf[i], src.buf[i]);
			}
		}
		return *this;
	}
	else {
		char **temp = nullptr, **second_temp = nullptr;
		int temp_size = 0, second_temp_size = 0, i = 0, j = 0, k = 0, count = 0, second_count = 0, flag = 0;
		for (i = 0; i < this->str_nmb; i++)
			for (j = i + 1; j < this->str_nmb; j++)
				if (this->buf[i] != nullptr && this->buf[j] != nullptr)
					if (strcmp(this->buf[i], this->buf[j]) == 0) {
						count++;
						break;
					}
		temp_size = this->str_nmb - count;
		temp = new char *[temp_size];
		for (i = 0; i < this->str_nmb; i++) {
			if (this->buf[i] == nullptr) {
				temp[k] = nullptr;
				k++;
			}
			else {
				for (j = 0; j < i; j++) {
					if (this->buf[j] != nullptr && this->buf[i] != nullptr)
						if (strcmp(this->buf[j], this->buf[i]) == 0) {
							flag = 1;
							break;
						}
				}
				if (flag == 0) {
					temp[k] = new char[strlen(this->buf[i]) + 1];
					strcpy(temp[k], this->buf[i]);
					k++;
				}
				flag = 0;
			}
		}
		flag = 0, k = 0, count = 0;
		for (i = 0; i < src.str_nmb; i++)
			for (j = i + 1; j < src.str_nmb; j++)
				if (src.buf[i] != nullptr && src.buf[j] != nullptr)
					if (strcmp(src.buf[i], src.buf[j]) == 0) {
						second_count++;
						break;
					}
		second_temp_size = src.str_nmb - second_count;
		second_temp = new char *[second_temp_size];
		for (i = 0; i < src.str_nmb; i++) {
			if (src.buf[i] == nullptr) {
				second_temp[k] = nullptr;
				k++;
			}
			else {
				for (j = 0; j < i; j++) {
					if (src.buf[j] != nullptr && src.buf[i] != nullptr)
						if (strcmp(src.buf[j], src.buf[i]) == 0) {
							flag = 1;
							break;
						}
				}
				if (flag == 0) {
					second_temp[k] = new char[strlen(src.buf[i]) + 1];
					strcpy(second_temp[k], src.buf[i]);
					k++;
				}
				flag = 0;
			}
		}
		flag = 0;
		for (i = 0; i < second_temp_size; i++)
			for (j = 0; j < temp_size; j++)
				if (second_temp[i] != nullptr && temp[j] != nullptr)
					if (strcmp(second_temp[i], temp[j]) == 0) {
						count++;
						break;
					}
		this->Empty();
		this->str_nmb = temp_size + second_temp_size - count;
		this->buf = new char *[this->str_nmb];
		for (i = 0; i < temp_size; i++) {
			if (temp[i] == nullptr)
				this->buf[i] = nullptr;
			else {
				this->buf[i] = new char[strlen(temp[i]) + 1];
				strcpy(this->buf[i], temp[i]);
			}
		}
		for (j = 0; j < second_temp_size; j++) {
			if (second_temp[j] == nullptr) {
				this->buf[i] = nullptr;
				i++;
			}
			else {
				for (k = 0; k < temp_size; k++)
					if (temp[k] != nullptr)
						if (strcmp(temp[k], second_temp[j]) == 0) {
							flag = 1;
							break;
						}
				if (flag == 0) {
					this->buf[i] = new char[strlen(second_temp[j]) + 1];
					strcpy(this->buf[i], second_temp[j]);
					i++;
				}
				flag = 0;
			}
		}
		if (temp != nullptr) {
			for (i = 0; i < temp_size; i++)
				if (temp[i] != nullptr)
					delete[] temp[i];
			delete[] temp;
		}
		if (second_temp != nullptr) {
			for (i = 0; i < second_temp_size; i++)
				if (second_temp[i] != nullptr)
					delete[] second_temp[i];
			delete[] second_temp;
		}
		return *this;
	}
}

/*
performs sequential concatenation of the vector with
which this operator is called and the vector src
*/
MultiString &MultiString::operator+=(const MultiString &src) {
	if (src.buf == nullptr)
		return *this;
	else if (this->buf == nullptr) {
		this->str_nmb = src.str_nmb;
		this->buf = new char *[this->str_nmb];
		for (int i = 0; i < this->str_nmb; i++) {
			if (src.buf[i] == nullptr)
				this->buf[i] = nullptr;
			else {
				this->buf[i] = new char[strlen(src.buf[i]) + 1];
				strcpy(this->buf[i], src.buf[i]);
			}
		}
		return *this;
	}
	else {
		char **temp = nullptr;
		int temp_size = this->str_nmb, second_size = 0, i = 0;
		temp = new char* [this->str_nmb];
		for (i = 0; i < this->str_nmb; i++) {
			if (this->buf[i] == nullptr)
				temp[i] = nullptr;
			else {
				temp[i] = new char[strlen(this->buf[i]) + 1];
				strcpy(temp[i], this->buf[i]);
			}
		}
		this->Empty();
		if (temp_size > src.str_nmb) {
			this->str_nmb = temp_size;
			this->buf = new char *[this->str_nmb];
			for (i = 0; i < this->str_nmb; i++) {
				if (temp[i] == nullptr) {
					if (i < src.str_nmb) {
						if (src.buf[i] == nullptr)
							this->buf[i] = nullptr;
						else {
							this->buf[i] = new char[strlen(src.buf[i]) + 1];
							strcpy(this->buf[i], src.buf[i]);
						}
					}
				}
				else {
					if (i < src.str_nmb) {
						if (src.buf[i] != nullptr)
							second_size = strlen(src.buf[i]);
						else
							second_size = 0;
					}
					this->buf[i] = new char[strlen(temp[i]) + second_size + 1];
					strcpy(this->buf[i], temp[i]);
					if (i < src.str_nmb)
						if (src.buf[i] != nullptr)
							strcat(this->buf[i], src.buf[i]);
				}
			}
		}
		else {
			this->str_nmb = src.str_nmb;
			this->buf = new char *[this->str_nmb];
			for (i = 0; i < this->str_nmb; i++) {
				if (i < temp_size) {
					if (temp[i] == nullptr) {
						if (src.buf[i] == nullptr)
							this->buf[i] = nullptr;
						else {
							this->buf[i] = new char[strlen(src.buf[i]) + 1];
							strcpy(this->buf[i], src.buf[i]);
						}
					}
					else {
						if (src.buf[i] == nullptr) {
							this->buf[i] = new char[strlen(temp[i]) + 1];
							strcpy(this->buf[i], temp[i]);
						}
						else {
							this->buf[i] = new char[strlen(temp[i]) + strlen(src.buf[i]) + 1];
							strcpy(this->buf[i], temp[i]);
							strcat(this->buf[i], src.buf[i]);
						}
					}
				}
				else {
					if (src.buf[i] == nullptr)
						this->buf[i] = nullptr;
					else {
						this->buf[i] = new char[strlen(src.buf[i]) + 1];
						strcpy(this->buf[i], src.buf[i]);
					}
				}
			}
		}
		if (temp != nullptr) {
			for (i = 0; i < temp_size; i++)
				if (temp[i] != nullptr)
					delete[] temp[i];
			delete[] temp;
		}
		return *this;
	}
}
