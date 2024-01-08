/**
 * @date: 2024 Jan 07
 * @time: 23:17
 * @author: Chris
 * @title: 84. Largest Rectangle in Histogram
 * @link: https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
**/
package day60

// 找每个柱子左右两侧第一个小于该柱子的柱子
// 找小的，需要维护一个单调递增栈
func largestRectangleArea(heights []int) int {
	// 结尾添加最小值0，让heights中最后一个元素可以出栈，计算它的面积！
	// 而且他还可以让所有留在栈中的元素都出栈[1,2,2,2,2,3],第一个2可是面积最大值
	heights = append(heights, 0)
	stack := []int{-1} // 防止栈底元素弹出时，找不到左柱子
	maxArea := 0

	for i, h := range heights {
		// 维护递增栈，寻找两侧第一个小的竹子

		// 注意栈中第一个元素是-1,不属于heights中，不能进行判断，所以栈长度要>1
		for len(stack) > 1 && h < heights[stack[len(stack)-1]] { // 此时i为右侧第一个小于栈顶的，为右侧柱子
			height := heights[stack[len(stack)-1]] // 栈顶元素高度
			stack = stack[:len(stack)-1]           // 出栈

			//计算面积
			left := stack[len(stack)-1] // 此时栈顶为左侧第一个小于弹出的栈顶的，为左侧柱子
			width := i - left - 1       // 求两个柱子中间的距离，要-1
			maxArea = max(maxArea, height*width)
		}

		stack = append(stack, i) // 当前柱子入栈，记录索引值
	}
	return maxArea
}
