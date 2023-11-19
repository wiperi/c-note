row, col = 10


class point:
    isArrived: bool = False


# 0 means not used, 1 means used
matrix = [row * 0][col * 0]
start = (1, 2)
end = (10, 9)

position = start
path = []


def dfs(position):
    if position == end:
        return path

    for choice in choiceSet:
        if choice is not arrived:
            dfs(matrix, choice)
