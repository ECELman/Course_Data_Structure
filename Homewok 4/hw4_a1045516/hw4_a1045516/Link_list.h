#ifndef LINK_LIST_H
#define LINK_LIST_H

class ChainNode
{
public:
	ChainNode(int, ChainNode*);

	int data;
	ChainNode *link;
};

class Chain
{
public:
	Chain();

	void insert(int, int); // 新增節點

	void Delete(int); // 刪除節點

	void show(); // 印出鏈結串列

	int kill_people(int, int); // 找尋k所對應的最小值n

	~Chain(); // 清空鏈結串列裡頭的所有節點
private:
	ChainNode *first, *current;
	int count = 0;
};

#endif