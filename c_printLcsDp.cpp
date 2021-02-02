#include<bits/stdc++.h>
using namespace std;

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
                j--;
            }
            else
            {
                i--;
            }
        }
    }


    reverse(ans.begin(),ans.end());

    return ans;
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
    

    
    cout<<lcs(s1,s2,m,n)<<"\n";
    
    return 0;
}


//ip:
//s1=acbcf
//s2=abcdaf
//op:
/*
0 0 0 0 0 0 0 
0 1 1 1 1 1 1 
0 1 1 2 2 2 2 
0 1 2 2 2 2 2 
0 1 2 3 3 3 3 
0 1 2 3 3 3 4 
abcf
*/
