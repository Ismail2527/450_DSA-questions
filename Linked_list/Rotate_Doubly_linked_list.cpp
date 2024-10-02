//{ Driver Code Starts
//Initial Template for C++

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
void *solve(Node *head,int N){
    if(N == 0){
        return ;
    }
    Node* current = head;
    int count = 1;
    while(count < N && current != NULL){
        current = current->next;
        count++;
    }
    Node *change = current;
    while(current->next != NULL){
        current->next = head;
        head -> prev = current;
        head = change->next;
        head->prev = NULL;
        change->next = NULL;
    }

}
int main(){

    return 0;
}