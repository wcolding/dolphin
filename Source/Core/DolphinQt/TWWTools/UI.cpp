#include "UI.h"
#include "WindWaker.h"

namespace TWWTools
{
  void PrintMessage(std::string msg)
  {
    OSD::AddMessage(msg, OSD::Duration::SHORT, OSD::Color::CYAN);
  }

  // Writes a pretty 'got item' message to the game window
  void ItemMsg(WWItem item)
  {
    // todo: add player credit to start
    std::string msg = "";
    switch (item)
    {
    case WWItem::Sword1:
      msg = "Hero's Sword";
      break;
    case WWItem::Sword2:
      msg = "Master Sword";
      break;
    case WWItem::Sword3:
      msg = "Master Sword (Half-Charged)";
      break;
    case WWItem::Sword4:
      msg = "Master Sword (Fully-Charged)";
      break;

    case WWItem::Shield1:
      msg = "Hero's Shield";
      break;
    case WWItem::Shield2:
      msg = "Mirror Shield";
      break;

    case WWItem::SmallKey:
      switch (GetStageID())
      {
      case StageID::DRC:
        msg += "DRC ";
        break;
      case StageID::FW:
        msg += "FW ";
        break;
      case StageID::TotG:
        msg += "TotG ";
        break;
      case StageID::Earth:
        msg += "ET ";
        break;
      case StageID::Wind:
        msg += "WT ";
        break;
      default:
        break;
      }
      msg += "Small Key";
      break;
    case WWItem::Bow1:
      msg = "Bow";
      break;
    case WWItem::Bow2:
      msg = "Bow (Fire & Ice Arrows)";
      break;
    case WWItem::Bow3:
      msg = "Bow (Light Arrows)";
      break;

    case WWItem::Telecope:
      msg = "Telescope";
      break;

    case WWItem::NoItem:
      msg = "No item";
      break;

    default:
      msg = "Undefined item: " + std::to_string(item);
      break;
    }
    PrintMessage(msg);
  }
}
