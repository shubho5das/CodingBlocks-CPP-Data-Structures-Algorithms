// KEEP CALM and Enjoy the Problem B-)

/* Editorial:	
	This problem can be easily solved with the help of Hashing. 
	The idea is to create an empty map where each key represents the relative horizontal distance of the node from the root node and value in the map maintains a pair containing node’s value and its level number. 
	Then we do a pre-order traversal of the tree and if current level of a node is more than or equal to maximum level seen so far for the same horizontal distance as current node’s or current horizontal distance is seen for the first time, we update the value and the level for current horizontal distance in the map. 
	For each node, we recurse for its left subtree by decreasing horizontal distance and increasing level by 1 and recurse for right subtree by increasing both level and horizontal distance by 1. 

	Refer GFG, StackOverflow for more detailed (and better) explanation
*/

// Code Snippet- Recurisve Approach:

void bottomViewHelper(node *root, int level, int dist, map<int, pair<int, int> > &mp) {
    if(root == NULL) {
        return;
    }
    if(mp.find(dist) == mp.end() or level>=mp[dist].second) {
        mp[dist] = {root->data, level};
    }
    bottomViewHelper(root->left, level+1, dist-1, mp);
    bottomViewHelper(root->right, level+1, dist+1, mp);
}

void bottomView(node *root)
{
   map<int, pair<int, int> >mp;
   bottomViewHelper(root, 0, 0, mp);
   for(auto val:mp){
       cout<<val.second.first<<" ";
   }
}

