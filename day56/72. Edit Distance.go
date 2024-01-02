package main

// \brief  最小编辑
func minDistance(word1 string, word2 string) int {
	m, n := len(word1), len(word2)
	dp := make([][]int, m+1)

	for i := range dp {
		dp[i] = make([]int, n+1)
		dp[i][0] = i
	}

	for j := 0; j <= n; j++ {
		dp[0][j] = j
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if word1[i-1] == word2[j-1] { // 不用编辑
				dp[i][j] = dp[i-1][j-1]
			} else { // 增删改， 一个增=另外一个删
				//               改         ，word1增      word2增
				dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
			}
		}
	}
	return dp[m][n]
}
