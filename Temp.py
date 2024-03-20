import sys

class RBNode:

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.parent = None
        self.colour = "R"

    def get_uncle(self):
        if self.parent is None or self.parent.parent is None:
            return None
        if self.parent.is_left_child():
            return self.parent.parent.right
        else:
            return self.parent.parent.left

    def is_leaf(self):
        return self.left is None and self.right is None

    def is_left_child(self):
        return self == self.parent.left if self.parent else False

    def is_right_child(self):
        return self == self.parent.right if self.parent else False

    def is_red(self):
        return self.colour == "R"

    def is_black(self):
        return not self.is_red()

    def make_black(self):
        self.colour = "B"

    def make_red(self):
        self.colour = "R"

    def rotate_right(self, root):
        leftChild = self.left
        self.left = leftChild.right
        if leftChild.right:
            leftChild.right.parent = self
        leftChild.parent = self.parent
        if not self.parent:
            root = leftChild
        elif self == self.parent.right:
            self.parent.right = leftChild
        else:
            self.parent.left = leftChild
        leftChild.right = self
        self.parent = leftChild
        return root

    def rotate_left(self, root):
        rightChild = self.right
        self.right = rightChild.left
        if rightChild.left:
            rightChild.left.parent = self
        rightChild.parent = self.parent
        if not self.parent:
            root = rightChild
        elif self == self.parent.left:
            self.parent.left = rightChild
        else:
            self.parent.right = rightChild
        rightChild.left = self
        self.parent = rightChild
        return root

    def __str__(self):
        return "(" + str(self.value) + "," + self.colour + ")"

    def __repr__(self):
        return "(" + str(self.value) + "," + self.colour + ")"


class RBTree:

    def __init__(self,):
        self.root = None

    def is_empty(self):
        return self.root is None

    def insert(self, value):
        if self.is_empty():
            self.root = RBNode(value)
            self.root.make_black()
        else:
            self.__insert(self.root, value)

    def __insert(self, node, value):
        if value < node.value:
            if node.left is None:
                node.left = RBNode(value)
                node.left.parent = node
                self.fix(node.left)
            else:
                self.__insert(node.left, value)
        else:
            if node.right is None:
                node.right = RBNode(value)
                node.right.parent = node
                self.fix(node.right)
            else:
                self.__insert(node.right, value)

    def fix(self, node):
        while node.parent and node.parent.is_red():
            parent = node.parent
            grandparent = parent.parent
            if parent == grandparent.left:
                uncle = grandparent.right
                if uncle and uncle.is_red():
                    parent.make_black()
                    uncle.make_black()
                    grandparent.make_red()
                    node = grandparent
                else:
                    if node == parent.right:
                        node = parent
                        self.root = node.rotate_left(self.root)
                    parent.make_black()
                    grandparent.make_red()
                    self.root = grandparent.rotate_right(self.root)
            else:
                uncle = grandparent.left
                if uncle and uncle.is_red():
                    parent.make_black()
                    uncle.make_black()
                    grandparent.make_red()
                    node = grandparent
                else:
                    if node == parent.left:
                        node = parent
                        self.root = node.rotate_right(self.root)
                    parent.make_black()
                    grandparent.make_red()
                    self.root = grandparent.rotate_left(self.root)
        self.root.make_black()

    def __str__(self):
        if self.is_empty():
            return "[]"
        return "[" + self.__str_helper(self.root) + "]"

    def __str_helper(self, node):
        if node.is_leaf():
            return "[" + str(node) + "]"
        if node.left is None:
            return "[" + str(node) + " -> " + self.__str_helper(node.right) + "]"
        if node.right is None:
            return "[" +  self.__str_helper(node.left) + " <- " + str(node) + "]"
        return "[" + self.__str_helper(node.left) + " <- " + str(node) + " -> " + self.__str_helper(node.right) + "]"

    def print_tree(self):
        self.__print_helper(self.root, "", True)

    def __print_helper(self, node, indent, last):
        if node:
            sys.stdout.write(indent)
            if last:
                sys.stdout.write("R----")
                indent += "     "
            else:
                sys.stdout.write("L----")
                indent += "|    "
            s_color = "RED" if node.is_red() else "BLACK"
            print(str(node.value) + "(" + s_color + ")")
            self.__print_helper(node.left, indent, False)
            self.__print_helper(node.right, indent, True)


rbTree = RBTree()
rbTree.insert(2)
rbTree.insert(3)
rbTree.insert(4)
print(rbTree.__str__())
rbTree.print_tree()
