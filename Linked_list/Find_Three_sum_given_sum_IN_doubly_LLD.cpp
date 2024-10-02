#include <bits/stdc++.h> 
/***********************************************

    Following is the class structure of the Node class:

    class DLLNode
    {
        public:
        int data;
        DLLNode *next;
        DLLNode *prev;
    };

***********************************************/

int countTriplets(DLLNode* head, int x)
{
    // WRITE YOUR CODE HERE
    DLLNode* ptr2 = head;
    DLLNode* ptr3;

    unordered_map<int,int>mp;
    int ans =0;
    for(; ptr2!= NULL && (ptr2->next != NULL) ; ptr2 = ptr2->next){
        for( ptr3 = ptr2->next ; ptr3 != NULL; ptr3 = ptr3->next){
            int b = ptr2->data;
            int c = ptr3->data;
            int a = x -b -c;

            if( mp.find(a) != mp.end()){
                ans++;
            }
        }
        mp[ptr2->data]++;  
    }
    return ans;
}  