#include "ClientIO.h"
#include "Items.h"
#include "ZeldaMacros.h"
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

    WriteFile(outPipe, msg, (DWORD)(len + 4), bytesIO, 0);
    //PrintMessage("Buffer size " + std::to_string(len) + " written");
  }

  void ClientHandler::ReceiveClient()
  {
    if (!clientConnected)
      return;

    char msg[PIPE_BUFFER_SIZE];
    memset(&msg, 0, PIPE_BUFFER_SIZE);

    bool hasMsg = ReadFile(inPipe, msg, PIPE_BUFFER_SIZE, bytesIO, 0);
    if (hasMsg)
    {
      int packetType = 0;
      memcpy(&packetType, msg, 4);

      switch (packetType)
      {
      case 0:
        break;
      case GIVE_ITEM:
      {
        WWItem item = (WWItem)msg[4];
        switch (item)
        {
        case WWItem::Hookshot:
          GiveHookshot();
          break;
        case WWItem::Boots:
          GiveIronBoots();
          break;
        default:
          break;
        }
        break;
      }
      default:
        break;
      }
    }

  }

  ClientHandler::ClientHandler()
  {
    outPipe = INVALID_HANDLE_VALUE;
    inPipe = INVALID_HANDLE_VALUE;

    while (true)
    {
      outPipe = CreateFile(DOLPHIN_OUT_PIPE, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
      inPipe = CreateFile(DOLPHIN_IN_PIPE, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);

      if ((outPipe != INVALID_HANDLE_VALUE) && (inPipe != INVALID_HANDLE_VALUE))
        break;
    }

    clientConnected = true;
    DWORD clientReadThreadID = 0;
    CreateThread(
      NULL,                   // default security attributes
      0,                      // use default stack size  
      ClientReadThread,       // thread function name
      this,          // argument to thread function 
      0,                      // use default creation flags 
      &clientReadThreadID);
  }

  DWORD WINAPI ClientHandler::ClientReadThread(LPVOID lpParam)
  {
    ClientHandler *client = reinterpret_cast<ClientHandler*>(lpParam);
    
    while (client->clientConnected)
    {
      client->ReceiveClient();
    }

    return 0;
  }

}
