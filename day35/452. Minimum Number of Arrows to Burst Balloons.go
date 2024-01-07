/**
 * @date: 2024 Jan 07
 * @time: 21:21
 * @author: Chris
 * @title: 452. Minimum Number of Arrows to Burst Balloons
 * @link: https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/
**/
package day35

import "sort"

// 解决这类题的方案，就是按照两个维度进行先后排序！
// 先按起始位置排序
// 然后按终止进行射箭
func findMinArrowShots(points [][]int) int {
	res := 1
	sort.Slice(points, func(i, j int) bool {
		return points[i][0] < points[j][0]
	})

	for i := 1; i < len(points); i++ {

		if points[i-1][1] < points[i][0] { // 如果不重叠，需要多来一支箭
			res++
		} else { // 如果重叠，第i个气球可以和i-1射穿，更新他俩公共右边界
			points[i][1] = min(points[i-1][1], points[i][1])
		}
	}
	return res
}
