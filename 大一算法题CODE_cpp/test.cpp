#include<bits/stdc++.h>
using namespace std;

int get_the_first_match(int lo,int hi,int match){
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(match(mid)){
            hi=mid-1;
        }else{
            lo=mid+1;
        }
        return lo;
    }
}