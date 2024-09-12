class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = words.size();
        string temp;
        for(int i=0;i<words.size();i++)
        {   
            temp = words[i];
            for(int j=0;j<temp.size();j++)
            {
                  if (allowed.find(temp[j]) != std::string::npos) 
                  {
                        continue;
                  }
                  else
                  {
                    count--;
                    break;
                  }
            }

        }
        return count;
    }
};
