/**
 * @date: 2024 Jan 06
 * @time: 10:50
 * @author: Chris
 * @title: 455. Assign Cookies
 * @link: https://leetcode.cn/problems/assign-cookies/description/
**/
package day31

import (
	"sort"
)

// 优先满足胃口小的孩子，
// 如果不可以换下一个物品；如果换孩子的的话也不能满足
func findContentChildren(g []int, s []int) int {
	// sort by ascending
	sort.Ints(g)
	sort.Ints(s)
	child := 0
	// 遍历物品，如果不行换下个物品
	for sIndex := 0; child < len(g) && sIndex < len(s); sIndex++ {
		// 物品sIndex在不断递增
		// child只有满足的当前孩子时候才递增，才会尝试分配给下一个孩子
		if s[sIndex] >= g[child] {
			child++
		}
	}
	return child
}

// 优先满足胃口大的孩子，
// 如果不行，换下个孩子； 如果换下一个物品的话也不能满足。
func findContentChildren2(g []int, s []int) int {
	// sort
	sort.Ints(g)
	sort.Ints(s)

	sIndex := len(s) - 1
	// 遍历孩子，如果不行换孩子
	for i := len(g) - 1; sIndex >= 0 && i >= 0; i-- { // 孩子可能大于饼干数，注意sIndex别越界
		if s[sIndex] >= g[i] {
			sIndex--
		}
	}
	return (len(s) - 1) - sIndex
}
