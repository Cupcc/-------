class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:

    def getIntersectionNode(self, headA: ListNode,
                            headB: ListNode) -> ListNode:
        sizeA = 0
        sizeB = 0
        curA = headA
        curB = headB
        while curA:
            curA = curA.next
            sizeA += 1
        while curB:
            curB = curB.next
            sizeB += 1
        curA = headA
        curB = headB
        if sizeB > sizeA:
            curA, curB = curB, curA
            sizeA, sizeB = sizeB, sizeA

        for _ in range(sizeA - sizeB):
            curA = curA.next

        while curA:
            if curA == curB:
                return curA
            curA = curA.next
            curB = curB.next

        return None


class Solution:
    """代码复用
    """

    def getLength(self, head: ListNode) -> int:
        length = 0
        while head:
            head = head.next
            length += 1
        return length

    def moveForward(self, head: ListNode, steps: int) -> ListNode:
        while steps:
            head = head.next
            steps -= 1
        return head

    def getIntersectionNode(self, headA: ListNode,
                            headB: ListNode) -> ListNode:
        lenA = self.getLength(headA)
        lenB = self.getLength(headB)
        if lenA > lenB:
            headA = self.moveForward(headA, lenA - lenB)
        else:
            headB = self.moveForward(headB, lenB - lenA)

        while headA and headB:
            if headA == headB:
                return headA
            else:
                headA = headA.next
                headB = headB.next

        return None


class Solution:
    
    def getIntersectionNode(self, headA: ListNode,
                            headB: ListNode) -> ListNode:
        """双指针等比法
            A 和 B 拼接，遍历完 A 去遍历 B。
            其中包含 None 控指针。
            时间复杂度：O(a+b),最差情况 无交点且长度不相等(lenA!=lenB and c = 0)
            空间复杂度：O(1)
        """
        # # 边缘处理, 可以忽略
        # if not headA or not headB:
        #     return None

        pointerA, pointerB = headA, headB

        while pointerA != pointerB:
            pointerA = pointerA.next if pointerA else headB
            pointerB = pointerB.next if pointerB else headA

        return pointerA
