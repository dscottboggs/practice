
def get_shortest(sticks):
    shortest = 10**3+1
    for stick in sticks:
        if stick < shortest:
            shortest = stick
    return shortest

delete_of_length = lambda length, sticks: [stick for stick in sticks if stick != length]

sub_from_all = lambda val, sticks: [stick - val for stick in sticks]

def cutSticks(sticks):
    out = []
    while sticks:
        out.append(len(sticks))
        shortest = get_shortest(sticks)
        sticks = delete_of_length(shortest, sticks)
        sticks = sub_from_all(shortest, sticks)
    return out
