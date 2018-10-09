#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// stack實作
template <class T>
class Stack
{
public:
	// 初始化max_stack_size以及stack陣列
	Stack(int max_size)
	{
		max_stack_size = max_size;
		stack = new T[max_stack_size];
	}

	// 判斷stack是不是滿的
	bool is_full()
	{
		if (top == max_stack_size - 1) return true;
		else return false;
	}

	// 判斷stack是不是空的
	bool is_empty()
	{
		if (top == -1) return true;
		else return false;
	}

	// 如果stack不是滿的話，加入元素到stack當中
	void push(T num)
	{
		if (is_full()) cout << "the stack is full" << endl;
		else
		{
			stack[++top] = num;
			count++;
		}
	}

	// 如果stack不是空的話，將stack最頂層的元素給取出並且刪除
	void pop()
	{
		if (is_empty()) cout << "the stack is empty" << endl;
		else
		{
			stack[top--].~T();
			count--;
		}
	}

	// 取得stack最頂層的元素
	T top_element() { return stack[top]; }

	// 回傳stack目前已存進的元素有幾個
	int size() { return count; }

	// 將動態陣列stack所佔用的記憶體空間給歸還
	~Stack() { delete []stack; }

private:
	int max_stack_size, top = -1, count = 0;
	T *stack;
};

// 方位結構
struct offsets
{
	int a, b;
};

// 每個方位的移動方向
offsets mov[8] = { { -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 } };

// 座標結構
struct items
{
	int x, y, dir;
};

// 地圖、標記
char **maze = NULL, **mark = NULL;

// 路徑搜尋
int path(int s_i, int s_j, int d_i, int d_j, int row, int column)
{
	Stack<items> record(row*column); // 創建stack
	items now_path;
	items next_path;

	// start位置
	now_path.x = s_i;
	now_path.y = s_j;
	now_path.dir = 0;
	record.push(now_path); // 第一個位置push進去

	while (!record.is_empty())
	{
		now_path = record.top_element(); //最上層位置拿出來
		record.pop();
		int i = now_path.x, j = now_path.y, dir = now_path.dir;
		mark[i][j] = '0';
		for (int k = dir; k<8; k++)
		{
			int g = i + mov[k].a;
			int h = j + mov[k].b;

			// 到達終點
			if (g == d_i && h == d_j)
			{
				mark[i][j] = '2';
				now_path.x = i;
				now_path.y = j;
				now_path.dir = k + 1;
				record.push(now_path);

				return record.size();
			}
			else if (maze[g][h] == '0' && mark[g][h] != '2') // 尚未到達終點，判斷是否為活路
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

	// 假如在地圖上找不到任何的路徑的話，則寫入找不到路徑
	fstream out;
	out.open("p3.out", ios::out);
	if (!out) cout << "無法開啟檔案" << endl;
	else
	{
		out << "no path in maze" << endl << endl;
		return record.size();
	}
}

int main()
{
	// 開檔
	fstream in;
	int row = 0, column = 0, s_i, s_j, d_i, d_j;
	in.open("p3.in", ios::in);
	if (!in) cout << "檔案無法開啟" << endl;
	else
	{
		// 先判斷有幾列幾行
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

		// 讀入地圖
		in.open("p3.in", ios::in);
		if (!in) cout << "檔案無法開啟" << endl;
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

						// 找起點
						if (s[i] == 's')
						{
							s_i = temp_row;
							s_j = temp_column;
						}

						// 找終點
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

	// 尋找路徑並且回傳stack大小
	int size = path(s_i, s_j, d_i, d_j, row, column);

	// 將結果寫入檔案
	if (size == 0)
	{
		fstream out;
		out.open("p3.out", ios::app);
		if (!out) cout << "無法開啟檔案" << endl;
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
		if (!out) cout << "無法開啟檔案" << endl;
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