//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        
        string ans="";
        
        int carry=0;
        
        int n1=X.size();
        int n2=Y.size();
        
        while(n1 || n2){
            
            if(n1<=0){
                int a2=Y[n2-1]-'0';
                int sum=a2+carry;
                int ournum=sum%10;
                carry=sum/10;
                char ourchar=ournum+'0';
                ans=ourchar+ans;
                n2--;
                
                
                
            }else if(n2<=0){
                int a1=X[n1-1]-'0';
                int sum=a1+carry;
                int ournum=sum%10;
                carry=sum/10;
                char ourchar=ournum+'0';
                ans=ourchar+ans;
                n1--;
                
            }else{
                
                int a1=X[n1-1]-'0';
                int a2=Y[n2-1]-'0';
                int sum=a1+a2+carry;
                int ournum=sum%10;
                carry=sum/10;
                char ourchar=ournum+'0';
                ans=ourchar+ans;
                n1--;
                n2--;
                
            }
        
            
        }
        char ourcarri=carry+'0';
        ans=ourcarri+ans;
        
        int i=0;
        while(ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);
        if(ans.size()==0)return "0";
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends