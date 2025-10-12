#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* back;
public:
    node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    node(int data1, node* next1, node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
};

node* convertarr2DLL(vector<int> arr) {
    node* head = new node(arr[0]);
    node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        node* temp = new node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

node* deletehead(node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    node* prev = head;
    head = head->next;
    head->back = nullptr;
    delete prev;
    return head;
}

node* deletetail(node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    node* newnode = temp->back;
    newnode->next = nullptr;
    delete temp;
    return head;
}
node* removekelement(node* head,int k){
    if(head == nullptr){
        return nullptr;;
    }
    int cnt = 0;
    node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    node* prev = temp->back;
    node* front = temp->next;
    if(prev == nullptr){
        return deletehead(head);
    }
    else if(front == nullptr){
        return deletetail(head);
    }
    else{
        prev->next = front;
        front->back = prev;
        delete temp;
        return head;
    }
}
void deleteelement(node* temp){
    node* prev = temp->back;
    node* front = temp->next;
    if(front == nullptr){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);

}
void print(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    node* head = convertarr2DLL(arr);
    print(head);
    cout << endl;
    head = deletehead(head);
    print(head);
    cout << endl;
    head = deletetail(head);
    print(head);
    cout << endl;
    head = removekelement(head,4);
    print(head);
    cout << endl;
    deleteelement(head->next);
    print(head);
    return 0;
}