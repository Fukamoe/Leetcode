import re
from functools import lru_cache
from itertools import product

class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        ans = self.dfs(board, "".join(sorted(hand)))
        return ans if ans <= 5 else -1

    @lru_cache(None)
    def dfs(self, cur_board: str, cur_hand: str):
        if not cur_board:
            return 0
        
        res = 6
        for i, j in product(range(len(cur_board) + 1), range(len(cur_hand))):
            # 第 1 个剪枝条件: 手中颜色相同的球只需要考虑其中一个即可
            if j > 0 and cur_hand[j] == cur_hand[j - 1]:
                continue

            # 第 2 个剪枝条件: 只在连续相同颜色的球的开头位置插入新球
            if i > 0 and cur_board[i - 1] == cur_hand[j]:
                continue

            # 第 3 个剪枝条件: 只考虑放置新球后有可能得到更优解的位置
            #  - 第 1 种情况 : 当前球颜色与后面的球的颜色相同   
            #  - 第 2 种情况 : 当前后颜色相同且与当前颜色不同时候放置球
            choose = False
            if 0 < i < len(cur_board) and cur_board[i - 1] == cur_board[i] and cur_board[i - 1] != cur_hand[j]:
                choose = True
            if i < len(cur_board) and cur_board[i] == cur_hand[j]:
                choose = True
            if choose:
                new_board = self.clean(cur_board[:i] + cur_hand[j] + cur_board[i:])
                new_hand = cur_hand[:j] + cur_hand[j + 1:]
                res = min(res, self.dfs(new_board, new_hand) + 1)
        return res

    @staticmethod
    def clean(s):
        n = 1
        while n:
            s, n = re.subn(r'(.)\1{2,}', '', s)
        return s
