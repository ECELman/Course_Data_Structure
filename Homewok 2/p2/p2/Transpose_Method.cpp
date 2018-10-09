#include "Transpose_Method.h"
#include <ctime>
#include <fstream>

// constructor
Transpose_Method::Transpose_Method(int main_row, int main_column, int **temp_value, int temp_term)
{
	set_term(temp_term);
	set_member(main_row, main_column, temp_value);
}

// set the term
void Transpose_Method::set_term(int temp_term)
{
	term = temp_term;
}

// set the member
void Transpose_Method::set_member(int main_row, int main_column, int **temp_value)
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

// transpose
void Transpose_Method::method_selection()
{
	if (term > 0)
	{
		transpose_matrix = new Matrix_Term[term];

		double start = 0, end = 0;

		start = (double)clock() / CLOCKS_PER_SEC;

		// transpose
		int current_site = 0;
		for (int col = 0; col < column; col++)
		{
			for (int i = 0; i < term; i++)
			{
				if (sparse_matrix[i].column == col)
				{
					transpose_matrix[current_site].row = col;
					transpose_matrix[current_site].column = sparse_matrix[i].row;
					transpose_matrix[current_site].value = sparse_matrix[i].value;

					current_site++;
				}
			}
		}

		end = (double)clock() / CLOCKS_PER_SEC;

		cout << "Transpose_Method      : " << end - start << endl;

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

		delete[]sparse_matrix;
		delete[]transpose_matrix;
	}
}