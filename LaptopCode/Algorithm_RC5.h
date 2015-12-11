#include "ICrypto.h"

class Algorithm_RC5 : public ICrypto
{
  public:
	void Run(unsigned int plaintext[2],const char *keystr, int plaintextlength_segments);
};

