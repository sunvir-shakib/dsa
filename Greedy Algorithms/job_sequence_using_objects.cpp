#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Job{
public:
    int idx;
    int deadLine;
    int profit;

    Job(int idx, int deadLine, int profit){
        this-> idx = idx;
        this -> deadLine = deadLine;
        this -> profit = profit;
    }
};

int maxProfit(vector<pair<int, int>>&pairs){
    int n = pairs.size();
    vector<Job> jobs;

    for(int i=0; i<n; i++){
        jobs.emplace_back(i, pairs[i].first, pairs[i].second); //idx, deadline, profit
    }

        sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){ //Sort Jobs by Profit (Descending)
        return a.profit > b.profit;
        });

        cout<<"selecting job"<<jobs[0].idx<<endl;
        int profit = jobs[0].profit;
        int safeDeadline = 2;

        for(int i=1; i<n; i++){
            if(jobs[i].deadLine >= safeDeadline){
                cout<<"selecting job"<<jobs[i].idx <<endl;
                profit += jobs[i].profit;
                safeDeadline++;
            }
        }
        cout<<"max profit: "<<profit<<endl;
        return profit;
}

int main() 
{
   int n = 4;
   vector<pair<int, int>> jobs(4, make_pair(0,0));
   jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    maxProfit(jobs); 

    return 0;
}


/*

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Job {
public:
    int id;
    int deadLine;
    int profit;

    Job(int id, int deadLine, int profit) {
        this->id = id;
        this->deadLine = deadLine;
        this->profit = profit;
    }
};

// Comparator: Sort jobs by profit descending
bool compare(Job &a, Job &b) {
    return a.profit > b.profit;
}

int maxProfit(vector<pair<int, int>>& pairs) {
    int n = pairs.size();
    vector<Job> jobs;

    // Step 1: Create Job objects
    for (int i = 0; i < n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    // Step 2: Sort by profit (high to low)
    sort(jobs.begin(), jobs.end(), compare);

    // Step 3: Find max deadline
    int maxDead = 0;
    for (auto &job : jobs) {
        maxDead = max(maxDead, job.deadLine);
    }

    // Step 4: Create slot array (0-indexed unused)
    vector<int> slots(maxDead + 1, -1);  // slot[i] = jobId if occupied
    int totalProfit = 0;

    cout << "Selected Jobs: ";
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadLine; j > 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                cout << "Job" << jobs[i].id << " ";
                break;
            }
        }
    }

    cout << "\nMax Profit: " << totalProfit << endl;
    return totalProfit;
}

int main() {
    vector<pair<int, int>> jobs = {
        {4, 20},  // deadline, profit
        {1, 10},
        {1, 40},
        {1, 30}
    };

    maxProfit(jobs);
    return 0;
}


*/