//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    //in safe functions we are checking three conditions
    //1.  position should be inside the matrix
    //2.  array value should be open that is 1 for travel
    //3.  visited should be marked 0
    bool isSafe(int x, int y, int n, vector<vector<int > > visited, 
                vector<vector<int>> &m){
        if( (x >= 0 && x<n) && (y >= 0 && y<n) && visited[x][y] == 0 && m[x][y]== 1){
        return true;
        }
        else{
            return false;
        }
    }
    //solve function
    void solve(vector<vector<int>> &m, int n, vector<string>& ans, int x, int y, 
               vector<vector<int > > visited, string path){
        
        //we have reached x, y here
        
        //base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        //mark visited =  1
        visited[x][y] = 1;
        
        
        //4 choices of movement down, up, left, right and here x and y value changes
        
        //down
         int newx = x+1;
         int newy = y;
         if(isSafe(newx, newy, n, visited, m)){
            path.push_back('D');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
         }
         
         //left
         newx = x;
         newy = y-1;
         if(isSafe(newx, newy, n, visited, m)){
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
         }
         
         //right
         newx = x;
         newy = y+1;
         if(isSafe(newx, newy, n, visited, m)){
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
         }
         
         //up
         
          newx = x-1;
         newy = y;
         if(isSafe(newx, newy, n, visited, m)){
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
         }
         
        // when back track mark visited 0 to get other paths possible
      visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        //to store ans
        vector<string> ans;
        
        //srtarting position is 0 then
        if(m[0][0] == 0){
            return ans;
        }
        
        //source at start is (0,0)
        int srcx = 0;
        int srcy = 0;
       
       //visited array (2d array) to keep track of path visited
        vector<vector<int > > visited = m;
        //initialise with 0
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        
        //path which is a empty string
        string path = "";
        
        //recursive functional call
        solve(m, n, ans, srcx, srcy, visited, path);
       
        //answer in sorted order
        sort(ans.begin(), ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends