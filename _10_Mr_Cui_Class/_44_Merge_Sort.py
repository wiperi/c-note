from _03_Basis_Functions import head, tail, concat


"""
归并排序为什么快? 

对于两个本身有序的数组, 目标是将它们合并成有序的一个数组。
方案1, 拼接2个数组, 然后选择排序, 复杂度(m + n)^2 / 2
方案2, 归并排序的merge方法, 最差复杂度m + n, 最佳复杂度min(m, n)
方案1忽略了子数组本身有序的特性, 导致复杂度平方级别, 而方案2充分利用了这一点。
"""


# 合并两个数组
def mergeRecur(l, r):
    if l == []:
        return r
    if r == []:
        return l

    if head(l) < head(r):
        return concat(head(l), mergeRecur(tail(l), r))
    else:
        return concat(head(r), mergeRecur(l, tail(r)))


# 列表对半切片
def split(arr):
    mid = (len(arr) - 1) // 2
    return arr[0 : mid + 1], arr[mid + 1 : len(arr)]


# 递归，自顶向下的归并
def mergeSortRecur(arr):
    if len(arr) == 1:  # baes case
        return arr
    left, right = split(arr)
    return mergeRecur(mergeSortRecur(left), mergeSortRecur(right))


if False:
    print(mergeSortRecur([7, 5, 4, 3, 1, 4, 6, 9, 8, 0]))
