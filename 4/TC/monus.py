def pred(x):
    if x == 0:
        return 0
    else:
        return x


def monus1(x):
    if x == 0:
        return 0
    else:
        pred(monus1(x))
