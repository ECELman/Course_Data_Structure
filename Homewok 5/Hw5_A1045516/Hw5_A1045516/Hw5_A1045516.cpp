#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// �إ߾𪺵��I
class Tree_node
{
public:
	Tree_node(char word,int frequency)
	{ 
		this->word = word;
		this->frequency = frequency;
		use = false;
		mark = -1;
		left_child = right_child = upper_parent = NULL;
	}

	char word;
	int frequency, mark;
	bool use;
	Tree_node *left_child, *right_child,*upper_parent;
};

// ��X�W�v�̤p���r���A�åB�^�ǸӦr���b�}�C��������
int min_frequency(Tree_node **node, int count)
{
	int min = 1000;
	int index;
	for (int i = 0; i < count; i++)
	{
		if (node[i]->frequency < min && node[i]->use == false)
		{
			min = node[i]->frequency;
			index = i;
		}
	}

	node[index]->use = true;

	return index;
}

int main()
{
	//------------------------------------------------------------------------------------------------------------
	// Ū���ɮרåB�Ыؾ𪺵��I
	string s, code;
	int count = 0;
	Tree_node **node = NULL;

	fstream in;
	in.open("p5.in", ios::in);
	if (!in) cout << "�ɮ׵L�k�}��" << endl;
	else
	{
		stringstream ss;

		// ���P�_�`�@���X�Ӧr��
		while (getline(in, s))
		{
			if (s.length() == 0) break;
			else count++;
		}
		in.close();

		in.open("p5.in", ios::in);
		if (!in) cout << "�ɮ׵L�k�}��" << endl;
		else
		{
			node = new Tree_node*[count * 2 - 1]();
			int temp_count = 0;

			stringstream ss;
			while (getline(in, s))
			{
				// ���pŪ��Ŧ�A�h����Ū���U�@��
				if (s == " ") continue;

				// �Ыؾ𪺵��I
				if (temp_count != count)
				{
					ss << s;
					char word;
					int frequency;

					// ���pŪ�J���r�����ťզr���A�h�t�~�w��word�Mfrequency���B�z
					if (s[0] == ' ' && s[1] == ' ')
					{
						ss >> frequency;
						word = ' ';
					}
					else ss >> word >> frequency;
					
					node[temp_count] = new Tree_node(word, frequency);

					temp_count++;

					ss.clear();
				}
				else code = s;
			}
			in.close();
		}
	}
	
	//------------------------------------------------------------------------------------------------------------
	// �̷��N�Ұҽs�X���W�h�ӥh�N�Ҧ����I�s���_�Ӧ����@�Ӿ𪺵��c
	Tree_node *root = NULL; // �Ыخڵ��I
	int temp_count = count; // �ӥh������ɷs�W���I�b�}�C���s�񪺦�m��index
	char word = '1'; // ����º�O���F��ɷs�W�X�Ӫ����I�ӥh�����аO

	/* �}�l�Ыؾ�A�ӳo�̪�count���ҥH�n��1����]�N�b��]���s�W�����I�O�Ѩ�Ӥl���I�ӥh�ЫإX�Ӫ��A
	   ���p���Ѧ�5�Ӧr���A����N�|�h�s�W4�ӵ��I�X�ӡA�ӳo�s�W�X�Ӫ����I�ƶq��n�N�O�`�r���1 */
	for (int i = 0; i < count - 1; i++)
	{
		int node_sum = 0, min_1, min_2;

		// ��X�W�v�Ĥ@�p���r���A�åB�N�аO�]��0
		min_1 = min_frequency(node, temp_count);
		node[min_1]->mark = 0;

		// ��X�W�v�ĤG�p���r���A�åB�N�аO�]��1
		min_2 = min_frequency(node, temp_count);
		node[min_2]->mark = 1;

		// �`�X�Ĥ@�p���r���M�ĤG�p���r�����W�v�A�����s���I���W�v�A�åB�N�Ĥ@�p���r����b���l��A�ĤG�p���r����b�k�l��
		node_sum = node[min_1]->frequency + node[min_2]->frequency;
		node[temp_count] = new Tree_node(word + i, node_sum);
		node[temp_count]->left_child = node[min_1];
		node[temp_count]->right_child = node[min_2];

		// �����W�v�Ĥ@�p���r���M�W�v�ĤG�p���r���ҳЫإX�Ӫ������I�A��ɰ��s�X���ɭԥΪ���
		node[min_1]->upper_parent = node[temp_count];
		node[min_2]->upper_parent = node[temp_count];
		
		// ��X�ڵ��I
		if (i == count - 2) root = node[temp_count];
		else temp_count++;
	}

	//------------------------------------------------------------------------------------------------------------
	// �ΨӦs��C�Ӧr���ҹ������s�X
	int **huffman_code = new int*[count];
	for (int i = 0; i < count; i++) huffman_code[i] = new int[count]();
	
	// �|�⤸������l�Ʀ�-1���ت��N�O���F���@�U�L�X�s�X���ɭԥi�H�h���P�_���ʧ@
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++) huffman_code[i][j] = -1;

	// �d��C�Ӧr���������s�X
	for (int i = 0; i < count; i++)
	{
		Tree_node *current_node = node[i];
		int index = 0;

		// �q�̩��@�����W��A������ڵ��I����A�o�˦r���ҹ����s�X�N�X�ӤF
		while (current_node != root)
		{
			huffman_code[i][index] = current_node->mark;
			current_node = current_node->upper_parent;

			index++;
		}
	}

	//------------------------------------------------------------------------------------------------------------
	// �N���G�g�J�ɮ�
	fstream out;
	out.open("p5.out", ios::out);
	if (!out) cout << "�L�k�}���ɮ�" << endl;
	else
	{
		for (int i = 0; i < count; i++)
		{
			out << node[i]->word << " ";
			for (int j = count - 1; j >= 0; j--) if (huffman_code[i][j] != -1) out << huffman_code[i][j];
			out << endl;
		}

		out << endl;
		for (int i = 0; i < code.length(); i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (code[i] == node[j]->word)
				{
					for (int k = count - 1; k >= 0; k--)
					{
						if (huffman_code[j][k] != -1) out << huffman_code[j][k];
					}
				}
			}
		}
	}

	return 0;
}