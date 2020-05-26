#include "ClientIO.h"
#include "UI.h"
#include <iostream>

namespace TWWTools
{
  void SendClient(int msgType, char* buffer, size_t len)
  {
    char typeBuffer[4];
    memcpy(&typeBuffer, &msgType, 4);

    for (int i = 0; i < 4; i++)
    {
      std::cout << typeBuffer[i];
    }

    for (int i = 0; i < len; i++)
    {
      std::cout << buffer[i];
    }

    //std::cout << std::endl;
    PrintMessage("Buffer size " + std::to_string(len) + " written");
  }


  void SendRawAndEcho(std::string msg)
  {
    std::cout << msg << std::endl;
    PrintMessage(msg);
  }

}
