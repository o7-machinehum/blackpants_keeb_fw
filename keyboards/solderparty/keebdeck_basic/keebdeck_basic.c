// Copyright 2025 Solder Party
// SPDX-License-Identifier: GPL-2.0-or-later

#include "hal.h"

void board_init(void) {
  // Remap PA11->PA9 and PA12->PA10 for USB
  SYSCFG->CFGR1 |= SYSCFG_CFGR1_PA11_PA12_RMP;
}
