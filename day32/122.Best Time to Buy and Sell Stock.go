/**
 * @date: 2024 Jan 06
 * @time: 13:27
 * @author: Chris
 * @title: 122.Best Time to Buy and Sell Stock
 * @link: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
**/
package day32

func maxProfit(prices []int) int {

	res := 0
	for i := 1; i < len(prices); i++ {
		// 一段时间的交易 == 每天连续的交易
		// 如果有利润就买了卖，无利润不操作
		res += max(prices[i]-prices[i-1], 0)
	}
	return res
}
