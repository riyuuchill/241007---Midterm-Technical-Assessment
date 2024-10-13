#include <iostream>  // IO operations especially in its basic form or standard
#include <cmath>     // For such math functions like sqrt and pow
#include <vector>    // When we want to store points in the vector container.
using namespace std;

// Given that, it is a function for Euclidean distance between two points (x1, y1) and (x2, y2)
float getting_distance(float x1, float y1, float x2, float y2) {
    // For calculating the distance using this formula: (x2-x1)^2 + (y2 - y1)^2)
    float distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;  // Return distance
}

// Natural numbers summing function
size_t getting_sum(size_t N) {
    // If you want to compute the sum of a first N natural numbers then use the formula N * (N + 1) / 2
    size_t sum = N * (N + 1) / 2;
    return sum;  // Return the calculated sum
}

int main() {
    size_t N;  // Declaration for number of delivery points variable
    float total_distance = 0;  // Total distance between consecutive points variable
    size_t sum;  // Variable of total distance between consecutive points
    
    // Ask the user how many delivery points
    cout << "Enter the total number of delivery points: ";
    cin >> N;

    // Input a vector of the coordinate pairs ( N in total)
    vector<pair<float, float>> points(N);

    // Give the coordinates of each points as input
    for (size_t i = 0; i < N; ++i) {
        cout << "\nEnter the coordinates for Point " << i + 1 << "." << endl;
        cout << "X: ";
        cin >> points[i].first;  // Input x-coordinate
        cout << "Y: ";
        cin >> points[i].second;  // Input y-coordinate
    }

    // Find the total distance between consecutive delivery points.
    for (size_t i = 1; i < N; ++i) {
        total_distance += getting_distance(points[i-1].first, points[i-1].second, points[i].first, points[i].second);
    }

    // Given that, sum first N natural number
    sum = getting_sum(N);

    // The output of distance and sum of natural numbers
    cout << "\n" << endl;
    cout << "Total distance traveled: " << total_distance << endl;
    cout << "Sum of the first " << N << " natural numbers: " << sum << endl;

    return 0;  // Provide a successful way to run the program
}

/*
As a demonstration of the use of the mathematical tools, that is the Pythagorean theorem and the formula for the 
summation of the natural numbers, the code is provided. The function getting_distance uses the euclidean distance 
with two points within a two D space using the pythagorean theorem. It is a theorem that the distance between 
points (x1, y1) and (x2, y2) can be computed as the square root of the sum of the squares of points' x and y 
coordinate differences, i.e. sqrt((x2 - x1)² + (y2 - y1)²). This is a starting point in geometry on how to find 
how much distance between 2 points you will go in a straight line. We also see with the help of getting_sum 
function which well known mathematical formula used for the sum of first N natural numbers i.e by multiplying N with
 (N + 1)/2. The advantage of this is that based on this formula, no iterative addition is required as you can 
 calculate the sum. Together these functions show how practical problems can be solved using mathematical concepts 
 in programming.
*/