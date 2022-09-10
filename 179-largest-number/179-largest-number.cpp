class Solution {
public:
  static  bool custom_comparator( string a , string b){
        if(a+b > b+a) return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        
        vector<string> nums_str;
        string ans;
        
        for(int x : nums){
            nums_str.push_back(to_string(x));
        }
        sort(nums_str.begin(), nums_str.end(), custom_comparator);
        for( string x : nums_str){
            ans+=x;
        }
        int start =0;
        while(ans[start] == '0' && start < ans.size()-1) start++;
        return ans.substr(start);
        
    }
};