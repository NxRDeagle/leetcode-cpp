#include <iostream>
#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> res(amount + 1, amount + 1);
        res[0] = 0;

        int diff;
        for (int i = 1; i <= amount; ++i) {

            for (int coin : coins) {
                diff = i - coin;
                if (diff >= 0)
                    res[i] = std::min(res[i], res[diff] + 1);
            }
        }

        return res[amount] > amount ? -1 : res[amount];
    }
};

int main() {
    Solution* sl = new Solution();
    auto vec = std::vector<int>{ 1, 2, 5 };
    sl->coinChange(vec, 11);
}

//You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//
//Return the fewest number of coins that you need to make up that amount.If that amount of money cannot be made up by any combination of the coins, return -1.
//
//You may assume that you have an infinite number of each kind of coin.
//
//
//
//Example 1:
//
//Input: coins = [1, 2, 5], amount = 11
//Output : 3
//Explanation : 11 = 5 + 5 + 1
//Example 2 :
//
//    Input : coins = [2], amount = 3
//    Output : -1
//    Example 3 :
//
//    Input : coins = [1], amount = 0
//    Output : 0
//
//
//    Constraints :
//
//    1 <= coins.length <= 12
//    1 <= coins[i] <= 2^31 - 1
//    0 <= amount <= 10^4