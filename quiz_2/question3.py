#function that takes the head of a linked list and returns the reversed list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
def reverse_linked_list(head):
    """takes the head of the linked list and returns the reversed list"""
    prev = None
    current = head
    while(current is not None):
        next = current.next
        current.next = prev
        prev = current
        current = next
    return prev

#example case
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)

result = reverse_linked_list(head)

while result is not None:
    print(result.data)
    result = result.next