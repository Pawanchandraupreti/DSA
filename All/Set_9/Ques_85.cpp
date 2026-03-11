// Job Sequencing Problem (Greedy)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job{
    int id,deadline,profit;
};

int main(){

    vector<Job> jobs = {
        {1,2,100},
        {2,1,19},
        {3,2,27},
        {4,1,25},
        {5,3,15}
    };

    sort(jobs.begin(),jobs.end(),[](Job a,Job b){
        return a.profit>b.profit;
    });

    int slot[4]={-1};

    int profit=0;

    for(auto job:jobs){
        for(int j=job.deadline-1;j>=0;j--){
            if(slot[j]==-1){
                slot[j]=job.id;
                profit+=job.profit;
                break;
            }
        }
    }

    cout<<profit;
}