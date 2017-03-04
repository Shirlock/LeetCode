/*
32ms
Your runtime beats 10.22% of cpp submissions.


可以用除法来避免使用long long：
25 ms
Your runtime beats 31.09% of cpp submissions

 while (str[i] >= '0' && str[i] <= '9') {
        if (ans >  INT_MAX / 10 || (ans == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        ans  = 10 * ans + (str[i++] - '0');
    }
*/
class Solution {
public:
    int myAtoi(string str) {
        int i=0,sign=1;
        long long tmp,ans=0;
        while(str[i]==' ')i++;
        if(str[i]=='+' || str[i]=='-'){
            if(str[i]=='-')sign=-1;
            i++;
        }
        while(str[i]>='0'&&str[i]<='9'){
            tmp=ans*10+str[i]-'0';
            if(tmp*sign>=INT_MAX) return INT_MAX;
            if(tmp*sign<=INT_MIN) return INT_MIN;
            ans=tmp;
            i++;
        }
        ans*=sign;
        return ans;
    }
};