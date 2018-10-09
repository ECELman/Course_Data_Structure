#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// stack��@
template <class T>
class Stack
{
public:
	// ��l��max_stack_size�H��stack�}�C
	Stack(int max_size)
	{
		max_stack_size = max_size;
		stack = new T[max_stack_size];
	}

	// �P�_stack�O���O����
	bool is_full()
	{
		if (top == max_stack_size - 1) return true;
		else return false;
	}

	// �P�_stack�O���O�Ū�
	bool is_empty()
	{
		if (top == -1) return true;
		else return false;
	}

	// �p�Gstack���O�����ܡA�[�J������stack��
	void push(T num)
	{
		if (is_full()) cout << "the stack is full" << endl;
		else
		{
			stack[++top] = num;
			count++;
		}
	}

	// �p�Gstack���O�Ū��ܡA�Nstack�̳��h�����������X�åB�R��
	void pop()
	{
		if (is_empty()) cout << "the stack is empty" << endl;
		else
		{
			stack[top--].~T();
			count--;
		}
	}

	// ���ostack�̳��h������
	T top_element() { return stack[top]; }

	// �^��stack�ثe�w�s�i���������X��
	int size() { return count; }

	// �N�ʺA�}�Cstack�Ҧ��Ϊ��O����Ŷ����k��
	~Stack() { delete []stack; }

private:
	int max_stack_size, top = -1, count = 0;
	T *stack;
};

// ��쵲�c
struct offsets
{
	int a, b;
};

// �C�Ӥ�쪺���ʤ�V
offsets mov[8] = { { -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 } };

// �y�е��c
struct items
{
	int x, y, dir;
};

// �a�ϡB�аO
char **maze = NULL, **mark = NULL;

// ���|�j�M
int path(int s_i, int s_j, int d_i, int d_j, int row, int column)
{
	Stack<items> record(row*column); // �Ы�stack
	items now_path;
	items next_path;

	// start��m
	now_path.x = s_i;
	now_path.y = s_j;
	now_path.dir = 0;
	record.push(now_path); // �Ĥ@�Ӧ�mpush�i�h

	while (!record.is_empty())
	{
		now_path = record.top_element(); //�̤W�h��m���X��
		record.pop();
		int i = now_path.x, j = now_path.y, dir = now_path.dir;
		mark[i][j] = '0';
		for (int k = dir; k<8; k++)
		{
			int g = i + mov[k].a;
			int h = j + mov[k].b;

			// ��F���I
			if (g == d_i && h == d_j)
			{
				mark[i][j] = '2';
				now_path.x = i;
				now_path.y = j;
				now_path.dir = k + 1;
				record.push(now_path);

				return record.size();
			}
			else if (maze[g][h] == '0' && mark[g][h] != '2') // �|����F���I�A�P�_�O�_������
			{
				mark[i][j] = '2';
				now_path.x = i;
				now_path.y = j;
				now_path.dir = k + 1;
				record.push(now_path);
				next_path.x = g;
				next_path.y = h;
				next_path.dir = 0;
				record.push(next_path);
				break;
			}
		}
	}

	// ���p�b�a�ϤW�䤣����󪺸��|���ܡA�h�g�J�䤣����|
	fstream out;
	out.open("p3.out", ios::out);
	if (!out) cout << "�L�k�}���ɮ�" << endl;
	else
	{
		out << "no path in maze" << endl << endl;
		return record.size();
	}
}

int main()
{
	// �}��
	fstream in;
	int row = 0, column = 0, s_i, s_j, d_i, d_j;
	in.open("p3.in", ios::in);
	if (!in) cout << "�ɮ׵L�k�}��" << endl;
	else
	{
		// ���P�_���X�C�X��
		string s;
		int test = 0;
		while (getline(in, s))
		{
			row++;
			if (test == 0)
			{
				for (int i = 0; i < s.length(); i++)
					if (s[i] != ' ') column++;

				test = 1;
			}
		}
		in.close();

		// Ū�J�a��
		in.open("p3.in", ios::in);
		if (!in) cout << "�ɮ׵L�k�}��" << endl;
		else
		{
			maze = new char*[row + 2];
			for (int i = 0; i < row + 2; i++) maze[i] = new char[column + 2]();

			mark = new char*[row + 2];
			for (int i = 0; i < row + 2; i++) mark[i] = new char[column + 2]();

			int temp_row = 1, temp_column = 1;
			for (int i = 0; i < column + 2; i++) maze[0][i] = '1';
			for (int i = 0; i < column + 2; i++) maze[row + 1][i] = '1';
			for (int i = 1; i <= row; i++) maze[i][0] = '1';
			for (int i = 1; i <= row; i++) maze[i][column + 1] = '1';
			while (getline(in, s))
			{
				for (int i = 0; i < s.length(); i++)
				{
					if (s[i] != ' ' && temp_column != 0)
					{
						maze[temp_row][temp_column] = s[i];

						// ��_�I
						if (s[i] == 's')
						{
							s_i = temp_row;
							s_j = temp_column;
						}

						// ����I
						if (s[i] == 'd')
						{
							d_i = temp_row;
							d_j = temp_column;
						}

						temp_column++;
					}
				}

				temp_row++;
				temp_column = 1;
			}

			in.close();
		}
	}

	// �M����|�åB�^��stack�j�p
	int size = path(s_i, s_j, d_i, d_j, row, column);

	// �N���G�g�J�ɮ�
	if (size == 0)
	{
		fstream out;
		out.open("p3.out", ios::app);
		if (!out) cout << "�L�k�}���ɮ�" << endl;
		else
		{
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= column; j++)
				{
					if (maze[i][j] == 's') out << "s ";
					else if (maze[i][j] == 'd') out << "d ";
					else out << maze[i][j] << " ";
				}

				out << endl;
			}

			out << endl << size << endl;
		}

		out.close();
	}
	else
	{
		fstream out;
		out.open("p3.out", ios::out);
		if (!out) cout << "�L�k�}���ɮ�" << endl;
		else
		{
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= column; j++)
				{
					if (maze[i][j] == 's') out << "s ";
					else if (maze[i][j] == 'd') out << "d ";
					else if (mark[i][j] == '2') out << "* ";
					else out << maze[i][j] << " ";
				}

				out << endl;
			}

			out << endl << size << endl;
		}

		out.close();
	}

	return 0;
}