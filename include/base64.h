#ifndef BASE64_H
#define BASE64_H

/* For uintX_t */
#include <stdint.h>

/* For size_t */
#include <stddef.h>

static const char BASE64_TABLE[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

typedef struct s_base64_ctx
{
	uint8_t buffer[3];
} t_base64_ctx;

void base64_encode( const uint8_t *data, size_t len, uint8_t *ciphertext );

#endif
