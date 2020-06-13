/**
 * @file
 * Debug messages infrastructure
 */

/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 * 
 * Adapted for OCAC
 * 
 */
#ifndef OCAC_HDR_DEBUG_H
#define OCAC_HDR_DEBUG_H

#include "ocac/arch.h"
#include "ocac/opt.h"

/**
 * @defgroup debugging_levels OCAC_DBG_MIN_LEVEL and OCAC_DBG_TYPES_ON values
 * @ingroup ocac_opts_debugmsg
 * @{
 */

/** @name Debug level (OCAC_DBG_MIN_LEVEL)
 * @{
 */
/** Debug level: ALL messages*/
#define OCAC_DBG_LEVEL_ALL     0x00
/** Debug level: Warnings. bad checksums, dropped packets, ... */
#define OCAC_DBG_LEVEL_WARNING 0x01
/** Debug level: Serious. memory allocation failures, ... */
#define OCAC_DBG_LEVEL_SERIOUS 0x02
/** Debug level: Severe */
#define OCAC_DBG_LEVEL_SEVERE  0x03
/**
 * @}
 */

#define OCAC_DBG_MASK_LEVEL    0x03
/* compatibility define only */
#define OCAC_DBG_LEVEL_OFF     OCAC_DBG_LEVEL_ALL

/** @name Enable/disable debug messages completely (OCAC_DBG_TYPES_ON)
 * @{
 */
/** flag for OCAC_DEBUGF to enable that debug message */
#define OCAC_DBG_ON            0x80U
/** flag for OCAC_DEBUGF to disable that debug message */
#define OCAC_DBG_OFF           0x00U
/**
 * @}
 */

/** @name Debug message types (OCAC_DBG_TYPES_ON)
 * @{
 */
/** flag for OCAC_DEBUGF indicating a tracing message (to follow program flow) */
#define OCAC_DBG_TRACE         0x40U
/** flag for OCAC_DEBUGF indicating a state debug message (to follow module states) */
#define OCAC_DBG_STATE         0x20U
/** flag for OCAC_DEBUGF indicating newly added code, not thoroughly tested yet */
#define OCAC_DBG_FRESH         0x10U
/** flag for OCAC_DEBUGF to halt after printing this debug message */
#define OCAC_DBG_HALT          0x08U
/**
 * @}
 */

/**
 * @}
 */

/**
 * @defgroup ocac_assertions Assertion handling
 * @ingroup ocac_opts_debug
 * @{
 */
/**
 * OCAC_NOASSERT: Disable OCAC_ASSERT checks:
 * To disable assertions define OCAC_NOASSERT in arch/cc.h.
 */
#ifdef __DOXYGEN__
#define OCAC_NOASSERT
#undef OCAC_NOASSERT
#endif
/**
 * @}
 */

#ifndef OCAC_NOASSERT
#define OCAC_ASSERT(message, assertion) do { if (!(assertion)) { \
  OCAC_PLATFORM_ASSERT(message); }} while(0)
#else  /* OCAC_NOASSERT */
#define OCAC_ASSERT(message, assertion)
#endif /* OCAC_NOASSERT */

#ifndef OCAC_ERROR
#ifdef OCAC_DEBUG
#define OCAC_PLATFORM_ERROR(message) OCAC_PLATFORM_DIAG((message))
#else
#define OCAC_PLATFORM_ERROR(message)
#endif

/* if "expression" isn't true, then print "message" and execute "handler" expression */
#define OCAC_ERROR(message, expression, handler) do { if (!(expression)) { \
  OCAC_PLATFORM_ERROR(message); handler;}} while(0)
#endif /* OCAC_ERROR */

/** Enable debug message printing, but only if debug message type is enabled
 *  AND is of correct type AND is at least OCAC_DBG_LEVEL.
 */
#ifdef __DOXYGEN__
#define OCAC_DEBUG
#undef OCAC_DEBUG
#endif

#ifdef OCAC_DEBUG
#define OCAC_DEBUG_ENABLED(debug) (((debug) & OCAC_DBG_ON) && \
                                   ((debug) & OCAC_DBG_TYPES_ON) && \
                                   ((s16_t)((debug) & OCAC_DBG_MASK_LEVEL) >= OCAC_DBG_MIN_LEVEL))

#define OCAC_DEBUGF(debug, message) do { \
                               if (OCAC_DEBUG_ENABLED(debug)) { \
                                 OCAC_PLATFORM_DIAG(message); \
                                 if ((debug) & OCAC_DBG_HALT) { \
                                   while(1); \
                                 } \
                               } \
                             } while(0)

#else  /* OCAC_DEBUG */
#define OCAC_DEBUG_ENABLED(debug) 0
#define OCAC_DEBUGF(debug, message)
#endif /* OCAC_DEBUG */

#endif /* OCAC_HDR_DEBUG_H */