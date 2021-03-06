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
  /// Class assignment for a measurement point
  /// </summary>
  public enum PointClass : byte
  {
    /// <summary>
    /// No event class assignment
    /// </summary>
    Class0 = 0x1,
    /// <summary>
    /// Assigned to event class 1
    /// </summary>
    Class1 = 0x2,
    /// <summary>
    /// Assigned to event class 2
    /// </summary>
    Class2 = 0x4,
    /// <summary>
    /// Assigned to event class 3
    /// </summary>
    Class3 = 0x8
  }
}
