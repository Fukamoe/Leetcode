﻿// LeetcodePractice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class DisjointSetUnion {
private:
	vector<int> f, rank;
	int n;

public:
	DisjointSetUnion(int _n) {
		n = _n;
		rank.resize(n, 1);
		f.resize(n);
		for (int i = 0; i < n; i++) {
			f[i] = i;
		}
	}

	int find(int x) {
		return f[x] == x ? x : f[x] = find(f[x]);
	}

	void unionSet(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) {
			return;
		}
		if (rank[fx] < rank[fy]) {
			swap(fx, fy);
		}
		rank[fx] += rank[fy];
		f[fy] = fx;
	}
};


bool canPlaceFlowers(vector<int>& flowerbed, int n);
vector<int> maxSlidingWindow(vector<int>& nums, int k);
ListNode* partition(ListNode* head, int x);
int fib(int n);
vector<vector<int>> largeGroupPositions(string s);
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);
int findCircleNum(vector<vector<int>>& isConnected);
void dfs(vector<vector<int>>& isConnected, vector<int>& isProvince, int provinces, int i);
void rotate(vector<int>& nums, int k);
int maxProfit(vector<int>& prices);
vector<string> summaryRanges(vector<int>& nums);
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs);
vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems);
vector<int> topSort(vector<int>& deg, vector<vector<int>>& graph, vector<int>& items);
int Find(vector<int>& parent, int index);
void Union(vector<int>& parent, int index1, int index2);
vector<int> findRedundantConnection(vector<vector<int>>& edges);
vector<bool> prefixesDivBy5(vector<int>& A);
void dfs(int x, vector<vector<int>>& edge, vector<int>& vis);
int removeStones(vector<vector<int>>& stones);
int maximumProduct(vector<int>& nums);


int main()
{
	std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

//01-01  605 种花问题
bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
	if (!n)
		return true;
	int nLen = flowerbed.size();
	if (1 == nLen && !flowerbed.front() && 1 == n)
		return true;
	flowerbed.insert(flowerbed.begin(), 0);
	flowerbed.push_back(0);
	nLen += 1;;
	for (int i = 1; i < nLen && 0 < n; ++i)
	{
		if (!flowerbed[i] && !flowerbed[i - 1] && !flowerbed[i + 1])
		{
			--n;
			flowerbed[i] = 1;
		}
	}
	return !n;
}

//01-02  239 滑动窗口最大值
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> vReturn;
	deque<int> dqIndex;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (!dqIndex.empty() && i - k == dqIndex.front())
			dqIndex.pop_front();
		while (!dqIndex.empty() && nums[dqIndex.back()] < nums[i])
			dqIndex.pop_back();

		dqIndex.push_back(i);

		if (i > k - 2)
			vReturn.push_back(nums[dqIndex.front()]);
	}
	return vReturn;
}

//01-03  86 分隔列表
ListNode* partition(ListNode* head, int x)
{
	ListNode* Front = new ListNode(0);
	ListNode* Head = Front;
	ListNode* Back = new ListNode(0);
	ListNode* End = Back;
	while (nullptr != head)
	{
		if (x > head->val)
		{
			Front->next = head;
			Front = Front->next;
		}
		else
		{
			Back->next = head;
			Back = Back->next;
		}
		head = head->next;
	}
	Back->next = nullptr;
	Front->next = End->next;
	return Head->next;
}
// 509 斐波那契数
int fib(int n)
{
	double d = sqrt(5);
	return (pow((1 + d) / 2, n) - pow((1 - d) / 2, n)) / d;
}
// 830 较大分组的位置
vector<vector<int>> largeGroupPositions(string s)
{
	vector<vector<int>> vRet;
	s.append("1");
	int count = 1;
	for (int i = 0; i < s.length() - 1; ++i)
	{
		if (s[i] != s[i + 1])
		{
			if (2 < count)
				vRet.push_back({ i - count + 1, i });
			count = 1;
		}
		else
			++count;
	}
	return vRet;
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
		int nvars = 0;
		unordered_map<string, int> variables;

		int n = equations.size();
		for (int i = 0; i < n; i++) {
			if (variables.find(equations[i][0]) == variables.end()) {
				variables[equations[i][0]] = nvars++;
			}
			if (variables.find(equations[i][1]) == variables.end()) {
				variables[equations[i][1]] = nvars++;
			}
		}

		vector<vector<pair<int, double>>> edges(nvars);
		for (int i = 0; i < n; i++) {
			int va = variables[equations[i][0]], vb = variables[equations[i][1]];
			edges[va].push_back(make_pair(vb, values[i]));
			edges[vb].push_back(make_pair(va, 1.0 / values[i]));
		}

		vector<double> ret;
		for (const auto& q : queries) {
			double result = -1.0;
			if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()) {
				int ia = variables[q[0]], ib = variables[q[1]];
				if (ia == ib) {
					result = 1.0;
				}
				else {
					queue<int> points;
					points.push(ia);
					vector<double> ratios(nvars, -1.0);
					ratios[ia] = 1.0;

					while (!points.empty() && ratios[ib] < 0) {
						int x = points.front();
						points.pop();

						for (const auto edge : edges[x]) {
							if (ratios[edge.first] < 0) {
								ratios[edge.first] = ratios[x] * edge.second;
								points.push(edge.first);
							}
						}
					}
					result = ratios[ib];
				}
			}
			ret.push_back(result);
		}
		return ret;
}

int findCircleNum(vector<vector<int>>& isConnected)
{
	int nLen = isConnected.size();
	vector<int> isProvince(nLen);
	int Province = 0;
	for (int i = 0; i < nLen; ++i)
	{
		if (!isProvince[i])
		{
			dfs(isConnected, isProvince, nLen, i);
			++Province;
		}
	}
	return Province;
}

void dfs(vector<vector<int>>& isConnected, vector<int>& isProvince, int provinces, int i)
{
	for (int j = 0; j < provinces; ++j)
	{
		if (isConnected[i][j] == 1 && !isProvince[j])
		{
			isProvince[j] = 1;
			dfs(isConnected, isProvince, provinces, j);
		}
	}
}

void rotate(vector<int>& nums, int k)
{
	k = k % nums.size();
	reverse(nums.begin(), nums.begin() + nums.size() - k);
	reverse(nums.begin() + nums.size() - k, nums.end());
	reverse(nums.begin(), nums.end());
}

int maxProfit(vector<int>& prices)
{
	int Buy_1 = INT32_MIN, Sell_1 = INT32_MIN, Buy_2 = 0, Sell_2 = 0;

		for (auto p : prices)
		{
			Buy_1 = max(Buy_1, -p);
			Sell_1 = max(Sell_1, Buy_1 + p);
			Buy_2 = max(Buy_2, Sell_1 - p);
			Sell_2 = max(Sell_2, Buy_2 + p);
		}
		return Sell_2;
}

vector<string> summaryRanges(vector<int>& nums)
{
		vector<string> vRet;
		int nLen = nums.size();
		int nStart = 0;
		for (int i = 0; i < nLen; ++i)
		{
			if (i + 1 == nLen || nums[i] + 1 != nums[i + 1])
			{
				vRet.push_back(to_string(nums[nStart]) + (nStart == i ? "" : "->" + to_string(nums[i])));
				nStart = i + 1;
			}
		}
		return vRet;
}

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
{
	DisjointSetUnion dsu(s.length());
	for (auto& it : pairs) {
		dsu.unionSet(it[0], it[1]);
	}
	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < s.length(); i++) {
		mp[dsu.find(i)].emplace_back(s[i]);
	}
	for (auto& m : mp) {
		sort(m.second.begin(), m.second.end(), greater<int>());
	}
	for (int i = 0; i < s.length(); i++) {
		int x = dsu.find(i);
		s[i] = mp[x].back();
		mp[x].pop_back();
	}
	return s;
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)
{
	vector<vector<int>> groupItem(n + m);

	// 组间和组内依赖图
	vector<vector<int>> groupGraph(n + m);
	vector<vector<int>> itemGraph(n);

	// 组间和组内入度数组
	vector<int> groupDegree(n + m, 0);
	vector<int> itemDegree(n, 0);

	vector<int> id;
	for (int i = 0; i < n + m; ++i) {
		id.emplace_back(i);
	}

	int leftId = m;
	// 给未分配的 item 分配一个 groupId
	for (int i = 0; i < n; ++i) {
		if (group[i] == -1) {
			group[i] = leftId;
			leftId += 1;
		}
		groupItem[group[i]].emplace_back(i);
	}
	// 依赖关系建图
	for (int i = 0; i < n; ++i) {
		int curGroupId = group[i];
		for (auto& item : beforeItems[i]) {
			int beforeGroupId = group[item];
			if (beforeGroupId == curGroupId) {
				itemDegree[i] += 1;
				itemGraph[item].emplace_back(i);
			}
			else {
				groupDegree[curGroupId] += 1;
				groupGraph[beforeGroupId].emplace_back(curGroupId);
			}
		}
	}

	// 组间拓扑关系排序
	vector<int> groupTopSort = topSort(groupDegree, groupGraph, id);
	if (groupTopSort.size() == 0) {
		return vector<int>{};
	}
	vector<int> ans;
	// 组内拓扑关系排序
	for (auto& curGroupId : groupTopSort) {
		int size = groupItem[curGroupId].size();
		if (size == 0) {
			continue;
		}
		vector<int> res = topSort(itemDegree, itemGraph, groupItem[curGroupId]);
		if (res.size() == 0) {
			return vector<int>{};
		}
		for (auto& item : res) {
			ans.emplace_back(item);
		}
	}
	return ans;
}

vector<int> topSort(vector<int>& deg, vector<vector<int>>& graph, vector<int>& items)
{
	queue<int> Q;
	for (auto& item : items) {
		if (deg[item] == 0) {
			Q.push(item);
		}
	}
	vector<int> res;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		res.emplace_back(u);
		for (auto& v : graph[u]) {
			if (--deg[v] == 0) {
				Q.push(v);
			}
		}
	}
	return res.size() == items.size() ? res : vector<int>{};
}

int Find(vector<int>& parent, int index)
{
	if (parent[index] != index) {
		parent[index] = Find(parent, parent[index]);
	}
	return parent[index];
}

void Union(vector<int>& parent, int index1, int index2)
{
	parent[Find(parent, index1)] = Find(parent, index2);
}

vector<int> findRedundantConnection(vector<vector<int>>& edges)
{
	int nodesCount = edges.size();
	vector<int> parent(nodesCount + 1);
	for (int i = 1; i <= nodesCount; ++i) {
		parent[i] = i;
	}
	for (auto& edge : edges) {
		int node1 = edge[0], node2 = edge[1];
		if (Find(parent, node1) != Find(parent, node2)) {
			Union(parent, node1, node2);
		}
		else {
			return edge;
		}
	}
	return vector<int>{};
}

vector<bool> prefixesDivBy5(vector<int>& A)
{
	vector<bool> list;
	int prefix = 0;
	int length = A.size();
	for (int i = 0; i < length; i++) {
		prefix = ((prefix << 1) + A[i]) % 5;
		list.emplace_back(prefix == 0);
	}
	return list;
}

void dfs(int x, vector<vector<int>>& edge, vector<int>& vis)
{
	vis[x] = true;
	for (auto& y : edge[x]) {
		if (!vis[y]) {
			dfs(y, edge, vis);
		}
	}
}

int removeStones(vector<vector<int>>& stones)
{
	int n = stones.size();
	vector<vector<int>> edge(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
				edge[i].push_back(j);
			}
		}
	}
	vector<int> vis(n);
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			num++;
			dfs(i, edge, vis);
		}
	}
	return n - num;
}

int maximumProduct(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int n = nums.size();
	return max(nums[0] * nums[1] * nums[n - 1], nums[n - 3] * nums[n - 2] * nums[n - 1]);
}

//
//class UnionFind {
//private:
//	vector<int> f, sz;
//public:
//	UnionFind(int n) : f(n), sz(n) {
//		for (int i = 0; i < n; i++) {
//			f[i] = i;
//			sz[i] = 1;
//		}
//	}
//
//	int find(int x) {
//		if (f[x] == x) {
//			return x;
//		}
//		int newf = find(f[x]);
//		f[x] = newf;
//		return f[x];
//	}
//
//	void merge(int x, int y) {
//		int fx = find(x), fy = find(y);
//		if (fx == fy) {
//			return;
//		}
//		f[fx] = fy;
//		sz[fy] += sz[fx];
//	}
//
//	int size(int x) {
//		return sz[find(x)];
//	}
//};
//
//class Solution {
//public:
//	vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
//		int h = grid.size(), w = grid[0].size();
//
//		UnionFind uf(h * w + 1);
//		vector<vector<int>> status = grid;
//		for (int i = 0; i < hits.size(); i++) {
//			status[hits[i][0]][hits[i][1]] = 0;
//		}
//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++) {
//				if (status[i][j] == 1) {
//					if (i == 0) {
//						uf.merge(h * w, i * w + j);
//					}
//					if (i > 0 && status[i - 1][j] == 1) {
//						uf.merge(i * w + j, (i - 1) * w + j);
//					}
//					if (j > 0 && status[i][j - 1] == 1) {
//						uf.merge(i * w + j, i * w + j - 1);
//					}
//				}
//			}
//		}
//		const vector<pair<int, int>> directions{ {0, 1},{1, 0},{0, -1},{-1, 0} };
//		vector<int> ret(hits.size(), 0);
//		for (int i = hits.size() - 1; i >= 0; i--) {
//			int r = hits[i][0], c = hits[i][1];
//			if (grid[r][c] == 0) {
//				continue;
//			}
//			int prev = uf.size(h * w);
//
//			if (r == 0) {
//				uf.merge(c, h * w);
//			}
//			for (const auto [dr, dc] : directions) {
//				int nr = r + dr, nc = c + dc;
//
//				if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
//					if (status[nr][nc] == 1) {
//						uf.merge(r * w + c, nr * w + nc);
//					}
//				}
//			}
//			int size = uf.size(h * w);
//			ret[i] = max(0, size - prev - 1);
//			status[r][c] = 1;
//		}
//		return ret;
//	}
//};
//class Solution {
//public:
//	bool checkStraightLine(vector<vector<int>>& coordinates) {
//		int deltaX = coordinates[0][0], deltaY = coordinates[0][1];
//		int n = coordinates.size();
//		for (int i = 0; i < n; ++i) {
//			coordinates[i][0] -= deltaX;
//			coordinates[i][1] -= deltaY;
//		}
//		int A = coordinates[1][1], B = -coordinates[1][0];
//		for (int i = 2; i < n; ++i) {
//			int x = coordinates[i][0], y = coordinates[i][1];
//			if (A * x + B * y != 0) {
//				return false;
//			}
//		}
//		return true;
//	}
//};
//class UnionFind {
//public:
//	vector<int> parent;
//
//	UnionFind(int n) {
//		parent.resize(n);
//		for (int i = 0; i < n; i++) {
//			parent[i] = i;
//		}
//	}
//
//	void unionSet(int index1, int index2) {
//		parent[find(index2)] = find(index1);
//	}
//
//	int find(int index) {
//		if (parent[index] != index) {
//			parent[index] = find(parent[index]);
//		}
//		return parent[index];
//	}
//};
//
//class Solution {
//public:
//	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//		map<string, int> emailToIndex;
//		map<string, string> emailToName;
//		int emailsCount = 0;
//		for (auto& account : accounts) {
//			string& name = account[0];
//			int size = account.size();
//			for (int i = 1; i < size; i++) {
//				string& email = account[i];
//				if (!emailToIndex.count(email)) {
//					emailToIndex[email] = emailsCount++;
//					emailToName[email] = name;
//				}
//			}
//		}
//		UnionFind uf(emailsCount);
//		for (auto& account : accounts) {
//			string& firstEmail = account[1];
//			int firstIndex = emailToIndex[firstEmail];
//			int size = account.size();
//			for (int i = 2; i < size; i++) {
//				string& nextEmail = account[i];
//				int nextIndex = emailToIndex[nextEmail];
//				uf.unionSet(firstIndex, nextIndex);
//			}
//		}
//		map<int, vector<string>> indexToEmails;
//		for (auto& [email, _] : emailToIndex) {
//			int index = uf.find(emailToIndex[email]);
//			vector<string>& account = indexToEmails[index];
//			account.emplace_back(email);
//			indexToEmails[index] = account;
//		}
//		vector<vector<string>> merged;
//		for (auto& [_, emails] : indexToEmails) {
//			sort(emails.begin(), emails.end());
//			string& name = emailToName[emails[0]];
//			vector<string> account;
//			account.emplace_back(name);
//			for (auto& email : emails) {
//				account.emplace_back(email);
//			}
//			merged.emplace_back(account);
//		}
//		return merged;
//	}
//};
//class DisjointSetUnion {
//private:
//	vector<int> f, rank;
//	int n;
//
//public:
//	DisjointSetUnion(int _n) {
//		n  = _n;
//		rank.resize(n, 1);
//		f.resize(n);
//		for (int i  = 0; i  < n; i++) {
//			f[i] = i;
//		}
//	}
//
//	int find(int x) {
//		return f[x] == x  ? x  : f[x] = find(f[x]);
//	}
//
//	int unionSet(int x, int y) {
//		int fx  = find(x), fy  = find(y);
//		if (fx  == fy) {
//			return false;
//		}
//		if (rank[fx] < rank[fy]) {
//			swap(fx, fy);
//		}
//		rank[fx] += rank[fy];
//		f[fy] = fx;
//		return true;
//	}
//};
//
//struct Edge {
//	int len, x, y;
//	Edge(int len, int x, int y) : len(len), x(x), y(y) {
//	}
//};
//
//class Solution {
//public:
//	int minCostConnectPoints(vector<vector<int>>&points) {
//		auto dist  = [&](int x, int y) -> int  {
//			return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
//		};
//		int n  = points.size();
//		DisjointSetUnion dsu(n);
//		vector<Edge> edges;
//		for (int i  = 0; i  < n; i++) {
//			for (int j  = i  + 1; j  < n; j++) {
//				edges.emplace_back(dist(i, j), i, j);
//			}
//		}
//		sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int  { return a.len  < b.len; });
//		int ret  = 0, num  = 1;
//		for (auto & [len, x, y] : edges) {
//			if (dsu.unionSet(x, y)) {
//				ret  += len;
//				num++;
//				if (num  == n) {
//					break;
//				}
//			}
//		}
//		return ret;
//	}
//};
// 并查集模板
//class UnionFind {
//public:
//	vector<int> parent;
//	vector<int> size;
//	int n;
//	// 当前连通分量数目
//	int setCount;
//
//public:
//	UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1) {
//		iota(parent.begin(), parent.end(), 0);
//	}
//
//	int findset(int x) {
//		return parent[x] == x ? x : parent[x] = findset(parent[x]);
//	}
//
//	bool unite(int x, int y) {
//		x = findset(x);
//		y = findset(y);
//		if (x == y) {
//			return false;
//		}
//		if (size[x] < size[y]) {
//			swap(x, y);
//		}
//		parent[y] = x;
//		size[x] += size[y];
//		--setCount;
//		return true;
//	}
//
//	bool connected(int x, int y) {
//		x = findset(x);
//		y = findset(y);
//		return x == y;
//	}
//};
//
//class Solution {
//public:
//	vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
//		int m = edges.size();
//		for (int i = 0; i < m; ++i) {
//			edges[i].push_back(i);
//		}
//		sort(edges.begin(), edges.end(), [](const auto& u, const auto& v) {
//			return u[2] < v[2];
//			});
//
//		// 计算 value
//		UnionFind uf_std(n);
//		int value = 0;
//		for (int i = 0; i < m; ++i) {
//			if (uf_std.unite(edges[i][0], edges[i][1])) {
//				value += edges[i][2];
//			}
//		}
//
//		vector<vector<int>> ans(2);
//
//		for (int i = 0; i < m; ++i) {
//			// 判断是否是关键边
//			UnionFind uf(n);
//			int v = 0;
//			for (int j = 0; j < m; ++j) {
//				if (i != j && uf.unite(edges[j][0], edges[j][1])) {
//					v += edges[j][2];
//				}
//			}
//			if (uf.setCount != 1 || (uf.setCount == 1 && v > value)) {
//				ans[0].push_back(edges[i][3]);
//				continue;
//			}
//
//			// 判断是否是伪关键边
//			uf = UnionFind(n);
//			uf.unite(edges[i][0], edges[i][1]);
//			v = edges[i][2];
//			for (int j = 0; j < m; ++j) {
//				if (i != j && uf.unite(edges[j][0], edges[j][1])) {
//					v += edges[j][2];
//				}
//			}
//			if (v == value) {
//				ans[1].push_back(edges[i][3]);
//			}
//		}
//
//		return ans;
//	}
//};

//class Solution {
//public:
//	vector<int> addToArrayForm(vector<int>& A, int K) {
//		vector<int> res;
//		int n = A.size();
//		for (int i = n - 1; i >= 0; --i) {
//			int sum = A[i] + K % 10;
//			K /= 10;
//			if (sum >= 10) {
//				K++;
//				sum -= 10;
//			}
//			res.push_back(sum);
//		}
//		for (; K > 0; K /= 10) {
//			res.push_back(K % 10);
//		}
//		reverse(res.begin(), res.end());
//		return res;
//	}
//};
//class Solution {
//private:
//	vector<vector<int>> edges;
//	vector<int> used;
//
//public:
//	void dfs(int u) {
//		used[u] = true;
//		for (int v : edges[u]) {
//			if (!used[v]) {
//				dfs(v);
//			}
//		}
//	}
//
//	int makeConnected(int n, vector<vector<int>>& connections) {
//		if (connections.size() < n - 1) {
//			return -1;
//		}
//
//		edges.resize(n);
//		for (const auto& conn : connections) {
//			edges[conn[0]].push_back(conn[1]);
//			edges[conn[1]].push_back(conn[0]);
//		}
//
//		used.resize(n);
//		int ans = 0;
//		for (int i = 0; i < n; ++i) {
//			if (!used[i]) {
//				dfs(i);
//				++ans;
//			}
//		}
//
//		return ans - 1;
//	}
//};
//class Solution {
//public:
//	int findLengthOfLCIS(vector<int>& nums) {
//		int ans = 0;
//		int n = nums.size();
//		int start = 0;
//		for (int i = 0; i < n; i++) {
//			if (i > 0 && nums[i] <= nums[i - 1]) {
//				start = i;
//			}
//			ans = max(ans, i - start + 1);
//		}
//		return ans;
//	}
//};
//class Solution {
//public:
//	int find(vector<int>& f, int x) {
//		if (f[x] == x) {
//			return x;
//		}
//		int fa = find(f, f[x]);
//		f[x] = fa;
//		return fa;
//	}
//
//	void merge(vector<int>& f, int x, int y) {
//		int fx = find(f, x);
//		int fy = find(f, y);
//		f[fx] = fy;
//	}
//
//	int regionsBySlashes(vector<string>& grid) {
//		int n = grid.size();
//		vector<int> f(n * n * 4);
//		for (int i = 0; i < n * n * 4; i++) {
//			f[i] = i;
//		}
//
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				int idx = i * n + j;
//				if (i < n - 1) {
//					int bottom = idx + n;
//					merge(f, idx * 4 + 2, bottom * 4);
//				}
//				if (j < n - 1) {
//					int right = idx + 1;
//					merge(f, idx * 4 + 1, right * 4 + 3);
//				}
//				if (grid[i][j] == '/') {
//					merge(f, idx * 4, idx * 4 + 3);
//					merge(f, idx * 4 + 1, idx * 4 + 2);
//				}
//				else if (grid[i][j] == '\\') {
//					merge(f, idx * 4, idx * 4 + 1);
//					merge(f, idx * 4 + 2, idx * 4 + 3);
//				}
//				else {
//					merge(f, idx * 4, idx * 4 + 1);
//					merge(f, idx * 4 + 1, idx * 4 + 2);
//					merge(f, idx * 4 + 2, idx * 4 + 3);
//				}
//			}
//		}
//
//		unordered_set<int> fathers;
//		for (int i = 0; i < n * n * 4; i++) {
//			int fa = find(f, i);
//			fathers.insert(fa);
//		}
//		return fathers.size();
//	}
//};

//class Solution {
//public:
//	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//		vector<int> num(100);
//		int ret = 0;
//		for (auto& it : dominoes) {
//			int val = it[0] < it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
//			ret += num[val];
//			num[val]++;
//		}
//		return ret;
//	}
//};
// 并查集模板
//class UnionFind {
//public:
//	vector<int> parent;
//	vector<int> size;
//	int n;
//	// 当前连通分量数目
//	int setCount;
//
//public:
//	UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1) {
//		iota(parent.begin(), parent.end(), 0);
//	}
//
//	int findset(int x) {
//		return parent[x] == x ? x : parent[x] = findset(parent[x]);
//	}
//
//	bool unite(int x, int y) {
//		x = findset(x);
//		y = findset(y);
//		if (x == y) {
//			return false;
//		}
//		if (size[x] < size[y]) {
//			swap(x, y);
//		}
//		parent[y] = x;
//		size[x] += size[y];
//		--setCount;
//		return true;
//	}
//
//	bool connected(int x, int y) {
//		x = findset(x);
//		y = findset(y);
//		return x == y;
//	}
//};
//
//class Solution {
//public:
//	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
//		UnionFind ufa(n), ufb(n);
//		int ans = 0;
//
//		// 节点编号改为从 0 开始
//		for (auto& edge : edges) {
//			--edge[1];
//			--edge[2];
//		}
//
//		// 公共边
//		for (const auto& edge : edges) {
//			if (edge[0] == 3) {
//				if (!ufa.unite(edge[1], edge[2])) {
//					++ans;
//				}
//				else {
//					ufb.unite(edge[1], edge[2]);
//				}
//			}
//		}
//
//		// 独占边
//		for (const auto& edge : edges) {
//			if (edge[0] == 1) {
//				// Alice 独占边
//				if (!ufa.unite(edge[1], edge[2])) {
//					++ans;
//				}
//			}
//			else if (edge[0] == 2) {
//				// Bob 独占边
//				if (!ufb.unite(edge[1], edge[2])) {
//					++ans;
//				}
//			}
//		}
//
//		if (ufa.setCount != 1 || ufb.setCount != 1) {
//			return -1;
//		}
//		return ans;
//	}
//};
//class Solution {
//public:
//	int pivotIndex(vector<int>& nums) {
//		int total = accumulate(nums.begin(), nums.end(), 0);
//		int sum = 0;
//		for (int i = 0; i < nums.size(); ++i) {
//			if (2 * sum + nums[i] == total) {
//				return i;
//			}
//			sum += nums[i];
//		}
//		return -1;
//	}
//};
//class Solution {
//private:
//	static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//
//public:
//	int minimumEffortPath(vector<vector<int>>& heights) {
//		int m = heights.size();
//		int n = heights[0].size();
//		int left = 0, right = 999999, ans = 0;
//		while (left <= right) {
//			int mid = (left + right) / 2;
//			queue<pair<int, int>> q;
//			q.emplace(0, 0);
//			vector<int> seen(m * n);
//			seen[0] = 1;
//			while (!q.empty()) {
//				auto [x, y] = q.front();
//				q.pop();
//				for (int i = 0; i < 4; ++i) {
//					int nx = x + dirs[i][0];
//					int ny = y + dirs[i][1];
//					if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny] && abs(heights[x][y] - heights[nx][ny]) <= mid) {
//						q.emplace(nx, ny);
//						seen[nx * n + ny] = 1;
//					}
//				}
//			}
//			if (seen[m * n - 1]) {
//				ans = mid;
//				right = mid - 1;
//			}
//			else {
//				left = mid + 1;
//			}
//		}
//		return ans;
//	}
//};
// 优先队列中的数据结构。其中 (i,j) 代表坐标，val 代表水位。
//struct Entry {
//	int i;
//	int j;
//	int val;
//	bool operator<(const Entry& other) const {
//		return this->val > other.val;
//	}
//	Entry(int ii, int jj, int val) : i(ii), j(jj), val(val) {}
//};
//
//class Solution {
//public:
//	int swimInWater(vector<vector<int>>& grid) {
//		int n = grid.size();
//		priority_queue<Entry, vector<Entry>, function<bool(const Entry& x, const Entry& other)>> pq(&Entry::operator<);
//		vector<vector<int>> visited(n, vector<int>(n, 0));
//
//		pq.push(Entry(0, 0, grid[0][0]));
//		int ret = 0;
//		vector<pair<int, int>> directions{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
//		while (!pq.empty()) {
//			Entry x = pq.top();
//			pq.pop();
//			if (visited[x.i][x.j] == 1) {
//				continue;
//			}
//
//			visited[x.i][x.j] = 1;
//			ret = max(ret, grid[x.i][x.j]);
//			if (x.i == n - 1 && x.j == n - 1) {
//				break;
//			}
//
//			for (const auto [di, dj] : directions) {
//				int ni = x.i + di, nj = x.j + dj;
//				if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
//					if (visited[ni][nj] == 0) {
//						pq.push(Entry(ni, nj, grid[ni][nj]));
//					}
//				}
//			}
//		}
//		return ret;
//	}
//};
//class Solution {
//public:
//	vector<int> f;
//
//	int find(int x) {
//		return f[x] == x ? x : f[x] = find(f[x]);
//	}
//
//	bool check(const string& a, const string& b, int len) {
//		int num = 0;
//		for (int i = 0; i < len; i++) {
//			if (a[i] != b[i]) {
//				num++;
//				if (num > 2) {
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//
//	int numSimilarGroups(vector<string>& strs) {
//		int n = strs.size();
//		int m = strs[0].length();
//		f.resize(n);
//		for (int i = 0; i < n; i++) {
//			f[i] = i;
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = i + 1; j < n; j++) {
//				int fi = find(i), fj = find(j);
//				if (fi == fj) {
//					continue;
//				}
//				if (check(strs[i], strs[j], m)) {
//					f[fi] = fj;
//				}
//			}
//		}
//		int ret = 0;
//		for (int i = 0; i < n; i++) {
//			if (f[i] == i) {
//				ret++;
//			}
//		}
//		return ret;
//	}
//};
//
