#include <stdio.h>
#include <stdlib.h>
/**
 * 求出字符串中的最长无重复字串
 * 用滑动窗口
*/
int lengthOfLongestSubstring(char * s){
    int start = 0;
    int end = 0;
    int maxsize = 0;
    int cursize = 0;
    int len = strlen(s);
    if (len == 0)
        return 0;
    for (; end < len && maxsize < len - start; end++) {// 滑动窗口变长
        cursize++;
        for (int k = start; k <= end; k++) {// k作为索引，每次从滑动窗的开始位置遍历，保证了cursize大小内滑动窗内的数字无重复
            if (s[k] == s[end + 1]) {
                if (cursize > maxsize)
                    maxsize = cursize;
                start = k + 1; // 从k开始到end+1是有重复且一定不是最长的，所以start=k+1
                cursize = end - start + 1;
                break;
            }
        }
    }
    if (cursize > maxsize) 
        return cursize;
    else
        return maxsize;
}

void main()
{
    char *s = "abcabcbb";
    int res = lengthOfLongestSubstring(s);
    printf("%d\n", res);
    getchar();
}