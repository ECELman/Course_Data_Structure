#include<iostream>
#include<fstream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

// 位置結構
struct offsets
{
	int a, b;
};

offsets mov[8] = { { -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 } };

// 座標結構
struct items
{
	int x, y, dir;
};

// 地圖、標記
char **maze = NULL, **mark = NULL;


// 路徑搜尋
void path(int s_i,int s_j,int d_i,int d_j)
{

	stack<items> record; // stack
	items now_path;
	items next_path;
	// start位置
	now_path.x = s_i;
	now_path.y = s_j;
	now_path.dir = 0;
	record.push(now_path); // 第一個位置push進去

	while (!record.empty())
	{
		now_path = record.top(); //最上層位置拿出來
		record.pop();
		int i = now_path.x, j = now_path.y, dir = now_path.dir;
		mark[i][j] = '0';
		for (int k = dir; k<8; k++)
		{
			int g = i + mov[k].a;
			int h = j + mov[k].b;
			if (g == d_i && h == d_j)
			{
				mark[i][j] = 'b';
				now_path.x = i;
				now_path.y = j;
				now_path.dir = k + 1;
				record.push(now_path);

				return;
			}
			else if (maze[g][h] == '0' && mark[g][h] != 'b')
			{
				mark[i][j] = 'b';
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

	cout << "no path in maze" << endl;
}

int main()
{
	fstream in;
	int row = 0, column = 0, count1 = 0, count2 = -1;
	int s_i, s_j,d_i,d_j;
	string *seq = NULL;
	in.open("maze.txt", ios::in);
	if (!in) cout << "檔案無法開啟" << endl;
	else
	{
		string s;
		while (getline(in, s))
		{
			row++;
			if (column < s.length()) column = s.length();
		}
		in.close();

		maze = new char*[row+2];
		for (int i = 0; i < row+2; i++) maze[i] = new char[column+2];

		for (int i = 0; i < row+2; i++)
		{
			for (int j = 0; j < column + 2; j++) maze[i][j] = 'a';
		}
		
		in.open("maze.txt", ios::in);
		if (!in) cout << "檔案無法開啟" << endl;
		else
		{
			mark = new char*[row + 2];
			for (int i = 0; i < row + 2; i++) mark[i] = new char[column + 2]();

			int temp_row = 1, temp_column = 1,test=0;
			char max, min;
			while (getline(in, s))
			{
				for (int i = 0; i < s.length(); i++)
				{
					if (s[i]<'A' || s[i]>'Z')
					{
						maze[temp_row][temp_column] = s[i];
						if (test == 0)
						{
							max = maze[temp_row][temp_column];
							min = maze[temp_row][temp_column];
							test = 1;
						}
						else
						{
							if (max < maze[temp_row][temp_column]) max = maze[temp_row][temp_column];
							if (min > maze[temp_row][temp_column] && maze[temp_row][temp_column]!='0') min = maze[temp_row][temp_column];
						}
						temp_column++;
					}
				}
				temp_row++;
				temp_column = 1;
			}
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= column; j++)
				{
					if (maze[i][j] == min)
					{
						maze[i][j] = 's';
						s_i = i;
						s_j = j;
						break;
					}
				}
			}
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= column; j++)
				{
					if (maze[i][j] == max)
					{
						maze[i][j] = 'd';
						d_i = i;
						d_j = j;
						break;
					}
				}
			}
		}
		in.close();
	}

    path(s_i,s_j,d_i,d_j);

	maze[s_i][s_j] = 's';
	mark[s_i][s_j] = '0';
	fstream out;
	out.open("maze_ans.txt", ios::out);
	if (!out) cout << "無法開啟檔案" << endl;
	else
	{
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= column; j++)
			{
				if (maze[i][j] == '0' && mark[i][j] == 'b') out << "*";
				if (maze[i][j] != 'a' && mark[i][j] != 'b') out << maze[i][j];
			}

			out << endl;
		}
	}

	out.close();

	return 0;
}