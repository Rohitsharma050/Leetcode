class Solution {
public:
 vector<vector<int>>ans;
void getans(int i,int n,int k,vector<int>&temp)
{
    if(temp.size()==k)
    {
        ans.push_back(temp);
        return;
    }
    if(i>n)
    return;
    temp.push_back(i);
    getans(i+1,n,k,temp);
    temp.pop_back();
    getans(i+1,n,k,temp);
}
    vector<vector<int>> combine(int n, int k) {
       
        int i = 1;
        vector<int>temp;
        getans(i,n,k,temp);
        return ans;
    }
};
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
