import sys
from _03_Basis_Functions import *

# 检查当前python的module搜索路径
print(f"\n\nsys.path = {sys.path}\n\n")


# 列表中每个元素相乘
def multi_list(alist: list) -> int:
    if alist == []:
        return 1
    else:
        return head(alist) * multi_list(tail(alist))


# 列表元素计数
def count_list(alist: list, acc: int) -> int:
    if head(alist) != None:
        return count_list(tail(alist), acc + 1)
    else:
        return acc


# 列表元素全部 + 2
def list_add2(alist):
    if alist == []:
        return []
    else:
        return concat([head(alist) + 2], tail(alist))


# 列表元素全部 × 2
def list_multi2(alist):
    if alist == []:
        return []
    else:
        return concat([head(alist) * 2], tail(alist))


# module test
if __name__ == "__main__":
    list1 = [3, 4, 5]
    print(f"multi_list(list1) = {multi_list(list1)}")
    print(f"count_list(list1) = {count_list(list1, 0)}")

    list1 = [1, 2, 9]
    print(f"list1 = {list1}")
    print(f"add_list(list1) = {list_add2(list1)}")
    print(f"multi_list(list1) = {list_multi2(list1)}")
