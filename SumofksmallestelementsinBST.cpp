void helper(Node *root,int &k,int &sum){
    
    if(root==NULL)return;
    
    helper(root->left,k,sum);
    if(k<=0)return;
    k--;
    sum+=root->data;
    helper(root->right,k,sum);
    
    
}

int sum(Node* root, int k) 
{ 
  int sum=0;
  helper(root,k,sum);
  return sum;
  
    
} 