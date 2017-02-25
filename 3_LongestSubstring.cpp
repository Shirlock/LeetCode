//
//  3_LongestSubstring.cpp
//  
//
//  Created by songyu on 2017/2/24.
//
//


/*
 
 25 ms
 Your runtime beats 66.81% of cpp submissions
 
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        int* f=new int[len];
        f[0]= (len>0)? 1:0;
        for(int i=1;i<len;i++){
            int j;
            for(j=i-1;j>=i-f[i-1];j--){
                if(s[j]==s[i]){
                    break;
                }
            }
            f[i]=i-j;
        }
        int maxn=0;
        for(int i=0;i<len;i++){
            if(maxn<f[i]) maxn=f[i];
        }
        delete []f;
        return maxn;
    }
};
