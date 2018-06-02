/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/
/*You are required to complete
this function*/
bool cond(Node *curr, int n1, int n2);

Node* LCA(Node *curr, int n1, int n2)
{
	if(curr != NULL)
	{
		if(cond(curr, n1, n2) == 1)
			return curr;
	}

	if(n1 < curr->data && n2 < curr->data)
		return LCA(curr->left, n1, n2);
	else
		return LCA(curr->right, n1, n2);
}

bool cond(Node *curr, int n1, int n2)
{
	if(n1 > n2)
		swap(n1, n2); 

	// ensuring n1 < n2 and checking: n1 <= current-value < n2
	return ((curr->data >= n1) && (curr->data < n2));
}
