#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Matrix_Term.h"
#include "Traditional_Method.h"
#include "Transpose_Method.h"
#include "Fast_Transpose_Method.h"
using namespace std;

int main()
{
	int **sparse_matrix = NULL, main_row, main_column, count = 0, test = 0;

	// input the file
	fstream in;
	in.open("p2.in", ios::in);
	if (!in) cout << "檔案無法開啟" << endl;
	else
	{
		string f_row;
		stringstream ss;

		// create sparse matrix to store the non-zero elements;
		while (getline(in, f_row, '\n'))
		{
			ss << f_row;
			int m_row, m_column, m_value;
			if (test == 0)
			{
				ss >> m_row >> m_column;
				main_row = m_row;
				main_column = m_column;
				sparse_matrix = new int*[m_row];
				for (int i = 0; i < m_row; i++) sparse_matrix[i] = new int[m_column]();
				test = 1;
			}
			else
			{
				ss >> m_row >> m_column >> m_value;
				count++;
				sparse_matrix[m_row][m_column] = m_value;
			}

			ss.clear();
		}
	}

	in.close();

	// the polymorphism of method
	Matrix_Term *mt;

	Traditional_Method tm(main_row, main_column, sparse_matrix);
	mt = &tm;
	mt->method_selection();
	cout << endl;

	Transpose_Method trm(main_row, main_column, sparse_matrix, count);
	mt = &trm;
	mt->method_selection();
	cout << endl;

	Fast_Transpose_Method ftrm(main_row, main_column, sparse_matrix, count);
	mt = &ftrm;
	mt->method_selection();

	for (int i = 0; i < main_row; i++) delete []sparse_matrix[i];
	delete []sparse_matrix;

	return 0;
}