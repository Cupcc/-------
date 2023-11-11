/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function (n) {
    //默认为undefined. map()只会对已经初始化的元素进行操作。
    //callbackFn is invoked only for array indices that have assigned values; it is not invoked for empty slots in sparse arrays​
    let res = new Array(n).fill(0).map(
        () => new Array(n).fill(0)
    )

    let loop = Math.floor(n / 2)
    let startx = starty = 0
    let count = 1
    for (let offset = 1; offset <= loop; offset++, startx++, starty++) {
        let row = startx, col = starty
        for (; col < n - offset; col++) {
            res[row][col] = count++
        }
        for (; row < n - offset; row++) {
            res[row][col] = count++
        }
        for (; col > starty; col--) {
            res[row][col] = count++
        }
        for (; row > startx; row--) {
            res[row][col] = count++
        }
    }
    if (n % 2 != 0) {
        res[loop][loop] = count
    }
    return res
};