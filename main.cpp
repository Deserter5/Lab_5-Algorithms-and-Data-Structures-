#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "SearchAlgorithms.h"

void displayMenu() {
    std::cout << "\n================ LAB 5: BINARY SEARCH ================\n";
    std::cout << "1. Generate and sort random sequence\n";
    std::cout << "2. Display element by position\n";
    std::cout << "3. Execute Algorithm B (Binary Search)\n";
    std::cout << "4. Execute Algorithm Q (Quick Sequential Search)\n";
    std::cout << "5. Perform empirical comparative analysis\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option (1-6): ";
}

int main() {
    int choice = 0;
    int sequenceSize = 0;
    std::vector<int> dataSequence;
    bool isDataReady = false;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Enter sequence size (N): ";
            std::cin >> sequenceSize;

            if (sequenceSize <= 0) {
                std::cout << "Error: Size must be greater than 0.\n";
                break;
            }

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, sequenceSize * 10);

            dataSequence.resize(sequenceSize);
            for (int i = 0; i < sequenceSize; ++i) {
                dataSequence[i] = dis(gen);
            }

            std::sort(dataSequence.begin(), dataSequence.end());
            isDataReady = true;

            std::cout << "Sequence successfully generated and sorted!\n";
            std::cout << "First elements: ";
            for (int i = 0; i < std::min(sequenceSize, 10); ++i) {
                std::cout << dataSequence[i] << " ";
            }
            std::cout << "\n";
            break;
        }
        case 2: {
            if (!isDataReady) {
                std::cout << "Please generate the sequence first (option 1)!\n";
                break;
            }

            int position;
            std::cout << "Enter element position (1 to " << sequenceSize << "): ";
            std::cin >> position;

            if (position >= 1 && position <= sequenceSize) {
                std::cout << "Element at position " << position << " is: " << dataSequence[position - 1] << "\n";
            }
            else {
                std::cout << "Invalid position!\n";
            }
            break;
        }
        case 3: {
            if (!isDataReady) {
                std::cout << "Please generate the sequence first (option 1)!\n";
                break;
            }

            int targetValue;
            std::cout << "Enter search argument (K): ";
            std::cin >> targetValue;

            auto start = std::chrono::high_resolution_clock::now();
            int resultPosition = SearchAlgorithms::binarySearchB(dataSequence, targetValue);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;

            if (resultPosition != -1) {
                std::cout << "[Algorithm B] Element found at position: " << resultPosition << "\n";
            }
            else {
                std::cout << "[Algorithm B] Element not found.\n";
            }
            std::cout << "Execution time: " << duration.count() << " ms\n";
            break;
        }
        case 4: {
            if (!isDataReady) {
                std::cout << "Please generate the sequence first (option 1)!\n";
                break;
            }

            int targetValue;
            std::cout << "Enter search argument (K): ";
            std::cin >> targetValue;

            auto start = std::chrono::high_resolution_clock::now();
            int resultPosition = SearchAlgorithms::quickSequentialSearchQ(dataSequence, targetValue);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;

            if (resultPosition != -1) {
                std::cout << "[Algorithm Q] Element found at position: " << resultPosition << "\n";
            }
            else {
                std::cout << "[Algorithm Q] Element not found.\n";
            }
            std::cout << "Execution time: " << duration.count() << " ms\n";
            break;
        }
        case 5: {
            if (!isDataReady) {
                std::cout << "Please generate the sequence first (option 1)!\n";
                break;
            }

            int targetValue;
            std::cout << "Enter test search argument (K) for comparison: ";
            std::cin >> targetValue;

            auto startB = std::chrono::high_resolution_clock::now();
            int posB = SearchAlgorithms::binarySearchB(dataSequence, targetValue);
            auto endB = std::chrono::high_resolution_clock::now();
            double timeB = std::chrono::duration<double, std::micro>(endB - startB).count();

            auto startQ = std::chrono::high_resolution_clock::now();
            int posQ = SearchAlgorithms::quickSequentialSearchQ(dataSequence, targetValue);
            auto endQ = std::chrono::high_resolution_clock::now();
            double timeQ = std::chrono::duration<double, std::micro>(endQ - startQ).count();

            std::cout << "\n--- COMPARATIVE ANALYSIS RESULTS ---\n";
            std::cout << "Array size (N): " << sequenceSize << "\n";
            std::cout << "Algorithm B (Binary Search): " << timeB << " us (position: " << posB << ")\n";
            std::cout << "Algorithm Q (Quick Sequential Search): " << timeQ << " us (position: " << posQ << ")\n";
            break;
        }
        case 6:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}