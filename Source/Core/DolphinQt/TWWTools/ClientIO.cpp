#include "ClientIO.h"
#include <iostream>

namespace TWWTools
{
  void SendClient(int msgType, char* buffer)
  {
    std::cout << msgType;
    for (int i = 0; i < sizeof(buffer); i++)
    {
      std::cout << buffer[i];
    }
  }

  
}
