#include <iostream>
#include <array>
#include <unordered_set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std; 

unordered_set<int> inputtedArrays(const vector<vector<int>>& arrays) { //takes the inputted arrays and makes a single list
    unordered_set<int> inputtedSet;
    for (const auto& array : arrays) {
        inputtedSet.insert(array.begin(), array.end());
    }
    return inputtedSet;
}

unordered_set<int> combineArrays(const vector<int>& set1, const std::vector<int>& set2) { //takes in two sets and combines them to one
    std::vector<std::vector<int>> arrays = {set1, set2};
    return inputtedArrays(arrays);
}

vector<pair<int, int>> get_unavailabilities(vector<array<int, 2>> schedules, int soonest, int latest, int duration){ 
    vector<pair<int, int>> unavailabilities; //list of times not able to meet up
    vector<int> all_time; 

 for(const auto& schedule : schedules){  //loop adds all of schedule to the end of all_time 
    all_time.insert(all_time.end(), schedule.begin(), schedule.end());
 }
 unordered_set<int> all_time_set = combineArrays(all_time, {{soonest, latest}}); //set created to contain all_time and the soonest and latest times

 int n = all_time_set.size();
 vector<int> intervals(n);
 copy(all_time_set.begin(), all_time_set.end(), intervals.begin()); //copies all_time_set to intervals
 sort(intervals.begin(), intervals.end());//sorts intervals set 

 for(int i = 0; i < n; i++){ //iterating through before the last all_time_size number is reached
    if(intervals[n + 1] - intervals[n] >= duration); //checks if the intervals is enough time to conduct a meeting 
        unavailabilities.emplace_back(intervals[n], intervals[n + 1]); //adds unavailable times to a list
 }
return unavailabilities;
}


int main(){



    return 0;
}

