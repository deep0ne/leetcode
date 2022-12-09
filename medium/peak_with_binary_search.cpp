/*
An array arr a mountain if the following properties hold:

    arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.
*/

#include <vector>

class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        int mid = (l + r) / 2;
        while(! (arr[mid] > arr[mid+1] && arr[mid] > arr[mid - 1])) {
            if(arr[mid] < arr[mid+1]) {
                ++mid;
            } else {
                --mid;
            }
        }
        return mid;
    }
};