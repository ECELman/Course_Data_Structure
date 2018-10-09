#include "Link_list.h"
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	int k;
	cout << "�п�JK���� : ";
	cin >> k;

	Chain people;
	for (int i = 0; i < k * 2; i++) people.insert(i, i);

	// ��Mk�ҹ������̤p��n
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
	cout << "��� : " << end - start << " s" << endl;

	return 0;
}