#include <iostream>
using namespace std;

int findFloor(int arr[], int n, int x) {
    int start = 0;
    int end = n - 1;
    int floor = -1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] <= x) {
            floor = arr[mid];
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return floor;
}

int findCeil(int arr[], int n, int x) {
    int start = 0;
    int end = n - 1;
    int ceil = -1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] >= x) {
            ceil = arr[mid];
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ceil;
}

int findPeak(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int mid = (start + end) / 2;

        if (arr[start] >= arr[mid]) {
            end = mid;
        } else {
            start = mid;
        }
    }

    return arr[start];
}

int findMinimum(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int mid = (start + end) / 2;

        if (arr[start] <= arr[mid]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return arr[start];
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[50];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element for floor and ceiling: " << endl;
    cin >> x;

    int floor = findFloor(arr, n, x);
    cout << "The floor of the sorted rotated array is " << floor << endl;

    int ceil = findCeil(arr, n, x);
    cout << "The ceiling of the sorted rotated array is " << ceil << endl;

    int peakElement = findPeak(arr, n);
    cout << "The peak element of the rotated array is " << peakElement << endl;

    int minElement = findMinimum(arr, n);
    cout << "The minimum element of the rotated array is " << minElement << endl;

    return 0;
}
