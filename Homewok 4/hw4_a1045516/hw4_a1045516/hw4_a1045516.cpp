#include "Link_list.h"
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	int k;
	cout << "請輸入K的值 : ";
	cin >> k;

	Chain people;
	for (int i = 0; i < k * 2; i++) people.insert(i, i);

	// 找尋k所對應的最小值n
	cout << "K = " << k << endl;
	double start, end;
	start = (double)clock() / CLOCKS_PER_SEC;
	for (int n = k + 1;; n++)
	{
		int result = people.kill_people(n, k);
		if (result == 0) continue;
		else break;
	}
	end = (double)clock() / CLOCKS_PER_SEC;
	cout << "秒數 : " << end - start << " s" << endl;

	return 0;
}