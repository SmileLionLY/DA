#include <iostream>

template <typename T, int size>
void InsertSort(T (&array)[size]) {
    T temp[size];
    for (int i = 0; i < size; i++) {

        if (0 == i) {
            temp[0] = array[0];    
        } else {
            int insert_index = i;
            for (int j = i - 1; j >= 0 && temp[j] > array[i]; j--) {
                temp[j + 1] = temp[j];
                insert_index = j;
            }
            temp[insert_index] = array[i];

        }
    }
    for (int i = 0; i < size; i++) {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int array[] = {1, 2, 3, 0, -99, -8, -12, 32, 24};
    InsertSort(array);
    return 0;
}
