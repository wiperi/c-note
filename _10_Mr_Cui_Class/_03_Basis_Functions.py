def head(alist: list) -> int:
    if alist == []:
        return None
    return alist[0]


def tail(alist: list):
    return alist[1:]


def concat(a: list, b: list) -> list:
    return a + b
