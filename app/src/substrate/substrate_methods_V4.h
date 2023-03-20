/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V4.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_BALANCES_V4 10

#define PD_CALL_BALANCES_TRANSFER_ALL_V4 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V4_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V4 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V4_t;

#endif

typedef union {
    pd_balances_transfer_all_V4_t balances_transfer_all_V4;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_balances_force_unreserve_V4_t balances_force_unreserve_V4;
#endif
} pd_MethodBasic_V4_t;

#define PD_CALL_BALANCES_TRANSFER_V4 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V4_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V4 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V4_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V4 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V4_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_BALANCES_SET_BALANCE_V4 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V4_t;

#endif

typedef union {
    pd_balances_transfer_V4_t balances_transfer_V4;
    pd_balances_force_transfer_V4_t balances_force_transfer_V4;
    pd_balances_transfer_keep_alive_V4_t balances_transfer_keep_alive_V4;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_balances_set_balance_V4_t balances_set_balance_V4;
#endif
} pd_MethodNested_V4_t;

typedef union {
    pd_MethodBasic_V4_t basic;
    pd_MethodNested_V4_t nested;
} pd_Method_V4_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
