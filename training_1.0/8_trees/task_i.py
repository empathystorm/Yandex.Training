import sys

sys.setrecursionlimit(100000)

class Node:
    def __init__(self, name):
        self.name = name
        self.parent = None
        self.descendants = 0

    def update_descendants(self, increment):
        self.descendants += increment
        if self.parent:
            self.parent.update_descendants(increment)

nodes = {}

def add(descendant, parent):
    if parent not in nodes:
        nodes[parent] = Node(parent)
    if descendant not in nodes:
        nodes[descendant] = Node(descendant)
    nodes[descendant].parent = nodes[parent]
    nodes[parent].update_descendants(nodes[descendant].descendants + 1)

fin = open("input.txt", 'r')
fout = open("output.txt", 'w')

n = int(fin.readline())

for i in range(n-1):
    descendant, parent = map(str, fin.readline().strip().split())
    add(descendant, parent)

for name, descendants in sorted((name, node.descendants) for name, node in nodes.items()):
    print(name, descendants, file=fout)