#include <iostream>

template <typename T, int size>
void QuickSort(T (&array)[size], int left, int right) {
    T temp = array[left];
    int left_index = left;
    int right_index = right;
    if (left < right) {
        while (left_index < right_index) {
            while (array[right_index] >= temp && left_index < right_index) {
                right_index--;
            }
            array[left_index] = array[right_index];//如果是left == right 则交换也是没问题的

            while (array[left_index] <= temp && left_index < right_index) {
                left_index++;
            }
            array[right_index] = array[left_index];
        }
        array[left_index] = temp;
        QuickSort(array, left, right_index - 1);
        QuickSort(array, right_index + 1, right);
    }
}


int main() {
    int a[9] = {7, 3, 4, 2, 6, 7, 7, 6, 8};
    QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        std::cout << a[i] << " ";
    }
    return 0;
}

