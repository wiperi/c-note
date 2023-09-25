from _30_Sum_Of_List import head, tail, concat


def list_add2(alist):
    if alist == []:
        return []
    else:
        return concat([head(alist)[0] + 2], tail(alist))


def list_multi2(alist):
    if alist == []:
        return []
    else:
        return concat([head(alist)[0] * 2], tail(alist))


# module test
listA = [1, 2, 9]
print(f"listA = {listA}")
print(f"multi_list(listA) = {list_add2(listA)}")
