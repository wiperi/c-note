import sys
from _30_Sum_Of_List import *

# 检查当前python的module搜索路径
print(f"\n\nsys.path = {sys.path}\n\n")


# 列表中每个元素相乘
def multi_list(alist: list) -> int:
    if alist == []:
        return 1
    else:
        return head(alist)[0] * multi_list(tail(alist))


# 列表元素计数
def count_list(alist: list, acc: int) -> int:
    if head(alist) != []:
        return count_list(tail(alist), acc + 1)
    else:
        return acc


# module test
if __name__ == "__main__":
    listA = [3, 4, 5]
    print(f"multi_list(listA) = {multi_list(listA)}")
    print(f"count_list(listA) = {count_list(listA, 0)}")
