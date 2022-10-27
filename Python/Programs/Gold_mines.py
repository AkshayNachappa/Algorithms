MAX = 100
def getMaxGold(gold, m, n):
    goldTable = [[0 for i in range(n)]
                        for j in range(m)]
    for col in range(n-1, -1, -1):
        for row in range(m):
            if (col == n-1):
                right = 0
            else:
                right = goldTable[row][col+1]
            if (row == 0 or col == n-1):
                right_up = 0
            else:
                right_up = goldTable[row-1][col+1]
            if (row == m-1 or col == n-1):
                right_down = 0
            else:
                right_down = goldTable[row+1][col+1]
            goldTable[row][col] = gold[row][col] + max(right, right_up, right_down)
    res = goldTable[0][0]
    for i in range(1, m):
        res = max(res, goldTable[i][0])

    return res
gold = [[0,1,4,2,8,2]
,[4,3,6,5,0,4]
,[1,2,4,1,4,6]
,[2,0,7,3,2,2]
,[3,1,5,9,2,4]
,[2,7,0,8,5,1
]]
m = len(gold[0])
n = len(gold[0])
print(getMaxGold(gold, m, n))
