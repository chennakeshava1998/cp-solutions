// Question 1: June 4th. 2018
// Given a binary tree, check whether it is a BST (Binary Search Tree) or not.

/*
 Approach-1: Fails for these types of test-cases: (Naiive)
 Eg:    10
     /     \
   7       39
     \
      11

      

bool check_bst(Node *root);


// Condition for BST: left <= root < right


*/



// Approach-2: Perform inOrder traversal and check if the final sequence is sorted
// Some alternatives in this method still cause Segmentation Fault: Lines: 76 and 88

struct Node
{
	int val;
	Node *left, *right;
};


bool isBST(Node* root);
void inOrder(Node *root, vector<int>&v);


void inOrder(Node *root, vector<int>&v)
{
	if(root == NULL)
		return;

	inOrder(root->left, v);

	v.push_back(root->data);

	inOrder(root->right, v);	
}



bool isBST(Node* root) {
	vector<int>v;
	int i;
	inOrder(root, v);
    
    vector<int>a(v.size());

	for(i=0;i<v.size();++i)
	    a[i] = v[i];


/*
FIXME: The below for-loop causes a Seg-Fault, why ??
	for(i=0;i<v.size()-1;++i)
	{
		if(v[i] > v[i+1])
			return 0;
	}
*/


sort(v.begin(), v.end());

/*
FIXME: Usage of a copy method, to copy vectors causes Seg-Fault
copy(v.begin(), v.end(), a.begin());
*/


if(v == a)
    return 1;
else
    return 0;
    
}
