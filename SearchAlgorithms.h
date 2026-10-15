#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include <vector>

class SearchAlgorithms {
public:
    static int binarySearchB(const std::vector<int>& collection, int target);
    static int quickSequentialSearchQ(std::vector<int> collection, int target);
};

#endif
