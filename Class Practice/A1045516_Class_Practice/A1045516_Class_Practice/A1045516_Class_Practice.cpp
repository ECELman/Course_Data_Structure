#include <iostream>
using namespace std;

template <class T>
class ChainNode
{
public:
	ChainNode() { link = NULL; }

	T data;
	ChainNode<T> *link;
};

template <class T>
class Chain
{
public:
	Chain() { first = NULL; }
	ChainNode<T>* insert(T value)
	{
		ChainNode<T> *current_locate;
		if (first == NULL)
		{
			first = new ChainNode<T>;
			current_locate = first;
		}
		else
		{
			current_locate = first;
			while (current_locate->link != NULL) current_locate = current_locate->link;
			current_locate->link = new ChainNode<T>;
			current_locate = current_locate->link;
		}

		current_locate->data = value;
		
		return first;
	}
private:
	ChainNode<T> *first;
};

int main()
{
	char alp[5] = { 'a','b','c','d','e' };
	Chain<char> list;
	ChainNode<char> *current;
	for (int i = 0; i < 5; i++) current = list.insert(alp[i]);

	for (; current != NULL; current = current->link)
	{
		if (current->link != NULL) cout << current->data << " -> ";
		else cout << current->data << endl;
	}

	return 0;
}