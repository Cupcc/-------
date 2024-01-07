/**
 * @date: 2024 Jan 07
 * @time: 20:49
 * @author: Chris
 * @title: 406. Queue Reconstruction by Height
 * @link: https://leetcode.cn/problems/queue-reconstruction-by-height/description/
**/
package day35

import "sort"

// people[i] = [hi,ki] 身高，前面比他高的人
// 根据题目，可以确定，身高高的应该在前面！其次要满足k的要求
// 所以先按身高排列，再按k值排列（先排k不行，举反例）
func reconstructQueue(people [][]int) [][]int {
	// 身高从大到小排列，if身高相同，k小的站在前面
	sort.Slice(people, func(i, j int) bool {
		if people[i][0] == people[j][0] {
			return people[i][1] < people[j][1] // 身高相同时，k从小到大排列
		}
		return people[i][0] > people[j][0] //身高从高到矮排列
	})

	// 在k的位置进行插入，优先插入K小的
	for i, p := range people {
		// p[0]身高，p[1]是k值
		// 第一个参数目的数组，第二参数原数组
		copy(people[p[1]+1:i+1], people[p[1]:i]) // 从[k，i]，往后移动1个位置
		people[p[1]] = p                         // p 的位置插入
	}
	return people
}
