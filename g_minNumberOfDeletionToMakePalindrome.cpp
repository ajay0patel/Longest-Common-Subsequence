/*
Minimum number of deletions to make a string palindrome
Given a string of size ‘n’. The task is to remove or delete
minimum number of characters from the string so that the 
resultant string is palindrome.

step - 1 : find LPS(longest palindromic subsequence)
step - 2 : ans = s.length()-lps

*/

#include <bits/stdc++.h>
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define ll long long int

int lcs(string s1,string s2,int m,int n){
    int dp[m + 1][n + 1];  
    
    
    for (int i = 0; i <= m; i++)  
    {  
        for (int j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            dp[i][j] = 0;  
      
        else if (s1[i - 1] == s2[j - 1])  
            dp[i][j] = dp[i - 1][j - 1] + 1;  
      
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
        }  
    }  
    
    return dp[m][n];
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1;
    cin>>s1;
    string s2=s1;
    reverse(s2.begin(),s2.end());
    
    int m=s1.length();
    int n=m;
    

    
    int lps=lcs(s1,s2,m,n); //length of longest palindromic subsequence

    int ans=m-lps;
    cout<<ans;

    return 0;
}

//ip:agbcba  op:1
