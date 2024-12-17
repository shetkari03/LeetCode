#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max-heap to store the potential increases
        auto cmp = [](const pair<double, pair<int, int>>& a, const pair<double, pair<int, int>>& b) {
            return a.first < b.first; // Max-heap based on the increase
        };
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, decltype(cmp)> maxHeap(cmp);
        
        // Initialize the heap with the initial ratios and potential increases
        for (const auto& cls : classes) {
            int pass = cls[0];
            int total = cls[1];
            double currentRatio = static_cast<double>(pass) / total;
            double potentialIncrease = static_cast<double>(pass + 1) / (total + 1) - currentRatio;
            maxHeap.push({potentialIncrease, {pass, total}});
        }
        
        // Assign extra students
        for (int i = 0; i < extraStudents; ++i) {
            auto top = maxHeap.top();
            maxHeap.pop();
            int pass = top.second.first;
            int total = top.second.second;
            // Update the class with the extra student
            pass++;
            total++;
            // Recalculate the potential increase and push back into the heap
            double newPotentialIncrease = static_cast<double>(pass + 1) / (total + 1) - static_cast<double>(pass) / total;
            maxHeap.push({newPotentialIncrease, {pass, total}});
        }
        
        // Calculate the final average pass ratio
        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            int pass = top.second.first;
            int total = top.second.second;
            totalRatio += static_cast<double>(pass) / total;
        }
        
        return totalRatio / classes.size(); // Return the average
    }
};