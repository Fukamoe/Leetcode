//class Solution {
//private:
//    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
//
//public:
//    int slidingPuzzle(vector<vector<int>>& board) {
//        // 枚举 status 通过一次交换操作得到的状态
//        auto get = [&](string& status) -> vector<string> {
//            vector<string> ret;
//            int x = status.find('0');
//            for (int y: neighbors[x]) {
//                swap(status[x], status[y]);
//                ret.push_back(status);
//                swap(status[x], status[y]);
//            }
//            return ret;
//        };
//
//        string initial;
//        for (int i = 0; i < 2; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                initial += char(board[i][j] + '0');
//            }
//        }
//        if (initial == "123450") {
//            return 0;
//        }
//
//        queue<pair<string, int>> q;
//        q.emplace(initial, 0);
//        unordered_set<string> seen = {initial};
//
//        while (!q.empty()) {
//            auto [status, step] = q.front();
//            q.pop();
//            for (auto&& next_status: get(status)) {
//                if (!seen.count(next_status)) {
//                    if (next_status == "123450") {
//                        return step + 1;
//                    }
//                    q.emplace(next_status, step + 1);
//                    seen.insert(move(next_status));
//                }
//            }
//        }
//
//        return -1;
//    }
//};
//class Solution {
//    pair<int, int> id2rc(int id, int n) {
//        int r = (id - 1) / n, c = (id - 1) % n;
//        if (r % 2 == 1) {
//            c = n - 1 - c;
//        }
//        return {n - 1 - r, c};
//    }
//
//public:
//    int snakesAndLadders(vector<vector<int>> &board) {
//        int n = board.size();
//        vector<int> vis(n * n + 1);
//        queue<pair<int, int>> q;
//        q.emplace(1, 0);
//        while (!q.empty()) {
//            auto p = q.front();
//            q.pop();
//            for (int i = 1; i <= 6; ++i) {
//                int nxt = p.first + i;
//                if (nxt > n * n) { // 超出边界
//                    break;
//                }
//                auto rc = id2rc(nxt, n); // 得到下一步的行列
//                if (board[rc.first][rc.second] > 0) { // 存在蛇或梯子
//                    nxt = board[rc.first][rc.second];
//                }
//                if (nxt == n * n) { // 到达终点
//                    return p.second + 1;
//                }
//                if (!vis[nxt]) {
//                    vis[nxt] = true;
//                    q.emplace(nxt, p.second + 1); // 扩展新状态
//                }
//            }
//        }
//        return -1;
//    }
//};
//class Solution {
//public:
//    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
//        if (source == target) {
//            return 0;
//        }
//
//        int n = routes.size();
//        vector<vector<int>> edge(n, vector<int>(n));
//        unordered_map<int, vector<int>> rec;
//        for (int i = 0; i < n; i++) {
//            for (int site : routes[i]) {
//                for (int j : rec[site]) {
//                    edge[i][j] = edge[j][i] = true;
//                }
//                rec[site].push_back(i);
//            }
//        }
//
//        vector<int> dis(n, -1);
//        queue<int> que;
//        for (int bus : rec[source]) {
//            dis[bus] = 1;
//            que.push(bus);
//        }
//        while (!que.empty()) {
//            int x = que.front();
//            que.pop();
//            for (int y = 0; y < n; y++) {
//                if (edge[x][y] && dis[y] == -1) {
//                    dis[y] = dis[x] + 1;
//                    que.push(y);
//                }
//            }
//        }
//
//        int ret = INT_MAX;
//        for (int bus : rec[target]) {
//            if (dis[bus] != -1) {
//                ret = min(ret, dis[bus]);
//            }
//        }
//        return ret == INT_MAX ? -1 : ret;
//    }
//};
