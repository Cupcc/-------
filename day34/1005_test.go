package day34

import "testing"

func Test(t *testing.T) {
	testCases := []struct {
		desc string
		nums []int
		k    int
		want int
	}{
		{
			"cases1", []int{3, -1, 0, 2}, 3, 6,
		},
	}
	for _, tC := range testCases {
		t.Run(tC.desc, func(t *testing.T) {
			ans := largestSumAfterKNegations(tC.nums, tC.k)
			if ans != tC.want {
				t.Errorf("Case %s failed: expected %v, got %v", tC.desc, tC.want, ans)
			}
		})
	}
}
