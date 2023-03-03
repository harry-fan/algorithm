#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1; // 左子节点的索引
    int r = 2 * i + 2; // 右子节点的索引

    // 左子节点比根节点大
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    // 右子节点比根节点大
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    // 如果最大值不是根节点，交换根节点和最大值
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // 递归调整堆
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // 建立初始堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 根节点和最后一个节点交换，重新调整堆
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}


int main() {
    int arr[] = {1, 4, 3, 8, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " ";
    cout << endl;
}
