#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

int find_starting_city(vector<int>& city_distances, vector<int>& fuel, int mpg) {
    
    int n = city_distances.size(); // number of cities

    for (int start = 0; start < n; start++) {
        
        int tank = 0; // gas in tank
        
        int valid = 1; // flag indicating if current starting city is valid
        
        

        for (int i = 0; i < n; i++) {
            
            int j = (start + i) % n; // index of current city
            
            int gas = fuel[j]; // gas available at current city
            
            int distance = city_distances[j]; // distance to next city
            
            tank += gas * mpg - distance; // update gas in tank after traveling to next city



            if (tank < 0) {
                
                valid = 0; // current starting city is not valid
                
                break;
            }
        }

        if (valid) {
            
            return start;
            
        }
    }

    return -1; // no valid starting city found
}
int main() {
    vector<int> city_distances = {0, 0, 0, 0, 0};
    vector<int> fuel = {0, 0, 0, 0, 0};
    int mpg = 10;
    
    cout << "City Distances (5) = ";
    vector<int> city_distance(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> city_distances[i];
    }
    
    cout <<"Fuel (5)= ";
     for (int i = 0; i < 5; i++)
     {
         cin >> fuel[i];
     }
    
    cout << "MPG(1) = ";
     for (int i = 0; i < 1; i++)
     {
         cin >> mpg;
     }
    int starting_city = find_starting_city(city_distances, fuel, mpg);

    if (starting_city >= 0) {
        cout << "Preferred starting city is " << starting_city << endl;
    } else {
        cout << "No valid starting city found" << endl;
    }

    return 0;
}
