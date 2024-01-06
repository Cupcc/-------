/**
 * @date: 2024 Jan 06
 * @time: 17:16
 * @author: Chris
 * @title: 135. Candy
 * @link: https://leetcode.cn/problems/candy/
**/
package day34

// 比邻居高，糖果比邻居糖果多，
// 如果相等（即不比邻居高），那么可以不比邻居多。
// 比如： ratings[1, 2, 2] 糖果为：[1, 2, 1]
func candy(ratings []int) int {
	n := len(ratings)
	if n == 0 {
		return 0
	}
	// 初始化，每人一个糖
	candies := make([]int, n)
	for i := range candies {
		candies[i] = 1
	}

	// 确保每个比左邻居评分高的孩子，比左邻居多一颗糖果。
	// 从左到右 --->
	for i := 1; i < n; i++ {
		//评分比左侧高！
		if ratings[i] > ratings[i-1] {
			// 比左侧多一个
			candies[i] = candies[i-1] + 1
		}
	}

	// 确保每个比右邻居评分高的孩子，比右邻居多一颗糖果。
	// 从右到左  <---
	for i := n - 2; i >= 0; i-- {
		//评分比右侧高！  如果糖果少的话再操作，糖果多不要操作，可能会减少糖果！
		// 比如 [1,2,3,1] 糖果数[1,2,3,1],不加这个条件3就变成2了！
		if ratings[i] > ratings[i+1] && candies[i] <= candies[i+1] {
			candies[i] = candies[i+1] + 1
		}
	}
	total := 0
	for _, c := range candies {
		total += c
	}
	return total
}
