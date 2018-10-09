#include<iostream>
using namespace std;

class Leterchain
{
public:
	Leterchain() { num = new char[10](); }

	void add(char var)
	{
		if (count == 10) cout << "空間已滿" << endl;
		else
		{
			count++;
			num[count - 1] = var;
		}
	}

	char get(int index)
	{
		return num[index];
	}

	void Delete(int index)
	{
		if (count == 0) cout << "已經沒有資料" << endl;
		else
		{
			if (index<0 || index >= count) cout << "error" << endl;
			else
			{
				if (index == 0)
				{
					char *temp = new char[count - 1]();
					for (int i = 1; i < count; i++) temp[i - 1] = num[i];
					count--;
					num = new char[10]();
					for (int i = 0; i < count; i++) num[i] = temp[i];
				}
				else if (index == count - 1)
				{
					if (count == 0) cout << "已經沒有資料" << endl;
					else
					{
						num[count - 1] = 0;
						count--;
					}
				}
				else
				{
					char *temp = new char[count - 1]();
					int i;
					for (i = 0; i < index; i++)
					{
						temp[i] = num[i];
					}
					for (int j = index + 1; j < count; j++)
					{
						temp[i] = num[j];
						i++;
					}
					count--;
					num = new char[10]();
					for (int i = 0; i < count; i++) num[i] = temp[i];
				}
			}
		}
	}

	int size() { return count; }

	void insert(int index, char var)
	{
		if (index > count || index < 0)
		{
			cout << "error" << endl;
		}
		else
		{
			char *temp = new char[count + 1]();
			int i;
			for (i = 0; i < index; i++)
			{
				temp[i] = num[i];
			}
			temp[index] = var;
			i++;
			for (int j = index; j < count; j++)
			{
				temp[i] = num[j];
				i++;
			}
			count++;
			num = new char[10]();
			for (int i = 0; i < count; i++) num[i] = temp[i];
		}
	}
private:
	int count = 0;
	char *num;
};

int main()
{
	Leterchain obj1;
	obj1.add('A');
	obj1.add('B');
	obj1.add('C');
	obj1.add('D');
	cout << obj1.size() << endl;
	cout << obj1.get(0) << " " << obj1.get(1) << endl;
	obj1.Delete(1);
	obj1.insert(1, 'J');
	cout << obj1.get(0) << " " << obj1.get(1) << endl;

	return 0;
}