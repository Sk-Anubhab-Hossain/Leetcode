class Solution {
public:
    bool isPalindrome(string s) {
        string s2= \\;
        for(char c: s){
            if(isalnum(c)){
                s2+=tolower(c);
            }
        }
        string s2_rev= s2;
        reverse(s2.begin(),s2.end());
        return (s2_rev==s2);

    }
};