#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class StackUV{
private :
    vector<int> v ;
public :
    void push(int val){
        v.push_back(val);
    };
    int pop(){
        if(v.size()==0){
            cout<<"Stack is empty!"<<endl;
            return -1 ;
        }
        int returnValue = v.back();
        v.pop_back();
        return returnValue ;
    };
    int top(){
        if(v.size()==0){
            cout<<"Stack is empty!"<<endl ;
            return -1;
        }
        return v.back();
    };
    bool isEmpty(){
        return v.size() == 0 ;
    };
};

class StackLL{
private :
    list<int> l;
public :
    void push(int val){
        l.push_front(val);
    };
    int pop(){
        if(l.size()==0){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        int popValue = l.front();
        l.pop_front();
        return popValue ;
    };
    int top(){
        if(l.size()==0){
            cout<<"Stack is empty!"<<endl;
            return -1 ;
        }
        return l.front();
    };
    bool isEmpty(){
        return l.size()==0;
    };
};

int main(){
    StackUV s ;
    s.push(10);
    s.push(20);
    s.push(30);
    while(1){
        cout<<s.pop()<<" ";
        if(s.isEmpty()) break ;
    }
    cout<<endl;
    StackLL a ;
    a.push(10);
    a.push(20);
    a.push(30);
    while(1){
        cout<<a.pop()<<" ";
        if(a.isEmpty()) break ;
    }
    cout<<endl;
    stack<int> S ;
    S.push(10);
    S.push(20);
    S.push(30);
    while(1){
        cout<<S.top()<<" ";
        S.pop();
        if(S.empty()) break ;
    }
    cout<<endl;
    return 0 ;
}