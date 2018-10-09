#ifndef TRANSPOSE_METHOD_H
#define TRANSPOSE_METHOD_H

#include "Matrix_Term.h";

class Transpose_Method : public Matrix_Term
{
public:
	Transpose_Method(int, int, int**, int);

	void set_term(int);
	void set_member(int, int, int**);

	void method_selection();
private:
	Matrix_Term *sparse_matrix, *transpose_matrix;
	int term;
};

#endif