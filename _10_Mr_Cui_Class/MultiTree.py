class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    def remove_child(self, child):
        self.children.remove(child)


# 递归方式构建多叉树
def build_tree(data):
    if not data:
        return None

    root_value = data[0]
    root = TreeNode(root_value)

    for child_data in data[1:]:
        child = build_tree(child_data)
        root.add_child(child)

    return root


# 遍历多叉树
def traverse_tree(node):
    if not node:
        return

    print(node.value)

    for child in node.children:
        traverse_tree(child)


# 示例用法
data = ["A", ["B", ["C"], ["D"]], ["E", ["F"]]]

root = build_tree(data)
traverse_tree(root)








