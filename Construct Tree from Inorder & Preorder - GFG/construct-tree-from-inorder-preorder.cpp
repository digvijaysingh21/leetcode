//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
   void createMapping(int in[], map<int,int> &nodeToIndex, int n){
        for(int i=0; i< n; i++){
            nodeToIndex[in[i]] =  i;
        }
    }
    Node* solve(int in[], int pre[], int &index, 
         int inorderStart, int inoredrEnd, int n, map<int,int> &nodeToIndex){
        //bas case
        if(index >= n || inorderStart > inoredrEnd){
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        int position = nodeToIndex[element];
        
        //recursive call
        root-> left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
        root-> right = solve(in, pre, index, position+1, inoredrEnd, n, nodeToIndex);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        //create node to index mapping
        createMapping(in, nodeToIndex,n);
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
        
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends