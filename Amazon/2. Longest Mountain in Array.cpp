/*
https://leetcode.com/problems/longest-mountain-in-array/

list of problems that involved 1 or 2 passes from left to right/right to left:

53 Maximum Subarray
121 Best Time to Buy and Sell Stock
152 Maximum Product Subarray
238 Product of Array Except Self
739 Daily Temperatures
769 Max Chunks to Make Sorted
770 Max Chunks to Make Sorted II
821 Shortest Distance to a Character
845 Longest Mountain in Array

*/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
       int n = arr.size();
        // 1. IDENTIFY PEAKS
        // 2. TRAVERSE BACKWARDS WHILE PREVIOUS ELEMENT -
        // - IS SMALLER THAT CURRENT (i.e. GO TO THE START ROOT OF THE MOUNTAIN)
        // 3. TRAVERSE FORWARD WHILE NEXT ELEMENT IS SMALLER THAN CURRENT 
        // (i.e. GO TO THE END ROOT OF THE MOUNTAIN)
        // 4 . ADD THEM TO CALCULATE THE MOUNTAIN LENGTH
        int max_length = 0;
        for(int i=1;i<n-1;i++)
        {
            if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])) //PEAK CONDITION
            {
                int start_root = i;
                int end_root = i;
                while( start_root>0 && arr[start_root] > arr[start_root-1])
                {
                    start_root--; //getting start root
                    
                }
                while( end_root<n-1 && arr[end_root] > arr[end_root+1] )
                {
                    end_root++; //getting end root
                }
                max_length = max(max_length,(end_root-start_root+1));
                i = end_root;
            }
        }
        return max_length;
    }
};