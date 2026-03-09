def insert_begin(head, data):
    new = Node(data)

    if head == NULL:
        new.next = new
        new.prev = new
        return new

    last = head.prev

    new.next = head
    new.prev = last
    last.next = new
    head.prev = new

    return new

def insert_end(head, data):
    new = Node(data)

    if head == NULL:
        new.next = new
        new.prev = new
        return new

    last = head.prev

    last.next = new
    new.prev = last
    new.next = head
    head.prev = new

    return head

def delete_begin(head):
    if head is None:
        return None

    if head.next == head:
        return None

    last = head.prev
    head = head.next

    head.prev = last
    last.next = head

    return head

def delete_end(head):
    if head is None:
        return None

    if head.next == head:
        return None

    last = head.prev
    second_last = last.prev

    second_last.next = head
    head.prev = second_last

    return head


