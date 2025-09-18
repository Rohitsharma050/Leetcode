class TaskManager {
public:
struct Comp {
    bool operator()(const pair<int, pair<int, int>>& a,
                    const pair<int, pair<int, int>>& b) const {
        if (a.first == b.first)
            return a.second.first > b.second.first; // highest taskId first
        return a.first > b.first; // highest priority first
    }
};


    unordered_map<int,pair<int,int>>task_user;
    set<pair<int,pair<int,int>>,Comp>prioritySet;
    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(auto task:tasks)
        {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            task_user[taskId] = {userId,priority};
            prioritySet.insert({priority,{taskId,userId}});
        }

    }
    
    void add(int userId, int taskId, int priority) {
        task_user[taskId] = {userId,priority};
        prioritySet.insert({priority,{taskId,userId}});

    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = task_user[taskId].second;
        int userId = task_user[taskId].first;
        task_user[taskId] = {userId,newPriority};
        prioritySet.erase({oldPriority,{taskId,userId}});
        prioritySet.insert({newPriority,{taskId,userId}});

    }
    
    
    void rmv(int taskId) {
    int userId = task_user[taskId].first;
    int priority = task_user[taskId].second;
    task_user.erase(taskId);
    prioritySet.erase({priority,{taskId,userId}});      
    }
    
   int execTop() {
    if (prioritySet.empty()) return -1;

    auto top = *prioritySet.begin();
    int priority = top.first;
    int taskId = top.second.first;
    int userId = top.second.second;

    prioritySet.erase(prioritySet.begin());
    task_user.erase(taskId);

    return userId;
    }

};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
