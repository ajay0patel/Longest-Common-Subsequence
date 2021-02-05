//Longest Palindromic subsequences
//use LCS ... string s1=input ,s2=rev(a)

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
    int n=s2.length();
    

    
    cout<<lcs(s1,s2,m,n);

    return 0;
}
