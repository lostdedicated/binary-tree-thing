#include <iostream>

using namespace std;

void clear()
{
	cout << "\033[2J\033[1;1H";
}
void done()
{
	cout << "Done!";
	cin.ignore();
	cin.get();
}

struct node
{
	int key_value;
	node *left;
	node *right;
};

class btree
{

public:
	btree()
	{
		root = NULL;
	};

	~btree()
	{
		destroy(root);
	};

	void insert(int key)
	{
		if (root != NULL)
		{
			insert(key, root);
		}
		else
		{
			root = new node;
			root->key_value = key;
			root->left = NULL;
			root->right = NULL;
		}
	};

	node *search(int key)
	{
		return search(key, root);
	};

	void destroy()
	{
		destroy(root);
	};
	void print()
	{
		print(root);
	}
private:
	void destroy(node *leaf)
	{
		if (leaf != NULL)
		{
			destroy(leaf->left);
			destroy(leaf->right);
			delete leaf;
		}
	};

	void insert(int key, node *leaf)
	{
		if(key< leaf->key_value)
		{
			if(leaf->left!=NULL)
			{
			insert(key, leaf->left);
			}
			else
			{
				leaf->left=new node;
				leaf->left->key_value=key;
				leaf->left->left=NULL;
				leaf->left->right=NULL;
			}
		}
		else if(key>=leaf->key_value)
		{
			if(leaf->right!=NULL)
			{
				insert(key, leaf->right);
			}
			else
			{
				leaf->right=new node;
				leaf->right->key_value=key;
				leaf->right->left=NULL;
				leaf->right->right=NULL;
			}
		}
	};


	node *search(int key, node *leaf)
	{
		if (leaf != NULL)
		{
			if (key == leaf->key_value)
			{
				return leaf;
			}
			if (key<leaf->key_value)
			{
				return search(key, leaf->left);
			}
			else
			{
				return search(key, leaf->right);
			}
		}
		else return NULL;
	};
	void print(node *leaf)
	{
		if (leaf != NULL)
		{
			if (leaf->left != NULL)
			{
				print(leaf->left);
			}
			if (leaf->right != NULL)
			{
				print(leaf->right);
			}
 			cout << leaf->key_value << "\n";
		}
		else
		{
			return;
		}
	}
	node *root;
};

int main()
{
	btree tree;
	int value, nodesToAdd, i;
	char action;
	do
	{
		clear();
		cout << "Binary tree thing\n Select an action:\n 1. Add nodes \n 2. Search for a value (first matching node) \n 3. Print the tree \n 4. Shutdown \n"; 
		cout << "Input: ";
		cin >> action;
		switch (action)
		{
			case '1': 
				clear();
				cout << "Nodes to add: ";
				cin >> nodesToAdd;
				cout << "Enter the values, separated by spaces: ";
				for (int i = 0; i != nodesToAdd; i++)
				{
					cin >> value;
					tree.insert(value);
				}
				done();
				break;

			case '2':
				clear();
				cout << "Value to search for: ";
				cin >> value;
				if (tree.search(value) == 0)
				{
					cout << "No nodes containing entered value \n";
				}
				else
				{
					cout << "Address is " << tree.search(value) << "\n";
				}
				done();
				break;

			case '3':
				clear();
				tree.print();
				done();
				break;

			case '4':
				clear();
				tree.destroy();
				break;
		}
	} while (action != '4');
	return 0;
}