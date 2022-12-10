//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    if(k>= num.size()) return "0";
    stack<char>s;
    for(int i=0;i<num.size();i++){
        if(s.empty()) s.push(num[i]);
        else{
            while(!s.empty() && s.top()>num[i] && k>0){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
    }
    while(k> 0){
        s.pop();
        k--;
    }
    if(s.empty()) return "0";
    string ans;
    while(!s.empty()){
        ans=s.top()+ans;
        s.pop();
    }
    int i=0;
    while(ans[i] == '0'){
        i++;
    }
    return(ans.substr(i) =="") ?"0" : ans.substr(i);
}