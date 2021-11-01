def solution(arr):
    globalSum, localSum=0, 0
    for i in range(len(arr)):
        curr=arr[i]
        if(localSum+curr<localSum):
            localSum=0
        else:
            localSum=curr+localSum
        globalSum=max(localSum, globalSum)
#         print(localSum, globalSum)
    return globalSum
arr=list(map(int, input().strip().split()))
p = solution(arr)
p
