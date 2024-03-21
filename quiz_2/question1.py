class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
def hasCycle(head):
    """checking if a linked list has a cycle
       implimeted the tortoise and hare algorithm"""
    if head is None or head.next is None:
        return False

    slow = head
    fast = head.next

    while slow != fast:
        if fast is None or fast.next is None:
            return False
        slow = slow.next
        fast = fast.next.next

    return True

#example case
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)
head.next.next.next.next.next = head.next  # creating a cycle

result = hasCycle(head)
print(result)