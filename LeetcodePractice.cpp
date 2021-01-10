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


