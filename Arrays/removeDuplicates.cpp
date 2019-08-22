/*
    Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
    O(1) memory

    Example:
     nums = [1,1,2],
     Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
     It doesn't matter what you leave beyond the returned length.
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int removeDuplicates (vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }

    

}

int main() {
    int num;
    vector<int> nums;
    int size;

    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> num;
        nums.push_back(num);
    }

    cout << "length: " << removeDuplicates(nums) << endl;


    return 0;
}