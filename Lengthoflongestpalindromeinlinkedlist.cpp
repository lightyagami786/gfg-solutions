//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}



// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
#include <bits/stdc++.h>

bool isPalindrome(int si,int ei,vector<int> &vec){
    
    while(si<=ei){
        if(vec[si]!=vec[ei]){
            return false;
        }
        si++;
        ei--;
    }
    return true;
    
}

int maxPalindrome(Node *head)
{
    // conveert into vector
    
    vector<int> vec;
    
    while(head!=NULL){
        vec.push_back(head->data);
        head=head->next;
    }
    
    int n=vec.size();
    int maxAns=0;
    
    for(int i=0;i<n;i++){
        
        for(int j=n-1;j>=i;j--){
            if(isPalindrome(i,j,vec)){
                maxAns=max(maxAns,j-i+1);
                break;
            }
        }
        
    }
    
    return maxAns;
    
}