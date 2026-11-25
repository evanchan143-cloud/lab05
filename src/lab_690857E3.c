#include <stdio.h>
#include <string.h>

/**
 * Copies at most `num_char` characters from `psource` to `ptarget`.
 * Ensures the target buffer is null-terminated.
 */
void copy(char *psource, char *ptarget, unsigned num_char) {
    unsigned i = 0;
    
    // Copy characters until we hit the null-terminator of psource 
    // or reach the limit num_char
    while (i < num_char && *psource != '\0') {
        *ptarget = *psource;
        ptarget++;
        psource++;
        i++;
    }
    
    // Null-terminate the destination buffer
    *ptarget = '\0';
}

/**
 * Concatenates two strings psrc1 and psrc2 into ptarget.
 * num_char represents the total size of the destination buffer (ptarget) to avoid buffer overflow.
 */
void concatenate(char *psrc1, char *psrc2, char *ptarget, unsigned num_char) {
    if (num_char == 0) return;
    
    unsigned chars_written = 0;
    
    // 1. Copy the first string (psrc1) into ptarget as much as possible
    while (chars_written < num_char - 1 && *psrc1 != '\0') {
        *ptarget = *psrc1;
        ptarget++;
        psrc1++;
        chars_written++;
    }
    
    // 2. Concatenate the second string (psrc2) into ptarget up to the remaining buffer limit
    while (chars_written < num_char - 1 && *psrc2 != '\0') {
        *ptarget = *psrc2;
        ptarget++;
        psrc2++;
        chars_written++;
    }
    
    // 3. Always null-terminate the final output string
    *ptarget = '\0';
}


// DO NOT change the code below
#ifndef ___TEST___
int main(void)
{
    char buffer[100];
    char *source = "This is the first sentence.  ";
    char *target = "This is the second sentence.";

    concatenate(source, target, buffer, 70);

    printf("%s", buffer);
    return 0;
}
#endif
// DO NOT change the code above