from _30_Sum_Of_List import head, tail, concat


# 列表元素全部 + 2
def list_add2(alist):
    if alist == []:
        return []
    else:
        return concat([head(alist)[0] + 2], tail(alist))


# 列表元素全部 × 2
def list_multi2(alist):
    if alist == []:
        return []
    else:
        return concat([head(alist)[0] * 2], tail(alist))


# module test
if __name__ == "__main__":
    listA = [1, 2, 9]
    print(f"listA = {listA}")
    print(f"add_list(listA) = {list_add2(listA)}")
    print(f"multi_list(listA) = {list_multi2(listA)}")
