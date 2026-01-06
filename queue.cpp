#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
class Node {
public :
    int val ;
    Node * next ;
    Node(int val){
        this -> val = val ;
        this -> next = NULL ;
    };

};
class Queue{
private :
    Node * head ;
    Node * tail ;
public :
    Queue(){
        this -> head = this -> tail = NULL ;
    };
    void push(int val){
        Node * newNode = new Node(val);
        if(empty()){
            head = tail = newNode ;
        }else{
            tail->next = newNode ;
            tail = newNode ;
        }
    };

    void pop(){
        if(empty()){
            cout<<"Queue is empty!"<<endl;
            return ;
        }
        Node * temp = head ;
        head = head -> next ;
        if(empty()){
            tail = NULL ;
        }
        delete temp ;
    };

    int front(){
        if(empty()){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        return head->val ;
    };

    bool empty(){
        return head == NULL;
    };
};



int main(){
    Queue q ;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    // Output : 1 2 3 
    cout<<endl;
    
    return 0 ;
}