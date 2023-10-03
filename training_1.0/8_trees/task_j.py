import sys

sys.setrecursionlimit(100000)

class Node:
    def __init__(self, name):
        self.name = name
        self.descendants = []
        self.depth = 0

    def update_depth(self, increment):
        self.depth += increment
        for descendant in self.descendants:
            descendant.update_depth(increment)         

nodes = {}

def add(descendant, parent):
    if parent not in nodes:
        nodes[parent] = Node(parent)
    if descendant not in nodes:
        nodes[descendant] = Node(descendant)
    nodes[parent].descendants.append(nodes[descendant])
    nodes[descendant].update_depth(nodes[parent].depth + 1)

fin = open("input.txt", 'r')
fout = open("output.txt", 'w')

n = int(fin.readline())

for i in range(n-1):
    descendant, parent = map(str, fin.readline().strip().split())
    add(descendant, parent)

for name, depth in sorted((name, node.depth) for name, node in nodes.items()):
    print(name, depth, file=fout)