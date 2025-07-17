#ifndef BASE64_H
#define BASE64_H

/* For uintX_t */
#include <stdint.h>

/* For size_t */
#include <stddef.h>

static const char BASE64_TABLE[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void base64_encode( const uint8_t *text, size_t len, uint8_t *ciphertext );

#endif
