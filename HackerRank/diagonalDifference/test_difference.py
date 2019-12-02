from difference import diagonal_difference, left_diagonal_sum
from difference import right_diagonal_sum

arrays = [
    {
        'array': [[11, 2,   4],
                  [ 4, 5,   6],
                  [10, 8, -12]],
        'right': 4,
        'left': 19,
        'diff': 15
    }, {
        'array': [[15,  7, 90,  2],
                  [356,-5, -2,  0],
                  [50, 50, 50, 50],
                  [-50, 0,  0,-60]],
        'right': 0,
        'left': 0,
        'diff': 0
    }
    # TODO: more test cases
]


def test_right_diagonal():
    """Test that the right diagonal sum of the array is the correct value."""
    for array in arrays:
        assert right_diagonal_sum(array['array']) == array['right']


def test_left_diagonal():
    """Test that the left diagonal sum of the array is the correct value."""
    for array in arrays:
        assert left_diagonal_sum(array['array']) == array['left']


def test_difference():
    """Test that diagonal_difference() outputs the right values."""
    for array in arrays:
        assert diagonal_difference(array['array']) == array['diff']
