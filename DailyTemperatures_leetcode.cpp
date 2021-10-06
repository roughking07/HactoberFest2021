/*
https://leetcode.com/problems/daily-temperatures/
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days
you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>v;
        stack<pair<int,int>>s;
        int n=t.size();
       
        for(int i=n-1;i>=0;i--){
    
               while(!s.empty() && s.top().first<=t[i]){
               s.pop();
               }
    
               if(s.empty()){
               v.push_back(0);
               }
               else{
               v.push_back(s.top().second-i);
               }

             s.push({t[i],i});
            }
        reverse(v.begin(),v.end());
        return v;
    }
};
