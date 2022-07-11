// This is so DUMB! This needs to stop, Prateek Bhaiya ;P

/*
Enter the values of all the nodes in the binary tree in pre-order format,
where true suggest the node exists and false suggests it is NULL

Eg: 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false */


// Code Snippet:
// WRONG CODE - x undefined
node *buildtree_dumbo_style(node *&root)
{
  if(x==0)
  {
    x++;
    int k;
    cin>>k;
    root=new node(k);
    root->left = buildtree_dumbo_style(root->left);
    root->right = buildtree_dumbo_style(root->right);
    return root;
  }
  else
  {
    string str;
    cin>>str;
    int d;
    if(str=="true")
    {
      cin>>d;
      node *temp=new node(d);
      temp->left = buildtree_dumbo_style(temp->left);
      temp->right = buildtree_dumbo_style(temp->right);
      return temp;
    }
    else
    if(str=="false")
    {
      return root;
    }
  }
  return root;
}
