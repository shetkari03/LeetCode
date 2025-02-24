
class Solution {
    vector<int> bob_path;

    bool path_to_bob(unordered_map<int, vector<int>>& mp, vector<int>& visited, vector<int>& curr, int node, int& bob) {
        curr.push_back(node);

        if (node == bob) {
            bob_path = curr;
            return true;
        }

        for (auto it : mp[node]) {
            if (visited[it] == 0) {
                visited[it] = 1;
                if (path_to_bob(mp, visited, curr, it, bob)) {
                    return true;
                }
                visited[it] = 0;
            }
        }
        curr.pop_back();
        return false;
    }

    int helper(unordered_map<int, vector<int>>& mp, vector<int>& amount, int bob, vector<int>& isLeaf) {
        int size = amount.size();
        unordered_map<int, int> bob_time_stamp;
        for (int i = 0; i < bob_path.size(); i++) {
            bob_time_stamp[bob_path[i]] = i;
        }

        int maxi = INT_MIN;
        queue<vector<int>> q;
        vector<int> visited(size, 0);
        q.push({0, 0, amount[0]});
        visited[0] = 1;

        while (!q.empty()) {
            int level_size = q.size();
            while (level_size--) {
                auto front = q.front();
                q.pop();
                int curr_node = front[0];
                int curr_time = front[1];
                int curr_score = front[2];

                if (isLeaf[curr_node]) {
                    maxi = max(maxi, curr_score);
                    continue;
                }

                for (int neighbor : mp[curr_node]) {
                    if (visited[neighbor]) continue;

                    int new_time = curr_time + 1;
                    int new_score = curr_score;

                    if (bob_time_stamp.find(neighbor) != bob_time_stamp.end()) {
                        int bob_time = bob_time_stamp[neighbor];
                        if (bob_time < new_time) {
                            // Bob arrived earlier, Alice gets nothing
                        } else if (bob_time > new_time) {
                            new_score += amount[neighbor];
                        } else {
                            new_score += amount[neighbor] / 2;
                        }
                    } else {
                        new_score += amount[neighbor];
                    }

                    visited[neighbor] = 1;
                    q.push({neighbor, new_time, new_score});
                }
            }
        }

        return maxi;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int size = amount.size();
        unordered_map<int, vector<int>> undirected_map;
        vector<int> visited(size, 0);
        vector<int> isLeaf(size, 0);

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            undirected_map[a].push_back(b);
            undirected_map[b].push_back(a);
        }

        for (int i = 0; i < size; ++i) {
            if (i != 0 && undirected_map[i].size() == 1) {
                isLeaf[i] = 1;
            }
        }

        bob_path.clear();
        vector<int> curr;
        visited[0] = 1;
        path_to_bob(undirected_map, visited, curr, 0, bob);
        reverse(bob_path.begin(), bob_path.end());

        return helper(undirected_map, amount, bob, isLeaf);
    }
};