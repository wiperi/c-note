class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def preorder(root: TreeNode):
    if not root:
        return
    print(root.val)
    preorder(root.left)
    preorder(root.right)


def buildTree(alist: list) -> TreeNode:
    length = len(alist)
    nodes = [None] * length
    for i in range(length):
        nodes[i] = TreeNode(alist[i])  # 创建节点时应该直接调用构造函数，而不是使用.__init__
    for i in range(length):
        if (2 * i + 1) < length:
            nodes[i].left = nodes[2 * i + 1]
        if (2 * i + 2) < length:
            nodes[i].right = nodes[2 * i + 2]
    return nodes[0]


def insert(root: TreeNode, newval):
    pre = None
    while root != None:
        if newval > root.val:
            pre = root
            root = root.right
        if newval < root.val:
            pre = root
            root = root.left
    if newval > pre.val:
        pre.right = TreeNode(newval)
    else:
        pre.left = TreeNode(newval)


# test
def testBuildTree():
    alist = [5, 3, 7, 2, 4, 6, 8]
    root = buildTree(alist)  # 使用 buildTree 函数来构建二叉树
    preorder(root)  # 正确地打印出根节点的值


def testInsert():
    root = buildTree([6, 3, 8])
    insert(root, 1)
    insert(root, 7)
    preorder(root)


if __name__ == "__main__":
    testInsert()
