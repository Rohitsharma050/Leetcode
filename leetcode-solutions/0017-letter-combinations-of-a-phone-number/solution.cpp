class Solution {
public:
void subset(int index,string digits,string substring,vector<string> &ans,string mapping[])
{
    if(index==digits.length())
    {
        ans.push_back(substring);
        return;
    }
    int number=digits[index]-'0';
    string value=mapping[number];
    for(int i=0;i<value.length();i++)
    {
        substring.push_back(value[i]);
        subset(index+1,digits,substring,ans,mapping);
        substring.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
        return ans;
        string substring="";
        string mapping[10] = {"" ,"","abc","def","ghi","jkl" ,"mno","pqrs","tuv","wxyz" };
        subset(0,digits,substring,ans,mapping);
        return ans;
        
    }
};
