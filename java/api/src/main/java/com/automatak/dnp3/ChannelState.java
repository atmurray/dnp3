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
package com.automatak.dnp3;

/**
* Enumeration for possible states of a channel
*/
public enum ChannelState
{
  /**
  * offline and idle
  */
  CLOSED(0),
  /**
  * trying to open
  */
  OPENING(1),
  /**
  * waiting to open
  */
  WAITING(2),
  /**
  * open
  */
  OPEN(3),
  /**
  * stopped and will never do anything again
  */
  SHUTDOWN(4);

  private final int id;

  private ChannelState(int id)
  {
    this.id = id;
  }

  public int toType()
  {
    return id;
  }

  public static ChannelState fromType(int arg)
  {
    switch(arg)
    {
      case(0):
        return CLOSED;
      case(1):
        return OPENING;
      case(2):
        return WAITING;
      case(3):
        return OPEN;
      case(4):
        return SHUTDOWN;
    }
    return SHUTDOWN;
  }
}
