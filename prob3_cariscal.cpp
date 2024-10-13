#include <iostream>

using namespace std;

void hanoi(int n, char source, char destination, char buffer, int& move_count) {
    if (n == 1) {
        cout << "Move Package 1 from " << source << " to " << destination << endl;
        move_count++;
        return;
    }

    hanoi(n - 1, source, buffer, destination, move_count);

    cout << "Move Package " << n << " from " << source << " to " << destination << endl;
    move_count++;

    hanoi(n - 1, buffer, destination, source, move_count);
}

int main() {
    int N;
    int move_count = 0;

    cout << "Enter the total number of packages: ";
    cin >> N;

    hanoi(N, 'A', 'C', 'B', move_count);

    cout << "Total number of moves required: " << move_count << endl;

    return 0;
}

/*
The process of the Tower of Hanoi can be thought of as the process of doing something recursive that breaks down 
the problem into smaller subproblems and has to move N sets of packages from a source peg to a destination peg 
using an auxiliary peg. The algorithm follows these steps: It then first recursively moves the top N-1 packages 
from the source peg to the auxiliary peg, and then moves the largest package directly the destination peg, and 
finally recursively moves the N-1 packages from the auxiliary peg to the destination peg. It continues until the 
base case at which only one package has to be moved. This algorithm works fine and its time complexity is O(2^N) 
as we take two steps for the first smaller subproblem and another N- first smaller subproblems so the number of 
steps required increases exponentially based upon N. Using certain input values of N, the number of required total 
moves can fit the formula of 2^N - 1. For example, if N = 3, then there would be no 7 moves were taken.
*/