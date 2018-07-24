#include <iostream>

template <typename T>
void Combination(T *array, int first, int mid, int last, T *temp) {
    int index_a = first, index_b = mid + 1, index = 0;
    while (index_a <= mid&& index_b <= last) {
        if (array[index_a] <= array[index_b]) {
            temp[index++] = array[index_a++];
        } else {
            temp[index++] = array[index_b++];
        }
    }
    while (index_a <= mid) {
        temp[index++] = array[index_a++];
    }
    while (index_a <= mid) {
        temp[index++] = array[index_b++];
    }
    for(int i = 0; i < index; i++) {
        array[first + i] = temp[i];
    }

}

template <typename T>
void MergeSort(T *array, int first, int last) {
    if (first < last) {
        T temp[last - first + 1];
        int middle = (first + last) / 2;
        MergeSort(array, first, middle);
        MergeSort(array, middle + 1, last);
        Combination(array, first, middle, last, temp);
    }
    for (int i = 0; i < last - first + 1; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int array[9] = {2, 1, 5, 4, 7, 2, 3, 10, 8};
    MergeSort(array, 0, 8);
    return 0;
}
