/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once

namespace stm32plus
{
  namespace ili9325
  {
    namespace DrivingWaveControlCmd
    {
      enum
      {
        Opcode = 2,
        FixedBits = 1<<10,

        EOR = 1<<8,
        BC = 1<<9
      };
    }
  }
}

