#pragma once

#include <string>
	
namespace Matthew5
{
	namespace Util
	{
		// These comments were added by Davant Stewart.
		// Encoding is NOT encryption, anyone can decode it. Encoding is placing data 
		// into a format that can be stored or transferred over protocols that are designed 
		// to deal with textual data. 
		// For example, how do you POST a blob of data to a web service?  You can Encode 
		// it to text and then POST. You could also encode some data and add it to the end 
		// of a Url as a query string.


		static const unsigned char base64_table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

		static const int B64index[256] = { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 62, 63, 62, 62, 63, 52, 53, 54, 55,
		56, 57, 58, 59, 60, 61,  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,
		7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,  0,
		0,  0,  0, 63,  0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
		41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 };


		class EncodeDecodeBase64
		{
		public:
			EncodeDecodeBase64();
			~EncodeDecodeBase64();

			/*
			* Base64 encoding/decoding (RFC1341)
			* Copyright (c) 2005-2011, Jouni Malinen <j@w1.fi>
			*
			* This software may be distributed under the terms of the BSD license.
			* See README for more details.
			*/
			// 2016-12-12 - Gaspard Petit : Slightly modified to return a std::string 
			// instead of a buffer allocated with malloc.

			/**
			* base64_encode - Base64 encode
			* @src: Data to be encoded
			* @len: Length of the data to be encoded
			* @out_len: Pointer to output length variable, or %NULL if not used
			* Returns: Allocated buffer of out_len bytes of encoded data,
			* or empty string on failure
			*/

			static std::string base64_encode(const unsigned char *src, size_t len);


			// Polfosol's snippet from base64 decode snippet in c++
			// https://stackoverflow.com/questions/180947/base64-decode-snippet-in-c/13935718

			static std::string base64_decode(const void* data, const size_t len);

			// Added by Davant Stewart to simplify a bit for strings.
			// You may also want to encode text because the text contains charactors 
			// that are not supported by some protocals. Unsafe charactors like < > # % 
			// { } | \ ^ ~ [ ] ' and others should be encoded for a url.
			static std::string base64_encodeString(const std::string & vrSrc);

			// Added by Davant Stewart to simplify a bit for strings.
			// You may also want to encode text because the text contains charactors 
			// that are not supported by some protocals. Unsafe charactors like < > # % 
			// { } | \ ^ ~ [ ] ' and others should be encoded for a url.
			// So if text was encoded you want to get it back as text as well.
			static std::string base64_decodeString(const std::string & vrSrc);

			// Added by Davant Stewart 
			// There is no reason to encode data and return a blob because the point of 
			// this encoding is to place data into a format that can be stored or 
			// transferred over media that are designed to deal with textual data. 
			// blob * base64_encode(....)  ... Not needed
		};
	}
}
