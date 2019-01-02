#include<bits/stdc++.h>
using namespace std;
vector<int> lps(string pat)
{
    int n=pat.size(),j;
    vector<int> lp(n);
    lp[0]=0;
    for(int i=1;i<n;i++)
    {
        j=lp[i-1];
        while(j>0&&pat[i]!=pat[j])
        j=lp[j-1];
        
        if(pat[i]==pat[j])
        ++j;
        
        lp[i]=j;
    }
    return lp;
}
int kmp(string ptr,string txt)
{
    int n=txt.size();
    int m=ptr.size();
    vector<int> lp=lps(ptr);
    int i=0,j=0,ctr=0;
    while(i<n)
    {
        if(ptr[j]==txt[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            ctr++;
            j=lp[j-1];
        }
        else if(i<n&&ptr[j]!=txt[i])
        {
            if(j!=0)
                j=lp[j-1];
            else 
                i++;
        }
    }
    
    return ctr;
}
int main()
{
    string pat,text;
    cin>>pat>>text;
    cout<<kmp(pat,text)<<endl;
}