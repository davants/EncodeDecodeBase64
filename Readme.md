<h4>C++ Encode Decode Base64 Project</h4> 
 

This is a small project that contains Base64 Encode/Decode functionality and some notes. <br />
The Encode/Decode logic was NOT written by Davant Stewart, only the client and a couple<br />
of added wrapper functions. <br />
I added the original coder’s license in the source and in the LICENSE.txt document.
                                                                                                    <br />
The client code has 2 examples, encoding and decoding a std::string and <br />
encoding and decoding a binary blob.<br />

<h5>Why do we care about encoding things? </h5>
Encoding is NOT encryption, anyone can decode it. 
Encoding is placing data into a format that can be stored or transferred over protocols 
that are designed to deal with textual data. 
For example, how do you POST a blob of data to a web service?  You can Encode 
it to text and then POST. You could also encode some data and add it to the end 
of a Url as a query string. <br />
You may also want to encode text because the text contains characters 
that are not supported by some protocols. Unsafe characters like < > # % 
{ } | \ ^ ~ [ ] ' and others should be encoded for a Url.


 
	
