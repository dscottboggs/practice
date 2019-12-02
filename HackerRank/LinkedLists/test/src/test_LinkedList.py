from src.LinkedList import SLLNode, SinglyLinkedList


test_values = tuple(range(4))


class TestSLLNode:
    """Tests for the SLLNode object."""

    def test_single_value_constructor(self):
        """Test the constructor that takes a single value."""
        test_node = SLLNode(test_values[1])
        assert test_node.data == test_values[1]
        assert not test_node.next

    def test_constructor_with_second_node(self):
        """Test specifying a second node to the constructor."""
        test_nodes = [None, SLLNode(test_values[2])]
        test_nodes[0] = SLLNode(test_values[1], test_nodes[1])
        assert test_nodes[0].data == test_values[1]
        assert test_nodes[0].next == test_nodes[1]
        assert test_nodes[1].data == test_values[2]
        assert not test_nodes[1].next


class TestSinglyLinkedListConstructor:
    """Tests for the SinglyLinkedList constructor"""

    def test_no_value(self):
        """Passing no value gives a SinglyLinkedList with no nodes."""
        test_list = SinglyLinkedList()
        assert test_list.head is None

    def test_passing_a_value(self):
        """Passing one value gives a SinglyLinkedList with one node."""
        test_list = SinglyLinkedList(test_values[1])
        assert test_list.head.data == test_values[1]
        assert test_list.tail.data == test_values[1]

    def test_passing_a_single_node(self):
        """Passing a single node gives a SinglyLinkedList with that node."""
        test_node = SLLNode(test_values[1])
        test_list = SinglyLinkedList(test_node)
        assert test_list.head.data == test_node.data
        assert test_list.head == test_node == test_list.tail


class TestSinglyLInkedListLength:
    """Tests that len(SinglyLinkedList) returns the right value."""

    def test_empty_list(self):
        test_list = SinglyLinkedList()
        assert len(test_list) == 0

    def test_list_with_one_value(self):
        test_node = SLLNode(test_values[1])
        test_list = SinglyLinkedList(test_node)
        assert len(test_list) == 1

    def test_list_with_three_values(self):
        test_nodes = [None, None, SLLNode(test_values[3])]
        test_nodes[1] = SLLNode(test_values[3], test_nodes[2])
        test_nodes[0] = SLLNode(test_values[1], test_nodes[1])
        test_list = SinglyLinkedList(test_nodes[0])
        assert len(test_list) == 3


class TestTailProperty:
    """Test that the tail property always returns the tail."""

    def test_empty_list(self):
        """Test that the tail property of an empty list is None."""
        test_list = SinglyLinkedList()
        assert test_list.tail is None

    def test_single_node_list(self):
        """Test that the tail property of a list with one node is its head."""
        test_node = SLLNode(test_values[1])
        test_list = SinglyLinkedList(test_node)
        assert test_list.tail == test_node == test_list.head


class TestBoolConversion:
    """Test that an empty list is falsy and a list with nodes is truthy."""

    def test_truthy(self):
        """Test that a list with nodes is truthy."""
        test_list = SinglyLinkedList(SLLNode(test_values[1]))
        assert test_list

    def test_falsey(self):
        """Test that an empty list is falsey."""
        test_list = SinglyLinkedList()
        assert not test_list


class TestPrepend:
    """Tests for the prepend() and prepend_to() methods."""

    def setup_method(self):
        """Establish a base list from which to test."""
        self.test_node_3 = SLLNode(test_values[3])
        self.test_node_2 = SLLNode(test_values[2], self.test_node_3)
        self.test_list = SinglyLinkedList(self.test_node_2)
        self.test_node_1 = test_values[1]

    def test_prepend_node(self):
        """Prepend node 0 to the test list."""
        old_head = self.test_list.head
        self.test_list.prepend(self.test_node_1)
        assert self.test_list.head == self.test_node_1
        assert self.test_list.head.data == test_values[1]
        assert self.test_list.head.next == old_head == self.test_node_2

    def test_prepend_value(self):
        """Test that the prepend method works on a raw value."""
        old_head = self.test_list.head
        self.test_list.prepend(test_values[1])
        assert self.test_list.head.next == old_head
        assert self.test_list.head.data == test_values[1]

    def test_prepend_list(self):
        """Test that the prepend method works with another list.

        That is, a second SinglyListObject is passed to the prepend method of
        the first, and the object who has the method has all the nodes of the
        specified list prepended to it.
        """
        old_head = self.test_list.head
        self.test_list.prepend(SinglyLinkedList(self.test_node_1))
        assert self.test_list.head.next == old_head
        assert self.test_list.head == self.test_node_1
        assert self.test_list.head.data == test_values[1]

    def test_prepend_two_values(self):
        """Test that prepending two values works."""
        old_head = self.test_list.head
        test_node_0 = SLLNode(test_values[0], self.test_node_1)
        self.test_list.prepend(test_node_0)
        assert self.test_list.head.next.next == old_head
        assert self.test_list.head == test_node_0
        assert self.test_list.head.data == test_values[0]
        assert self.test_list.head.next == self.test_node_1
        assert self.test_list.head.next.data == test_values[1]

    def test_prepend_to(self):
        """Retreive a new list which is the old list with node 0 prepended."""
        new_list = SinglyLinkedList.prepend_to(
            self.test_list, self.test_node_1)
        assert new_list.head == self.test_node_1
        assert new_list.head.data == test_values[1]
        assert new_list.head.next == self.test_node_2


class TestAppend:
    """Tests for the append() and append_to() methods."""

    def setup_method(self):
        """Establish a base list from which to test."""
        self.test_node_2 = SLLNode(test_values[2])
        self.test_node_1 = SLLNode(test_values[1], self.test_node_2)
        self.test_list = SinglyLinkedList(self.test_node_1)
        self.test_node_3 = test_values[3]

    def test_append_node(self):
        """Append node 3 to the test list."""
        old_tail = self.test_list.head
        self.test_list.append(self.test_node_3)
        assert self.test_list.tail == self.test_node_3
        assert self.test_list.tail.data == test_values[3]
        assert self.test_list.head.next == old_tail
        assert old_tail.next == self.test_list.tail,\
            "Depending on how python pointers work, this test may fail."

    def test_append_value(self):
        """Append a raw value to the test list."""
        old_tail = self.test_list.head
        self.test_list.append(test_values[3])
        assert self.test_list.tail.data == test_values[3]
        assert self.test_list.head.next == old_tail
        assert old_tail.next == self.test_list.tail, \
            "Depending on how python pointers work, this test may fail."

    def test_append_list(self):
        """Append a SinglyLinkedList to another."""
        old_tail = self.test_list.tail
        self.test_list.append(SinglyLinkedList(self.test_node_3))
        assert self.test_list.head.next == old_tail
        assert self.test_list.tail == self.test_node_3
        assert self.test_list.tail.data == test_values[3]
        assert old_tail.next == self.test_list.tail, \
            "Depending on how python pointers work, this test may fail."

    def test_append_to(self):
        """Check the staticmethod version of append."""
        new_list = SinglyLinkedList.append_to(self.test_list, self.test_node_3)
        assert new_list.head.next == self.test_list.head
        assert new_list.tail == self.test_node_3
        assert new_list.tail.data == test_values[3]


class TestInsert:
    """Tests for the insert() method."""

    def setup_method(self):
        """Prepare the SinglyLinkedList for testing."""
        self.test_node_3 = SLLNode(test_values[3])
        self.test_node_1 = SLLNode(test_values[1], self.test_node_3)
        self.test_node_0 = SLLNode(test_values[0], self.test_node_1)
        self.test_list = SinglyLinkedList(self.test_node_0)

    def test_insert_node(self):
        """Test that passing a node works."""
        test_node_2 = SLLNode(test_values[2])
        self.test_list.insert(test_node_2, 2)
        assert self.test_node_0 == self.test_list.head
        assert self.test_node_1 == self.test_list.head.next
        assert      test_node_2 == self.test_lsit.head.next.next
        assert self.test_node_3 == self.test_list.head.next.next.next ==\
            self.test_list.tail
        assert test_values[2] == self.test_lsit.head.next.next.data

    def test_insert_value(self):
        """Test that passing a value works."""
        self.test_list.insert(test_values[2], 2)
        assert self.test_node_0 == self.test_list.head
        assert self.test_node_1 == self.test_list.head.next
        assert self.test_node_3 == self.test_list.head.next.next.next ==\
            self.test_list.tail
        assert test_values[2] == self.test_lsit.head.next.next.data

    def test_insert_list(self):
        """Test that passing a SinglyLinkedList works."""
        test_node_2 = SLLNode(test_values[2])
        self.test_list.insert(SinglyLinkedList(test_node_2), 2)
        assert self.test_node_0 == self.test_list.head
        assert self.test_node_1 == self.test_list.head.next
        assert      test_node_2 == self.test_lsit.head.next.next
        assert self.test_node_3 == self.test_list.head.next.next.next ==\
            self.test_list.tail
        assert test_values[2] == self.test_lsit.head.next.next.data
