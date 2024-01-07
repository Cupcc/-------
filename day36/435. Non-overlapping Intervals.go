/**
 * @date: 2024 Jan 07
 * @time: 22:00
 * @author: Chris
 * @title: 435. Non-overlapping Intervals
 * @link: https://leetcode.cn/problems/non-overlapping-intervals/description/
**/
package day36

import (
	"math"
	"sort"
)

// 目的：移除区间的最小数量，使剩余区间不重叠
// 转化：｜移除个数 = 总区间 - 非重叠区间｜ 所以求非重叠区的最大个数！
// 如何求非重叠的最大个数！
// 让非重叠区的“范围”尽量小，数量就多了！
// 做过了射箭问题，我们知道这类问题，要选定一个因素先进行排序
// 左右都可以，这次我们按右边界排序
func eraseOverlapIntervals(intervals [][]int) int {
	// 需要移除的个数 = 总区间个数 - 非重叠区间个数
	if len(intervals) == 0 {
		return 0
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][1] < intervals[j][1]
	})

	// 记录非重叠区间
	count := 0           // 非重叠区间个数
	end := math.MinInt64 // 非重叠区右边界,题目中区间包含负数
	for i := 0; i < len(intervals); i++ {
		// 上一个非重叠区间的右边界 <= 当前i的左边界，即非重叠，count++
		if end <= intervals[i][0] {
			count++
			end = intervals[i][1] // 更新非重叠区右边界
		}
	}
	return len(intervals) - count
}
