//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* solve(Node* first, Node* second){
    if(first -> next == NULL){
        first-> next = second;
    return first;
    }
    
       Node* curr1 = first;
       Node* next1 = curr1-> next;
       Node* curr2 = second;
       Node*  next2 = curr2-> next;
    
    while(next1 != NULL && curr2 != NULL){
        if(curr2 -> data >= curr1 -> data && 
           curr2 -> data <= next1-> data){
            
            curr1 -> next = curr2;
            next2 = curr2-> next;
            curr2-> next= next1;
            
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1= next1-> next;
            if(next1 == NULL){
                curr1 -> next = curr2;
                    return first;
            }
        }
    }
    return first;
}


//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
   Node* first = head1;
   Node* second = head2;
    // code here
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    if(first -> data <= second -> data){
        solve(first, second);
    }
    else{
        solve(second,first);
    }
}  