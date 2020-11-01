#include "common.h"

#define NUM (15000)
#define NUM_SIGN (3)

char signs[NUM_SIGN] = {'(', ')', '\0'};

void dfs(char *temp, int n, int len, int left, int right, int *returnSize, char **res)
{
    if (right == n && left == n) {
        res[*returnSize] = malloc(sizeof(char) * (2 * n + 1));
        strncpy(res[*returnSize], temp, (2 * n + 1));
        res[*returnSize][(2 * n + 1) - 1] = '\0';
        (*returnSize)++;
        return;
    }

    if (left < n) { // add left
        temp[len] = signs[0];
        dfs(temp, n, left + right + 1, left + 1, right, returnSize, res);
    }
    if (left > right && right < n) { // add right
        temp[len] = signs[1];
        dfs(temp, n, left + right + 1, left, right + 1, returnSize, res);
    }
}

char ** generateParenthesis(int n, int* returnSize)
{
    char **res = malloc(sizeof(char) * NUM);
    *returnSize = 0;
    if (n != 0) {
        char *temp = malloc(sizeof(char) * (2 * n + 1));
        temp[0] = signs[0];
        dfs(temp, n, 1, 1, 0, returnSize, res);
    }
    return res;
}

int main()
{
    int n = 2;
    int returnSize = 0;
    generateParenthesis(n, &returnSize);
    return 0;
}