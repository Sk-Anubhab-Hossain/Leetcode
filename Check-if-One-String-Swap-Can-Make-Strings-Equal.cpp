class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // int n2= s2.size();
        // if(s1==s2) return true;
        // for(int i=0;i<n2;i++){
        //     for(int j=i+1;j<n2;j++){
        //         swap(s2[i],s2[j]);
        //         if(s2==s1){
        //             return true;
        //             break;
        //         }
        //         swap(s2[i],s2[j]);
        //     }
        // }
        // return false;

        vector<int> diffIndices;
        if(s1==s2) return true;

        for(int i=0;i<s2.size();i++){
            if(s1[i] != s2[i]){
                diffIndices.push_back(i);
            }
        }

        if(diffIndices.size() != 2) return false;

        int i=diffIndices[0], j=diffIndices[1];
        return (s1[i]==s2[j] && s1[j]==s2[i]);
    }
};