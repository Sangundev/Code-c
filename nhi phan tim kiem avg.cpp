typedef struct node{
int info;
struct node *left;
struct node *right;
}Node;
void Init(Node* &proot){ proot=NULL ;}
	Node* CreateNode(int x){
	NODEPTR p = new Node;
	If(p==NULL) return 0;
	p->info = x; 
	p->left = NULL;
	p->right = NULL;
	p->height = 1;
 return p;
}
}
node *insertnode(node *p, int x)
{
	if (p == NULL)
		return createNode(x);
	if (x < p->data) // add to the right side
		p->left = insert(p->left, x);
	else if (x > p->data) // add to the left side
	p->right = insert(p->right, x);
	p->height = 1 + max(getHeight(p->left), getHeight(p->right));
	return balance(p); // balance the tree
} 

node * removeNode(node *root, int x)
{
	if (root == NULL)
		return root;
	if (root->data > x)
		root->left = deleteNode(root->left, x);
	else if (root->data < x)
		root->right = deleteNode(root->right, x);
 	else
	 {
 
 	if (root->left == NULL)
 {
 		node *temp = root->right;
 	delete root;
 	return temp;
}
		else if (root->right == NULL)
{
	node *temp = root->left;
	delete root;
	return temp;
}
	node *temp = minValueNode(root->right);
 	root->data = temp->data; 
 	root->right = deleteNode(root->right, temp->data); 
}
if (root == NULL) 
return root;
root->height = 1 + max(getHeight(root->left), getHeight(root->right));
return balance(root);
}

