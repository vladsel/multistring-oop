#include "MultiString.h"

int main() {
	MultiString A;
	MultiString B(7);
	MultiString C(4);
	MultiString E(A);

	A.Setat(0, "error"); //error
	E.Setat(5, "error"); //error
	E.Printstr(5); //error

	B.Setat(0, nullptr);
	B.Setat(1, "room");
	B.Setat(2, "important");
	B.Setat(3, "laptop");
	B.Setat(4, "TV");
	B.Setat(5, "$money$");
	B.Setat(6, "water");

	B.Setat(7, "error"); //error

	C.Setat(0, "Picture");
	C.Setat(1, "Tour");
	C.Setat(2, "Deadline");
	C.Setat(3, nullptr);
	MultiString D(C);

	cout << endl << "Print B:" << endl;
	for (int i = 0; i < 7; i++)
		B.Printstr(i);
	cout << endl << "Print C:" << endl;
	for (int i = 0; i < 4; i++)
		C.Printstr(i);
	cout << endl << "Print D:" << endl;
	for (int i = 0; i < 4; i++)
		D.Printstr(i);
	cout << endl;

	B.Printstr(7); //error
	
	C.Empty();

	cout << endl << "Isempty C: " << C.Isempty();
	cout << endl << "Isempty B: " << B.Isempty() << endl;

	cout << endl << "Getlength A: " << A.Getlength();
	cout << endl << "Getlength B: (includes \'\\0\'): " << B.Getlength() << endl;

	cout << endl << "Find index D: " << D.Find("Tour") << endl;
	cout << "\tFind index D: " << D.Find(nullptr) << endl; //error
	cout << "\t\tFind index D: " << D.Find("error") << endl; //error;
	
	cout << endl;
	char *ptr = nullptr;
	ptr = B[0]; //error
	if (ptr != nullptr) {
		cout << "operator[]() B: " << ptr << endl;
		delete[] ptr;
	}
	ptr = B[-2]; //error
	if (ptr != nullptr) {
		cout << "operator[]() B: " << ptr << endl;
		delete[] ptr;
	}
	cout << endl;
	ptr = B[5];
	if (ptr != nullptr) {
		cout << "operator[]() B: " << ptr << endl;
		delete[] ptr;
	}

	B += E;
	B += D;
	cout << endl << "B+=D:" << endl;
	for (int i = 0; i < 7; i++)
		B.Printstr(i);

	B.MergeMultiStringexclusive(D);
	cout << endl << "Merged B(D):" << endl;
	for (int i = 0; i < 7 + 4 - 1; i++) {
		if (i == 7)
			cout << endl;
		B.Printstr(i);
	}

	cout << endl;
	B.Printstr(7 + 4); //error

	D.MergeMultiStringexclusive(B);
	cout << endl << "Merged D(B):" << endl;
	for (int i = 0; i < 4 + 7; i++) {
		if (i == 4)
			cout << endl;
		D.Printstr(i);
	}

	cout << endl << endl;
	return 0;
}
