//	Shane Brown
//	CS 6490 - Network Security
//	Project: Lightweight Cryptographic Algorithms Comparison
//	Dec. 3, 2015
//
//	Description:
//	Interface that all the cryptographic algorithms which are being compared
//	needs to implement
//	(Actually this is an abstract class to be technically correct)

//typedef unsigned int WORD; /* Should be 32-bit = 4 bytes        */


#ifndef _ICrypto_
#define _ICrypto_
class ICrypto
{
  public:
    ICrypto(){}
    virtual ~ICrypto(){}
	//	unsigned int should equal 4-bytes, so plaintext is 8 bytes in length for each segment
	//	plaintext = is the initial plaintext string to encrypt
	//	keystr = is the initial vector string
	//	plaintextlength_segments = number of segments of plaintext to emulate, in order to emulate encrypting longer strings; total emulated length = 8 bytes * plaintextlength_segments
    virtual void Run(unsigned int plaintext[2],const char *keystr, int plaintextlength_segments)=0;		//	This is the method that each class needs to implement
};
#endif


