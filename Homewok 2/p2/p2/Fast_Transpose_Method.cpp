#include "Fast_Transpose_Method.h"
#include <ctime>
#include <fstream>

// constructor
Fast_Transpose_Method::Fast_Transpose_Method(int main_row, int main_column, int **temp_value, int temp_term)
{
	set_term(temp_term);
	set_member(main_row, main_column, temp_value);
}

// set the term
void Fast_Transpose_Method::set_term(int temp_term)
{
	term = temp_term;
}

// ste the member
void Fast_Transpose_Method::set_member(int main_row, int main_column, int **temp_value)
{
	row = main_row;
	column = main_column;
	sparse_matrix = new Matrix_Term[term];

	int temp_term = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (temp_value[i][j] != 0 && temp_term<term)
			{
				sparse_matrix[temp_term].row = i;
				sparse_matrix[temp_term].column = j;
				sparse_matrix[temp_term].value = temp_value[i][j];
				temp_term++;
			}
		}
	}
}

// fast transpose
void Fast_Transpose_Method::method_selection()
{
	if (term > 0)
	{
		row_size = new int[column]();
		row_start = new int[column]();
		transpose_matrix = new Matrix_Term[term];

		for (int i = 0; i < term; i++) row_size[sparse_matrix[i].column]++;

		for (int i = 1; i < column; i++) row_start[i] = row_start[i - 1] + row_size[i - 1];

		double start = 0, end = 0;

		start = (double)clock() / CLOCKS_PER_SEC;

		// fast transpose
		for (int i = 0; i < term; i++)
		{
			int j = row_start[sparse_matrix[i].column];

			transpose_matrix[j].row = sparse_matrix[i].column;
			transpose_matrix[j].column = sparse_matrix[i].row;
			transpose_matrix[j].value = sparse_matrix[i].value;

			row_start[sparse_matrix[i].column]++;
		}

		end = (double)clock() / CLOCKS_PER_SEC;

		cout << "Fast_Transpose_Method : " << end - start << endl;

		fstream out;
		out.open("p2.out", ios::app);
		if (!out) cout << "檔案無法開啟" << endl;
		else
		{
			// the format of file output 
			/*for (int i = 0; i < term; i++)
			{
				out << "(" << sparse_matrix[i].row
					<< "," << sparse_matrix[i].column
					<< "," << sparse_matrix[i].value
					<< ")"
					<< " becomes ";

				for (int j = 0; j < term; j++)
				{
					if (sparse_matrix[i].row == transpose_matrix[j].column &&
						sparse_matrix[i].column == transpose_matrix[j].row)
					{
						out << "(" << transpose_matrix[j].row
							<< "," << transpose_matrix[j].column
							<< "," << transpose_matrix[j].value
							<< ")"
							<< " in the transpose" << endl;

						break;
					}
				}
			}*/

			out << end - start << endl;
		}

		out.close();

		delete[] row_size;
		delete[] row_start;
		delete[] sparse_matrix;
		delete[] transpose_matrix;
	}
}