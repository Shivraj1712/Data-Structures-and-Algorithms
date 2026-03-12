    #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;

    class Node{
    public:
        int val ;
        Node * left , * right ;
        Node(int val){
            this->val = val;
            this->left = NULL ;
            this->right = NULL ;
        }
    };

    class BinaryTree{
    public:
        static int idx ;
        Node * root ;
        BinaryTree(){
            this->root=NULL ;
            this->idx = 0 ;
        }
        Node * buildTree(vector<int>&arr){
            if(idx >= arr.size() || arr[idx] == -1){
                idx++;
                return NULL ;
            }
            Node * root = new Node(arr[idx++]);
            root->left = buildTree(arr);
            root->right = buildTree(arr);
            return root ;
        }
        vector<vector<int>> levelOrderTraversal(){
            if(this->root == NULL) return {};
            queue<Node*> q ;
            vector<vector<int>> traversal;
            vector<int> values ;
            q.push(this->root);
            q.push(NULL);
            while(!q.empty()){
                Node * curr = q.front();
                q.pop();
                if(curr == NULL){
                    traversal.push(values);
                    if(q.empty()) break ;
                    else{
                        q.push(NULL);
                        values.clear();
                    }
                }else{
                    values.push_back(curr->val);
                    if(curr->left != NULL) q.push(curr->left);
                    if(curr->right != NULL) q.push(curr->right);
                }
            }
            return traversal;
        };
        void preOrderTraversal(Node * root){
            if(!root) return ;
            cout<<root->val<<" ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
        void inOrderTraversal(Node * root){
            if(!root) return ;
            inOrderTraversal(root->left);
            cout<<root->val<<" ";
            inOrderTraversal(root->right);
        }
        void postOrderTraversal(Node * root){
            if(!root) return ;
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout<<root->val<<" ";
        }
    };

    int BinaryTree::idx = 0 ;

    class BinarySearchTree{
    public: 
        static int idx ;
        Node * root ;
        BinarySearchTree(){
            this->root = NULL ;
            this->idx = 0 ;
        }
        Node * insert(Node * root,int val){
            if(!root){
                Node * newNode = new Node(val);
                root = newNode ;
                return root ;
            }else{
                if(root->val >= val){
                    root->left = insert(root->left, val);
                }else{
                    root->right = insert(root->right,val);
                }
                return root ;
            }
        }
        Node * buildBST(vector<int>& arr,Node * root){
            if(arr.size() == 0) return NULL ;
            for(int i : arr){
                root = insert(root,i);
            }
            this->root = root ;
            return root ;
        }
    };

    int BinarySearchTree::idx = 0 ;