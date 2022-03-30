// https://leetcode-cn.com/problems/maximize-the-confusion-of-an-exam/
/*
滑动窗口，一次遍历字符串，双指针，前后指针，然后更改max
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(findmax(answerKey,k,'F'), findmax(answerKey,k,'T'));

    }

    int findmax(string s, int k, char c)
    {
        int n = s.size();
        int cnt = 0, l = 0, change = 0;
        for(int r  = 0; r < n;  r++)
        {
            if( s[r] == c) change ++;
            while( change > k )
            {
                if( s[l] == c) change --;
                l++;
            }

            cnt = max(cnt, r - l + 1);

        }
        return cnt; 

    }
};


void display(vector<int> x)
{
    for(int i = 0; i < x.size(); i++)
    {
        cout<<x[i]<<" ";
    }
    return ; 
}

int main(){
    Solution x;
    string a = "TTFTTFTT";
    int k = 1;
    int ans = x.maxConsecutiveAnswers(a,k);
    cout<<ans;
    return 0 ;
}
