/**
 * @date: 2024 Jan 07
 * @time: 23:01
 * @author: Chris
 * @title: 56. Merge Intervals
 * @link: https://leetcode.cn/problems/merge-intervals/description/
**/
package day36

import "sort"

// 合并重叠区间，留下即为非重叠
// 左边界排序
func merge(intervals [][]int) [][]int {
	var res [][]int // 存放不重叠的区间

	// 按照左边界排序
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	// 第一个区间直接放入结果集
	res = append(res, intervals[0])

	for i := 1; i < len(intervals); i++ {
		// 发现重叠，注意相邻也算重叠，所以包含==
		if intervals[i][0] <= res[len(res)-1][1] {
			// 合并区间，更新右边界
			res[len(res)-1][1] = max(res[len(res)-1][1], intervals[i][1])
		} else {
			// 区间不重叠，加入结果集合
			res = append(res, intervals[i])
		}
	}
	return res
}
