// url: https://leetcode-cn.com/problems/self-dividing-numbers/
#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans; 
        for(int i = left; i <= right; i ++)
        {
            bool flag = testdiv(i);
            if( flag) ans.push_back(i);
        }
        return ans; 
    }
    bool testdiv(int x)
    {
        int tmp = x;
        while(tmp >0 )
        {
            int a = tmp % 10;
            tmp /= 10;
            if( a == 0||x % a != 0 ) return false;
            
        }
        return true; 
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
    vector<int> a = x.selfDividingNumbers(1,22);
    cout<<"here";
    display(a);
    return 0 ;
}
