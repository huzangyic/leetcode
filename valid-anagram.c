#include <string.h>
#include <stdio.h>

/**
先排序，再统计的方法
*/
void sort(char *s)
{
	int i = 0;
    	int j = 0;
    	for (i = 1; i < strlen(s); i++) {
		if (*(s+i) < *(s+i-1)) {
			int tmp = *(s+i);
			for (j = i-1; (*(s+j) > tmp) && j >= 0; j--) {
				*(s+j+1) = *(s+j);
			}
			*(s+j+1) = tmp;
		}
    	}
}

int method1()
{
	char s1[512] = "anagram";
        char s2[512] = "nagaram";
        sort(s1);
        sort(s2);
        if (strcmp(s1, s2) != 0) {
                return -1;
        }
        return 0;
}

/**
不用排序的方法，两个字符串中字符统计数应该是相等的
*/
int method2()
{
	char s1[512] = "anagram";
	char s2[512] = "nagaram";
	int n = strlen(s1);
	int m = strlen(s2);
	if (n != m) {
		return -1;
	}

	char a[26] = {0};
	int i = 0;
	for (i = 0; i < n; i++) {
		a[s1[i] - 'a']++;
		a[s2[i] - 'a']--;
	}
	for (i = 0; i < 26; i++) {
		if(a[i] != 0)
			return -1;
	}
	return 0;
}

int main()
{
	method1();
	method2();
	return 0;
}
