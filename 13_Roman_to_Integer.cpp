class Solution {
public:
    int change(char c){
        int tmp;
         switch(c){
                case 'I':
                tmp=1;
                break;
                
                case 'V':
                tmp=5;
                break;
                
                case 'X':
                tmp=10;
                break;
                
                case 'L':
                tmp=50;
                break;
                
                case 'C':
                tmp=100;
                break;
                
                case 'D':
                tmp=500;
                break;
                
                case 'M':
                tmp=1000;
                break;
            }
            return tmp;
    }
    int romanToInt(string s) {
         // string sym[]={"I","V", "X", "L", "C", "D","M"};
         //  int num[]={1,5,10,50,100,500,100};
        
        int ans=0,tmp;
        for(int i=0;i<s.size()-1;i++){
            if(change(s[i+1])/change(s[i])==5||change(s[i+1])/change(s[i])==10)
                ans-=change(s[i]);
            else
                ans+=change(s[i]);
        }
        ans+=change(s[s.size()-1]);
        return ans;
    }
};