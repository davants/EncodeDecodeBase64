#include <iostream>
#include <string>

#include "EncodeDecodeBase64.h"

using namespace Matthew5::Util;

void TestStringEncode(void)
{
	std::string vUrl = "Stuff that can't go as a url query string, like another url...https://www.bing.com and stuff like { } | \\ ^ ~ [ ]\"";
	
	std::cout << std::endl << std::endl << "Original String to Encode: \n" << vUrl;

	std::string vEncodedString = EncodeDecodeBase64::base64_encodeString(vUrl);

	std::cout << std::endl << std::endl << "Encoded Version: \n" << vEncodedString;

	// Now back again

	std::string vBackAgain = EncodeDecodeBase64::base64_decodeString(vEncodedString);

	if (vBackAgain != vUrl)
	{
		std::cout << std::endl << "ERROR - The decoded string does not match the original!";
	}
	else
	{
		std::cout << std::endl << std::endl << "Match! - The decoded string mathes the original.";
		std::cout << std::endl << std::endl << "Decoded, back again, version that matches the original: \n" << vBackAgain;
	}
}

void TestBinaryEncode(void)
{
	// This function will create a blob of data, encode it and then bring it back!
	std::cout << std::endl << "Test blob encode and decode.";

	//std::cout << std::endl << "Blob before endoding: ";

	float blob[1000];
	for (int i = 0; i < 1000; i++)
	{
		blob[i] = i * 5.1f;
		
		//std::cout << blob[i] << ",";
	}

	size_t vSizeOfBlob = sizeof(blob);

	// Cast it to an unsigned char because that is what the encode function wants.
	const unsigned char * vpBlob = (const unsigned char *)blob;

	std::string vEncodedBlob = EncodeDecodeBase64::base64_encode(vpBlob, vSizeOfBlob);

	// std::cout << std::endl << "Encoded Blob Value: " << vEncodedBlob;

	// Now back again

	std::string vBackAgain = EncodeDecodeBase64::base64_decodeString(vEncodedBlob);

	const unsigned char * vpBlobBack = (const unsigned char *)vBackAgain.c_str();;

	float * vpBlobBackFloat = (float *)vpBlobBack;

	// Now use the ol C/C++ memory compare function to see if things are back to Nice!
	// - memcmp takes two addresses and the number of bytes you want to compare.
	int vMemCmpResult = memcmp(vpBlobBackFloat, blob, vSizeOfBlob);
	// If memcmp returns zero the blobs match.
	const int Match = 0;

	if (vMemCmpResult == Match)
	{
		std::cout << std::endl << std::endl << "Match! - The decoded blob matches the original.";

		//std::cout << std::endl << "Decoded blob: ";

		for (int i = 0; i < 1000; i++)
		{
			//std::cout << vpBlobBackFloat[i] << ",";
		}
	}
	else
	{
		std::cout << std::endl << "ERROR - Decoded blob does not match the original!";
	}
}

int main()
{
	std::cout << "Hello";

	std::cout << std::endl << std::endl << "............................................";
	std::cout << std::endl << "Test encoding and decoding a std::string with special chars.";


	TestStringEncode();

	std::cout << std::endl << std::endl << "............................................";


	std::cout << std::endl << "Now test binary data";

	TestBinaryEncode();

	std::cout << std::endl << std::endl << std::endl << "Type any key to exit.";


	std::cin.get();
}