/* 
Simon and Speck Block cipher implementation
Published by NSA in June 2013, https://eprint.iacr.org/2013/404.pdf

Author: Nicolas Courtois, Theodosis Mourouzis, Guangyan Song
Jan 2014
*/


#pragma once
#include "simonSpeckBasic.h"
#include "ICrypto.h"


class Speck : public ICrypto
{
  public:
	void Run(unsigned int plaintext[2],const char *keystr, int plaintextlength_segments);
        void SpeckEncryptBlock64128(u32 PL,u32 PR,u32 &CL, u32 &CR, u32* key,int nn,int keysize,int rounds);
        void SpeckEncryptBlock(u64 PL,u64 PR,u64 &CL, u64 &CR, u64* key,int nn,int keysize);
};
