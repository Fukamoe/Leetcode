// LeetcodePractice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <deque>

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

int main()
{
	for (int i = 0; i < 31; ++i)
		std::cout << fib(i) << std::endl;
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

int fib(int n)
{
	double d = sqrt(5);
	return (pow((1 + d) / 2, n) - pow((1 - d) / 2, n)) / d;
}
