class NumberContainers {
public:
//unordered map to store kis index pe konsa number hai {index,number}
unordered_map<int,int>indexmp;
//map to store koi number kis kis pe store hai (set isliye kyuki ak se jyada index pe store ho skta hai aur ordered isliye kyuki minimum index 
//starting mia hi hoga)
unordered_map<int,set<int>>numbermp;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        
        //check if the index has already a numebr
        if(indexmp.count(index))
        {
            //extract prevnumber
            int prenum = indexmp[index];
            //erase this index from number map set
            numbermp[prenum].erase(index);
            if(numbermp[prenum].empty())
            {
                numbermp.erase(prenum);
            }
        }
        indexmp[index] = number;
        numbermp[number].insert(index);

    }
    
    int find(int number) {
        if(numbermp.count(number))
        {
            return *numbermp[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
