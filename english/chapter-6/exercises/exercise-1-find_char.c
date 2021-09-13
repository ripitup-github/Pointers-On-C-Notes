/**
 * The program requires two nested loops: 
 * The outer selects each character in the first string one by one, 
 * and the inner checks that character against each of the characters from the second string.
 * The loops can also be nested the other way around.
 * 
 * 
 * Find the first occurrence in ’str’ of any of the characters in ’chars’ 
 * and return a pointer to that location.
 * If none are found, or if 'str' or 'chars' are NULL pointers,
 * a NULL pointer is returned.
**/

#include <stdio.h>
#include <stdlib.h>

char * find_char(const char * source, const char * chars);

/**
 * function main is use to test.
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
     * 'char * cp':
     * Is order to make the inner initialize 'cp' to point to the starting position of chars 
     * when everytime the outter finish.
     * 
     * If you use 'chars' directly, it will cause segment fault.
     * Because when 'chars++', 'chars' out of bounds. 
    **/

    char * cp;

    if (source != NULL && chars != NULL) {

        /**
         * From 'source' first character compare with 'chars' every character,
         * until 'source' last character.
         * If match correctly, the first matched character's address will be returned.
         * Else, function return NULL
        **/

        for (; *source != '\0'; source++) {
            for (cp = chars; *cp != '\0'; cp++)
                if (*cp == *source)
                    return source;
        }
    }

    return NULL;
}