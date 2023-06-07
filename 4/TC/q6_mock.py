def functionRep(x, y, z):
    if z == 1:
        return x, y
    else:
        x = x + y
        y = y + 5
        z = z - x + 1   # special minus
        return functionRep(x, y, z)
