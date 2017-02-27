/*
思路一 字符串反转 然后求最长公共子串 然而有问题  比如 
Input:
"abcdasdfghjkldcba"
Output:
"abcd"
Expected:
"a"
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        if(len<=1) return s;
        string rs=s;
        reverse(rs.begin(),rs.end());
        int d[1001][1001];
        for(int j=0;j<=len;j++){
            d[0][j]=0;
        }
        for(int i=1;i<=len;i++){
           for(int j=1;j<=len;j++){
               if(s[i-1]==rs[j-1]){
                   d[i][j]=d[i-1][j-1]+1;
               }else{
                   d[i][j]=0;
               }
           }
        }
       int maxIndex,maxL=-1;
       for(int i=1;i<=len;i++){
           for(int j=1;j<=len;j++){
              if(d[i][j]>maxL){
                  maxL=d[i][j];
                  maxIndex=i;
              }
           }
        }
      return s.substr(maxIndex-maxL,maxL);
    }
};


/*
思路二 动态规划 d[i][j] 表示子串i到j是否为回文
// Time complexity O(n*n)
92ms
Your runtime beats 27.35% of cpp submissions
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        if(len<=1) return s;
        int d[1001][1001],left=0,right=0;
        
      for(int step=0;step<len;step++){
          for(int i=0;i+step<len;i++){
              if(s[i]==s[i+step]){
                  if(step>=2){
                  d[i][i+step]=d[i+1][i+step-1];
                  if(d[i][i+step]){
                      left=i;right=i+step;
                    }
                  }else {
                      d[i][i+step]=1;
                      left=i;right=i+step;
                  }
              }
              else {
                  d[i][i+step]=0;
              }
          }
      }
      return s.substr(left,right-left+1);
    }
};


/*
思路三 以i为中点向两边展开判断，分奇数和偶数两种情况
// Time complexity O(n*n)
16ms
Your runtime beats 56.02% of cpp submissions
*/
class Solution {
public:
    string longestPalindrome(string s) {
    int maxLeft=0,maxL=1,left,right,len=s.length();
  for(int i=0;i<len-1;i++){
    if(s[i]==s[i+1]){
        if(maxL<2){
          maxLeft=i;
          maxL=2;
        }
      left=i-1;
      right=i+2;
      while(left>=0&&right<len&&s[left]==s[right]){
        if(right-left+1>maxL){
          maxLeft=left;
          maxL=right-left+1;
        }
        left--;
        right++;
      }
    }
  }
  for(int i=0;i<len-1;i++){
    left=i-1;
    right=i+1;
    while(left>=0&&right<len&&s[left]==s[right]){
      if(right-left+1>maxL){
        maxLeft=left;
        maxL=right-left+1;
      }
      left--;
      right++;
    }
  }
    return s.substr(maxLeft,maxL);
    }
};


/*
思路三的改进 以i为中点向两边展开判断，连续相同的数合并处理
// Time complexity O(n*n)
6ms
Your runtime beats 77.83% of cpp submissions
*/


class Solution {
public:
    string longestPalindrome(string s) {
    int maxLeft=0,maxL=1,left,right,len=s.length();
  for(int i=0;i<len-1;){
      left=right=i;
    while(s[right]==s[right+1]){
      right++;
    }
    i=right+1;
    while(left>=0&&right<len&&s[left]==s[right]){
      if(right-left+1>maxL){
        maxLeft=left;
        maxL=right-left+1;
      }
      left--;
      right++;
    }
  }
    return s.substr(maxLeft,maxL);
    }
};