#include<vector>
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> result(n);  // To store the results
    stack<int> s;  // Stack to keep track of the next smaller elements

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack if they are greater than or equal to the current element
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // If stack is empty, no smaller element to the right
        if (s.empty()) {
            result[i] = -1;
        } else {
            // The top element of the stack is the next smaller element
            result[i] = s.top();
        }

        // Push the current element onto the stack
        s.push(arr[i]);
    }

    return result;
}