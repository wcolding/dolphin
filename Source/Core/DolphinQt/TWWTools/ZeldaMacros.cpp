#include "ZeldaMacros.h"
#include "Items.h"
#include "WindWaker.h"
#include "UI.h"

#define printItem(item) TWWTools::ItemMsg(WWItem::item)

namespace TWWTools
{
  void GiveTelescope()
  {
    Memory::Write_U8(WWItem::Telecope, PLAYER_INV_ADDR);
    printItem(Telecope);
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
      UpdateEquipButtons(SET_PICTOBOX);
      break;
    case 1:
      Memory::Write_U8(WWItem::PictoBox1, PLAYER_INV_ADDR + 8);
      UpdateEquipButtons(SET_PICTOBOX);
      break;
    case 2:
      Memory::Write_U8(WWItem::PictoBox2, PLAYER_INV_ADDR + 8);
      UpdateEquipButtons(SET_PICTOBOX);
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
      UpdateEquipButtons(SET_BOW);
      break;
    case 1:
      Memory::Write_U8(WWItem::Bow1, PLAYER_INV_ADDR + 12);
      Memory::Write_U8(0b00000001, PLAYER_BOWS);
      UpdateEquipButtons(SET_BOW);
      break;
    case 2:
      Memory::Write_U8(WWItem::Bow2, PLAYER_INV_ADDR + 12);
      Memory::Write_U8(0b00000011, PLAYER_BOWS);
      UpdateEquipButtons(SET_BOW);
      break;
    case 3:
      Memory::Write_U8(WWItem::Bow3, PLAYER_INV_ADDR + 12);
      Memory::Write_U8(0b00000111, PLAYER_BOWS);
      UpdateEquipButtons(SET_BOW);
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

    // Set the timer for forest water so it doesn't expire immediately
    // Default time is 20 min, set in frames
    // 30 fps * 60 sec * 20 min = 36,000 frames = 0x8CA0
    // Only starts counting down once the player moves to another area
    if (contents == WWBottleContents::ForestWater)
      Memory::Write_U16(0x8CA0, 0x803C4C6E);
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

  // This only works in randomizer
  void GiveHurricaneSpin()
  {
    u8 spinByte = Memory::Read_U8(PLAYER_SWORD_SPIN);
    spinByte |= 0x01;
    Memory::Write_U8(spinByte, PLAYER_SWORD_SPIN);
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

  void UpdateEquipButtons(int itemCode)
  {
    u8* equipsPtr = Memory::GetPointer(X_BUTTON_ITEM);
    u8 equips[3];
    memcpy(&equips, equipsPtr, 3);
    WWItem currentItem;

    switch (itemCode)
    {
    case SET_PICTOBOX:
      currentItem = (WWItem)Memory::Read_U8(PLAYER_INV_ADDR + 8);

      for (int i = 0; i < 3; i++)
      {
        if ((equips[i] == WWItem::PictoBox1) || (equips[i] == WWItem::PictoBox2))
        {
          Memory::Write_U8(currentItem, X_BUTTON_ITEM + i);
        }
      }
      break;
    case SET_BOW:
      currentItem = (WWItem)Memory::Read_U8(PLAYER_INV_ADDR + 12);
      for (int i = 0; i < 3; i++)
      {
        if ((equips[i] == WWItem::Bow1) || (equips[i] == WWItem::Bow2) || (equips[i] == WWItem::Bow3))
        {
          Memory::Write_U8(currentItem, X_BUTTON_ITEM + i);
        }
      }
      break;
    default:
      break;
    }

  }

  // Takes an item code as an argument and upgrades that item by one level if possible
  void UpgradeItem(int itemCode)
  {
    WWItem currentItem;

    switch (itemCode)
    {
    case SET_PICTOBOX:
    {
      currentItem = (WWItem)Memory::Read_U8(PLAYER_INV_ADDR + 8);
      if (currentItem == WWItem::NoItem)
        SetPictoBox(1);
      if (currentItem == WWItem::PictoBox1)
        SetPictoBox(2);
      break;
    }
    case SET_BOW:
    {
      currentItem = (WWItem)Memory::Read_U8(PLAYER_INV_ADDR + 12);
      if (currentItem == WWItem::NoItem)
        SetBow(1);
      if (currentItem == WWItem::Bow1)
        SetBow(2);
      if (currentItem == WWItem::Bow2)
        SetBow(3);
      break;
    }
    case SET_SWORD:
    {
      currentItem = (WWItem)Memory::Read_U8(PLAYER_STATUS_ADDR + 14);
      if (currentItem == WWItem::NoItem)
        SetSword(1);
      if (currentItem == WWItem::Sword1)
        SetSword(2);
      if (currentItem == WWItem::Sword2)
        SetSword(3);
      if (currentItem == WWItem::Sword3)
        SetSword(4);
      break;
    }
    case SET_SHIELD:
    {
      currentItem = (WWItem)Memory::Read_U8(PLAYER_STATUS_ADDR + 15);
      if (currentItem == WWItem::NoItem)
        SetShield(1);
      if (currentItem == WWItem::Shield1)
        SetShield(2);
      break;
    }
    case SET_MAGIC:
    {
      u8 currentMaxMagic = Memory::Read_U8(PLAYER_STATUS_ADDR + 19);
      if (currentMaxMagic < 0x10)
      {
        Memory::Write_U8(0x10, PLAYER_STATUS_ADDR + 19); // max magic
        Memory::Write_U8(0x10, PLAYER_STATUS_ADDR + 20); // current magic
      }
      if (currentMaxMagic == 0x10)
      {
        Memory::Write_U8(0x20, PLAYER_STATUS_ADDR + 19); // max magic
        Memory::Write_U8(0x20, PLAYER_STATUS_ADDR + 20); // current magic
      }
      break;
    }
    case SET_WALLET:
    {
      u8 wallet = Memory::Read_U8(PLAYER_STATUS_ADDR + 18);
      if (wallet < 1)
        Memory::Write_U8(1, PLAYER_STATUS_ADDR + 18);
      if (wallet == 1)
        Memory::Write_U8(2, PLAYER_STATUS_ADDR + 18);
      break;
    }
    case SET_BOW_CAPACITY:
    {
      u32 cap_addr = 0x803C4C77;
      u8 capacity = Memory::Read_U8(cap_addr);
      if (capacity == 30)
      {
        Memory::Write_U8(60, cap_addr);
        Memory::Write_U8(60, 0x803C4C71);
      }
      if (capacity == 60)
      {
        Memory::Write_U8(99, cap_addr);
        Memory::Write_U8(99, 0x803C4C71);
      }
      break;
    }
    case SET_BOMB_CAPACITY:
    {
      u32 cap_addr = 0x803C4C78;
      u8 capacity = Memory::Read_U8(cap_addr);
      if (capacity == 30)
      {
        Memory::Write_U8(60, cap_addr);
        Memory::Write_U8(60, 0x803C4C72);
      }
      if (capacity == 60)
      {
        Memory::Write_U8(99, cap_addr);
        Memory::Write_U8(99, 0x803C4C72);
      }
      break;
    }
    default:
      break;
    }
  }

  // Takes an item code as an argument and downgrades that item or removes it
  void DowngradeItem(int itemCode)
  {
    WWItem currentItem;

    switch (itemCode)
    {
    case SET_PICTOBOX:
    {
      currentItem = (WWItem)Memory::Read_U8(PLAYER_INV_ADDR + 8);
      if (currentItem == WWItem::PictoBox1)
        SetPictoBox(0);
      if (currentItem == WWItem::PictoBox2)
        SetPictoBox(1);
      break;
    }
    case SET_BOW:
    {
      currentItem = (WWItem)Memory::Read_U8(PLAYER_INV_ADDR + 12);
      if (currentItem == WWItem::Bow1)
        SetBow(0);
      if (currentItem == WWItem::Bow2)
        SetBow(1);
      if (currentItem == WWItem::Bow3)
        SetBow(2);
      break;
    }
    case SET_SWORD:
    {
      currentItem = (WWItem)Memory::Read_U8(PLAYER_STATUS_ADDR + 14);
      if (currentItem == WWItem::Sword1)
        SetSword(0);
      if (currentItem == WWItem::Sword2)
        SetSword(1);
      if (currentItem == WWItem::Sword3)
        SetSword(2);
      if (currentItem == WWItem::Sword4)
        SetSword(3);
      break;
    }
    case SET_SHIELD:
    {
      currentItem = (WWItem)Memory::Read_U8(PLAYER_STATUS_ADDR + 15);
      if (currentItem == WWItem::Shield1)
        SetShield(0);
      if (currentItem == WWItem::Shield2)
        SetShield(1);
      break;
    }
    case SET_MAGIC:
    {
      u8 currentMaxMagic = Memory::Read_U8(PLAYER_STATUS_ADDR + 19);
      if (currentMaxMagic == 0x10)
        Memory::Write_U8(0, PLAYER_STATUS_ADDR + 19);
      if (currentMaxMagic == 0x20)
        Memory::Write_U8(0x10, PLAYER_STATUS_ADDR + 19);
      break;
    }
    case SET_WALLET:
    {
      u8 wallet = Memory::Read_U8(PLAYER_STATUS_ADDR + 18);
      if (wallet == 1)
        Memory::Write_U8(0, PLAYER_STATUS_ADDR + 18);
      if (wallet > 1)
        Memory::Write_U8(1, PLAYER_STATUS_ADDR + 18);
      break;
    }
    case SET_BOW_CAPACITY:
    {
      u32 cap_addr = 0x803C4C77;
      u8 capacity = Memory::Read_U8(cap_addr);
      if (capacity == 60)
        Memory::Write_U8(30, cap_addr);
      if (capacity == 99)
        Memory::Write_U8(60, cap_addr);
      break;
    }
    case SET_BOMB_CAPACITY:
    {
      u32 cap_addr = 0x803C4C78;
      u8 capacity = Memory::Read_U8(cap_addr);
      if (capacity == 60)
        Memory::Write_U8(30, cap_addr);
      if (capacity == 99)
        Memory::Write_U8(60, cap_addr);
      break;
    }
    default:
      break;
    }
  }

  void RemoveItem(u8 item)
  {
    switch (item)
    {
    case WWItem::Telecope:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR);
      break;
    case WWItem::Sail:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 1);
      break;
    case WWItem::WW:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 2);
      break;
    case WWItem::GrapplingHook:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 3);
      break;
    case WWItem::SpoilsBag:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 4);
      break;
    case WWItem::Boomerang:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 5);
      break;
    case WWItem::DekuLeaf:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 6);
      break;
    case WWItem::TingleTuner:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 7);
      break;
    case WWItem::Boots:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 9);
      break;
    case WWItem::MagicArmor:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 10);
      break;
    case WWItem::BaitBag:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 11);
      break;
    case WWItem::Bombs:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 13);
      Memory::Write_U8(0, PLAYER_BOMBS);
      break;
    case WWItem::MailBag:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 18);
      break;
    case WWItem::Hookshot:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 19);
      break;
    case WWItem::Hammer:
      Memory::Write_U8(WWItem::NoItem, PLAYER_INV_ADDR + 20);
      break;
    case WWItem::Bracelet:
      Memory::Write_U8(WWItem::NoItem, PLAYER_STATUS_ADDR + 16);
      Memory::Write_U8(0, PLAYER_QUEST_ADDR + 2);
      break;
    case WWItem::HurricaneSpin:
    {
      u8 spinByte = Memory::Read_U8(PLAYER_SWORD_SPIN);

      if (HasFlag(spinByte, 0x01))
      {
        spinByte ^= 0x01;
        Memory::Write_U8(spinByte, PLAYER_SWORD_SPIN);
      }
      break;
    }
    default:
      break;
    }

    // Remove from equip buttons
    u8* equipsPtr = Memory::GetPointer(X_BUTTON_ITEM);
    u8 equips[3];
    memcpy(&equips, equipsPtr, 3);

    for (int i = 0; i < 3; i++)
      if (equips[i] == item)
        Memory::Write_U8(WWItem::NoItem, X_BUTTON_ITEM + i);
  }

  void AddKeys(u16 keys)
  {
    Memory::Write_U16(keys, ADD_KEYS);
  }

  void AddSongs(u8 songs)
  {
    u8 curSongs = Memory::Read_U8(PLAYER_QUEST_ADDR + 9);
    curSongs |= songs;
    Memory::Write_U8(curSongs, PLAYER_QUEST_ADDR + 9);
  }

  void RemoveSongs(u8 songs)
  {
    u8 curSongs = Memory::Read_U8(PLAYER_QUEST_ADDR + 9);
    curSongs ^= songs;
    Memory::Write_U8(curSongs, PLAYER_QUEST_ADDR + 9);
  }

  void GiveWindsRequiem()
  {
    AddSongs(WWSongMask::WindsRequiem);
  }

  void GiveBalladofGales()
  {
    AddSongs(WWSongMask::BalladofGales);
  }

  void GiveCommandMelody()
  {
    AddSongs(WWSongMask::CommandMelody);
  }

  void GiveEarthGodsLyric()
  {
    AddSongs(WWSongMask::EarthGodsLyric);
  }

  void GiveWindGodsAria()
  {
    AddSongs(WWSongMask::WindGodsAria);
  }

  void GiveSongofPassing()
  {
    AddSongs(WWSongMask::SongofPassing);
  }

  void AddPearls(u8 pearls)
  {
    u8 curPearls = Memory::Read_U8(PLAYER_QUEST_ADDR + 11);
    curPearls |= pearls;
    Memory::Write_U8(curPearls, PLAYER_QUEST_ADDR + 11);

    // If all pearls are acquired, place them in the pedestals and raise TotG
    // This is behavior that randomizer does automatically when giving pearls
    if (HasFlag(curPearls, WWPearlMask::Din) && HasFlag(curPearls, WWPearlMask::Farore) && HasFlag(curPearls, WWPearlMask::Nayru))
    {
      u8 placed       = Memory::Read_U8(0x803C5240);
      u8 totgRaised   = Memory::Read_U8(0x803C524A);
      u8 totgCutscene = Memory::Read_U8(0x803C525A);

      placed       |= 0xD0; // all three pearls
      totgRaised   |= 0x40;
      totgCutscene |= 0x80;

      Memory::Write_U8(placed, 0x803C5240);
      Memory::Write_U8(totgRaised, 0x803C524A);
      Memory::Write_U8(totgCutscene, 0x803C525A);
    }
  }

  void RemovePearls(u8 pearls)
  {
    u8 curPearls = Memory::Read_U8(PLAYER_QUEST_ADDR + 11);
    curPearls ^= pearls;
    Memory::Write_U8(curPearls, PLAYER_QUEST_ADDR + 11);

    if (pearls != 0) // this should always return True, we aren't calling this for no reason
    {
      u8 placed = Memory::Read_U8(0x803C5240);
      u8 totgRaised = Memory::Read_U8(0x803C524A);
      u8 totgCutscene = Memory::Read_U8(0x803C525A);

      // un-set all pearls
      if (HasFlag(placed, 0x80)) // Din
        placed ^= 0x80;
      if (HasFlag(placed, 0x40)) // Farore
        placed ^= 0x40;
      if (HasFlag(placed, 0x10)) // Nayru
        placed ^= 0x10;

      if (HasFlag(totgRaised, 0x40))
        totgRaised ^= 0x40;

      if (HasFlag(totgCutscene, 0x80))
        totgCutscene ^= 0x80;

      Memory::Write_U8(placed, 0x803C5240);
      Memory::Write_U8(totgRaised, 0x803C524A);
      Memory::Write_U8(totgCutscene, 0x803C525A);
    }
  }

  void GiveDinsPearl()
  {
    AddPearls(WWPearlMask::Din);
  }

  void GiveFaroresPearl()
  {
    AddPearls(WWPearlMask::Farore);
  }

  void GiveNayrusPearl()
  {
    AddPearls(WWPearlMask::Nayru);
  }

  void SetTriforce(u8 triforce)
  {
    Memory::Write_U8(triforce, PLAYER_QUEST_ADDR + 10);
  }


  void SetStatues(u8 statues)
  {
    Memory::Write_U8(statues, PLAYER_STATUES);
  }


  void GiveCharts(u64 mask)
  {
    u64 curCharts = Memory::Read_U64(PLAYER_CHARTS_ADDR);
    curCharts |= mask;
    Memory::Write_U64(curCharts, PLAYER_CHARTS_ADDR);
  }

  void RemoveCharts(u64 mask)
  {
    u64 curCharts = Memory::Read_U64(PLAYER_CHARTS_ADDR);
    curCharts ^= mask;
    Memory::Write_U64(curCharts, PLAYER_CHARTS_ADDR);
  }


  void SetMailBagSlot(int slot, u8 mail)
  {
    if (slot < 0 || slot > 7)
      return;

    Memory::Write_U8(mail, PLAYER_BAGS_ADDR + (8 * 2) + slot);
  }

  bool HasFlag(u8 value, u8 flag)
  {
    if ((value & flag) != 0)
      return true;
    return false;
  }
}
