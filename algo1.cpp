#include <iostream>
#include <vector>
using namespace std;

// Big O is O(N^2)

int findCity(vector<int>& cityDistances, vector<int>& fuel, int mpg) {
    
    int n = cityDistances.size(); // number of cities

    for (int start = 0; start < n; start++) {  //)(O)n level 1 Big O Complexity
        
        int tank = 0; // gas in tank
        
        int valid = 1; // current starting city is valid

        for (int i = 0; i < n; i++) { //O(n) level 2 Big O Complexity
            
            int j = (start + i) % n; // index of current city
            
            int gas = fuel[j]; // gas available at current city
            
            int distance = cityDistances[j]; // distance to next city
            
            tank += gas * mpg - distance; // updates gas after traveling to next city



            if (tank < 0) {
                
                valid = 0; // Invalid current city
                
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
    vector<int> cityDistances = {0, 0, 0, 0, 0};
    vector<int> fuel = {0, 0, 0, 0, 0};
    int mpg = 10;
    
    cout << "City Distances (5) = ";
    for (int i = 0; i < 5; i++) // (O)1 Big O Complexity
    {
        cin >> cityDistances[i]; //User input for city distances
    }
    
    cout <<"Fuel (5)= ";
     for (int i = 0; i < 5; i++) // (O)1 Big O Complexity
     {
         cin >> fuel[i]; //User input for fuel
     }
    
    cout << "MPG(1) = ";

         cin >> mpg; //User input for MPG
    
    int starting_city = findCity(cityDistances, fuel, mpg);

    if (starting_city >= 0) {
        cout << "Preferred starting city is " << starting_city << endl;
    } else {
        cout << "No valid starting city found" << endl;
    }

    return 0;
}
