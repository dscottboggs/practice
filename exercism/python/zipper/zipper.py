#!/usr/bin/env python3.7
from typing import Union, TypeVar, Optional, Mapping, Tuple

BT = TypeVar('BT')


def _destructure_dict(
    data: Mapping[str, Union[int, BT]]
) -> Tuple[int, Union[int, BT, None], Union[int, BT, None]]:
    value = data['value']
    assert isinstance(value, int)
    return value, data.get('left'), data.get('right')


class Zipper(object):
    _value: int
    _left: Optional['Zipper']
    _right: Optional['Zipper']
    _up: Optional['Zipper']

    @classmethod
    def from_dict(cls, data: Mapping[str, int]):
        return cls(data['value'])

    def __init__(self,
                 value: Union[Mapping[str, int], int],
                 left: Optional[Union[BT, int]] = None,
                 right: Optional[Union[BT, int]] = None):
        if isinstance(value, dict):
            return Zipper.from_dict(value)
        self._value = value
        self._left = left and Zipper(*_destructure_dict(left))
        self._right = right and Zipper(*_destructure_dict(right))

    @classmethod
    def from_tree(cls, tree) -> 'Zipper':
        return cls(tree['value'], tree['left'], tree['right'])

    def value(self):
        """Return the value at this node"""
        return self._value

    def set_value(self):
        pass

    def left(self) -> 'Zipper':
        pass

    def set_left(self) -> 'Zipper':
        pass

    def right(self) -> 'Zipper':
        pass

    def set_right(self) -> 'Zipper':
        pass

    def up(self) -> 'Zipper':
        pass

    def to_tree(self) -> 'Zipper':
        pass
