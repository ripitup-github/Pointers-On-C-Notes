/**
 * 通过使用2个for循环嵌套遍历source和chars的字符是否匹配
 * 并返回一个指针指向第一个匹配字符在source中的位置
 * 
 * 如果不存在匹配，或者source和chars两个参数其中有1个或2个是NULL
 * 则函数返回NULL
**/

#include <stdio.h>
#include <stdlib.h>

char * find_char(const char * source, const char * chars);

/**
 * main函数用于测试
**/

int main(void)
{
    char * source = "ABCDEF";
    char * chars = "XRCQEF";

    printf("%s\n", find_char(source, chars));

    return EXIT_SUCCESS;
}

char * find_char(const char * source, const char * chars)
{
    /**
     * 创建cp，目的是为了完成一次外循环后，使内循环初始化cp指向chars的起始位置
     * 如果直接使用chars，将导致segment fault
    **/

    char * cp;

    if (source != NULL && chars != NULL) {

        /**
         * 从source的第一个字符开始与chars字符串从头到尾逐一比较，直至source的最后一个字符
         * 如若中途字符匹配则返回指向source中的对应字符的指针
        **/

        for (; *source != '\0'; source++) {
            for (cp = chars; *cp != '\0'; cp++)
                if (*cp == *source)
                    return source;
        }
    }

    return NULL;
}