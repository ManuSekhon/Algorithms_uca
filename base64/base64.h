/**
 * Implements base64 encoding and decoding functions for strings
 */

#ifndef BASE64_H
#define BASE64_H

/**
 * Encodes the given plaintext into base64 and returns the encoded
 * string. Caller is responsible for freeing the encoded string.
 */ 
char *encode (const char *plaintext);

/**
 * Decodes the base64 string given as argument into plaintext.
 * Returns plaintext or null if it fails to decode. Caller is
 * responsible for freeing the decoded string.
 */
char *decode (const char *encoded);

#endif // BASE64_H