// LeetcodePractice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
