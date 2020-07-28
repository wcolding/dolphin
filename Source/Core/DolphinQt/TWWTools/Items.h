#pragma once

typedef unsigned char u8;

namespace TWWTools
{
  typedef enum : u8
  {
    GreenRupee = 0x01, // 1
    BlueRupee = 0x02, // 5
    YellowRupee = 0x03, // 10
    RedRupee = 0x04, // 20
    PurpleRupee = 0x05, // 50
    OrangeRupee = 0x06, // 100
    SilverRupee = 0x0F, // 200

    PieceOfHeart = 0x07,
    HeartContainer = 0x08,

    Sword1 = 0x38, // Hero's Sword
    Sword2 = 0x39, // Master Sword
    Sword3 = 0x3A, // Half charged
    Sword4 = 0x3E, // Fully charged

    Shield1 = 0x3B, // Hero's Shield
    Shield2 = 0x3C, // Mirror Shield

    Bow1 = 0x27,
    Bow2 = 0x35, // Fire and Ice arrows
    Bow3 = 0x36, // Light arrows

    GrapplingHook = 0x25,
    DekuLeaf = 0x34,
    Boomerang = 0x2D,
    Bombs = 0x31,
    Hammer = 0x33,
    Hookshot = 0x2F,

    Sail = 0x78,
    WW = 0x22,

    SpoilsBag = 0x24,
    BaitBag = 0x2C,
    MailBag = 0x30,

    Bracelet = 0x28,
    Boots = 0x29,

    MagicArmor = 0x2A,
    HerosCharm = 0x43,
    TingleTuner = 0x21,
    Telecope = 0x20,
    PictoBox1 = 0x23,
    PictoBox2 = 0x26,

    Bottle = 0x50,

    i_WindsRequiem = 0x6D,
    i_BalladofGales = 0x6E,
    i_CommandMelody = 0x6F,
    i_EarthGodsLyric = 0x70,
    i_WindGodsAria = 0x71,
    i_SongofPassing = 0x72,

    FathersLetter = 0x98,
    NotetoMom = 0x99,
    MaggiesLetter = 0x9A,
    MoblinsLetter = 0x9B,
    CabanaDeed = 0x9C,
    ComplimentaryID = 0x9D,
    FillupCoupon = 0x9E,

    TownFlower = 0x8C,
    SeaFlower = 0x8D,
    ExoticFlower = 0x8E,
    HerosFlag = 0x8F,
    BigCatchFlag = 0x90,
    BigSaleFlag = 0x91,
    Pinwheel = 0x92,
    SickleMoonFlag = 0x93,
    SkullTowerIdol = 0x94,
    FountainIdol = 0x95,
    PostmanStatue = 0x96,
    ShopGuruStatue = 0x97,

    HurricaneSpin = 0xAA,
    TingleStatue1 = 0xA3, // Dragon 00000100
    TingleStatue2 = 0xA4, // Forbidden 00001000
    TingleStatue3 = 0xA5, // Goddess 00010000
    TingleStatue4 = 0xA6, // Earth 00100000
    TingleStatue5 = 0xA7, // Wind 01000000

    SmallKey = 0x15,

    NoItem = 0xFF

  } WWItem;

  typedef enum : u8
  {
    WindsRequiem = 0x01,
    BalladofGales = 0x02,
    CommandMelody = 0x04,
    EarthGodsLyric = 0x08,
    WindGodsAria = 0x10,
    SongofPassing = 0x20
  } WWSongMask;

  typedef enum : u8
  {
    Nayru = 0x01,
    Din = 0x02,
    Farore = 0x04
  } WWPearlMask;

  typedef enum : u8
  {
    Empty = 0x50,
    RedPotion = 0x51,
    GreenPotion = 0x52,
    BluePotion = 0x53,
    HalfSoup = 0x54,
    FullSoup = 0x55,
    Water = 0x56,
    Fairy = 0x57,
    Firefly = 0x58,
    ForestWater = 0x59
  } WWBottleContents;


}
