package main

import (
	"testing"
)

func TestIsAnagram(t *testing.T) {
	testCases := []struct {
		s      string
		t      string
		expect bool
	}{
		{"anagram", "nagaram", true},
		{"rat", "car", false},
	}
	for _, tc := range testCases {
		result := isAnagram(tc.s, tc.t)
		if result != tc.expect {
			t.Errorf("isAnagram(%q, %q) = %v; expected %v",
				tc.s, tc.t, result, tc.expect)
		}
	}
}

func TestIsAnagram2(t *testing.T) {
	testCases := []struct {
		s      string
		t      string
		expect bool
	}{
		{"anagram", "nagaram", true},
		{"rat", "car", false},
	}
	for _, tc := range testCases {
		result := isAnagram2(tc.s, tc.t)
		if result != tc.expect {
			t.Errorf("isAnagram2(%q, %q) = %v; expected %v",
				tc.s, tc.t, result, tc.expect)
		}
	}
}

// benchmark test 基准测试
func BenchmarkIsAnagram(b *testing.B) {
	for i := 0; i < b.N; i++ {
		isAnagram("anagram", "nagaram")
	}
}

func BenchmarkIsAnagram2(b *testing.B) {
	for i := 0; i < b.N; i++ {
		isAnagram2("anagram", "nagaram")
	}
}
