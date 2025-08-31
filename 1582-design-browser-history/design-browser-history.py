class Node:
    def __init__(self, url):
        self.url = url
        self.next = None
        self.prev = None


class BrowserHistory(object):

    def __init__(self, homepage):
        """
        :type homepage: str
        """
        new_node = Node(homepage)
        self.head = new_node
        self.tail = new_node
        self.curr_node = new_node

    def visit(self, url):
        """
        :type url: str
        :rtype: None
        """
        if self and self.head:
            new_node = Node(url)
            if self.curr_node.next:
                self.curr_node.next.prev = None
            self.curr_node.next = new_node
            new_node.prev = self.curr_node
            self.tail = new_node
            self.curr_node = self.tail

    def back(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        if self and self.head:
            steps_counter = 0
            while self.curr_node.prev:
                if steps_counter == steps:
                    return self.curr_node.url
                steps_counter += 1
                self.curr_node = self.curr_node.prev
            return self.curr_node.url
        return None

    def forward(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        if self and self.head:
            steps_counter = 0
            while self.curr_node.next:
                if steps_counter == steps:
                    return self.curr_node.url
                steps_counter += 1
                self.curr_node = self.curr_node.next
            return self.curr_node.url
        return None