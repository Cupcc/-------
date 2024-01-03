package day57

import "testing"

func Test(t *testing.T) {
	testCases := []struct {
		desc string
		s    string
		want int
	}{
		{"cases1", "aaa", 6},
		{"cases2", "abc", 3},
	}
	for _, tC := range testCases {
		t.Run(tC.desc, func(t *testing.T) {
			if countSubstrings(tC.s) != tC.want {
				t.Errorf("!!!")
			}
		})
	}
}
