from typing import Union, TypeVar, Any
from math import sqrt

Number = Union[int, float]


class ComplexNumber:
    def __init__(self, real: Number, imaginary: Number):
        self.real: Number = real
        self.imaginary: Number = imaginary

    def __eq__(self, other: object) -> bool:
        if isinstance(other, type(self)):
            return (self.real == other.real) and (self.imaginary == other.imaginary)
        if isinstance(other, int):
            return self == ComplexNumber(other, 0)
        raise TypeError(f"expected {other} to be a ComplexNumber")

    def __add__(self, other: Any) -> 'ComplexNumber':
        if isinstance(other, ComplexNumber):
            return ComplexNumber(self.real + other.real, self.imaginary + other.imaginary)
        if isinstance(other, tuple) and len(other) == 2:
            return self + ComplexNumber(*other)
        if isinstance(other, int) or isinstance(other, float):
            return self + ComplexNumber(other, 0)
        raise TypeError(f"expected {other} to be a ComplexNumber, or a single "
                        "or pair of values which can be translated into a "
                        "complex number")

    def __mul__(self, other):
        if isinstance(other, ComplexNumber):
            return ComplexNumber(
                self.real * other.real - self.imaginary * other.imaginary,
                self.imaginary * other.real + self.real * other.imaginary
            )

    def __sub__(self, other: Any) -> 'ComplexNumber':
        if isinstance(other, ComplexNumber):
            return ComplexNumber(self.real - other.real, self.imaginary - other.imaginary)
        if isinstance(other, tuple) and len(other) == 2:
            return self - ComplexNumber(*other)
        if isinstance(other, int) or isinstance(other, float):
            return self - ComplexNumber(other, 0)
        raise TypeError(f"expected {other} to be a ComplexNumber, or a single "
                        "or pair of values which can be translated into a "
                        "complex number")

    def __truediv__(self, other):
        pass

    def __abs__(self) -> float:
        return sqrt(self.real ** 2 + self.imaginary ** 2)

    def conjugate(self):
        return ComplexNumber(self.real, -self.imaginary)

    def exp(self):
        pass
