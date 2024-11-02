class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class Deque:
    def __init__(self):
        self.front = None
        self.back = None

    def is_empty(self):
        return self.front is None

    def push_back(self, data):
        new_node = Node(data)
        if self.back is not None:
            self.back.next = new_node
            new_node.prev = self.back
        else:
            self.front = new_node  
        self.back = new_node

    def push_front(self, data):
        new_node = Node(data)
        if self.front is not None:
            self.front.prev = new_node
            new_node.next = self.front
        else:
            self.back = new_node  
        self.front = new_node

    def pop_back(self):
        if self.is_empty():
            return None
        data = self.back.data
        self.back = self.back.prev
        if self.back is None:
            self.front = None  
        else:
            self.back.next = None
        return data

    def pop_front(self):
        if self.is_empty():
            return None
        data = self.front.data
        self.front = self.front.next
        if self.front is None:
            self.back = None  
        else:
            self.front.prev = None
        return data

    def back_value(self):
        if self.is_empty():
            return None
        return self.back.data

    def front_value(self):
        if self.is_empty():
            return None
        return self.front.data

    def clear(self):
        self.front = None
        self.back = None

    def size(self):
        count = 0
        current = self.front
        while current:
            count += 1
            current = current.next
        return count

if __name__ == "__main__":
    deque = Deque()
    deque.push_back(1)
    deque.push_back(2)
    deque.push_front(0)

    print("Front:", deque.front_value())  
    print("Back:", deque.back_value())    

    print("Popped from front:", deque.pop_front())  
    print("Popped from back:", deque.pop_back())    

    print("Size after pops:", deque.size())  