package main

import (
	"fmt"
	"time"
)

func isAnagram(s string, t string) bool {
	time.Sleep(time.Second * 3)
	if len(s) != len(t) {
		return false
	}

	record := [26]int{} //数组，访问最快
	for _, ch := range s {
		record[ch-'a']++
	}
	for _, ch := range t {
		index := ch - 'a'
		record[index]--
		if record[index] < 0 {
			// 提前退出
			return false
		}
	}
	return true
}
func isAnagram2(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	record := make(map[rune]int) //需要计算hash值和处理哈希冲突
	for _, ch := range s {
		record[ch]++
	}
	for _, ch := range t {
		record[ch]-- // 对于不存在的 ch，会添加并操作 -1.
		if record[ch] < 0 {
			return false
		}
	}
	return true
}
func main() {
	fmt.Println("I love you")
}
