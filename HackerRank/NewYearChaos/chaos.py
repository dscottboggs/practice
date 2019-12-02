

CHAOS_ERR = "Too chaotic"
allowed_epsilon = 2

class TestCase:
    def __init__(self, bribes, *values):
        self.bribes = bribes or CHAOS_ERR
        self.values = list(values)

cases = (
    TestCase(3, 2, 1, 5, 3, 4),
    TestCase(None, 2, 5, 1, 3, 4),
    TestCase(None, 5, 1, 2, 3, 7, 8, 6, 4),
    TestCase(7, 1, 2, 5, 3, 7, 8, 6, 4)
)

def test_chaos():
    for case in cases:
        assert minimum_bribes(case.values) == (case.bribes)

def minimum_bribes(queue):
    swaps = 0
    swapped = False
    bribes = {}

    for q_pos in xrange(len(queue) - 1):
        for sort_pos in xrange(len(queue) - 1):
            if queue[sort_pos] > queue[sort_pos + 1]:
                bribes[queue[sort_pos]-1] = bribes.get(queue[sort_pos]-1, 0) + 1
                if bribes[queue[sort_pos]-1] > 2:
                    return CHAOS_ERR
                queue[sort_pos], queue[sort_pos + 1] = queue[sort_pos + 1], queue[sort_pos]
                swaps += 1
                swapped = True
        if not swapped:
            break
    return swaps
