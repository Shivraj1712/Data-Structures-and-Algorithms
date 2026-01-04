#include <iostream>
#include <bits/stdc++.h>
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

class Linkedlist {
private :
    Node * head ;
    Node * tail ;
public :
    Linkedlist(){
        head = tail = NULL ;
    };
    void pushfront(int val){
        Node * newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode ;
            return ;
        }
        newNode->next = head ;
        head = newNode ;
    };
    void pushback(int val){
        Node * newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode ;
            return ;
        }
        tail->next = newNode ;
        tail = newNode ;
    };
    void insert(int pos , int val){
        if(pos < 0){
            cout<<"Invalid Value"<<endl;
            return ;
        }
        if(pos == 0){
            pushfront(val);
            return ;
        }
        Node * newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode ;
            return ;
        }
        Node * temp = head ;
        for(int i = 0 ; i < pos - 1 && temp != NULL ; i++){
            temp = temp->next ;
        }
        if(temp == NULL){
            cout<<"Position out of range"<<endl;
            delete newNode ;
            return ;
        }
        newNode->next = temp->next ;
        temp->next = newNode ;
        if(newNode->next == NULL){
            tail = newNode ;
        }
    };

    int search(int target){
        Node * temp = head ;
        int index = 0 ;
        while(temp != NULL){
            if(temp->val == target) return index ;
            index++;
            temp = temp->next ;
        }
        return -1 ;
    };
    void pop_front(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return ;
        }
        Node * temp = head ;
        head = head -> next ;
        if(head == NULL) tail = NULL ;
        delete temp ;
    };
    void pop_back(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return ;
        }
        if(head == tail){
            delete head ;
            head = tail = NULL ;
            return ;
        }
        Node * temp = head ;
        while(temp->next != tail){
            temp = temp->next ;
        }
        delete tail ;
        tail = temp ;
        tail->next = NULL ;
    };
    void printLL(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return ;
        }
        Node * temp = head ;
        while(temp != NULL){
            cout<<temp->val<<" -> ";
            temp = temp->next ;
        }
        cout<<" NULL "<<endl;
    };
    ~Linkedlist(){
        while(head != NULL){
            pop_front();
        }
    };
};

class DNode {
public :
    int val ;
    DNode * next ;
    DNode * prev ;
    DNode(int val){
        this -> val = val ;
        this -> next = NULL ;
        this -> prev = NULL ;
    };
};

class DLinkedlist {
private :
    DNode * head ;
    DNode * tail ;
public :
    DLinkedlist(){
        head = tail = NULL;
    };
    void push_front(int val){
        DNode * newNode = new DNode(val);
        if(head == NULL){
            head = tail = newNode ;
        }else{
            newNode->next = head ;
            head->prev = newNode ;
            head = newNode ;
        }
    };

    void push_back(int val){
        DNode * newNode = new DNode(val);
        if(head == NULL){
            head = tail = newNode ;
        }else{
            newNode->prev = tail ;
            tail->next = newNode ;
            tail = newNode ;
        }
    };

    void pop_front(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return ;
        }
        DNode * temp = head ;
        head = head -> next ;
        if(head != NULL){
            head -> prev = NULL ;
        }else{
            tail = NULL ;
        }
        temp -> next = NULL ;
        delete temp ;
    };

    void pop_back(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return ;
        }
        DNode * temp = tail ;
        tail = tail->prev;
        if(tail != NULL){
            tail->next = NULL ;
        }else{
            head = NULL ;
        }
        temp->prev = NULL;
        delete temp ;
    };

    void printDLL(){
        DNode * temp = head ;
        while(temp != NULL){
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }
        cout<<" NULL "<<endl;
    };
    ~DLinkedlist(){
        while(head != NULL){
            pop_front();
        }
    };
};

int main(){
    Linkedlist  l1 ;
    l1.pushback(3);
    l1.pushback(4);
    l1.pushfront(2);
    l1.pushfront(1);
    l1.printLL(); //OUTPUT : 1 -> 2 -> 3 -> 4 ->  NULL 
    return 0;
}