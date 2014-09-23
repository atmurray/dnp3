//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// 
// This file is auto-generated. Do not edit manually
// 
// Copyright 2013 Automatak LLC
// 
// Automatak LLC (www.automatak.com) licenses this file
// to you under the the Apache License Version 2.0 (the "License"):
// 
// http://www.apache.org/licenses/LICENSE-2.0.html
//

#include "EventAnalogResponse.h"

namespace opendnp3 {

int EventAnalogResponseToType(EventAnalogResponse arg)
{
  return static_cast<int>(arg);
}
EventAnalogResponse EventAnalogResponseFromType(int arg)
{
  switch(arg)
  {
    case(0):
      return EventAnalogResponse::Group32Var1;
    case(1):
      return EventAnalogResponse::Group32Var2;
    case(2):
      return EventAnalogResponse::Group32Var3;
    case(3):
      return EventAnalogResponse::Group32Var4;
    case(4):
      return EventAnalogResponse::Group32Var5;
    case(5):
      return EventAnalogResponse::Group32Var6;
    case(6):
      return EventAnalogResponse::Group32Var7;
    case(7):
      return EventAnalogResponse::Group32Var8;
  }
  return EventAnalogResponse::Group32Var8;
}

}
