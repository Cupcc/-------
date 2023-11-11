class Solution:
    # python>=3.9, can use build-in types (such as list)
    def generateMatrix(self, n: int) -> list[list[int]]:
        """
        [left, right)
        Args:
            n (int): 螺旋矩阵大小
        Variables:
            loop : 循环的次数
            offset: 结尾的位置
            startx,starty: 开始的位置
            count: 需要填入的数字
        Returns:
            List[List[int]]: _description_
        """
        res = [[0] * n for _ in range(n)]
        startx, starty = 0, 0
        loop = n // 2
        count = 1
        for offset in range(1, loop + 1):
            for j in range(starty, n - offset):
                res[startx][j] = count
                count += 1
            for i in range(startx, n - offset):
                res[i][n - offset] = count
                count += 1
            for j in range(n - offset, starty, -1):
                res[n - offset][j] = count
                count += 1
            for i in range(n - offset, startx, -1):
                res[i][starty] = count
                count += 1

            # 更新起始点
            startx += 1
            starty += 1
        if n % 2 != 0:  # 若为odd，填充中心点
            res[loop][loop] = count
        return res
