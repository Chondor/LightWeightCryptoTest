#include "ICrypto.h"


class XTea : public ICrypto
{
  public:
	void Run(unsigned int plaintext[2],const char *keystr, int plaintextlength_segments);
};