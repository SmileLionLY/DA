#include <iostream>

template <typename T>
void Combination(T *array_a, int size_a, T *array_b, int size_b, T *array, int size) {
    int index_a = 0, index_b = 0, index = 0;
    while (index_a < size_a && index_b < size_b) {
        if (array_a[index_a] <= array_b[index_b]) {
            array[index] = array_a[index_a];
            index_a++;
        } else {
            array[index] = array_b[index_b];
            index_b++;
        }
        index++;
    }
    if (index_a < size_a) {
        for (int i = 0; i < (size_a - index_a); i++) {
            array[index] = array_a[index_a + i];
            index++;
        }
    }
    if (index_b < size_b) {
        for (int i = 0; i < (size_b - index_b); i++) {
            array[index] = array_b[index_b + i];
            index++;
        }
    }

}

template <typename T>
void MergeSort(T *array, int size, int left, int right) {
    int buffer_size = right - left + 1;
    T temp[buffer_size];
    for (int i = 0; i < buffer_size; i++) {
        temp[i] = array[i];
    }
    if (right > left) {
        int middle = (right + left) / 2;
        MergeSort(array, middle + 1, left, middle);
        MergeSort(array, size - middle - 1, middle + 1, right);
        Combination(array, middle + 1, array + middle + 1, right - middle, temp, buffer_size);
    }
    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
        std::cout << temp[i] << " ";
    }
    std::cout << ";" << std::endl;
}

int main() {
    int array[3] = {2, 1, 5};
    MergeSort(array, 3, 0, 2);
    return 0;
}
