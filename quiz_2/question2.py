class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def findBeginningOfCycle(head: ListNode) -> ListNode:
    """returns the node where the cycle begins"""
    if not head or not head.next:
        return None

    slow = head
    fast = head.next

    while slow != fast:
        if not fast or not fast.next:
            return None
        slow = slow.next
        fast = fast.next.next

    slow = head
    fast = fast.next  
    while slow != fast:
        slow = slow.next
        fast = fast.next

    return slow

# Example case
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = head.next

node = findBeginningOfCycle(head)
print(node.val)
