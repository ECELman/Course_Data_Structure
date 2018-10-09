#include "Link_list.h"

#include <iostream>
using namespace std;

ChainNode::ChainNode(int data, ChainNode *link)
{
	this->data = data;
	this->link = link;
}

Chain::Chain() { first = NULL; }

// 新增節點
void Chain::insert(int index, int value)
{
	if (index > count || index < 0) cout << "index的範圍已經超出鏈結範圍， " << value << " 將不被插入鏈結中" << endl;
	else
	{
		if (index == 0)
		{
			ChainNode *new_node = new ChainNode(value, first);

			first = new_node;
			count++;
		}
		else
		{
			ChainNode *current_node = first;

			if (index == count)
			{
				while (current_node->link != NULL) current_node = current_node->link;

				ChainNode *new_node = new ChainNode(value, NULL);

				current_node->link = new_node;
				count++;
			}
			else
			{
				ChainNode *before_node = NULL;
				int current_index = 0;
				while (current_index != index)
				{
					current_node = current_node->link;
					current_index++;

					if (current_index == index - 1) before_node = current_node;
				}

				ChainNode *new_node = new ChainNode(value, current_node);

				before_node->link = new_node;

				count++;
			}
		}
	}
}

// 刪除節點
void Chain::Delete(int index)
{
	if (count == 0) cout << "鏈結已經空了，無元素可刪除" << endl;
	else
	{
		if (index == count || index > count || index < 0) cout << "index的範圍超出鏈結目前的範圍，指定位置的元素將不被刪除" << endl;
		else
		{
			if (index == 0)
			{
				ChainNode *delete_node = first;

				first = first->link;
				delete delete_node;

				count--;
			}
			else
			{
				ChainNode *current_node = first;
				ChainNode *before_delete_node = NULL;

				if (index == count)
				{
					while (current_node->link != NULL)
					{
						if (current_node->link->link == NULL) before_delete_node = current_node;
						current_node = current_node->link;
					}

					delete current_node;
					before_delete_node->link = NULL;

					count--;
				}
				else
				{
					ChainNode *next_delete_node = NULL;

					int current_index = 0;
					while (current_index != index)
					{
						if (current_index == index - 1) before_delete_node = current_node;

						current_node = current_node->link;

						current_index++;
					}

					next_delete_node = current_node->link;
					before_delete_node->link = next_delete_node;

					delete current_node;

					count--;
				}
			}
		}
	}
}

// 印出鏈結串列
void Chain::show()
{
	ChainNode *current = first;
	if (count == 0) cout << "NULL" << endl;
	else
	{
		for (; current != NULL; current = current->link)
		{
			if (current->link != NULL) cout << current->data << " -> ";
			else cout << current->data << endl;
		}
	}
}

// 找尋k所對應的最小值n
int Chain::kill_people(int n, int k)
{
	// 先將current目前的所在位置指向first
	current = first;

	int temp, after_mod, check = 0, temp_k;

	temp_k = k * 2;
	while (true)
	{
		/* 先將n和k進行取餘數的動作，會要這麼做是因為當其k值越大的時候，其所找到的最小值n會越來越大，
		如果直接照著n的報數下去跑的話，程式的執行時間肯定會超過15秒，所以利用取餘數的技巧可以大大
		的減少報數的總數，使得程式的運行時間能夠在15秒內跑完 */
		after_mod = n % temp_k;

		/* 根據取餘數後所得到的結果分別去指派不同的數值給temp，很特別的是，假如今天所取得的餘數是0的
		話，只需指派目前存活人數有多少人即可，不用去指派總報數，而且這樣子就能獲得與直接指派總報數
		一模一樣的結果 */
		if (after_mod == 0) temp = temp_k;
		else if (after_mod == 1) temp = 1;
		else temp = after_mod;

		/* 開始報數，這邊的關鍵點就是，假如移動到下一個位置的時候是空的或者是該位置已經被殺掉的話，像
		空的部分就必須指派first給他，如果不指派的話，會導致下方在取這個位置的資料是取不到資料的，
		並且會使程式直接當掉，而內部的while迴圈則是針對假如現在移動到的位置已經被殺掉的話，就必須
		去找尋還沒被殺掉的位置，可是如果找著找著結果已經移動到鏈結的最尾端，可是還沒找到還沒被殺掉
		的位置的話，則將first指派給current，回到鏈結的最開頭，這樣子才能繼續去尋找還沒被殺掉的位
		置，而且這麼寫的另一個目的就是去避免這個位置是空或者是已經被殺掉了，可是while迴圈的次數依
		然被減1，使得顯示的結果是錯誤的 */
		while (temp != 1)
		{
			current = current->link;

			if (current == NULL) current = first;
			else
			{
				while (current->data == -1)
				{
					current = current->link;
					if (current == NULL) current = first;
				}
			}

			temp--;
		}

		// 判斷是殺到好人還是壞人
		if (current->data < k)
		{
			// 假如殺到好人的話，代表這一次的尋找是失敗的，則必須將整個鏈結給復原回去
			current = first;
			for (int i = 0; i < k * 2; i++, current = current->link) if (current->data == -1) current->data = i;

			return 0;
		}
		else
		{
			// 假如殺到好人的話，則將該位置所存放的資料改為-1，做為被殺掉的標記
			current->data = -1;

			// 計算已經殺了幾個壞人
			check++;
			// 假如把全部的壞人都殺光的話，則將其最終的報數給印出來，並且回傳數值1來去代表已經找到最小值n了
			if (check == k)
			{
				cout << "N = " << n << endl;

				return 1;
			}
			else
			{
				// 假如還沒殺光所有的壞人的話，技移動到下一個位置繼續報數，繼續殺其它壞人，直到壞人都被殺光為止
				current = current->link;

				/* 假如移動到下一個位置的時候是空的或者是該位置已經被殺掉的話，像空的部分就必須指派first給他
				，如果不指派的話，會導致等等上方要去取得這個位置的資料的時候是取不到資料的，並且會使程式直
				接當掉，而內部的while迴圈則是針對假如現在移動到的位置已經被殺掉的話，就必須去找尋還沒被殺
				掉的位置，可是如果找著找著結果已經移動到鏈結的最尾端，可是還沒找到還沒被殺掉的位置的話，則
				將first指派給current，回到鏈結的最開頭，這樣子才能繼續去尋找還沒被殺掉的位置 */
				if (current == NULL) current = first;
				else
				{
					while (current->data == -1)
					{
						current = current->link;
						if (current == NULL) current = first;
					}
				}

				temp_k--;
			}
		}
	}
}

// 清空鏈結串列裡頭的所有節點
Chain::~Chain()
{
	ChainNode *next_node = NULL;
	while (first != NULL)
	{
		next_node = first->link;
		delete first;
		first = next_node;
		count--;
	}
}