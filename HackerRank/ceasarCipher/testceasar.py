from ceasar import fix_shift, convert_alphabet

shifted_5 = 'vwxyzabcdefghijklmnopqrstu'
shifted_10 = 'qrstuvwxyzabcdefghijklmnop'
shifted_20 = 'ghijklmnopqrstuvwxyzabcdef'
shifted_25 = 'bcdefghijklmnopqrstuvwxyza'


def test_fix_shift():
    assert fix_shift(25) == 25
    assert fix_shift(27) == 1
    assert fix_shift(50) == 24
    assert fix_shift(-5) == 21
    assert fix_shift(90) == 12


def test_convert_alphabet():
    assert convert_alphabet(5) == shifted_5
    assert convert_alphabet(10) == shifted_10
    assert convert_alphabet(-1) == shifted_25

def test_encode():
    # TODO: write tests for encode function
    ...
