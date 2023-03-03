#include <iostream>

using namespace std;

void show(int d[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
}

void merge(int d[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; ++i) {
        arr1[i] = d[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        arr2[i] = d[mid + 1 + i];
    }
    show(arr1, n1);
    show(arr2, n2);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            d[k] = arr1[i];
            ++i;
        } else {
            d[k] = arr2[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        d[k] = arr1[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        d[k] = arr2[j];
        ++k;
        ++j;
    }
}

void self_sort(int d[], int left, int right) {
    if (left < right) {
        //int mid = (right + left) / 2;
        int mid = left + (right - left) / 2;

        cout << left << ":" << mid << ":" << right << endl;
        self_sort(d, left, mid);
        self_sort(d, mid + 1, right); 
        merge(d, left, mid, right);
    }
}


int main() {
    int d[] = { 2, 3, 1, 4, 0 };

    int size = sizeof(d) / sizeof(d[0]);
    self_sort(d, 0, size - 1);
    show(d, size);
}
