#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// 建立樹的結點
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

// 找出頻率最小的字元，並且回傳該字元在陣列中的索引
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
	// 讀取檔案並且創建樹的結點
	string s, code;
	int count = 0;
	Tree_node **node = NULL;

	fstream in;
	in.open("p5.in", ios::in);
	if (!in) cout << "檔案無法開啟" << endl;
	else
	{
		stringstream ss;

		// 先判斷總共有幾個字元
		while (getline(in, s))
		{
			if (s.length() == 0) break;
			else count++;
		}
		in.close();

		in.open("p5.in", ios::in);
		if (!in) cout << "檔案無法開啟" << endl;
		else
		{
			node = new Tree_node*[count * 2 - 1]();
			int temp_count = 0;

			stringstream ss;
			while (getline(in, s))
			{
				// 假如讀到空行，則直接讀取下一行
				if (s == " ") continue;

				// 創建樹的結點
				if (temp_count != count)
				{
					ss << s;
					char word;
					int frequency;

					// 假如讀入的字元為空白字元，則另外針對word和frequency做處理
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
	// 依照霍夫曼編碼的規則來去將所有結點連接起來成為一個樹的結構
	Tree_node *root = NULL; // 創建根結點
	int temp_count = count; // 來去做為到時新增結點在陣列當中存放的位置的index
	char word = '1'; // 此行純粹是為了到時新增出來的結點來去給予標記

	/* 開始創建樹，而這裡的count之所以要減1的原因就在於因為新增的結點是由兩個子結點來去創建出來的，
	   假如今天有5個字元，那麼就會多新增4個結點出來，而這新增出來的結點數量剛好就是總字元減掉1 */
	for (int i = 0; i < count - 1; i++)
	{
		int node_sum = 0, min_1, min_2;

		// 找出頻率第一小的字元，並且將標記設為0
		min_1 = min_frequency(node, temp_count);
		node[min_1]->mark = 0;

		// 找出頻率第二小的字元，並且將標記設為1
		min_2 = min_frequency(node, temp_count);
		node[min_2]->mark = 1;

		// 總合第一小的字元和第二小的字元的頻率，做為新結點的頻率，並且將第一小的字元放在左子樹，第二小的字元放在右子樹
		node_sum = node[min_1]->frequency + node[min_2]->frequency;
		node[temp_count] = new Tree_node(word + i, node_sum);
		node[temp_count]->left_child = node[min_1];
		node[temp_count]->right_child = node[min_2];

		// 指明頻率第一小的字元和頻率第二小的字元所創建出來的父結點，到時做編碼的時候用的到
		node[min_1]->upper_parent = node[temp_count];
		node[min_2]->upper_parent = node[temp_count];
		
		// 找出根結點
		if (i == count - 2) root = node[temp_count];
		else temp_count++;
	}

	//------------------------------------------------------------------------------------------------------------
	// 用來存放每個字元所對應的編碼
	int **huffman_code = new int*[count];
	for (int i = 0; i < count; i++) huffman_code[i] = new int[count]();
	
	// 會把元素都初始化成-1的目的就是為了等一下印出編碼的時候可以去做判斷的動作
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++) huffman_code[i][j] = -1;

	// 查找每個字元的對應編碼
	for (int i = 0; i < count; i++)
	{
		Tree_node *current_node = node[i];
		int index = 0;

		// 從最底一路往上找，直到找到根結點為止，這樣字元所對應編碼就出來了
		while (current_node != root)
		{
			huffman_code[i][index] = current_node->mark;
			current_node = current_node->upper_parent;

			index++;
		}
	}

	//------------------------------------------------------------------------------------------------------------
	// 將結果寫入檔案
	fstream out;
	out.open("p5.out", ios::out);
	if (!out) cout << "無法開啟檔案" << endl;
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