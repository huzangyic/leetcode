#include "common.h"

#define RES_NUM (200)

int cmp(const void *p, const void *q)
{
    int *a = (int *)p;
    int *b = (int *)q;
    
    return (*a) > (*b);
}

void dfs(int *temp, int *candidates, int candidatesSize, int target, int *returnSize, int** returnColumnSizes, int pos, int index, int **res)
{
    if (target == 0) {
        res[*returnSize] = malloc(sizeof(int) * pos);
        memcpy(res[*returnSize], temp, sizeof(int) * pos);
        (*returnSize)++;
        (*returnColumnSizes)[*returnSize] = pos;
        return;
    } else if (target < 0) {
        return;
    }

    for (int i = index; i < candidatesSize; i++) {
        if (i > index && candidates[i - 1] == candidates[i]) { // 这里的i>index精髓
            continue;
        }
        temp[pos] = candidates[i];
        dfs(temp, candidates, candidatesSize, target - candidates[i], returnSize, returnColumnSizes, pos + 1, i + 1, res);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) // 这个二维数组就是对一个一位数组取指
{
    if (candidatesSize == 0) {
        return NULL;
    }
    int **res = malloc(sizeof(int *) * RES_NUM);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int *) * RES_NUM);

    // sort
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    // filter
    // int del = 0;
    // for (int i = 0; i < candidatesSize; i++) {
    //     if (candidates[i] == candidates[i + 1]) {
    //         del++;
    //     } else {
    //         candidates[i - del] = candidates[i];
    //     }
    // }
    int *temp = malloc(sizeof(int) * RES_NUM);

    dfs(temp, candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, 0, res);
    return res;
}

int main()
{
    int candidates[5] = {2,5,2,1,2};
    int returnSize = 0;
    int **returnColumnSizes = malloc(sizeof(int *) * 1);
    combinationSum2(candidates, 5, 5, &returnSize, returnColumnSizes);
    return 0;
}