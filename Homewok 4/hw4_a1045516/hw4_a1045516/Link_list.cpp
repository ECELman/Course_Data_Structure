#include "Link_list.h"

#include <iostream>
using namespace std;

ChainNode::ChainNode(int data, ChainNode *link)
{
	this->data = data;
	this->link = link;
}

Chain::Chain() { first = NULL; }

// �s�W�`�I
void Chain::insert(int index, int value)
{
	if (index > count || index < 0) cout << "index���d��w�g�W�X�쵲�d��A " << value << " �N���Q���J�쵲��" << endl;
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

// �R���`�I
void Chain::Delete(int index)
{
	if (count == 0) cout << "�쵲�w�g�ŤF�A�L�����i�R��" << endl;
	else
	{
		if (index == count || index > count || index < 0) cout << "index���d��W�X�쵲�ثe���d��A���w��m�������N���Q�R��" << endl;
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

// �L�X�쵲��C
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

// ��Mk�ҹ������̤p��n
int Chain::kill_people(int n, int k)
{
	// ���Ncurrent�ثe���Ҧb��m���Vfirst
	current = first;

	int temp, after_mod, check = 0, temp_k;

	temp_k = k * 2;
	while (true)
	{
		/* ���Nn�Mk�i����l�ƪ��ʧ@�A�|�n�o�򰵬O�]�����k�ȶV�j���ɭԡA��ҧ�쪺�̤p��n�|�V�ӶV�j�A
		�p�G�����ӵ�n�����ƤU�h�]���ܡA�{��������ɶ��֩w�|�W�L15��A�ҥH�Q�Ψ��l�ƪ��ޥ��i�H�j�j
		����ֳ��ƪ��`�ơA�ϱo�{�����B��ɶ�����b15���]�� */
		after_mod = n % temp_k;

		/* �ھڨ��l�ƫ�ұo�쪺���G���O�h�������P���ƭȵ�temp�A�ܯS�O���O�A���p���ѩҨ��o���l�ƬO0��
		�ܡA�u�ݫ����ثe�s���H�Ʀ��h�֤H�Y�i�A���Υh�����`���ơA�ӥB�o�ˤl�N����o�P���������`����
		�@�Ҥ@�˪����G */
		if (after_mod == 0) temp = temp_k;
		else if (after_mod == 1) temp = 1;
		else temp = after_mod;

		/* �}�l���ơA�o�䪺�����I�N�O�A���p���ʨ�U�@�Ӧ�m���ɭԬO�Ū��Ϊ̬O�Ӧ�m�w�g�Q�������ܡA��
		�Ū������N��������first���L�A�p�G���������ܡA�|�ɭP�U��b���o�Ӧ�m����ƬO�������ƪ��A
		�åB�|�ϵ{���������A�Ӥ�����while�j��h�O�w�ﰲ�p�{�b���ʨ쪺��m�w�g�Q�������ܡA�N����
		�h��M�٨S�Q��������m�A�i�O�p�G��ۧ�۵��G�w�g���ʨ��쵲���̧��ݡA�i�O�٨S����٨S�Q����
		����m���ܡA�h�Nfirst������current�A�^���쵲���̶}�Y�A�o�ˤl�~���~��h�M���٨S�Q��������
		�m�A�ӥB�o��g���t�@�ӥت��N�O�h�קK�o�Ӧ�m�O�ũΪ̬O�w�g�Q�����F�A�i�Owhile�j�骺���ƨ�
		�M�Q��1�A�ϱo��ܪ����G�O���~�� */
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

		// �P�_�O����n�H�٬O�a�H
		if (current->data < k)
		{
			// ���p����n�H���ܡA�N��o�@�����M��O���Ѫ��A�h�����N����쵲���_��^�h
			current = first;
			for (int i = 0; i < k * 2; i++, current = current->link) if (current->data == -1) current->data = i;

			return 0;
		}
		else
		{
			// ���p����n�H���ܡA�h�N�Ӧ�m�Ҧs�񪺸�Ƨאּ-1�A�����Q�������аO
			current->data = -1;

			// �p��w�g���F�X���a�H
			check++;
			// ���p��������a�H���������ܡA�h�N��̲ת����Ƶ��L�X�ӡA�åB�^�Ǽƭ�1�ӥh�N��w�g���̤p��n�F
			if (check == k)
			{
				cout << "N = " << n << endl;

				return 1;
			}
			else
			{
				// ���p�٨S�����Ҧ����a�H���ܡA�޲��ʨ�U�@�Ӧ�m�~����ơA�~����䥦�a�H�A�����a�H���Q��������
				current = current->link;

				/* ���p���ʨ�U�@�Ӧ�m���ɭԬO�Ū��Ϊ̬O�Ӧ�m�w�g�Q�������ܡA���Ū������N��������first���L
				�A�p�G���������ܡA�|�ɭP�����W��n�h���o�o�Ӧ�m����ƪ��ɭԬO�������ƪ��A�åB�|�ϵ{����
				�����A�Ӥ�����while�j��h�O�w�ﰲ�p�{�b���ʨ쪺��m�w�g�Q�������ܡA�N�����h��M�٨S�Q��
				������m�A�i�O�p�G��ۧ�۵��G�w�g���ʨ��쵲���̧��ݡA�i�O�٨S����٨S�Q��������m���ܡA�h
				�Nfirst������current�A�^���쵲���̶}�Y�A�o�ˤl�~���~��h�M���٨S�Q��������m */
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

// �M���쵲��C���Y���Ҧ��`�I
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