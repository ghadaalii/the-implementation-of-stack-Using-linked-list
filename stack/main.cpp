#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Node{
public:
    int data;
    Node *next;
};


class Stack{
    Node *top;
public:

    Stack(){
        top = NULL;
    }

    bool isEmpty(){
        return (top==NULL);
    }

    void push(int item){
        Node *newNode = new Node();
        newNode -> data = item;
        if(isEmpty()){
            newNode -> next = NULL;
            top = newNode;
        } else{
            newNode -> next = top;
            top = newNode;
        }
    }

    void display(){
        Node *temp = top;
        if(isEmpty()){
            cout << "Stack is Empty :(\n";
        }else{
            cout << "stack items \n";
            while(temp != NULL){
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }
    }

    int count(){
        int counter = 0 ;
        Node *temp = top;
        if(isEmpty()){
            cout << "Stack is Empty :(\n";
        }else{
            while(temp != NULL){
                counter++;
                temp = temp -> next;
            }
        }
        return counter;
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack is Empty\n";
        }else{
            int value ;
            Node *delptr = top ;
            value = top -> data;
            top = top -> next;
            delete delptr;
            return value;
        }

    }

    int Peek(){
        return top -> data;
    }

    bool isFound(int item){
        bool found = false;
        Node *temp = top;
        while(temp != NULL){
            if(temp -> data == item){
                found = true;
            }
            temp = temp -> next;
        }
        return found;
    }
};



int main(){
    Stack s;
    int numOfItems;
    cout << "Enter the number of items to push in stack\n";
    cin >> numOfItems;
    for(int i = 0 ; i < numOfItems ; i++){
        int num;
        cout << "Enter item to push\n";
        cin >> num;
        s.push(num);
    }
    cout << endl;
    s.display();
    cout << s.pop() << " was deleted form stack \n";
    s.display();
    cout << s.Peek() << " the value of the top \n";
    cout << "Stack contains " << s.count() << " items" <<endl;
    int item ;
    cout << "Enter item to search for \n";
    cin >> item ;
    if(s.isFound(item))
        cout << "the item is found :)\n";
    else
        cout << "the item is not found :( \n";
}