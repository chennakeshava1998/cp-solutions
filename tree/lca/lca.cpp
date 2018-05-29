
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */
int search_node(Node* node, int n1, int n2);
Node * LCA(Node* root ,int n1 ,int n2 )
{
	if(root == NULL)
		return NULL;


	if(root != NULL && search_node(root, n1, n2) != (n1 + n2))
   		return NULL;

   	if(root->left != NULL)
   	{
   		if(search_node(root->left, n1, n2) == (n1 + n2))
   			return LCA(root->left, n1, n2);
   	}
    
   	if(root->right != NULL)
   	{
   		if(search_node(root->right, n1, n2) == (n1 + n2))
   			return LCA(root->right, n1, n2);
   	}

   	return root;
}

int search_node(Node* node, int n1, int n2)
{
	int val = 0;
	if(node->data == n1)
		val += n1;
	else if(node->data == n2)
		val += n2;

	if(node->left != NULL)
		val += search_node(node->left, n1, n2);

	if(node->right != NULL)
		val += search_node(node->right, n1, n2);

	return val;
}