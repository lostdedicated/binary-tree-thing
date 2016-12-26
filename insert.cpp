void insert(int key, node *leaf)
{
	if (key < leaf->key_value)
	{
		if (leaf->left != NULL)
		{
			insert(key, leaf->left);
		}
		else
		{
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key> = leaf->key_value)
	{
		if (leaf->right != NULL)
		{
			insert(key, leaf->right);
		}
		else
		{
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
};