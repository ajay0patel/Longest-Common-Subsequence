//shortest common super-sequence
// ans will be len(s1)+len(s2)-len(lcs) 


#include<bits/stdc++.h>
using namespace std;

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
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);  

        }  
    }  

    /*printing dp table
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/


    
return dp[m][n];

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    
    int m=s1.length();
    int n=s2.length();
    

    
    cout<<m+n-lcs(s1,s2,m,n)<<"\n";
    
    return 0;
}


//ip:
//s1=AGGTAB
//s2=GXTXAYB
//op: 9
