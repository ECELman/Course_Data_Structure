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

	void insert(int, int); // �s�W�`�I

	void Delete(int); // �R���`�I

	void show(); // �L�X�쵲��C

	int kill_people(int, int); // ��Mk�ҹ������̤p��n

	~Chain(); // �M���쵲��C���Y���Ҧ��`�I
private:
	ChainNode *first, *current;
	int count = 0;
};

#endif