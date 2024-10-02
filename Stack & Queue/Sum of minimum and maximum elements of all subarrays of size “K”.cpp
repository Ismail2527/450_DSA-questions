#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
	deque<int> maxDeque, minDeque;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        // Remove elements that are out of this window from both deques
        if (!maxDeque.empty() && maxDeque.front() <= i - k) maxDeque.pop_front();
        if (!minDeque.empty() && minDeque.front() <= i - k) minDeque.pop_front();

        // Remove elements not useful for current window from maxDeque
        while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[i])
            maxDeque.pop_back();
        
        // Remove elements not useful for current window from minDeque
        while (!minDeque.empty() && nums[minDeque.back()] >= nums[i])
            minDeque.pop_back();
        
        // Add current element index to both deques
        maxDeque.push_back(i);
        minDeque.push_back(i);
        
        // If we have processed at least k elements, sum the front elements of both deques
        if (i >= k - 1) {
            sum += nums[maxDeque.front()] + nums[minDeque.front()];
        }
    }
    return sum;
}
