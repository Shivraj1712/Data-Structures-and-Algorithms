#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree {
private:
    static int idx = -1;

public:
    BinaryTree() {
        this->idx = -1;
    }

    Node* BuildTree(vector<int>& preorder) {
        idx++;
        if (idx >= preorder.size() || preorder[idx] == -1) {
            return NULL;
        }

        Node* root = new Node(preorder[idx]);
        root->left = BuildTree(preorder);
        root->right = BuildTree(preorder);

        return root;
    }

    void preOrderTraversal(Node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->val << endl;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void inOrderTraversal(Node* root) {
        if (root == NULL) {
            return;
        }
        inOrderTraversal(root->left);
        cout << root->val << endl;
        inOrderTraversal(root->right);
    }

    void postOrderTraversal(Node* root) {
        if (root == NULL) {
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->val << endl;
    }

    void levelOrderTraversal(Node * root){
        if(root == NULL){
            return ;
        }
        queue<Node*> q ;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node * curr = q.front() ;
            q.pop();
            if(curr == NULL){
                cout<<endl ;
                if(q.empty()){
                    break ;
                }else{
                    q.push(NULL);
                }
            }else{
                cout<<curr->val<<" ";
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
        }
    }

};

int BinaryTree::idx = -1 ;