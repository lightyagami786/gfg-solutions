//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool compare(Job a1,Job a2){
        return a1.profit>a2.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int ans=0;
        int count=0;
        
        vector<int> vec(n,-1);
        
        // sort on basis of profit
        
        sort(arr,arr+n,compare);
        
        for(int i=0;i<n;i++){
            
            int value=arr[i].profit;
            int index=arr[i].dead-1;
            
            if(vec[index]==-1){
                vec[index]=arr[i].id;
                ans+=value;
                count++;
            }else{
                
                index--;
                while(index>=0){
                    if(vec[index]==-1){
                        vec[index]=arr[i].id;
                        ans+=value;
                        count++;
                        break;
                    }
                    index--;
                    
                }
                
                
            }
            
            
            
        }
        vector<int> answer;
        answer.push_back(count);
        answer.push_back(ans);
        return answer;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends