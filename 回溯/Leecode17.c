#include "common.h"

char phone_num[10][5] = {
    {'\0'},
    {'\0'},
    {'a', 'b', 'c', '\0'},  // 2
    {'d', 'e', 'f', '\0'},  // 3
    {'g', 'h', 'i', '\0'},  // 4
    {'j', 'k', 'l', '\0'},  // 5
    {'m', 'n', 'o', '\0'},  // 6
    {'p', 'q', 'r', 's', '\0'}, // 7
    {'t', 'u', 'v', '\0'},  // 8
    {'w', 'x', 'y', 'z', '\0'}  // 9
};

void dfs(char *temp, char *digits, int step, int len, int *returnSize, char **res)
{
    if (step >= len) { // end of this step
        res[*returnSize] = (char *)malloc(sizeof(char) * len + 1);
        strncpy(res[*returnSize], temp, len);
        res[*returnSize][len] = '\0';
        (*returnSize)++;
        return;
    }

    for (int i = 0; phone_num[digits[step] - '0'][i] != '\0'; i++) {
        temp[step] = phone_num[digits[step] - '0'][i];
        dfs(temp, digits, step + 1, len, returnSize, res);
    }
    
}

char ** letterCombinations(char * digits, int* returnSize)
{
    char **res = (char **)malloc(sizeof(char*) * 150);;
    int len = strlen(digits);
    *returnSize = 0;
    if (len != 0) {
        char *temp = (char *)malloc(sizeof(char) * strlen(digits));
        dfs(temp, digits, 0, strlen(digits), returnSize, res);
    }
    return res;
}

int main()
{
    char *digits = "23";
    int returnSize = 0;

    char **res = malloc(sizeof(char*) * 100);
    res = letterCombinations(digits, &returnSize);
    return 0;
}