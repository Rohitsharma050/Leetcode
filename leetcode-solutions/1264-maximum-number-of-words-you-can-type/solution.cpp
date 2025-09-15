class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
         std::istringstream iss(text);
        std::vector<std::string> str;
        std::string word;

    while (iss >> word) {  
        str.push_back(word);
    }
        int count = 0;
        for(int i = 0;i<str.size();i++)
        {
            bool flag = false;
            for(char ch:str[i])
            {
                if(brokenLetters.find(ch)!=string::npos)
                {
                    flag = true;
                    break;
                }
                
            }
            if(!flag)
            {
                count++;
            }
        }
        return count;
    }
};
