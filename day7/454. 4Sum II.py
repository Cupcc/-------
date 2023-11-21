class Solution:

    def fourSumCount(self, nums1: list[int], nums2: list[int],
                     nums3: list[int], nums4: list[int]) -> int:
        hashmap = dict()
        for n1 in nums1:
            for n2 in nums2:
                if n1 + n2 in hashmap:
                    hashmap[n1 + n2] += 1
                else:
                    hashmap[n1 + n2] = 1

        count = 0
        for n3 in nums3:
            for n4 in nums4:
                if -(n3 + n4) in hashmap:
                    count += hashmap[0 - (n3 + n4)]
        return count


#  使用 get方法

    def fourSumCount(self, nums1: list[int], nums2: list[int],
                     nums3: list[int], nums4: list[int]) -> int:
        hashmap = dict()
        for n1 in nums1:
            for n2 in nums2:
                # 获取 n1+n2的值，如果不存在返回 0，
                # +1 后赋值给hashmap
                hashmap[n1 + n2] = hashmap.get(n1 + n2, 0) + 1
        count = 0
        for n3 in nums3:
            for n4 in nums4:
                key = -n3 - n4
                if key in hashmap:
                    count += hashmap[key]

        return count
