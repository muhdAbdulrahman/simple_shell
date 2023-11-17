#include "simpleshell.h"

/**
 * Check if the shell is in interactive mode.
 *
 * @param info The struct containing shell information.
 * @return 1 if in interactive mode, 0 otherwise.
 */
int interactive(info_t *info) {
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * Check whether a character is a delimiter.
 *
 * @param chr The character to check.
 * @param delim The delimiter string.
 * @return 1 if true, 0 otherwise.
 */
int is_delim(char chr, char *delim) {
    while (*delim) {
        if (*delim++ == chr)
            return 1;
    }
    return 0;
}

/**
 * Check if a character is alphabetic.
 *
 * @param chr The character to check.
 * @return 1 if alphabetic, 0 otherwise.
 */
int _isalpha(int chr) {
    return ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'));
}

/**
 * Convert a string to an integer.
 *
 * @param strg The string to be converted.
 * @return 0 if no numbers in the string, the converted number otherwise.
 */
int _atoi(char *strg) {
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; strg[i] != '\0' && flag != 2; i++) {
        if (strg[i] == '-')
            sign *= -1;

        if (strg[i] >= '0' && strg[i] <= '9') {
            flag = 1;
            result *= 10;
            result += (strg[i] - '0');
        } else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return output;
}
