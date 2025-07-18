#include "base64.h"

/* For printf() */
#include <stdio.h>

/* For memcmp(), strlen() */
#include <string.h>

int main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		printf( "Please, enter only 1 argument\n" );
		return ( 1 );
	}

	size_t len = strlen( argv[1] );
	size_t ciphertext_length = 4 * ( ( len + 2 ) / 3 ); // Plus grand de 1 ou 2 octets

	uint8_t plaintext[len];
	uint8_t ciphertext[ciphertext_length];

	printf( "Original:   %s\n", argv[1] );
	base64_encode( ( const uint8_t * ) argv[1], len, ciphertext );

	printf( "Ciphertext: %s\n", ciphertext );

	base64_decode( ciphertext, ciphertext_length, plaintext );
	printf( "Plaintext:  %s\n", plaintext );

	if ( !memcmp( argv[1], plaintext, len ) )
		printf( "OK\n" );
	else
		printf( "KO\n" );

	return ( 0 );
}