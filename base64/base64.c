/**
 * Implements base64 encoding and decoding functions for strings
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "base64.h"

// base64 encoding set
static const char base64_set[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// table to convert ascii values to 6-bit base64 values
static const int csix[256] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1,  0, -1, -1,
    -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
    -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

/**
 * Encodes the given plaintext into base64 and returns the encoded
 * string. Caller is responsible for freeing the encoded string.
 * Thanks to Apple opensource base64 page for inspiration.
 */
char *encode (const char *str)
{
    // length of output string
    int len = strlen(str);
    int output_len = ((len) / 3 * 4) + 2;
    char *out_str = malloc(output_len * sizeof(char));
    if (!out_str)
    {
        return NULL;
    }

    // encode data
    int i, index = 0;
    for (i = 0; i < len - 2; i += 3)
    {
        // first 6 bits of first char
        out_str[index++] = base64_set[(str[i] >> 2) & 0x3F];
        // next 2 bits of first char plus first 4 bits of second char
        out_str[index++] = base64_set[((str[i] & 0x3) << 4) | ((str[i + 1] >> 4) & 0xF)];
        // last 4 bits of second char plus first 2 bits of third char
        out_str[index++] = base64_set[((str[i + 1] & 0xF) << 2) | ((str[i + 2] >> 6) & 0x3)];
        // last 6 bits of third char
        out_str[index++] = base64_set[str[i + 2] & 0x3F];
    }

    // one char left
    if (i == len - 1)
    {
        out_str[index++] = base64_set[(str[i] >> 2) & 0x3F];
        out_str[index++] = base64_set[(str[i] & 0x3) << 4];
        out_str[index++] = '=';
        out_str[index++] = '=';
    }
    // two characters left
    else if (i < len)
    {
        out_str[index++] = base64_set[(str[i] >> 2) & 0x3F];
        out_str[index++] = base64_set[((str[i] & 0x3) << 4) | ((str[i + 1] >> 4) & 0xF)];
        out_str[index++] = base64_set[((str[i + 1] & 0xF) << 2)];
        out_str[index++] = '=';
    }

    out_str[index] = '\0';
    return out_str;
}

/**
 * Decodes the base64 string given as argument into plaintext.
 * Returns plaintext or null if it fails to decode. Caller is
 * responsible for freeing the decoded string.
 */
char *decode (const char *enc)
{
    int len = strlen(enc);

    // check if input is a valid base64 string
    for (int i = 0; i < len; i++)
    {
        if (csix[(int)enc[i]] == -1)
        {
            return NULL;
        }
    }

    // check if string is padded
    bool padding = (enc[len - 1] == '=');

    int out_len = ((len / 4) * 3) + 3;
    char *decoded = malloc(out_len * sizeof(char));
    if (!decoded)
    {
        return NULL;
    }

    // decode input
    int index = 0;
    for (int i = 0; i < len; i += 4)
    {
        // six bits of first char plus first two bits of second char
        decoded[index++] = ((csix[(int)enc[i]] & 0x3F) << 2) | ((csix[(int)enc[i + 1]] >> 4) & 0x3);
        // last four bits of second char and first four bits of third char
        decoded[index++] = ((csix[(int)enc[i + 1]] & 0xF) << 4) | ((csix[(int)enc[i + 2]] >> 2) & 0xF);
        // last two bits of third char and six bits of fourth char
        decoded[index++] = ((csix[(int)enc[i + 2]] & 0x3) << 6) | (csix[(int)enc[i + 3]] & 0x3F);
    }

    // loop already turns padding character to null terminator
    if (!padding)
    {
        decoded[index] = '\0';
    }

    return decoded;
}