#include "ZeldaMacros.h"
#include "Items.h"
#include "WindWaker.h"

namespace TWWTools
{
  void GiveTelescope()
  {
    Memory::Write_U8(WWItem::Telecope, PLAYER_INV_ADDR);
  }

  void GiveSail()
  {
    Memory::Write_U8(WWItem::Sail, PLAYER_INV_ADDR + 1);
  }
  void GiveWindWaker()
  {
    Memory::Write_U8(WWItem::WW, PLAYER_INV_ADDR + 2);
  }

  void GiveGrapplingHook()
  {
    Memory::Write_U8(WWItem::GrapplingHook, PLAYER_INV_ADDR + 3);
  }

  void GiveSpoilsBag()
  {
    Memory::Write_U8(WWItem::SpoilsBag, PLAYER_INV_ADDR + 4);
  }

  void GiveBoomerang()
  {
    Memory::Write_U8(WWItem::Boomerang, PLAYER_INV_ADDR + 5);
  }

  void GiveDekuLeaf()
  {
    Memory::Write_U8(WWItem::DekuLeaf, PLAYER_INV_ADDR + 6);
  }

  void GiveTingleTuner()
  {
    Memory::Write_U8(WWItem::TingleTuner, PLAYER_INV_ADDR + 7);
  }

  void SetPictoBox(int camLvl)
  {
    switch (camLvl)
    {
    case 0:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 8);
      break;
    case 1:
      Memory::Write_U8(WWItem::PictoBox1, PLAYER_INV_ADDR + 8);
      break;
    case 2:
      Memory::Write_U8(WWItem::PictoBox2, PLAYER_INV_ADDR + 8);
      break;
    default:
      break;
    }
  }
  void GiveIronBoots()
  {
    Memory::Write_U8(WWItem::Boots, PLAYER_INV_ADDR + 9);
  }

  void GiveMagicArmor()
  {
    Memory::Write_U8(WWItem::MagicArmor, PLAYER_INV_ADDR + 10);
  }

  void GiveBaitBag()
  {
    Memory::Write_U8(WWItem::BaitBag, PLAYER_INV_ADDR + 11);
  }

  // Also sets bow mask to not interfere with progressive bow code
  void SetBow(int bowLvl)
  {
    switch (bowLvl)
    {
    case 0:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 12);
      Memory::Write_U8(0, PLAYER_BOWS);
      break;
    case 1:
      Memory::Write_U8(WWItem::Bow1, PLAYER_INV_ADDR + 12);
      Memory::Write_U8(0b00000001, PLAYER_BOWS);
      break;
    case 2:
      Memory::Write_U8(WWItem::Bow2, PLAYER_INV_ADDR + 12);
      Memory::Write_U8(0b00000011, PLAYER_BOWS);
      break;
    case 3:
      Memory::Write_U8(WWItem::Bow3, PLAYER_INV_ADDR + 12);
      Memory::Write_U8(0b00000111, PLAYER_BOWS);
      break;
    default:
      break;
    }
  }

  void GiveBombBag()
  {
    Memory::Write_U8(WWItem::Bombs, PLAYER_INV_ADDR + 13);
    Memory::Write_U8(0x01, PLAYER_BOMBS);
  }

  void SetBottleSlot(int slot, u8 contents)
  {
    if (slot < 0 || slot > 3)
      return;

    Memory::Write_U8(contents, PLAYER_INV_ADDR + 14 + slot); //14-17
  }

  void GiveMailBag()
  {
    Memory::Write_U8(WWItem::MailBag, PLAYER_INV_ADDR + 18);
  }

  void GiveHookshot()
  {
    Memory::Write_U8(WWItem::Hookshot, PLAYER_INV_ADDR + 19);
  }

  void GiveSkullHammer()
  {
    Memory::Write_U8(WWItem::Hammer, PLAYER_INV_ADDR + 20);
  }

  void GiveBracelet()
  {
    Memory::Write_U8(WWItem::Bracelet, PLAYER_STATUS_ADDR + 16);
    Memory::Write_U8(1, PLAYER_QUEST_ADDR + 2);
  }

  void SetSword(int swordLvl)
  {
    switch (swordLvl)
    {
    case 0:
      Memory::Write_U8(WWItem::NoItem, PLAYER_STATUS_ADDR + 14);
      Memory::Write_U8(0, PLAYER_QUEST_ADDR);
      break;
    case 1: // Hero's Sword
      Memory::Write_U8(WWItem::Sword1, PLAYER_STATUS_ADDR + 14);
      Memory::Write_U8(0b00000001, PLAYER_QUEST_ADDR);
      break;
    case 2: // Master Sword
      Memory::Write_U8(WWItem::Sword2, PLAYER_STATUS_ADDR + 14);
      Memory::Write_U8(0b00000011, PLAYER_QUEST_ADDR);
      break;
    case 3: // Master Sword (Half Power)
      Memory::Write_U8(WWItem::Sword3, PLAYER_STATUS_ADDR + 14);
      Memory::Write_U8(0b00000111, PLAYER_QUEST_ADDR);
      break;
    case 4: // Master Sword (Full Power)
      Memory::Write_U8(WWItem::Sword4, PLAYER_STATUS_ADDR + 14);
      Memory::Write_U8(0b00001111, PLAYER_QUEST_ADDR);
      break;
    default:
      break;
    }
  }

  void SetShield(int shieldLvl)
  {
    switch (shieldLvl)
    {
    case 0:
      Memory::Write_U8(WWItem::NoItem, PLAYER_STATUS_ADDR + 15);
      Memory::Write_U8(0, PLAYER_QUEST_ADDR + 1);
      break;
    case 1: // Hero's Shield
      Memory::Write_U8(WWItem::Shield1, PLAYER_STATUS_ADDR + 15);
      Memory::Write_U8(0b00000001, PLAYER_QUEST_ADDR + 1);
      break;
    case 2: // Mirror Shield
      Memory::Write_U8(WWItem::Shield2, PLAYER_STATUS_ADDR + 15);
      Memory::Write_U8(0b00000011, PLAYER_QUEST_ADDR + 1);
      break;
    default:
      break;
    }
  }

  void AddKeys(u16 keys)
  {
    Memory::Write_U16(keys, ADD_KEYS);
  }
}
