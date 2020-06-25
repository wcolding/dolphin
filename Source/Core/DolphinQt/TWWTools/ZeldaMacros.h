#pragma once
#include "Core/HW/Memmap.h"

#define X_BUTTON_ITEM 0x803CA7DB
#define Y_BUTTON_ITEM 0x803CA7DC
#define Z_BUTTON_ITEM 0x803CA7DD

#define UPGRADE_PICTOBOX2 0x01
#define UPGRADE_BOW2 0x02
#define UPGRADE_BOW3 0x04

namespace TWWTools
{

  void GiveTelescope();
  void GiveSail();
  void GiveWindWaker();
  void GiveGrapplingHook();
  void GiveSpoilsBag();
  void GiveBoomerang();
  void GiveDekuLeaf();

  void GiveTingleTuner();
  void SetPictoBox(int camLvl);
  void GiveIronBoots();
  void GiveMagicArmor();
  void GiveBaitBag();
  void SetBow(int bowLvl);
  void GiveBombBag();

  void SetBottleSlot(int slot, u8 contents);
  void GiveMailBag();
  void GiveHookshot();
  void GiveSkullHammer();

  void GiveBracelet();
  void SetSword(int swordLvl);
  void SetShield(int shieldLvl);

  void UpdateEquipButtons(int command);

  void AddKeys(u16 keys);
}
