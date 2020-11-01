#include "common.h"
#define RES_NUM (200)

// index是递归中下一次选元素的开始位置
void dfs(int *temp, int *candidates, int candidatesSize, int target, int *returnSize, int** returnColumnSizes, int pos, int index, int **result)
{
    if (target == 0) {
        result[*returnSize] = (int *)malloc(sizeof(int) * pos);
        memset(result[*returnSize], 0, sizeof(int) * pos);
        memcpy(result[*returnSize], temp, sizeof(int) * pos);
        (*returnColumnSizes)[*returnSize] = pos;
        (*returnSize)++;
        return;
    } else if (target < 0) {
        return;
    }

    for (int i = index; i < candidatesSize; i++) {
        temp[pos] = candidates[i];
        dfs(temp, candidates, candidatesSize, target - candidates[i], returnSize, returnColumnSizes, pos + 1, i, result);
    }
}


int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    if (candidatesSize == 0) {
        return NULL;
    }
    int **result = malloc(sizeof(int *) * RES_NUM);
    int pos = 0;  // real len of temp
    int index = 0;  // indicate the used element
    int *temp = malloc(sizeof(int) * RES_NUM);
    *returnSize = 0; // leetcode 这个需要自己申请！
    *returnColumnSizes = malloc(sizeof(int) * RES_NUM); // leetcode 这个需要自己申请！
    dfs(temp, candidates, candidatesSize, target, returnSize, returnColumnSizes, pos, index, result);

    return result;
}