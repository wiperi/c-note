def bucketSortVerMy(arr):
    bucket = [0 for _ in range(10)]
    for i in range(len(arr)):
        bucket[arr[i]] += 1

    ret = []
    for i in range(len(bucket)):
        for _ in range(bucket[i]):
            ret.append(i)
            print(i)


if 0:
    bucketSortVerMy([4, 3, 2, 1])


def fillBucket(arr):
    b = [0 for _ in range(10)]
    for i in range(len(arr)):
        b[arr[i]] += 1
    return b


def pourBucket(b):
    ret = []
    for i in range(len(b)):
        for _ in range(b[i]):
            ret.append(i)
    return ret


def bucketSortVerCui(arr):
    return pourBucket(fillBucket(arr))


if 0:
    print(bucketSortVerCui([4, 3, 2, 1]))


def bucket_sort(nums: list[float]):
    """桶排序"""
    # 初始化 k = n/2 个桶，预期向每个桶分配 2 个元素
    k = len(nums) // 2
    buckets = [[] for _ in range(k)]
    # 1. 将数组元素分配到各个桶中
    for num in nums:
        # 输入数据范围 [0, 1)，使用 num * k 映射到索引范围 [0, k-1]
        i = int(num * k)
        # 将 num 添加进桶 i
        buckets[i].append(num)
    # 2. 对各个桶执行排序
    for bucket in buckets:
        # 使用内置排序函数，也可以替换成其他排序算法
        bucket.sort()
    # 3. 遍历桶合并结果
    i = 0
    for bucket in buckets:
        for num in bucket:
            nums[i] = num
            i += 1
