#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void merge_sort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; ++i)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while (i < n1) {
            arr[k++] = L[i++];
        }

        while (j < n2) {
            arr[k++] = R[j++];
        }
    }
}

void bubble_sort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void print_array(const vector<int> &arr) {
    for (int time : arr) {
        cout << time << " ";
    }
    cout << endl;
}

void analysis(vector<int> delivery_times) {
    vector<int> bubbleSortedTimes = delivery_times;
    auto startBubble = chrono::high_resolution_clock::now();
    bubble_sort(bubbleSortedTimes);
    auto endBubble = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleDuration = endBubble - startBubble;

    vector<int> mergeSortedTimes = delivery_times;
    auto startMerge = chrono::high_resolution_clock::now();
    merge_sort(mergeSortedTimes, 0, mergeSortedTimes.size() - 1);
    auto endMerge = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeDuration = endMerge - startMerge;

    cout << "BUBBLE SORT" << endl;
    cout << "Sorted delivery times: ";
    print_array(bubbleSortedTimes);
    cout << "Time taken: " << bubbleDuration.count() << " seconds\n";
    cout << "Time Complexity: O(n^2)\n";

    cout << "MERGE SORT" << endl;
    cout << "Sorted delivery times: ";
    print_array(mergeSortedTimes);
    cout << "Time taken: " << mergeDuration.count() << " seconds\n";
    cout << "Time Complexity: O(n log n)\n";
}

int main() {
    int N;

    cout << "Enter the number of deliveries: ";
    cin >> N;

    while (N <= 0) {
        cout << "Please enter a positive number for the number of deliveries: ";
        cin >> N;
    }

    vector<int> delivery_times(N);
    cout << "Enter the delivery times (in minutes)." << endl;

    for (int i = 0; i < N; ++i) {
        cout << "Delivery Time (" << i + 1 << "): ";
        cin >> delivery_times[i];
    }

    analysis(delivery_times);

    return 0;
}

// In the following code above, we shall identify two sorting techniques and they are the Bubble sort and the Merge
//sort. Besides, concerning time complexity, their Big O notation is quite different. Bubble sort needs a total of 
//n^2 comparisons because it has two loops to make adjacent comparison and then swaps them which makes it unfit for 
//large data sets. It is relatively slow especially with large inputs as in the worst case scenario each element 
//might have to conduct comparisons with all other elements. On the other hand Merge Sort has the time complexity of
//O(n log n) its work is to divide the input array as two halves in recursive manner then merge the halves in sorted
//manner. Because of this divide-and-conquer partitioning, Merge Sort is in fact much more efficient compared to 
//two other sorting algorithms in this scale of input size, further more in the large input size.

//Since Bubble Sort works efficiently on small inputs, there is a tendency the recursive step in Merge Sort would 
//take longer time and equal the time Bubble Sort took or even less than it. Thus, for medium sizes of inputs Merge 
//Sort wins out and the logarithmic nature of Merge Sort’s growth factor increases its performance even more, or 
//contrastingly, the quadratic time complexity of Bubble Sort becomes apparent. For large input sizes, the difference
//is stark: Merge Sort continues to have a complexity of O(n log n), while Bubble Sort’s overly slow performance due 
//to O(n²) means it will not be efficient for large arrays. Thus, even if Bubble Sort is completely acceptable for 
//an array having small elements, Merge Sort seems to be a perfect choice to handle larger inputs.