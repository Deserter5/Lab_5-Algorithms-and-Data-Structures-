#include "SearchAlgorithms.h"

int SearchAlgorithms::binarySearchB(const std::vector<int>& collection, int target) {
    int left = 1;
    int right = collection.size();

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (target == collection[mid - 1]) {
            return mid;
        }
        else if (target < collection[mid - 1]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int SearchAlgorithms::quickSequentialSearchQ(std::vector<int> collection, int target) {
    int size = collection.size();
    collection.push_back(target);

    int index = 1;
    while (collection[index - 1] != target) {
        index++;
    }

    if (index <= size) {
        return index;
    }
    else {
        return -1;
    }
}