#include "Traditional_Method.h"
#include <fstream>
#include <ctime>

// constructor
Traditional_Method::Traditional_Method(int temp_row, int temp_column, int **temp_value)
{
	set_member(temp_row, temp_column, temp_value);
}

// set the member
void Traditional_Method::set_member(int temp_row, int temp_column, int **temp_value)
{
	row = temp_row;
	column = temp_column;

	sparse_matrix = new int*[row];
	for (int i = 0; i<row; i++) sparse_matrix[i] = new int[column];

	for (int i = 0; i<row; i++)
		for (int j = 0; j<column; j++) sparse_matrix[i][j] = temp_value[i][j];

	transpose_matrix = new int*[column];
	for (int i = 0; i<column; i++) transpose_matrix[i] = new int[row];
}

// traditional transpose by 2-dimension
void Traditional_Method::method_selection()
{
	double start = 0, end = 0;

	start = (double)clock() / CLOCKS_PER_SEC;

	// traditional transpose by 2-dimension
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++) transpose_matrix[i][j] = sparse_matrix[j][i];
	}

	end = (double)clock() / CLOCKS_PER_SEC;

	cout << "Traditional_Method    : " << end - start << endl;

	fstream out;
	out.open("p2.out", ios::out);
	if (!out) cout << "檔案無法開啟" << endl;
	else
	{
		// the format of file output 
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (sparse_matrix[i][j] != 0)
				{
					out << "(" << i << "," << j << "," << sparse_matrix[i][j] << ")"
						<< " becomes "
						<< "(" << j << "," << i << "," << transpose_matrix[j][i] << ")"
						<< " in the transpose" << endl;
				}
			}
		}

		out << end - start << endl;
	}
	
	out.close();

	for (int i = 0; i < row; i++) delete []sparse_matrix[i];
	delete []sparse_matrix;
	for (int i = 0; i < column; i++) delete []transpose_matrix[i];
	delete []transpose_matrix;
}