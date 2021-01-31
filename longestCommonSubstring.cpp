#include<bits/stdc++.h>
using namespace std;
#define end "\n"
#define ll long long int
#define w(t) while(t--)



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
            dp[i][j] = 0;  
        }  
    }  
    int ans=INT_MIN;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           // cout<<dp[i][j]<<" ";
            if(dp[i][j]>ans){
                ans=dp[i][j];
            }
        }
        //cout<<end;
    }
    
    return ans;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    
    int m=s1.length();
    int n=s2.length();
    

    
    cout<<lcs(s1,s2,m,n)<<"\n";
    
    return 0;
}


//s1=OldSite:GeeksforGeeks.org
//s2=NewSite:GeeksQuiz.com
//op==10
