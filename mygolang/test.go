package main

import (
	"fmt"
	"os"
	"time"
)

var query = "1.txt"
var matches int
var workerCount = 0                   //定义当前的工人的数量
var maxWorkerCount = 32               //最大32个工人干活
var searchRequest = make(chan string) //包工头指派活
var workerDone = make(chan bool)      //工作是否干完了
var foundMatch = make(chan bool)      //是否找到

func main() {
	start := time.Now()

	workerCount = 1
	go search("/Users/cupccco/Desktop/代码随想录算法/mygolang", true)
	waitForWorkers()

	fmt.Println(matches, "matches")
	// elapsed time
	fmt.Println(time.Since(start))
}

func waitForWorkers() {
	for {
		select {
		case path := <-searchRequest:
			workerCount++
			go search(path, true)
		case <-workerDone:
			workerCount--
			if workerCount == 0 {
				return
			}
		case <-foundMatch:
			matches++
		}

	}
}

func search(path string, master bool) {
	files, err := os.ReadDir(path)
	if err == nil {
		for _, file := range files {
			name := file.Name()
			if name == query {
				foundMatch <- true
				fmt.Println(path + name)
			}
			if file.IsDir() {
				if workerCount < maxWorkerCount {
					searchRequest <- path + name + "/"
				} else {
					search(path+name+"/", false)
				}
			}
		}
		if master {
			workerDone <- true
		}
	}
}
