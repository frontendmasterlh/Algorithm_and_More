题目描述
给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和。

在此处，环形数组意味着数组的末端将会与开头相连呈环状。（
形式上，当 0 <= i < A.length 时 C[i] = A[i]，而当 i >= 0 时 C[i+A.length] = C[i]）

此外，子数组最多只能包含固定缓冲区 A 中的每个元素一次。
（形式上，对于子数组 C[i], C[i+1], ..., C[j]，不存在 i <= k1, k2 <= j 其中 k1 % A.length = k2 % A.length）

算法
(前缀和，单调队列) O(n)O(n)
将原数组扩充一倍后，这道题可以视为长度最多为 nn 最长连续子序列。先对求前缀和数组 sum。
对于以 ii 结尾的子数组，其最优答案是 sum[i]−min(sum[j]),i−n≤j<isum[i]−min(sum[j]),i−n≤j<i。在所有以 ii 结尾的子数组中找到最大值即为答案。
以上公式可以用单调队列来快速求解。维护一个单调递增的队列，队头元素为最小值，每次循环时首先将不满足长度的队头出队，然后更新当前的答案。
入队时，检查队尾元素与当前 sum[i]sum[i] 值的大小，如果 sum[i]sum[i] 小于等于队尾元素，则队尾元素出队。最后 sum[i]sum[i] 进队。


时间复杂度
每个元素最多进队一次，出队一次，故总时间复杂度为 O(n)O(n)。



// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& A) {
//         int n = A.size(), ans = A[0];

//         vector<int> sum(2 * n + 1, 0);
//         for (int i = 1; i <= 2 * n; i++) {
//             if (i <= n)
//                 sum[i] = sum[i - 1] + A[i - 1];
//             else
//                 sum[i] = sum[i - 1] + A[i - n - 1];
//         }

//         deque<int> q;
//         q.push_back(0);

//         for (int i = 1; i <= 2 * n; i++) {
//             while (!q.empty() && i - q.front() > n)
//                 q.pop_front();

//             ans = max(ans, sum[i] - sum[q.front()]);

//             while (!q.empty() && sum[i] <= sum[q.back()])
//                 q.pop_back();

//             q.push_back(i);
//         }

//         return ans;
//     }
// };

