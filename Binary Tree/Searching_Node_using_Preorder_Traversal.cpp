// KEEP CALM and Enjoy the Problem B-)

/* Code Snippet:
 To search a node in a Binary Tree (using pre-order traversal)
[Func returns address of key node; if key not present, NULL returned]
*/

node* search(node* root,ll key){
// Pre Order Traversal

	// Base Case
	if(root == NULL)
		return NULL;
	
	if(root->data == key)
		return root;

	// Recursive Case
	node * left = search(root->left,key);
	if(left != NULL)
		return left;
	node *right = search(root->right,key);
	if(right != NULL)
		return right;
	
	return NULL;
}

