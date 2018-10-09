#ifndef TRADITIONAL_METHOD_H
#define TRADITIONAL_METHOD_H

#include "Matrix_Term.h"

class Traditional_Method : public Matrix_Term
{
public:
	Traditional_Method(int, int, int**);

	void set_member(int, int, int**);

	void method_selection();
private:
	int **sparse_matrix = NULL, **transpose_matrix = NULL;
};

#endif