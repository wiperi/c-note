def head(alist: list) -> int:
    if alist == []:
        return None
    return alist[0]


def tail(alist: list):
    return alist[1:]


def concat(a, b):
    if isinstance(a, list):
        return a + b
    else:
        alist = [1]
        alist[0] = a
        return alist + b
        
