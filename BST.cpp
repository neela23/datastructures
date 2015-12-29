#include<iostream>
#include<queue>
using namespace std;

struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
}*root=NULL;

// *************************BASIC operations************************//

BSTNode* createNewNode(int value)
{
	BSTNode *newNode = new BSTNode();
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
}
int returnMaxElement(BSTNode* root)
{
	if(root==NULL)
		return -1;
	while(root->right)//!=NULL
		root=root->right;
	return root->data;
}

int returnMinElement(BSTNode *root)
{
        if(root==NULL)
                return 4000;
        while(root->left)//!=NULL
                root=root->left;
        return root->data;
}

BSTNode* insertElement(BSTNode *root, int element)// Insertion always happens at root node
{
	if(root == NULL)
	{
		BSTNode *newNode = createNewNode(element);
		root = newNode;
	}
	else if(element<root->data)
		root->left = insertElement(root->left, element);
	else
		root->right = insertElement(root->right, element);
	return root;
}
/*
void deleteElement(BSTNode *root, int element)
{
	queue <BSTNode*>q;
	q.push(root);
	while(q.size())
	{
		BSTNode *node = q.pop();
		cout<<node->data<<" ";
		if(node->left)
			q.push(node->left);
		if(node->right)
			q.push(node->right);

	}
}
*/	

void inorderDisplay(BSTNode *root)
{
	if(root!=NULL)
	{
		inorderDisplay(root->left);
		cout<<root->data<<"  ";
		inorderDisplay(root->right);
	}	
}

// End of Basic operations
//

// Find LCA - Least common ancestor
BSTNode* returnLCA(BSTNode *root, BSTNode *node1, BSTNode *node2)
{
	while(root!=NULL)
	{
		if((root->data > node1->data && root->data < node2->data) || (root->data < node1->data && root->data > node2->data))
			return root;
		if(root->data > node1->data) // or node2->data
			root = root->left;
		else
			root = root->right;
	}
	return root;		
}

//Check if the given binary tree is BST
int isBST(BSTNode* root)
{
	cout<<"Value:"<<root->data<<" ";
	if(root == NULL)
		return 1;
	//if(root->left && root->right)
	{
		if(root->data > returnMaxElement(root->left) && root->data < returnMinElement(root->right))
		{
			return isBST(root->left) && isBST(root->right);
		}
	}
/*
	else if(root->left)
	{
		if(root->data > returnMaxElement(root->left))
                {
                        return isBST(root->left) && isBST(root->right);
		}
	}
	else if(root->right)
	{	
		 if(root->data <= returnMinElement(root->right))
                {
                        return isBST(root->right);
		}
	}
	else
	{
		return 1;
	}*/
	return 0;
}
int isBSTInorder(BSTNode *root, int prev)
{
	if(root)
	{	
		if()


int main()
{
	//Basic operations
	root = createNewNode(7);
	BSTNode *nodeRef = root;
	insertElement(nodeRef, 10);
	nodeRef = root;
	insertElement(nodeRef, 12);
	nodeRef = root;
	insertElement(nodeRef, 5);
	nodeRef = root;
        insertElement(nodeRef, 15);
	nodeRef = root;
        insertElement(nodeRef, 3);
	nodeRef = root;
	insertElement(nodeRef,4);
	inorderDisplay(nodeRef);
	nodeRef = root;
	cout<<"\nMax Element:"<<returnMaxElement(nodeRef)<<"\n";
	nodeRef = root;
	cout<<"\nMin Element:"<<returnMinElement(nodeRef);
//	deleteElement(root,1);

	// LCA
	nodeRef = root;
	BSTNode* lca = returnLCA(nodeRef, nodeRef->left->left,nodeRef->right);
	if(lca)
		cout<<"\nLCA of "<<nodeRef->left->data<<" and "<<nodeRef->right->data<<" is "<<lca->data<<"\nLCA Manual:"<<root->data<<"\n";
	
	// Is BST
	nodeRef = root;
	if(isBST(nodeRef))
		cout<<"\nThe tree is BST";
	else
		cout<<"\n Not BST";
	return 1;
}
