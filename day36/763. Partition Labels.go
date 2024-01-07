/**
 * @date: 2024 Jan 07
 * @time: 22:35
 * @author: Chris
 * @title: 763. Partition Labels
 * @link: https://leetcode.cn/problems/partition-labels/description/
**/

package day36

// 尽可能同一个片段更多的重复字母
// goal： 子串分割点=遍历过的所有字母的出现的最远边界
// 步骤
// 1. 遍历字符串，统计每个字符的最后出现位置
// 2. 再次遍历字符串，找到分割点进行标记
func partitionLabels(s string) []int {
	hash := [26]int{0}
	var res []int

	// 记录每个字符最后出现的位置
	for i := 0; i < len(s); i++ {
		hash[s[i]-'a'] = i
	}
	start := 0
	end := 0 // 标记当前子串右边界｜分割点
	//
	for i := 0; i < len(s); i++ {
		// 找到当前子串中所有字符的最远出现的位置
		end = max(end, hash[s[i]-'a'])
		// 如果所有字符最远出现位置==当前下标，则找到了分割点
		if i == end {
			res = append(res, end-start+1)
			start = i + 1
		}
	}
	return res
}
