#!/usr/bin/env python3
from typing import Optional, Union


class SLLNode():
    """A node of a singly-linked list."""

    def __init__(self, node_data, next_node=None):
        self.data = node_data
        self.next = next_node


class SinglyLinkedList():
    """A data structure where parent elements hold a reference to a child.

    The child elements do not hold references to the parent, so this structure
    can only be iterated through forwards.
    """
    head, tail = None
    def __init__(self, head=None):
        if isinstance(head, SLLNode):
            self.head = head
        else:
            self.head = SLLNode(head)

    def __len__(self) -> int:
        """Determine how long the list is."""
        length = 0
        if self.head:
            length, element = 1, self.head
            while element.next is not None:
                length += 1
                element = element.next
        return length

    def __bool__(self):
        """Return true if the list is not empty."""
        return self.head is not None

    @property
    def tail(self):
        """The last node in the list"""
        return get_tail_of(self.head)

    def list_elements(
                self,
                list_or_node: Optional[Union[SinglyLinkedList, SLLNode]] = None
            ):
        """Print all elements of this or a specified list to stdout"""
        if list_or_node is None:
            if self.head:
                self.list_elements_of(self.head)
            else:
                print("Empty list.")
        else:
            self.list_elements_of(list_or_node)

    @staticmethod
    def list_elements_of(
                list_or_node: Optional[Union[SinglyLinkedList, SLLNode]] = None
            ):
        """Print all elements of the specified list to stdout."""
        if list_or_node is None:
            print("Empty list.")
        if isinstance(list_or_node, SinglyLinkedList):
            SinglyLinkedList.list_elements_of(list_or_node.head)
            return
        if isinstance(list_or_node, SLLNode):
            print(list_or_node.data)
            element = list_or_node
            while element.next:
                element = element.next
                print(element.data)

    @staticmethod
    def prepend_to(original_list, list_or_data=None):
        """Prepend a node or data to the given list.

        list_or_data can be anything. If it's a SinglyLinkedList or SLLNode,
        the original_list gets attached to its tail and it's returned.
        Otherwise, a new node is created and the original list is appended to
        it.

        original_list   must be a SinglyLinkedList or SLLNode. A TypeError will
                        be raised on any other input.
        list_or_data    This can be a SinglyLinkedList, a SLLNode, or raw data
                        to be put in an SLLNode.

        Returns a SinglyLinkedList.
        May raise a TypeError.
        """
        if isinstance(original_list, SinglyLinkedList):
            return SinglyLinkedList.prepend_to(
                original_list.head, list_or_data
            )
        elif isinstance(original_list, SLLNode):
            # do actual stuff
            if isinstance(list_or_data, SLLNode):
                newList = SinglyLinkedList(list_or_data)
                # both values are SLLNodes representing their respective heads
                newList.tail.next = original_list
                return newList
            elif isinstance(list_or_data, SinglyLinkedList):
                return SinglyLinkedList.prepend_to(
                    original_list, list_or_data.head
                )
            else:
                return SinglyLinkedList.prepend_to(
                    original_list, SLLNode(list_or_data)
                )
        else:
            raise TypeError(
                "The original list should be a SinglyLinkedList or SLLNode, "
                f"got {original_list} of type {type(original_list)}")

    def prepend(self, data):
        """Add a new element at the beginning of the list."""
        if isinstance(data, SLLNode):
            get_tail_of(data).next = self.head
            self.head = data
        else:
            self.prepend(SLLNode(data))

    def append(self, data):
        """Add a new element to the end of the list."""
        if isinstance(data, SLLNode):
            # the received data is actually a node.
            if self.head:
                self.tail.next = data
            else:
                self.head = data
        else:
            self.append(SLLNode(data))

    @staticmethod
    def append_to(original_list, list_or_data):
        """Static version of append() which returns the modified list."""
        if isinstance(original_list, SinglyLinkedList):
            return SinglyLinkedList.append_to(
                original_list.head, list_or_data)
        elif isinstance(original_list, SLLNode):
            if isinstance(list_or_data, SinglyLinkedList):
                return SinglyLinkedList.append_to(
                    original_list.head, list_or_data)
            elif isinstance(list_or_data, SLLNode):
                new_list = SinglyLinkedList(list_or_data)
                new_list.tail.next = original_list
                return new_list
            else:
                return SinglyLinkedList.append_to(
                    original_list, SLLNode(list_or_data)
                )
        else:
            raise TypeError(
                "original_list must be a SinglyLinkedList or SLLNode. "
                f"Received {original_list} of type {type(original_list)}")

    def insert(self, data, position: int):
        """Insert the given data at the given index of this list."""
        if isinstance(data, SLLNode):
            index: int = 0
            old_list: SinglyLinkedList = SinglyLinkedList(self.head)
            working_node: SLLNode = old_list.head
            self.head = None
            while index < position:
                if not working_node.next:
                    raise ValueError(
                        f"The requested position ({position}) is longer than"
                        f" the total length of the list ({index})."
                    )
                index += 1
                self.append(working_node.data)
                working_node = working_node.next
            self.append(data)
            self.append(working_node)
        if isinstance(data, SinglyLinkedList):
            self.insert(data.head)
        else:
            self.insert(SLLNode(data))

    @staticmethod
    def insert_into(old_list, data, position: int):
        """Get a new list with the given data inserted into the given list."""
        assert isinstance(old_list, SinglyLinkedList)
        if isinstance(data, SLLNode):
            index, new_list = 0, SinglyLinkedList()
            working_node = old_list.head
            while index < position:
                if not working_node.next:
                    raise ValueError(
                        f"The requested position ({position}) is longer than"
                        f" the total length of the list ({index})."
                    )
                index += 1
                new_list.append(working_node.data)
                working_node = working_node.next
            new_list.append(data)
            new_list.append(working_node)
            return new_list
        if isinstance(data, SinglyLinkedList):
            return SinglyLinkedList.insert_into(old_list, data.head, position)
        else:
            return SinglyLinkedList.insert_into(
                old_list, SLLNode(data), position)

    def delete_by_index(self, index):
        """Delete an element by its position in the list."""
        self.head = delete_from_list_by_index(self.head, index).head

    def delete_by_value(self, value):
        """Delete all of the elements that match the value specified."""
        self.head = delete_from_head_by_value(self.head, value).head


def delete_from_list_by_index(linked_list, index):
    """Delete the element at the given position from the given list."""
    delete_from_head_by_index(linked_list.head, index)


def delete_from_head_by_index(head, index):
    assert isinstance(index, int)
    assert index >= 0
    out = SinglyLinkedList()
    working_node = head
    working_index = 0
    while working_node is not None:
        if working_index != index:
            out.append(working_node)
        index += 1
        working_node = working_node.next
    return out


def delete_from_list_by_value(linked_list, value):
    """Delete all the values from the list that match the value."""
    return delete_from_head_by_value(linked_list.head, value)


def delete_from_head_by_value(head, value):
    """Delete all the instances of the value in the list at head."""
    assert isinstance(value, int)
    out = SinglyLinkedList()
    working_node = head
    while working_node is not None:
        if working_node.data != value:
            out.append(working_node)
        working_node = working_node.next
    return out


def get_tail_of(head: Optional[SLLNode]) -> Optional[SLLNode]:
    """Return the last element of a linked list given the first."""
    if head:
        element = head
        while element.next:
            element = element.next
        return element
    return None     # received head was none.
