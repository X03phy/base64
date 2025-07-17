#include "base64.h"

void base64_encode( const uint8_t *text, size_t len, uint8_t *ciphertext )
{
	size_t text_index = 0;
	size_t ciphertext_index = 0;

	while ( text_index < len )
	{
		ciphertext[ciphertext_index++] = BASE64_TABLE[( ( text[text_index] & 0xFC ) >> 2 )];

		if ( ( text_index + 1 ) == len )
		{
			ciphertext[ciphertext_index++] = BASE64_TABLE[( ( text[text_index] & 0x3 ) << 4 )];
			ciphertext[ciphertext_index++] = '=';
			ciphertext[ciphertext_index++] = '=';
			break;
		}

		ciphertext[ciphertext_index++] = BASE64_TABLE[( ( ( text[text_index] & 0x3 ) << 4 ) |
														( ( text[text_index + 1] & 0xF0 >> 4 ) ) )];

		if ( ( text_index + 2 ) == len )
		{
			ciphertext[ciphertext_index++] = BASE64_TABLE[( ( text[text_index + 1] & 0xF ) << 2 )];
			ciphertext[ciphertext_index++] = '=';
			break;
		}

		ciphertext[ciphertext_index++] = BASE64_TABLE[( ( ( text[text_index + 1] & 0xF ) << 2 ) |
														( ( text[text_index + 2] & 0xC0 ) >> 6 ) )];
		ciphertext[ciphertext_index++] = BASE64_TABLE[( text[text_index + 2] & 0x3F )];
		text_index += 3;
	}

	ciphertext[ciphertext_index] = '\0';
}

void base64_encode( const uint8_t *ciphertext, size_t len, uint8_t *text )
{

}

