//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
      
        int mod=1e9+7;
        
        vector<long long int> vec(n+1);
        
        vec[0]=1;
        vec[1]=1;
        vec[2]=2;
        
        for(int i=3;i<=n;i++){
            
            vec[i]=(vec[i-1]%mod+(i-1)*vec[i-2]%mod)%mod;
            
        }
        
        return vec[n];
        
        
        
        
        
        
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends