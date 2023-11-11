/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    return nums.indexOf(target)
};
var search = function (nums, target) {
    // target in [left, right)
    let left = 0
    let right = nums.length
    while (left < right) {
        let middle = left + ((right - left) >> 1)
        if (nums[middle] > target) right = middle
        else if (nums[middle] < target) left = middle + 1
        else return middle
    }
    return -1;
};

var search = function (nums, target) {
    // target in [left, right]
    let left = 0
    let right = nums.length - 1
    while (left <= right) {
        middle = left + ((right - left) >> 1)
        if (nums[middle] > target) right = middle - 1
        else if (nums[middle] < target) left = middle + 1
        else return middle
    }
    return -1;
};