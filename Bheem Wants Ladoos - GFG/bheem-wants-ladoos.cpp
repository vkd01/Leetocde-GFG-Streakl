//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{
    public:
    int sumChild(Node* root, int k) {
        if (root == NULL || k < 0) return 0;
        
        int data = root->data;
        data += sumChild(root->left, k - 1);
        data += sumChild(root->right, k - 1);
        
        return data;
    }
    
    int parent(Node* root, int home, int &ans, int k) {
        if (root == NULL) {
            return -1;
        }
        
        if (root->data == home) {
            ans += sumChild(root, k);
            // cout << ans << " ";
            return 1;
        }
        
        int ld = parent(root->left, home, ans, k);
        if (ld != -1) {
            if (ld > k) return ld + 1;
            int l = sumChild(root->right, k - ld - 1);
            // cout << l << " ";
            ans += l;
            ans += root->data;
            return ld + 1;
        }
        int rd = parent(root->right, home, ans, k);
        if (rd != -1) {
            if (rd > k) return rd + 1;
            int r = sumChild(root->left, k - rd - 1);
            // cout << r << " ";
            ans += r;
            ans += root->data;
            return rd + 1;
        }
        
        return -1;
    }
    
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        int ans = 0;
        int l = parent(root, home, ans, k);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends