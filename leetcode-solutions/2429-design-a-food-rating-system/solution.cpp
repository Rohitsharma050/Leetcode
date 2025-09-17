class FoodRatings {
public:
struct Comp {
    bool operator()(const pair<int,string> &a, const pair<int,string> &b) const {
        if (a.first != b.first) return a.first > b.first; // higher rating first
        return a.second < b.second; // lexicographically smaller first
    }
};

    map<string,int>food_rating;
    unordered_map<string ,string>food_cuisine;
    unordered_map<string,set<pair<int,string>,Comp>>cuisine_rating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0;i<n;i++)
        {
            food_rating[foods[i]] = ratings[i];
            food_cuisine[foods[i]] = cuisines[i];
            cuisine_rating[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldrating = food_rating[food];
        string cuisine = food_cuisine[food];
        cuisine_rating[cuisine].erase({oldrating,food});
        cuisine_rating[cuisine].insert({newRating,food});
        food_rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisine_rating[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
