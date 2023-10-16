from _03_Basis_Functions import *
from functools import reduce


# map函数，类似映射，将list中所有值按照mapping function转换为另一个值
def myMap(func, alist):
    if alist == []:
        return alist
    return concat([func(head(alist))], myMap(func, tail(alist)))

if False:
    print(list(map(lambda x: x * 2, [1, 2, 3])))
    print(list(myMap(lambda x: x * 2, [1, 2, 3])))


# filter函数，类似过滤，将list中符合filter function的值筛选出来
def myFilter(func, alist):
    if alist == []:
        return alist
    if func(head(alist)) is True:
        return concat([head(alist)], myFilter(func, tail(alist)))
    else:
        return myFilter(func, tail(alist))

if False:
    print(list(filter(lambda x: x < 60, [66, 59, 60, 66, 78])))
    print(list(myFilter(lambda x: x < 60, [66, 59, 60, 66, 78])))


# reduce函数，按照reduce function将整个列表reduce成一个值
def myReduce(func, alist):
    if alist == []:
        return None
    if len(alist) == 1:
        return head(alist)
    return func(head(alist), myReduce(func, tail(alist)))

if False:
    print(reduce(lambda x, y: x + y, [1, 2, 3, 4]))
    print(myReduce(lambda x, y: x + y, [1, 2, 3, 4]))
