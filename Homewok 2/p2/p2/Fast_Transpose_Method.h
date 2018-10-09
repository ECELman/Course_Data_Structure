#ifndef FAST_TRANSPOSE_METHOD_H
#define FAST_TRANSPOSE_METHOD_H

#include "Matrix_Term.h";

class Fast_Transpose_Method : public Matrix_Term
{
public:
	Fast_Transpose_Method(int, int, int**, int);

	void set_term(int);
	void set_member(int, int, int**);

	void method_selection();
private:
	int *row_size = NULL, *row_start = NULL, term;
	Matrix_Term *sparse_matrix, *transpose_matrix;
};

#endif