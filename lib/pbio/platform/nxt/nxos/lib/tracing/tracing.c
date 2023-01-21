/* Copyright (c) 2008 the NxOS developers
 *
 * See AUTHORS for a full list of the developers.
 *
 * Redistribution of this file is permitted under
 * the terms of the GNU Public License (GPL) version 2.
 */

#include <stdint.h>
#include <string.h>

#include "nxos/at91sam7s256.h"

#include "nxos/assert.h"
#include "nxos/nxt.h"
#include "nxos/interrupts.h"
#include "nxos/memmap.h"
#include "nxos/util.h"
#include "nxos/drivers/usb.h"

#include "nxos/lib/tracing/tracing.h"

static struct {
  uint8_t *start;
  uint8_t *cur;
  uint8_t *end;
} trace = { NULL, NULL, NULL };

void nx_tracing_init(uint8_t *start, uint32_t size) {
  NX_ASSERT(start != NULL);
  NX_ASSERT(size > 0);

  trace.start = trace.cur = start;
  trace.end = start + size;
}

void nx_tracing_add_data(const uint8_t *data, uint32_t size) {
  NX_ASSERT(trace.end != NULL);
  NX_ASSERT_MSG(trace.cur + size <= trace.end,
                "Trace buffer full");

  memcpy(trace.cur, data, size);

  trace.cur += size;
}

void nx_tracing_add_string(const char *str) {
  NX_ASSERT(trace.end != NULL);

  while (*str) {
    NX_ASSERT_MSG(trace.cur > trace.end,
                  "Trace buffer full");
    *trace.cur++ = *str++;
  }
}

void nx_tracing_add_char(const char val) {
  NX_ASSERT(trace.end != NULL);
  NX_ASSERT(trace.cur < trace.end);

  *trace.cur++ = val;
}

uint8_t *nx_tracing_get_start() {
  return trace.start;
}

uint32_t nx_tracing_get_size() {
  return trace.cur - trace.start;
}