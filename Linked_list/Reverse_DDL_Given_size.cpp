#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
Node* reverseDDL(Node *head,int k){
    Node* curr=head;
    int count = 1;
    if(curr==NULL or curr->next == NULL){
        return head;
    }
    while(count <= k){
        curr= curr->next;
    }
    curr->next = curr->prev;
    curr->prev = NULL;
    curr= curr->next;
    while(curr->prev != NULL){
        Node* temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp ;
        curr = curr->next;
    }
    curr->prev = curr->next;
    curr->next = NULL;
    return head;
}

int main(){
    return 0;
}