def void():
    pass

def truthy_or_falsey():
    for value in (True, False, 0, -1, 1, "", [], {}, None, void()):
        if value:
            yield str(value), True
        else:
            yield str(value), False

for value, bool in truthy_or_falsey():
    print("{} was {}".format(value, bool))
