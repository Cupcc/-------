package main

import "testing"

func TestMinDistance(t *testing.T) {
	testCases := []struct {
		word1 string
		word2 string
		want  int
	}{
		{"horse", "ros", 3},
		{"intention", "execution", 5},
		{"", "", 0},
		{"a", "b", 1},
	}

	for _, tC := range testCases {
		testname := tC.word1 + "_" + tC.word2
		t.Run(testname, func(t *testing.T) {
			ans := minDistance(tC.word1, tC.word2)
			if ans != tC.want {
				t.Errorf("minDistance('%s', '%s') = %d; want %d", tC.word1, tC.word2, ans, tC.want)
			}
		})
	}
}
