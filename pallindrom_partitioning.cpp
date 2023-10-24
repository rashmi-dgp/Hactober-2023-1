//question link: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
//DP approach:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int dp[501][501];

    bool isPallindrome(string s,int i,int j){
        while(j>=i){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int Rechelper(string &str,int i,int j)
    {
        if(isPallindrome(str,i,j)) return dp[i][j]=0;
        if(i>j)  return dp[i][j]=0;
        if(i==j) return dp[i][j]=0;
        
        if(dp[i][j]!=-1)  dp[i][j];
        int mn=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int left=0,right=0;
            if(dp[i][k]!=-1)    left=dp[i][k];
            else{
                left=Rechelper(str,i,k);
                dp[i][k]=left;
            }
            if(dp[k+1][j]!=-1)    right=dp[k+1][j];
            else{
                right=Rechelper(str,k+1,j);
                dp[k+1][j]=right;
            }
            int temp=1+right+left;
            if(temp<mn){
                mn=temp;
            }
        }
        return dp[i][j]=mn;
    }
    int palindromicPartition(string &str) {
         memset(dp, -1, sizeof(dp));
        return Rechelper(str,0,str.length()-1);

    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
