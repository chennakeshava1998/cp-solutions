/*
Tuesday - May 29th
Question 2:
struct Node
{
 Node *next;
 Node *random;
};

The above struct represents a node in a linked list. 
You are given the head of one such linked list. 
You are tasked with creating a replica of this linked list. 
Assumptions are next points to the next node in a linked list, 
random points to a random node in the linked list. 
Expected time complexity O(N).

*/

// O(NlogN) solution


// maps the (node address) ====> (node-number) for the provided LL
// Node-number is indexed by i in the function traverse_given_LL
map<struct Node*, int> given_LL;

// maps Node-number(Node-index) ====> Pointer-Address for the Duplicate LL
map<int, struct Node*> to_construct_LL;

int n;// total number of nodes in the provided LL 

// traverse the given LL and construct a mapping from (address-of-node) ---> (index-of-node);
// Also, find out the total number of nodes in the given LL
void traverse_given_LL(struct Node* HEAD)
{
	struct Node* ptr = HEAD;
	int i = 0;
	while(ptr != NULL)
	{
		given_LL[ptr] = i++;
		ptr = ptr->next;
	}

	n = i; 
}

// Creates the duplicate LL
// Returns the head pointer of the new LL
// Builds the inverse mapping to_construct_LL
struct Node* construct_new_LL()
{
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node)), HEAD, prev;
	HEAD = ptr;
	prev = ptr;
	int i = 0;

	to_construct_LL[i] = ptr;
	++i;

	while(i < n)
	{
		ptr = (struct Node*)malloc(sizeof(struct Node));
		to_construct_LL[i] = ptr;
		prev->next = ptr;

		// to prevent dangling pointers
		ptr->next = NULL;
		ptr->random = NULL;
		++i;
	}
	return HEAD;
}

// this function replicates the structure of LL1 in LL2 using the two maps.
// HEAD1 and HEAD2 are the starting nodes of the two LLs

void duplicate(HEAD1, HEAD2)
{
	struct Node *ptr1 = HEAD1, *ptr2 = HEAD2;

	while(ptr1 != NULL)
	{
		ptr2->random = to_construct_LL[given_LL[ptr1->random]];
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
}