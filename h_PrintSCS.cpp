/*
Given two strings X and Y, print the shortest string that has
both X and Y as subsequences. 
If multiple shortest supersequence exists, print any one of them.
    
Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB" 
OR Any string that represents shortest
supersequence of X and Y

0 0 0 0 0 0 0 0 
0 0 0 0 0 1 1 1 
0 1 1 1 1 1 1 1 
0 1 1 1 1 1 1 1 
0 1 1 2 2 2 2 2 
0 1 1 2 2 3 3 3 
0 1 1 2 2 3 3 4 
AGXGTXAYB
*/

#include <bits/stdc++.h>
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define ll long long int

string lcs(string s1,string s2,int m,int n){
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
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);  

        }  
    }  

    //printing dp table
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

  
  
    //traverse from the dp[m][n] for finding the answer
    
    string ans="";

    int i=m,j=n;

    while(i>0 && j>0){

        if (s1[i-1]==s2[j-1])
        {   
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }

        else
        {
            if(dp[i][j-1]>dp[i-1][j]){
                ans.push_back(s2[j-1]);
                j--;
            }
            else
            {   
                ans.push_back(s1[i-1]);
                i--;
            }
        }
    }


    //if any one of i and j == 0 ...,Include rmaining chars.
    while(i>0){
        ans.push_back(s1[i-1]);
        i--;
    }
    while(j>0){
        ans.push_back(s2[j-1]);
        j--;
    }


    reverse(ans.begin(),ans.end());

    return ans;
}


int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    
    int m=s1.length();
    int n=s2.length();
    

    
    cout<<lcs(s1,s2,m,n); 
 
    

    return 0;
}
