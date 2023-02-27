#include <iostream>
#include <vector>
using namespace std;

// Big O is O(N^2)

int findCity(vector<int>& cityDistances, vector<int>& fuel, int mpg) {
    
    int n = cityDistances.size(); // number of cities

    for (int start = 0; start < n; start++) {  //)(O)n level 1 Big O Complexity

        int valid = 1; // present starting city is valid

        int tank = 0; // gas in tank
        
        

        for (int i = 0; i < n; i++) { //O(n) level 2 Big O Complexity
            
            int j = (start + i) % n; // index of present city

            int distance = cityDistances[j]; // distance to next city

            int gas = fuel[j]; // gas available at present city
            
            tank += gas * mpg - distance; // updates gas after traveling to next city



            if (tank < 0) {
                
                valid = 0; // Invalid present city
                
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
    
    int startingCity = findCity(cityDistances, fuel, mpg);

    if (startingCity >= 0) {
        cout << "The preferred starting city is " << startingCity << endl;
    } else {
        cout << "No valid preferred city." << endl;
    }

    return 0;
}
