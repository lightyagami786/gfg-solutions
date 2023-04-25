//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> ourmap;
        
        int len=0;
        int summ=0;
        for(int i=0;i<n;i++){
            
            summ+=A[i];
            
            if(summ==0){
                len=i+1;
                continue;
            }
            
            if(ourmap.count(summ)==1  ){
                len=max(len,i-ourmap[summ]);
            }else{
                ourmap[summ]=i;
            }
            
            
        }
        if(summ==0){
            return n;
        }
        return len;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends