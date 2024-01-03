package day57

/*
@author chris
@time 2024-1-3
@see https://leetcode.cn/problems/longest-palindromic-subsequence/submissions/
*/
// 子序列可以不连续
func longestPalindromeSubseq(s string) int {
	// dp 子序列为回文字符串，最大长度
	dp := make([][]int, len(s))
	for i := range dp {
		dp[i] = make([]int, len(s))
		dp[i][i] = 1 //< 只有一个字符相等时,长度为1
	}

	// 头指针  下->上
	for i := len(s) - 1; i >= 0; i-- {
		// 尾指针要大于i。左->右
		for j := i + 1; j < len(s); j++ {
			// 相等 子串长度+2
			if s[i] == s[j] {
				dp[i][j] = dp[i+1][j-1] + 2
			} else {
				// 不相等，保持上一个状态
				dp[i][j] = max(dp[i+1][j], dp[i][j-1])
			}
		}
	}
	return dp[0][len(s)-1]
}
