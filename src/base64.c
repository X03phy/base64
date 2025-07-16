#include "base64.h"

void base64_encode( const uint8_t *data, size_t len, uint8_t *ciphertext )
{
	size_t data_index = 0;
	size_t ciphertext_index = 0;

	while ( data_index < len )
	{
		ciphertext[ciphertext_index++] = BASE64_TABLE[( ( data[data_index] & 0xFC ) >> 2 )];

		if ( ( data_index + 1 ) == len )
		{
			ciphertext[ciphertext_index++] = BASE64_TABLE[( ( data[data_index] & 0x3 ) << 4 )];
			ciphertext[ciphertext_index++] = '=';
			ciphertext[ciphertext_index++] = '=';
			break;
		}

		ciphertext[ciphertext_index++] = BASE64_TABLE[( ( ( data[data_index] & 0x3 ) << 4 ) |
														( ( data[data_index + 1] & 0xF0 >> 4 ) ) )];

		if ( ( data_index + 2 ) == len )
		{
			ciphertext[ciphertext_index++] = BASE64_TABLE[( ( data[data_index + 1] & 0xF ) << 2 )];
			ciphertext[ciphertext_index++] = '=';
			break;
		}

		ciphertext[ciphertext_index++] = BASE64_TABLE[( ( ( data[data_index] & 0x3 ) << 4 ) |
														( ( data[data_index + 1] & 0xF0 ) >> 4 ) |
														( ( data[data_index + 2] & 0xC0 ) >> 6 ) )];
		ciphertext[ciphertext_index++] = BASE64_TABLE[( data[data_index + 2] & 0x3F )];
		data_index += 3;
	}

	ciphertext[ciphertext_index] = '\0';
}
