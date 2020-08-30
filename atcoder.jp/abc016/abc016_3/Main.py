class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())


n, m = map(int, input().split())
my_friends = [[] for _ in range(n + 1)]
uf = UnionFind(n + 1)
for i in range(m):
    a, b = map(int, input().split())
    my_friends[a].append(b)
    my_friends[b].append(a)
    uf.union(a, b)
# print(my_friends)
# print(uf)
for i in range(1, n + 1):
    ans = 0
    member = set()
    for friend in my_friends[i]:
        s = set(my_friends[friend])
        member |= s
    ans = max(0, len(member) - len(member & set(my_friends[i])) - 1)
    # print(member)
    # print((member & set(my_friends[i])))
    print(ans)


