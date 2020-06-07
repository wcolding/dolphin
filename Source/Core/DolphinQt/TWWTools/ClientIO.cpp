#include "ClientIO.h"
//#include "UI.h"
#include <iostream>

namespace TWWTools
{
  void ClientHandler::SendClient(int msgType, char* buffer, size_t len)
  {
    if (!clientConnected)
      return;

    char msg[PIPE_BUFFER_SIZE];
    memset(&msg, 0, PIPE_BUFFER_SIZE);
    memcpy(&msg, &msgType, 4);
    memcpy(&msg[4], buffer, len);

    WriteFile(outPipe, msg, (DWORD)(len + 4), bytesWritten, 0);
    //PrintMessage("Buffer size " + std::to_string(len) + " written");
  }

  ClientHandler::ClientHandler()
  {
    outPipe = INVALID_HANDLE_VALUE;
    inPipe = INVALID_HANDLE_VALUE;

    while (true)
    {
      outPipe = CreateFile(DOLPHIN_OUT_PIPE, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

      if (outPipe != INVALID_HANDLE_VALUE)
        break;

      if (GetLastError() != ERROR_PIPE_BUSY)
        break;
    }

    clientConnected = true;
  }

}
