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

namespace Automatak.DNP3.Interface
{
  /// <summary>
  /// Enumeration for possible states of a channel
  /// </summary>
  public enum ChannelState : int
  {
    /// <summary>
    /// offline and idle
    /// </summary>
    CLOSED = 0,
    /// <summary>
    /// trying to open
    /// </summary>
    OPENING = 1,
    /// <summary>
    /// waiting to open
    /// </summary>
    WAITING = 2,
    /// <summary>
    /// open
    /// </summary>
    OPEN = 3,
    /// <summary>
    /// stopped and will never do anything again
    /// </summary>
    SHUTDOWN = 4
  }
}
