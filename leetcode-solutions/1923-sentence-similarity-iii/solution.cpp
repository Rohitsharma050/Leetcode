class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length()<s2.length())
        {
            swap(s1,s2);
        }
        vector<string>v1,v2;
        stringstream w1(s1);
        string token;
        while(w1>>token)
        {
            v1.push_back(token);
        }
        stringstream w2(s2);
        //string token;
        while(w2>>token)
        {
            v2.push_back(token);
        }
        int i=0,j = v1.size()-1;
        int k=0,l = v2.size()-1;
        while(i<v1.size() && k<v2.size() && v1[i]==v2[k])
        {
            i++;
            k++;
        }
        while(j>=i && l>=k && v1[j]==v2[l])
        {
            j--;
            l--;
        }
        return l<k;
        
    }
};
