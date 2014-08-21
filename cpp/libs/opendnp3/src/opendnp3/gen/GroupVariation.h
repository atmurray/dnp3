//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// Copyright 2013 Automatak LLC
// 
// Automatak LLC (www.automatak.com) licenses this file
// to you under the the Apache License Version 2.0 (the "License"):
// 
// http://www.apache.org/licenses/LICENSE-2.0.html
//

#ifndef __OPENDNP3_GENERATED_GROUPVARIATION_H_
#define __OPENDNP3_GENERATED_GROUPVARIATION_H_

#include <cstdint>

namespace opendnp3 {

/**
  Comprehensive list of supported groups and variations
*/
enum class GroupVariation : uint16_t
{
    Group1Var0 = 0x100,
    Group1Var1 = 0x101,
    Group1Var2 = 0x102,
    Group2Var0 = 0x200,
    Group2Var1 = 0x201,
    Group2Var2 = 0x202,
    Group2Var3 = 0x203,
    Group3Var0 = 0x300,
    Group3Var1 = 0x301,
    Group3Var2 = 0x302,
    Group4Var0 = 0x400,
    Group4Var1 = 0x401,
    Group4Var2 = 0x402,
    Group4Var3 = 0x403,
    Group10Var0 = 0xA00,
    Group10Var1 = 0xA01,
    Group10Var2 = 0xA02,
    Group11Var0 = 0xB00,
    Group11Var1 = 0xB01,
    Group11Var2 = 0xB02,
    Group12Var0 = 0xC00,
    Group12Var1 = 0xC01,
    Group13Var0 = 0xD00,
    Group20Var0 = 0x1400,
    Group20Var1 = 0x1401,
    Group20Var2 = 0x1402,
    Group20Var5 = 0x1405,
    Group20Var6 = 0x1406,
    Group21Var0 = 0x1500,
    Group21Var1 = 0x1501,
    Group21Var2 = 0x1502,
    Group21Var5 = 0x1505,
    Group21Var6 = 0x1506,
    Group21Var9 = 0x1509,
    Group21Var10 = 0x150A,
    Group22Var0 = 0x1600,
    Group22Var1 = 0x1601,
    Group22Var2 = 0x1602,
    Group22Var5 = 0x1605,
    Group22Var6 = 0x1606,
    Group23Var0 = 0x1700,
    Group23Var1 = 0x1701,
    Group23Var2 = 0x1702,
    Group23Var5 = 0x1705,
    Group23Var6 = 0x1706,
    Group30Var0 = 0x1E00,
    Group30Var1 = 0x1E01,
    Group30Var2 = 0x1E02,
    Group30Var3 = 0x1E03,
    Group30Var4 = 0x1E04,
    Group30Var5 = 0x1E05,
    Group30Var6 = 0x1E06,
    Group31Var0 = 0x1F00,
    Group32Var0 = 0x2000,
    Group32Var1 = 0x2001,
    Group32Var2 = 0x2002,
    Group32Var3 = 0x2003,
    Group32Var4 = 0x2004,
    Group32Var5 = 0x2005,
    Group32Var6 = 0x2006,
    Group32Var7 = 0x2007,
    Group32Var8 = 0x2008,
    Group33Var0 = 0x2100,
    Group40Var0 = 0x2800,
    Group40Var1 = 0x2801,
    Group40Var2 = 0x2802,
    Group40Var3 = 0x2803,
    Group40Var4 = 0x2804,
    Group41Var0 = 0x2900,
    Group41Var1 = 0x2901,
    Group41Var2 = 0x2902,
    Group41Var3 = 0x2903,
    Group41Var4 = 0x2904,
    Group42Var0 = 0x2A00,
    Group42Var1 = 0x2A01,
    Group42Var2 = 0x2A02,
    Group42Var3 = 0x2A03,
    Group42Var4 = 0x2A04,
    Group42Var5 = 0x2A05,
    Group42Var6 = 0x2A06,
    Group42Var7 = 0x2A07,
    Group42Var8 = 0x2A08,
    Group43Var0 = 0x2B00,
    Group50Var1 = 0x3201,
    Group51Var1 = 0x3301,
    Group51Var2 = 0x3302,
    Group52Var1 = 0x3401,
    Group52Var2 = 0x3402,
    Group60Var1 = 0x3C01,
    Group60Var2 = 0x3C02,
    Group60Var3 = 0x3C03,
    Group60Var4 = 0x3C04,
    Group70Var0 = 0x4600,
    Group70Var1 = 0x4601,
    Group70Var2 = 0x4602,
    Group70Var3 = 0x4603,
    Group70Var4 = 0x4604,
    Group70Var5 = 0x4605,
    Group70Var6 = 0x4606,
    Group70Var7 = 0x4607,
    Group80Var1 = 0x5001,
    Group110AnyVar = 0x6E00,
    Group111AnyVar = 0x6F00,
    Group112Var0 = 0x7000,
    Group112Var1 = 0x7001,
    Group112Var2 = 0x7002,
    Group112Var3 = 0x7003,
    Group112Var4 = 0x7004,
    Group112Var5 = 0x7005,
    Group112Var6 = 0x7006,
    Group112Var7 = 0x7007,
    Group113Var0 = 0x7100,
    Group113Var1 = 0x7101,
    Group113Var2 = 0x7102,
    Group113Var3 = 0x7103,
    UNKNOWN = 0xFFFF
};

uint16_t GroupVariationToType(GroupVariation arg);
GroupVariation GroupVariationFromType(uint16_t arg);
char const* GroupVariationToString(GroupVariation arg);

}

#endif
