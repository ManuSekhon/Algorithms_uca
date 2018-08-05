#include <assert.h>
#include <string.h>

#include "base64.h"

// test cases for encode
void test_encode(void)
{
    assert(strcmp(encode("xyz"), "eHl6") == 0);
    assert(strcmp(encode("12dse"), "MTJkc2U=") == 0);
    assert(strcmp(encode("ABE3ls"), "QUJFM2xz") == 0);
    assert(strcmp(encode("?3#*21"), "PzMjKjIx") == 0);
}

// test cases for decode
void test_decode(void)
{
    assert(strcmp("xyz", decode("eHl6")) == 0);
    assert(strcmp("?3#*21", decode("PzMjKjIx")) == 0);
    assert(decode("sdsrt?#") == NULL);
    assert(strcmp("12dse", decode("MTJkc2U=")) == 0);
    
}

int main (void)
{
    test_encode();
    test_decode();
}