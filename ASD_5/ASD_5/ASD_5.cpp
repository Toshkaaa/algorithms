#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
using namespace std;


struct Node
{
	int key;
	Node* left;
	Node* right;
	Node* parent;
};

class Tree
{
	Node* root;
public:
	Tree() :root(NULL) {};
	void Tree_Insert(int x);
	void Show_Tree(Node* tmp, string prob);
	void Find_number(int a);
	void Find_Max();
	Node* GetNode();
};

void Tree::Tree_Insert(int a)
{
	Node* Element_to_insert = new Node;
	Element_to_insert->key = a;
	Element_to_insert->left = Element_to_insert->right = NULL;
	Node* y = NULL;
	Node* x = root;
	while (x != NULL)
	{
		y = x;
		if (Element_to_insert->key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	Element_to_insert->parent = y;

	if (y == NULL)
	{
		root = Element_to_insert;
	}
	else if (y->key > Element_to_insert->key)
	{
		y->left = Element_to_insert;
	}
	else
	{
		y->right = Element_to_insert;
	}
}

void Tree::Show_Tree(Node* tmp, string prob)
{
	if (tmp != NULL)
	{
		prob = prob + "  ";
		Show_Tree(tmp->right, prob);
		cout << prob + " " << tmp->key << endl;
		if (tmp->left != NULL)
		{
			string prob2 = prob + "  ";
			while (tmp->left != NULL)
			{
				cout << prob2 << "\\" << endl;
				if (tmp->left->right != NULL)
				{
					string prob3 = prob2 +"";
					Show_Tree(tmp->left->right, prob3);
					prob3 = prob3.erase(prob3.length() - 2, 2);
				}
				cout << prob2 + " " << tmp->left->key << endl;
				prob2 = prob2 + "  ";
				tmp = tmp->left;
			}
		}
		if (tmp->parent != NULL and tmp->parent != tmp->parent->left)
		{
			cout << prob << "/" << endl;
			prob = prob.erase(prob.length() - 2, 2);
		}
	}
}

void Tree::Find_Max()
{
	if (root == NULL)
	{
		cout << "Your tree is empty!" << endl;
	}
	else
	{
		Node* tmp = root;
		while (tmp->right != NULL)
		{
			tmp = tmp->right;
		}
		cout << "Max element  is " << tmp->key << endl;
	}
}

void Tree::Find_number(int a)
{
	Node* tmp = root;
	while (tmp != NULL)
	{
		if (a == tmp->key)
		{
			cout << "Element " << a << " has been found in the tree! " << endl;
			break;
		}
		if (a > tmp->key)
		{
			tmp = tmp->right;
		}
		else
		{
			tmp = tmp->left;
		}
	}
}

Node* Tree::GetNode()
{
	return root;
}




struct Node2 
{
	string key;
	Node2* parent;
	Node2* left;
	Node2* right;
};

class Tree2
{
	Node2* root;
public:
	Tree2() :root(NULL) {};
	void Clear(Node2* tmp);
	void Tree_Insert(string x);
	Node2* Get_root();
	void Show_Tree(Node2* tmp, string prob);
	Node2* FindElement(string x);
	void Initial_Root();
	Node2* Tree_Successor(string x);
	Node2* Tree_Min(Node2* tmp);
	void DeleteElement(string x);
};

Node2* Tree2::Tree_Min(Node2 *tmp)
{
	while (tmp->left!=NULL)
	{
		tmp = tmp->left;
	}
	cout << "Element " << tmp->key << endl;
	return tmp;
}

Node2* Tree2::Tree_Successor(string x)
{
	Node2* tmp = FindElement(x);
	if (tmp->right!=NULL)
	{
		return tmp = Tree_Min(tmp->right);
	}
	Node2* tmp_parent = tmp->parent;
	while (tmp_parent->left!=tmp or tmp_parent!=NULL)
	{
		tmp = tmp_parent;
		tmp_parent=tmp_parent->parent;
	}
}

void Tree2::Initial_Root()
{
	root = NULL;
}

void Tree2::Clear(Node2 *tmp) 
{
	if (tmp)
	{
		Clear(tmp->left);
		Clear(tmp->right);
		delete tmp;
	}
}

void Tree2::Tree_Insert(string x)
{
	Node2* NewEl = new Node2;
	NewEl->key = x;
	NewEl->left = NewEl->right = NewEl->parent = NULL;
	Node2* tmp = root;
	Node2* tmp_parent = NULL;
	while (tmp!=NULL)
	{
		tmp_parent = tmp;
		if (tmp->key > NewEl->key)
		{
			tmp = tmp->left;
		}
		else
		{
			tmp = tmp->right;
		}
	}
	NewEl->parent = tmp_parent;
	if (tmp_parent==NULL)
	{
		root = NewEl;
	}
	else
	{
		if (tmp_parent->key > NewEl->key)
		{
			tmp_parent->left = NewEl;
		}
		else
		{
			tmp_parent->right = NewEl;
		}
	}
}

Node2* Tree2::Get_root()
{
	return root;
}

void Tree2::Show_Tree(Node2* tmp,string prob)
{
	if (tmp != NULL)
	{
		prob = prob + "  ";
		Show_Tree(tmp->right, prob);
		cout << prob + " " << tmp->key << endl;
		if (tmp->left != NULL)
		{
			string prob2 = prob + "  ";
			while (tmp->left != NULL)
			{
				cout << prob2 << "\\" << endl;
				if (tmp->left->right != NULL)
				{
					string prob3 = prob2 + "";
					Show_Tree(tmp->left->right, prob3);
					prob3 = prob3.erase(prob3.length() - 2, 2);
				}
				cout << prob2 + " " << tmp->left->key << endl;
				prob2 = prob2 + "  ";
				tmp = tmp->left;
			}
		}
		if (true)
		{
			cout << prob << "/" << endl;
			prob = prob.erase(prob.length() - 2, 2);
		}
	}
}

Node2* Tree2::FindElement(string x)
{
	Node2* tmp = root;
	while (tmp!=NULL)
	{
		if (x==tmp->key)
		{
			cout << "Element " <<tmp->key<<" has been found" << endl;
			return tmp;
		}
		else
		{
			if (tmp->key > x)
			{
				tmp = tmp->left;
			}
			else
			{
				tmp = tmp->right;
			}
		}
	}
	cout << "Your tree has not this element, that why we need to add it to the tree! " << endl;
	Tree_Insert(x);
}

void Tree2::DeleteElement(string x)
{
	Node2* tmp = FindElement(x);
	Node2* tmp_parent = tmp->parent;
	Node2* xy;
	if (tmp->left == NULL or tmp->right == NULL)
	{
		if (tmp->left != NULL and tmp->right==NULL)
		{
			xy = tmp->left;
			tmp->left->parent = tmp_parent;
		}
		else if (tmp->right != NULL and tmp->left==NULL)
		{
			xy = tmp->right;
			tmp->right->parent = tmp_parent;
		}
		else
		{
			xy = NULL;
		}

		if (tmp_parent->key > tmp->key)
		{
			tmp_parent->left = xy;
		}
		else
		{
			tmp_parent->right = xy;
		}
		delete tmp;
	}
	else
	{
		Node2* Successor=Tree_Successor(x);
		string my = Successor->key;
		DeleteElement(Successor->key);
		tmp->key = my;
	}
	cout << "Eement " << x << " has been deleted!" << endl;
}


void FindElementInTheFile(string x)
{
	char buff[50];
	fstream f;
	f.open("cppstudio.txt", ios_base::app | ios_base::in);
	while (f.getline(buff, 50))
	{
		if (x==buff)
		{
			cout << "The word has been found in the file!" << endl;
			f.close();
			return;
		}
	}
	cout << "Your file has not this element, that why we need to add it to the file! " << endl;
	f << x << endl;
	f.close();
}

void DeleteFromTheFile(string x) 
{
	char buff[50];
	fstream f;
	f.open("cppstudio.txt", ios_base::in);
	vector<string>buffer;
	bool flag;
	while (f.getline(buff, 50))
	{
		buffer.push_back(buff);
		if (x == buff)
		{
			cout << "The word has been found in the file!" << endl;		
			flag = 1;
		}
	}

	if (flag)
	{
		f.close();
		f.open("cppstudio.txt", ios::trunc | ios::out);
		for (int i = 0; i < buffer.size(); i++)
		{
			if (buffer[i] != x)
			{
				f << buffer[i] << endl;
			}
		}
		cout << "The word has been deleted from the file!" << endl;
	}
	f.close();
}

int main()
{
	/*Tree T;
	int number;
	cout << " Choose what u want to do: \n";
	cout << "1.Add element to the tree\n";
	cout << "2.Show tree\n";
	cout << "3.Find max number\n";
	cout << "4.Find your number\n";
	cout << "0.Exit\n";
	while (true)
	{
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 0)
			{
				break;
			}
			else cout << "Invalid input, please try again\n";
		}
		if (choice == 0) break;
		switch (choice)
		{
		case 1:
		{
			cout << "Enter your element to add in the tree: ";
			cin >> number;
			T.Tree_Insert(number);
			break;
		}
		case 2:
		{
			T.Show_Tree(T.GetNode(), "  ");
			cout << "This is your tree" << endl;
			break;
		}
		case 3:
		{
			T.Find_Max();
			break;
		}
		case 4:
		{
			int number1;
			cout << "Enter your number to find:  ";
			cin >> number1;
			T.Find_number(number1);
			break;
		}
		}
	}*/
	
	Tree2 tree2;
	cout << "Choose what u want to do: \n";
	cout << "1.Create tree from the file\n";
	cout << "2.Find word in the tree\n";
	cout << "3.Find word in the file\n";
	cout << "4.Delete word from the tree\n";
	cout << "5.Delete word from the file\n";
	cout << "6.Show your tree\n";
	cout << "0.Exit\n";
	while (true)
	{
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 0)
			{
				break;
			}
			else cout << "Invalid input, please try again!\n";
		}
		if (choice == 0) break;
		switch (choice)
		{
			case 1:
			{
				char buff[50];
				ifstream fin("cppstudio.txt");
				if (tree2.Get_root()!=NULL)
				{
					tree2.Clear(tree2.Get_root());
					tree2.Initial_Root();
				}
				while (fin.getline(buff, 50))
				{
					tree2.Tree_Insert(buff);
				}
				fin.close();
				break;
			}

			case 2:
			{
				string mystring;
				cout << "Enter word to find in the tree:  " ;
				cin >> mystring;
				clock_t time1 = clock();
				tree2.FindElement(mystring);
				clock_t time2 = clock();
				int delta = (time2 - time1) * 1000 / CLOCKS_PER_SEC;
				cout << "Time = " << delta << " ms" << endl;
				break;
			}

			case 3:
			{
				string mystring;
				cout << "Enter your string to find in the file:  ";
				cin >> mystring;
				clock_t time1 = clock();
				FindElementInTheFile(mystring);
				clock_t time2 = clock();
				int delta = (time2 - time1) * 1000 / CLOCKS_PER_SEC;
				cout << "Time = " << delta << " ms" << endl;
				break;
			}

			case 4:
			{
				string mystring;
				cout << "Enter your string to delete:  ";
				cin >> mystring;
				tree2.DeleteElement(mystring);
				break;
			}

			case 5:
			{
				string mystring;
				cout << "Enter your string to delete from the file:  ";
				cin >> mystring;
				DeleteFromTheFile(mystring);
				break;
			}

			case 6: 
			{
				tree2.Show_Tree(tree2.Get_root(), "  ");
				break;
			}
		}
	}
}