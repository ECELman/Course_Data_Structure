#ifndef MATRIX_TERM_H
#define MATRIX_TERM_H

#include <iostream>
using namespace std;

class Matrix_Term
{
public:
	virtual void set_member(int, int, int**);
	virtual void method_selection();

	friend class Traditional_Method;
	friend class Transpose_Method;
	friend class Fast_Transpose_Method;
private:
	int row, column, value;
};

#endif