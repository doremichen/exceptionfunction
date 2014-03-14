//============================================================================
// Name        : ExceptionFunction.cpp
// Author      : doremi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void Caculator(const double N1, const double N2, const char p) throw(const char*, const char);

double Validate(const char *N) throw(const char*);

int main() {

	char Number1[40], Number2[40];
	double Operand1, Operand2;
	char Operator;

	cout << "Please input the two number and one operator";

	try {

		cout << "Please enter: " << endl;
		cout << "First Number: "; cin >> Number1;
		cout << "Second Number: "; cin >> Number2;
		cout << "Operator: "; cin >> Operator;

		try {
			Operand1 = Validate(Number1);
			Operand2 = Validate(Number2);
		}
		catch(const char *str) {

			cout << "Error:" << str <<" is not available number." << endl;
		}

		Caculator(Operand1, Operand2, Operator);

	}
	catch(const char n) {
		cout << "Operation Error: " << n << " is not a valid Operator" << endl;
	}
	catch(const char *BadOperand) {
		cout << "Operation Error: " << BadOperand << endl;
	}

	return 0;
}

void Caculator(const double Oper1, const double Oper2, const char Symbol) throw(const char*, const char)
{
	double value;

	switch(Symbol) {
	case '+':
		value = Oper1 + Oper2;
		break;
	case '-':
		value = Oper1 - Oper2;
		break;
	case '*':
		value = Oper1 * Oper2;
		break;
	case '/':
		if(Oper2 == 0)
			throw "Division by 0 is not allowed.";
		value = Oper1 / Oper2;
		break;
	default:
		throw Symbol;
		break;
	}

	cout << Oper1 << Symbol << Oper2 << " = " << value << endl;

}

double Validate(const char *N) throw(const char*)
{
	double Valid;

	for(unsigned int i = 0; i < strlen(N); ++i) {
		if((!isdigit(N[i])) && (N[i] != '.')) {
			throw N;
		}
	}

	Valid = atof(N);

	return Valid;
}
