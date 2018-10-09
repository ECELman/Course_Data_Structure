#include <iostream>
using namespace std;

template <class T>
class ChainNode
{
public:
	ChainNode(T data,ChainNode<T> *link) 
	{ 
		this->data = data;
		this->link = link;
	}

	T data;
	ChainNode<T> *link;
};

template <class T>
class Chain
{
public:
	Chain() { first = NULL; }

	void insert(int index, T value)
	{
		if (index > count || index < 0) cout << "index���d��w�g�W�X�쵲�d��A " << value << " �N���Q���J�쵲��" << endl;
		else
		{
			if (index == 0)
			{
				ChainNode<T> *new_node = new ChainNode<T>(value, first);

				first = new_node;
				count++;

				cout << value << " �w�Q���J���쵲��" << endl;
			}
			else
			{
				ChainNode<T> *current_node = first;

				if (index == count)
				{
					while (current_node->link != NULL) current_node = current_node->link;

					ChainNode<T> *new_node = new ChainNode<T>(value, NULL);

					current_node->link = new_node;
					count++;

					cout << value << " �w�Q���J���쵲��" << endl;
				}
				else
				{
					ChainNode<T> *before_node = NULL;
					int current_index = 0;
					while (current_index != index)
					{
						current_node = current_node->link;
						current_index++;

						if (current_index == index - 1) before_node = current_node;
					}

					ChainNode<T> *new_node = new ChainNode<T>(value, current_node);

					before_node->link = new_node;

					count++;

					cout << value << " �w�Q���J���쵲��" << endl;
				}
			}
		}
	}

	void Delete(int index)
	{
		if (count == 0) cout << "�쵲�w�g�ŤF�A�L�����i�R��" << endl;
		else
		{
			if (index == count || index > count || index < 0) cout << "index���d��W�X�쵲�ثe���d��A���w��m�������N���Q�R��" << endl;
			else
			{
				if (index == 0)
				{
					ChainNode<T> *delete_node = first;
					cout << delete_node->data << " �w�q�쵲���R��" << endl;

					first = first->link;
					delete delete_node;

					count--;
				}
				else
				{
					ChainNode<T> *current_node = first;
					ChainNode<T> *before_delete_node = NULL;


					if (index == count)
					{
						while (current_node->link != NULL)
						{
							if (current_node->link->link == NULL) before_delete_node = current_node;
							current_node = current_node->link;
						}
						cout << current_node->data << " �w�q�쵲���R��" << endl;
						delete current_node;
						before_delete_node->link = NULL;

						count--;
					}
					else
					{
						ChainNode<T> *next_delete_node = NULL;

						int current_index = 0;
						while (current_index != index)
						{
							if (current_index == index - 1) before_delete_node = current_node;

							current_node = current_node->link;

							current_index++;
						}

						next_delete_node = current_node->link;
						before_delete_node->link = next_delete_node;

						cout << current_node->data << " �w�q�쵲���R��" << endl;
						delete current_node;

						count--;
					}
				}
			}
		}
	}

	void show()
	{
		ChainNode<T> *current = first;
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

	~Chain()
	{
		cout << endl << "�}�l�Ѻc : " << endl << endl;
		cout << "------------------------" << endl << endl;

		ChainNode<T> *next_node = NULL;
		while (first != NULL)
		{
			next_node = first->link;
			cout << first->data << " �w�g�q�쵲���R��" << endl << endl;
			delete first;
			first = next_node;
			count--;

			cout << "�ثe�쵲���A : " << endl;
			show();

			cout << endl << "------------------------" << endl << endl;
		}
	}
private:
	ChainNode<T> *first;
	int count = 0;
};

int main()
{
	char alp[5] = { 'a', 'b', 'c', 'd', 'e' };
	Chain<char> link_list;

	cout << "------------------------" << endl << endl;
	cout << "�إ��D�ةҭn���쵲 : " << endl;
	cout << endl << "------------------------" << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		link_list.insert(i, alp[i]);
		cout << endl << "�ثe���쵲���A : " << endl;
		link_list.show();
		cout << endl << "------------------------" << endl << endl;
	}

	cout << "�}�l�[�J�D�ةҭn�D�����e : " << endl;
	cout << endl << "------------------------" << endl << endl;
	link_list.insert(5, 'z');
	cout << endl << "�ثe���쵲���A : " << endl;
	link_list.show();
	cout << endl << "------------------------" << endl << endl;

	link_list.Delete(3);
	cout << endl << "�ثe���쵲���A : " << endl;
	link_list.show();
	cout << endl << "------------------------" << endl;

	return 0;
}