/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
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

#include "substrate_dispatch_V10.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_V10(
    parser_context_t* c, pd_balances_transfer_V10_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V10(
    parser_context_t* c, pd_balances_force_transfer_V10_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V10(
    parser_context_t* c, pd_balances_transfer_keep_alive_V10_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V10(
    parser_context_t* c, pd_balances_transfer_all_V10_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V10(
    parser_context_t* c, pd_balances_set_balance_V10_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V10(
    parser_context_t* c, pd_balances_force_unreserve_V10_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V10(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V10_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V10(c, &method->nested.balances_transfer_V10))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V10(c, &method->nested.balances_force_transfer_V10))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V10(c, &method->nested.balances_transfer_keep_alive_V10))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V10(c, &method->nested.balances_transfer_all_V10))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V10(c, &method->nested.balances_set_balance_V10))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V10(c, &method->basic.balances_force_unreserve_V10))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V10(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 10:
        return STR_MO_BALANCES;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V10(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2560: /* module 10 call 0 */
        return STR_ME_TRANSFER;
    case 2562: /* module 10 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 2563: /* module 10 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 2564: /* module 10 call 4 */
        return STR_ME_TRANSFER_ALL;
    default:
        return _getMethod_Name_V10_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V10_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 2561: /* module 10 call 1 */
        return STR_ME_SET_BALANCE;
    case 2565: /* module 10 call 5 */
        return STR_ME_FORCE_UNRESERVE;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V10(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2560: /* module 10 call 0 */
        return 2;
    case 2562: /* module 10 call 2 */
        return 3;
    case 2563: /* module 10 call 3 */
        return 2;
    case 2564: /* module 10 call 4 */
        return 2;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 2561: /* module 10 call 1 */
        return 3;
    case 2565: /* module 10 call 5 */
        return 2;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V10(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V10(
    pd_Method_V10_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V10 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_V10.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V10 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V10.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V10 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V10.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V10 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V10.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V10 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V10.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V10 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_keep_alive_V10.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V10 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V10.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V10 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_all_V10.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V10 - keep_alive */;
            return _toStringbool(
                &m->nested.balances_transfer_all_V10.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V10 - who */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_set_balance_V10.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V10 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V10.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V10 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V10.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V10 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_unreserve_V10.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V10 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V10.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V10(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V10(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2565: // Balances:Force unreserve
        return false;
    default:
        return true;
    }
}
