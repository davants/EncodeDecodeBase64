
#include "EncodeDecodeBase64.h"

namespace Matthew5
{
	namespace Util
	{

		EncodeDecodeBase64::EncodeDecodeBase64()
		{
		}


		EncodeDecodeBase64::~EncodeDecodeBase64()
		{
		}

		std::string EncodeDecodeBase64::base64_encodeString(const std::string & vrSrc)
		{
			const unsigned char * vpSrc = (const unsigned char *)vrSrc.c_str();

			return EncodeDecodeBase64::base64_encode(vpSrc, vrSrc.size());
		}

		std::string EncodeDecodeBase64::base64_encode(const unsigned char * src, size_t len)
		{
			unsigned char *out, *pos;
			const unsigned char *end, *in;

			size_t olen;

			olen = 4 * ((len + 2) / 3); /* 3-byte blocks to 4-byte */

			if (olen < len)
				return std::string(); /* integer overflow */

			std::string outStr;
			outStr.resize(olen);
			out = (unsigned char*)&outStr[0];

			end = src + len;
			in = src;
			pos = out;
			while (end - in >= 3) {
				*pos++ = base64_table[in[0] >> 2];
				*pos++ = base64_table[((in[0] & 0x03) << 4) | (in[1] >> 4)];
				*pos++ = base64_table[((in[1] & 0x0f) << 2) | (in[2] >> 6)];
				*pos++ = base64_table[in[2] & 0x3f];
				in += 3;
			}

			if (end - in) {
				*pos++ = base64_table[in[0] >> 2];
				if (end - in == 1) {
					*pos++ = base64_table[(in[0] & 0x03) << 4];
					*pos++ = '=';
				}
				else {
					*pos++ = base64_table[((in[0] & 0x03) << 4) |
						(in[1] >> 4)];
					*pos++ = base64_table[(in[1] & 0x0f) << 2];
				}
				*pos++ = '=';
			}

			return outStr;
		}

		std::string EncodeDecodeBase64::base64_decode(const void * data, const size_t len)
		{

			unsigned char* p = (unsigned char*)data;
			int pad = len > 0 && (len % 4 || p[len - 1] == '=');
			const size_t L = ((len + 3) / 4 - pad) * 4;
			std::string str(L / 4 * 3 + pad, '\0');

			for (size_t i = 0, j = 0; i < L; i += 4)
			{
				int n = B64index[p[i]] << 18 | B64index[p[i + 1]] << 12 | B64index[p[i + 2]] << 6 | B64index[p[i + 3]];
				str[j++] = n >> 16;
				str[j++] = n >> 8 & 0xFF;
				str[j++] = n & 0xFF;
			}
			if (pad)
			{
				int n = B64index[p[L]] << 18 | B64index[p[L + 1]] << 12;
				str[str.size() - 1] = n >> 16;

				if (len > L + 2 && p[L + 2] != '=')
				{
					n |= B64index[p[L + 2]] << 6;
					str.push_back(n >> 8 & 0xFF);
				}
			}
			return str;

		}

		std::string EncodeDecodeBase64::base64_decodeString(const std::string & vrSrc)
		{
			const void * data = vrSrc.c_str();

			return EncodeDecodeBase64::base64_decode(data, vrSrc.size());
		}

	}
}