class MovieRentingSystem {
public:
struct pair_hash {
    size_t operator()(const pair<int,int> &p) const {
        // Simple hash combine formula
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
    unordered_map<int,set<pair<int,int>>>movie_shop;//{movie,price,shop}
    set<pair<int,pair<int,int>>>rented;//{price,shop,movie}
    unordered_map<pair<int,int>,int,pair_hash>prices; //{shop,movie,price}
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i = 0;i<entries.size();i++)
        {
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];
            movie_shop[movie].insert({price,shop});
            prices[{shop,movie}] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int>s;
        auto &shops = movie_shop[movie];
        int i = 0;
        for(auto it:shops)
        {
            s.push_back(it.second);
            i++;
            if(i==5)
            {
                break;
            }
        }
        return s;
    }
    
    void rent(int shop, int movie) {
        int price = prices[{shop,movie}];
        rented.insert({price,{shop,movie}});
        movie_shop[movie].erase({price,shop});
    }
    
    void drop(int shop, int movie) {
        int price = prices[{shop,movie}];
        rented.erase({price,{shop,movie}});
        movie_shop[movie].insert({price,shop});

    }
    
    vector<vector<int>> report() {
        int i = 0;
        vector<vector<int>>r;
        for(auto it:rented)
        {
            int shop = it.second.first;
            int movie = it.second.second;
            r.push_back({shop,movie});
            i++;
            if(i==5)
            {
                break;
            }
        }
        return r;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
