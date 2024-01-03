package day57

/*
	@auther chris
	@time 2024-1-3
	@see https://leetcode.cn/problems/palindromic-substrings/
*/
// 不相等 false
// 相等
//  1. i==j 同一个字符，回文
//  2. |i-j|==1 aa 也是回文
//  3. i与j相差超过1，需要判断子串是不是
//     比如"abca" s[0] == s[3] 需要查看dp[i+1][j-1]是否为回文
func countSubstrings(s string) int {
	dp := make([][]bool, len(s))
	for i := range dp {
		dp[i] = make([]bool, len(s))
	}

	res := 0

	// 注意顺序，从i+1 到 i， 从j-1到j。从下到上，从左到右
	for i := len(s); i >= 0; i-- {
		for j := i; j < len(s); j++ {
			// 相等             1，2情况     3.情况
			if s[i] == s[j] && (j-i <= 1 || dp[i+1][j-1]) {
				dp[i][j] = true
				res++
			}
		}
	}
	return res
}
