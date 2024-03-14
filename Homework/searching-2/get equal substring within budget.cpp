#include<bits/stdc++.h>
using namespace std;

bool checker(string s, string t,int window,int maxCost){
    int cost=0;
    for(int i=0;i<window;i++) cost+=abs(s[i]-t[i]);

    if(cost<=maxCost) return true;
    for(int i=window;i<s.size();i++){
        cost=cost+abs(s[i]-t[i])-abs(s[i-window]-t[i-window]);
        if(cost<=maxCost) return true;
    }
    return false;
}
int equalSubstring(string s,string t,int maxCost){
        int low=0;
        int high=s.size();
        int maxi=0;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(checker(s,t,mid,maxCost)){
                maxi=max(maxi,mid);
                low=mid+1;
            }
            else high=mid-1;
        }
        return maxi;
    }
int main(){
    string s="abcd";
    string t="bcdf";
    cout<<equalSubstring(s,t,3);
    
}
