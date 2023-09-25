def head(alist: list) -> list:
    return alist[0:1]


def tail(alist: list):
    return alist[1:]


def concat(a: list, b: list) -> list:
    return a + b


# 用循环不变式，数学归纳法验证这个算法是否正确？
# 先证明 input = 0 成立；
# 再假设 input = k 成立，证明 input = k + 1 也成立；
# 
# 对于这个函数，示范如下：
# input = [] 
# return = 0 成立
# 接着，假设 sum_of_list(tail([b,c...n])) 是正确的
# 那么 sum_of_list([a,b,c...n]) 的运算结果是
# return a + sum_of_list(tail([b,c...n])) 结果正确
# 所以得出结论：该函数对于所有输入是正确的
def sum_of_list(alist: list) -> int:
    if alist == []:
        return 0
    else:
        return alist[0] + sum_of_list(tail(alist))


# 返回分数<60的元素的列表
def filter_failures(alist: list) -> list:
    if not alist:
        return []
    elif alist[0] < 60:
        return alist[0:1] + filter_failures(alist[1:])
    else:
        return filter_failures(alist[1:])


# module test
listA = [66, 77, 88, 99, 55]
listB = [11, 22, 33]
print(f"head(listA) = {head(listA)}")
print(f"tail(listA) = {tail(listA)}")
print(f"concat(listA, listB) = {concat(listA, listB)}")
print(f"sum_of_list(listB) = {sum_of_list(listB)}")
print(f"filter_failures = {filter_failures(listA)}")
