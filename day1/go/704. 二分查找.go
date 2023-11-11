package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func search(nums []int, target int) int {
	// binary search [left, right)
	left := 0
	right := len(nums)
	for left < right {
		middle := left + ((right - left) / 2)
		if nums[middle] > target {
			right = middle
		} else if nums[middle] < target {
			left = middle + 1
		} else {
			return middle
		}
	}
	return -1
}
func search1(nums []int, target int) int {
	// target in [left, right]
	left := 0
	right := len(nums) - 1
	for left <= right {
		middle := left + (right-left)/2
		if nums[middle] > target {
			right = middle - 1
		} else if nums[middle] < target {
			left = middle + 1
		} else {
			return middle
		}
	}
	return -1
}

func init() {
	in := bufio.NewScanner(os.Stdin)
	in.Buffer(nil, math.MaxInt32)
	_out, _ := os.Create("user.out")
	out := bufio.NewWriter(_out)
next:
	for in.Scan() {
		s := string(in.Bytes())
		in.Scan()
		tar, _ := strconv.Atoi(string(in.Bytes()))
		for i, _i := -1, 1; _i < len(s); _i++ {
			i++
			_neg := false
			if s[_i] == '-' {
				_i++
				_neg = true
			}
			v := int(s[_i] & 15)
			for _i++; s[_i]&15 < 10; _i++ {
				v = v*10 + int(s[_i]&15)
			}
			if _neg {
				v = -v
			}
			if v == tar {
				fmt.Fprintln(out, i)
				continue next
			}
			if v > tar { // ascending order
				break
			}
		}
		fmt.Fprintln(out, -1)
	}
	out.Flush()
	os.Exit(0)
}

func search2([]int, int) (_ int) { return }
