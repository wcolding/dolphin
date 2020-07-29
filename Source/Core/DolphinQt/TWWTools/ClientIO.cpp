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
        case WWItem::Telecope:
          GiveTelescope();
          break;
        case WWItem::Sail:
          GiveSail();
          break;
        case WWItem::WW:
          GiveWindWaker();
          break;
        case WWItem::GrapplingHook:
          GiveGrapplingHook();
          break;
        case WWItem::SpoilsBag:
          GiveSpoilsBag();
          break;
        case WWItem::Boomerang:
          GiveBoomerang();
          break;
        case WWItem::DekuLeaf:
          GiveDekuLeaf();
          break;
        case WWItem::TingleTuner:
          GiveTingleTuner();
          break;
        case WWItem::PictoBox1:
          SetPictoBox(1);
          break;
        case WWItem::PictoBox2:
          SetPictoBox(2);
          break;
        case WWItem::Boots:
          GiveIronBoots();
          break;
        case WWItem::MagicArmor:
          GiveMagicArmor();
          break;
        case WWItem::BaitBag:
          GiveBaitBag();
          break;
        case WWItem::Bow1:
          SetBow(1);
          break;
        case WWItem::Bow2:
          SetBow(2);
          break;
        case WWItem::Bow3:
          SetBow(3);
          break;
        case WWItem::Bombs:
          GiveBombBag();
          break;
          // skipping bottles for now
        case WWItem::MailBag:
          GiveMailBag();
          break;
        case WWItem::Hookshot:
          GiveHookshot();
          break;
        case WWItem::Hammer:
          GiveSkullHammer();
          break;
        case WWItem::Bracelet:
          GiveBracelet();
          break;
        case WWItem::Sword1:
          SetSword(1);
          break;
        case WWItem::Sword2:
          SetSword(2);
          break;
        case WWItem::Sword3:
          SetSword(3);
          break;
        case WWItem::Sword4:
          SetSword(4);
          break;
        case WWItem::Shield1:
          SetShield(1);
          break;
        case WWItem::Shield2:
          SetShield(2);
          break;
        default:
          break;
        }
        break;
      }
      case GIVE_KEYS:
      {
        u16 numKeys = 0;
        memcpy(&numKeys, &msg[4], 2);
        AddKeys(numKeys);
        break;
      }
      case UPGRADE_ITEM:
      {
        int itemCode = 0;
        memcpy(&itemCode, &msg[4], 4);
        UpgradeItem(itemCode);
        break;
      }
      case DOWNGRADE_ITEM:
      {
        int itemCode = 0;
        memcpy(&itemCode, &msg[4], 4);
        DowngradeItem(itemCode);
        break;
      }
      case REVOKE_ITEM:
      {
        u8 item = msg[4];
        RemoveItem(item);
        break;
      }
      case GIVE_SONG:
      {
        u8 song = msg[4];
        AddSongs(song);
        break;
      }
      case REMOVE_SONG:
      {
        u8 song = msg[4];
        RemoveSongs(song);
        break;
      }
      case GIVE_PEARL:
      {
        u8 pearl = msg[4];
        AddPearls(pearl);
        break;
      }
      case REMOVE_PEARL:
      {
        u8 pearl = msg[4];
        RemovePearls(pearl);
        break;
      }
      case SET_TRIFORCE:
      {
        u8 triforce = msg[4];
        SetTriforce(triforce);
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
