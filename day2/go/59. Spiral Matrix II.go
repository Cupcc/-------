package main

import "fmt"

func generateMatrix(n int) [][]int {
	startx, starty := 0, 0
	var loop int = n / 2
	count := 1
	offset := 1
	res := make([][]int, n) //二维切片

	for i := 0; i < n; i++ {
		res[i] = make([]int, n) //自动初始化
	}

	for loop > 0 {
		i, j := startx, starty
		for j = starty; j < n-offset; j++ {
			res[startx][j] = count
			count++
		}
		for ; i < n-offset; i++ {
			res[i][j] = count
			count++
		}
		for ; j > starty; j-- {
			res[i][j] = count
			count++
		}
		for ; i > startx; i-- {
			res[i][j] = count
			count++
		}
		startx++
		starty++
		loop--
		offset++
	}
	if n%2 == 1 {
		var center = n / 2
		res[center][center] = count
	}
	return res

}
func main() {
	n := 3
	fmt.Println(generateMatrix(n))
}
