#pragma once
#include "Core/HW/Memmap.h"

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

  void AddKeys(u16 keys);
}
