# Ledger Pendulum App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-pendulum/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-pendulum/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Pendulum app (https://pendulumchain.org/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
# Pendulum 10.10.x

## System

| Name                    | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                         |
| ----------------------- | ------ | --------- | ---------------- | ------- | --------------------------------- |
| Remark                  |        |           |                  |         | `Bytes`remark<br/>                |
| Set heap pages          |        |           |                  |         | `u64`pages<br/>                   |
| Set code                |        |           |                  |         | `Vecu8`code<br/>                  |
| Set code without checks |        |           |                  |         | `Vecu8`code<br/>                  |
| Set storage             |        |           |                  |         | `VecKeyValue`items<br/>           |
| Kill storage            |        |           |                  |         | `VecKey`keys<br/>                 |
| Kill prefix             |        |           |                  |         | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event       |        |           |                  |         | `Bytes`remark<br/>                |

## ParachainSystem

| Name                     | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                    |
| ------------------------ | ------ | --------- | ---------------- | ------- | -------------------------------------------- |
| Set validation data      |        |           |                  |         | `ParachainInherentData`data<br/>             |
| Sudo send upward message |        |           |                  |         | `UpwardMessage`message<br/>                  |
| Authorize upgrade        |        |           |                  |         | `Hash`code_hash<br/>`bool`check_version<br/> |
| Enact authorized upgrade |        |           |                  |         | `Vecu8`code<br/>                             |

## Timestamp

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| ---- | ------ | --------- | ---------------- | ------- | -------------------- |
| Set  |        |           |                  |         | `Compactu64`now<br/> |

## Balances

| Name                | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                  |
| ------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------------------ |
| Transfer            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Set balance         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>`CompactBalance`new_reserved<br/> |
| Force transfer      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>    |
| Transfer keep alive | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Transfer all        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                         |
| Force unreserve     |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                           |

## Democracy

| Name                      | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                      |
| ------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------ |
| Propose                   |        |           |                  |         | `BoundedCallOfT`proposal<br/>`CompactBalance`amount<br/>                       |
| Second                    |        |           |                  |         | `Compactu32`proposal<br/>                                                      |
| Vote                      |        |           |                  |         | `Compactu32`ref_index<br/>`AccountVote`vote<br/>                               |
| Emergency cancel          |        |           |                  |         | `ReferendumIndex`ref_index<br/>                                                |
| External propose          |        |           |                  |         | `BoundedCallOfT`proposal<br/>                                                  |
| External propose majority |        |           |                  |         | `BoundedCallOfT`proposal<br/>                                                  |
| External propose default  |        |           |                  |         | `BoundedCallOfT`proposal<br/>                                                  |
| Fast track                |        |           |                  |         | `H256`proposal_hash<br/>`BlockNumber`voting_period<br/>`BlockNumber`delay<br/> |
| Veto external             |        |           |                  |         | `H256`proposal_hash<br/>                                                       |
| Cancel referendum         |        |           |                  |         | `Compactu32`ref_index<br/>                                                     |
| Delegate                  |        |           |                  |         | `AccountIdLookupOfT`to<br/>`Conviction`conviction<br/>`Balance`balance<br/>    |
| Undelegate                |        |           |                  |         |                                                                                |
| Clear public proposals    |        |           |                  |         |                                                                                |
| Unlock                    |        |           |                  |         | `AccountIdLookupOfT`target<br/>                                                |
| Remove vote               |        |           |                  |         | `ReferendumIndex`index<br/>                                                    |
| Remove other vote         |        |           |                  |         | `AccountIdLookupOfT`target<br/>`ReferendumIndex`index<br/>                     |
| Blacklist                 |        |           |                  |         | `H256`proposal_hash<br/>`OptionReferendumIndex`maybe_ref_index<br/>            |
| Cancel proposal           |        |           |                  |         | `Compactu32`prop_index<br/>                                                    |
| Set metadata              |        |           |                  |         | `MetadataOwner`owner<br/>`OptionPreimageHash`maybe_hash<br/>                   |

## Council

| Name                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                         |
| ------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------- |
| Set members         |        |           |                  |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                              |
| Execute             |        |           |                  |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                              |
| Propose             |        |           |                  |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                    |
| Vote                |        |           |                  |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                       |
| Close old weight    |        |           |                  |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Compactu64`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |
| Disapprove proposal |        |           |                  |         | `Hash`proposal_hash<br/>                                                                                          |
| Close               |        |           |                  |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/>     |

## TechnicalCommittee

| Name                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                         |
| ------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------- |
| Set members         |        |           |                  |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                              |
| Execute             |        |           |                  |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                              |
| Propose             |        |           |                  |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                    |
| Vote                |        |           |                  |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                       |
| Close old weight    |        |           |                  |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Compactu64`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |
| Disapprove proposal |        |           |                  |         | `Hash`proposal_hash<br/>                                                                                          |
| Close               |        |           |                  |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/>     |

## Scheduler

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                  |
| -------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| Schedule             |        |           |                  |         | `BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                   |
| Cancel               |        |           |                  |         | `BlockNumber`when<br/>`u32`index<br/>                                                                                                      |
| Schedule named       |        |           |                  |         | `TaskName`id<br/>`BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>  |
| Cancel named         |        |           |                  |         | `TaskName`id<br/>                                                                                                                          |
| Schedule after       |        |           |                  |         | `BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                  |
| Schedule named after |        |           |                  |         | `TaskName`id<br/>`BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/> |

## Preimage

| Name               | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments         |
| ------------------ | ------ | --------- | ---------------- | ------- | ----------------- |
| Note preimage      |        |           |                  |         | `Vecu8`bytes<br/> |
| Unnote preimage    |        |           |                  |         | `Hash`hash<br/>   |
| Request preimage   |        |           |                  |         | `Hash`hash<br/>   |
| Unrequest preimage |        |           |                  |         | `Hash`hash<br/>   |

## Multisig

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                               |
| -------------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        |           |                  |         | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        |           |                  |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        |           |                  |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        |           |                  |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |

## Treasury

| Name             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                       |
| ---------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------- |
| Propose spend    |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Reject proposal  |        |           |                  |         | `Compactu32`proposal_id<br/>                                    |
| Approve proposal |        |           |                  |         | `Compactu32`proposal_id<br/>                                    |
| Spend            |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Remove approval  |        |           |                  |         | `Compactu32`proposal_id<br/>                                    |

## Bounties

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                          |
| -------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------- |
| Propose bounty       |        |           |                  |         | `CompactBalance`amount<br/>`Bytes`description<br/>                                 |
| Approve bounty       |        |           |                  |         | `Compactu32`bounty_id<br/>                                                         |
| Propose curator      |        |           |                  |         | `Compactu32`bounty_id<br/>`AccountIdLookupOfT`curator<br/>`CompactBalance`fee<br/> |
| Unassign curator     |        |           |                  |         | `Compactu32`bounty_id<br/>                                                         |
| Accept curator       |        |           |                  |         | `Compactu32`bounty_id<br/>                                                         |
| Award bounty         |        |           |                  |         | `Compactu32`bounty_id<br/>`AccountIdLookupOfT`beneficiary<br/>                     |
| Claim bounty         |        |           |                  |         | `Compactu32`bounty_id<br/>                                                         |
| Close bounty         |        |           |                  |         | `Compactu32`bounty_id<br/>                                                         |
| Extend bounty expiry |        |           |                  |         | `Compactu32`bounty_id<br/>`Bytes`remark<br/>                                       |

## ChildBounties

| Name               | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                 |
| ------------------ | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------- |
| Add child bounty   |        |           |                  |         | `Compactu32`parent_bounty_id<br/>`CompactBalance`amount<br/>`Vecu8`description<br/>                                       |
| Propose curator    |        |           |                  |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>`AccountIdLookupOfT`curator<br/>`CompactBalance`fee<br/> |
| Accept curator     |        |           |                  |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Unassign curator   |        |           |                  |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Award child bounty |        |           |                  |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>`AccountIdLookupOfT`beneficiary<br/>                     |
| Claim child bounty |        |           |                  |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Close child bounty |        |           |                  |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |

## Proxy

| Name                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                  |
| ------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------------------------------------------- |
| Proxy               |        |           |                  |         | `AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>                                         |
| Add proxy           |        |           |                  |         | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxy        |        |           |                  |         | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxies      |        |           |                  |         |                                                                                                                            |
| Create pure         |        |           |                  |         | `ProxyType`proxy_type<br/>`BlockNumber`delay<br/>`u16`index<br/>                                                           |
| Kill pure           |        |           |                  |         | `AccountIdLookupOfT`spawner<br/>`ProxyType`proxy_type<br/>`u16`index<br/>`Compactu32`height<br/>`Compactu32`ext_index<br/> |
| Announce            |        |           |                  |         | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Remove announcement |        |           |                  |         | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Reject announcement |        |           |                  |         | `AccountIdLookupOfT`delegate<br/>`CallHashOf`call_hash<br/>                                                                |
| Proxy announced     |        |           |                  |         | `AccountIdLookupOfT`delegate<br/>`AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>        |

## Session

| Name       | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                        |
| ---------- | ------ | --------- | ---------------- | ------- | -------------------------------- |
| Set keys   |        |           |                  |         | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys |        |           |                  |         |                                  |

## ParachainStaking

| Name                            | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                                                      |
| ------------------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Force new round                 |        |           |                  |         |                                                                                                                                                                                                                |
| Set inflation                   |        |           |                  |         | `Perquintill`collator_max_rate_percentage<br/>`Perquintill`collator_annual_reward_rate_percentage<br/>`Perquintill`delegator_max_rate_percentage<br/>`Perquintill`delegator_annual_reward_rate_percentage<br/> |
| Set max selected candidates     |        |           |                  |         | `u32`new\_<br/>                                                                                                                                                                                                |
| Set blocks per round            |        |           |                  |         | `BlockNumber`new\_<br/>                                                                                                                                                                                        |
| Set max candidate stake         |        |           |                  |         | `Balance`new\_<br/>                                                                                                                                                                                            |
| Force remove candidate          |        |           |                  |         | `LookupasStaticLookupSource`collator<br/>                                                                                                                                                                      |
| Join candidates                 |        |           |                  |         | `Balance`stake<br/>                                                                                                                                                                                            |
| Init leave candidates           |        |           |                  |         |                                                                                                                                                                                                                |
| Execute leave candidates        |        |           |                  |         | `LookupasStaticLookupSource`collator<br/>                                                                                                                                                                      |
| Cancel leave candidates         |        |           |                  |         |                                                                                                                                                                                                                |
| Candidate stake more            |        |           |                  |         | `Balance`more<br/>                                                                                                                                                                                             |
| Candidate stake less            |        |           |                  |         | `Balance`less<br/>                                                                                                                                                                                             |
| Join delegators                 |        |           |                  |         | `LookupasStaticLookupSource`collator<br/>`Balance`amount<br/>                                                                                                                                                  |
| Leave delegators                |        |           |                  |         |                                                                                                                                                                                                                |
| Delegator stake more            |        |           |                  |         | `LookupasStaticLookupSource`candidate<br/>`Balance`more<br/>                                                                                                                                                   |
| Delegator stake less            |        |           |                  |         | `LookupasStaticLookupSource`candidate<br/>`Balance`less<br/>                                                                                                                                                   |
| Unlock unstaked                 |        |           |                  |         | `LookupasStaticLookupSource`target<br/>                                                                                                                                                                        |
| Claim rewards                   |        |           |                  |         |                                                                                                                                                                                                                |
| Increment collator rewards      |        |           |                  |         |                                                                                                                                                                                                                |
| Increment delegator rewards     |        |           |                  |         |                                                                                                                                                                                                                |
| Execute scheduled reward change |        |           |                  |         |                                                                                                                                                                                                                |

## XcmpQueue

| Name                              | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                            |
| --------------------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------- |
| Service overweight                |        |           |                  |         | `OverweightIndex`index<br/>`Weight`weight_limit<br/> |
| Suspend xcm execution             |        |           |                  |         |                                                      |
| Resume xcm execution              |        |           |                  |         |                                                      |
| Update suspend threshold          |        |           |                  |         | `u32`new\_<br/>                                      |
| Update drop threshold             |        |           |                  |         | `u32`new\_<br/>                                      |
| Update resume threshold           |        |           |                  |         | `u32`new\_<br/>                                      |
| Update threshold weight           |        |           |                  |         | `Weight`new\_<br/>                                   |
| Update weight restrict decay      |        |           |                  |         | `Weight`new\_<br/>                                   |
| Update xcmp max individual weight |        |           |                  |         | `Weight`new\_<br/>                                   |

## PolkadotXcm

| Name                             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                 |
| -------------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Send                             |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedXcmTuple`message<br/>                                                                                                    |
| Teleport assets                  |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Reserve transfer assets          |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Execute                          |        |           |                  |         | `BoxVersionedXcmTasSysConfigRuntimeCall`message<br/>`Weight`max_weight<br/>                                                                                               |
| Force xcm version                |        |           |                  |         | `BoxMultiLocation`location<br/>`XcmVersion`xcm_version<br/>                                                                                                               |
| Force default xcm version        |        |           |                  |         | `OptionXcmVersion`maybe_xcm_version<br/>                                                                                                                                  |
| Force subscribe version notify   |        |           |                  |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Force unsubscribe version notify |        |           |                  |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Limited reserve transfer assets  |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |
| Limited teleport assets          |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |

## DmpQueue

| Name               | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                            |
| ------------------ | ------ | --------- | ---------------- | ------- | ---------------------------------------------------- |
| Service overweight |        |           |                  |         | `OverweightIndex`index<br/>`Weight`weight_limit<br/> |

## Vesting

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                |
| --------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------------- |
| Vest                  |        |           |                  |         |                                                                                          |
| Vest other            |        |           |                  |         | `AccountIdLookupOfT`target<br/>                                                          |
| Vested transfer       |        |           |                  |         | `AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/>                                |
| Force vested transfer |        |           |                  |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/> |
| Merge schedules       |        |           |                  |         | `u32`schedule1_index<br/>`u32`schedule2_index<br/>                                       |

## Utility

| Name          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                       |
| ------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------- |
| Batch         |        |           |                  |         | `VecCall`calls<br/>                             |
| As derivative |        |           |                  |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     |        |           |                  |         | `VecCall`calls<br/>                             |
| Dispatch as   |        |           |                  |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   |        |           |                  |         | `VecCall`calls<br/>                             |
| With weight   |        |           |                  |         | `Call`call<br/>`Weight`weight<br/>              |

## Currencies

| Name                     | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                 |
| ------------------------ | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------- |
| Transfer                 |        |           |                  |         | `LookupasStaticLookupSource`dest<br/>`CurrencyId`currency_id<br/>`Compactu128`amount<br/> |
| Transfer native currency |        |           |                  |         | `LookupasStaticLookupSource`dest<br/>`Compactu128`amount<br/>                             |
| Update balance           |        |           |                  |         | `LookupasStaticLookupSource`who<br/>`CurrencyId`currency_id<br/>`Amount`amount<br/>       |

## Tokens

| Name                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                           |
| ------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| Transfer            |        |           |                  |         | `LookupasStaticLookupSource`dest<br/>`CurrencyId`currency_id<br/>`CompactBalance`amount<br/>                                        |
| Transfer all        |        |           |                  |         | `LookupasStaticLookupSource`dest<br/>`CurrencyId`currency_id<br/>`bool`keep_alive<br/>                                              |
| Transfer keep alive |        |           |                  |         | `LookupasStaticLookupSource`dest<br/>`CurrencyId`currency_id<br/>`CompactBalance`amount<br/>                                        |
| Force transfer      |        |           |                  |         | `LookupasStaticLookupSource`source<br/>`LookupasStaticLookupSource`dest<br/>`CurrencyId`currency_id<br/>`CompactBalance`amount<br/> |
| Set balance         |        |           |                  |         | `LookupasStaticLookupSource`who<br/>`CurrencyId`currency_id<br/>`CompactBalance`new_free<br/>`CompactBalance`new_reserved<br/>      |

## XTokens

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                 |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| Transfer                     |        |           |                  |         | `CurrencyId`currency_id<br/>`Balance`amount<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>                   |
| Transfer multiasset          |        |           |                  |         | `BoxVersionedMultiAsset`asset<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>                                 |
| Transfer with fee            |        |           |                  |         | `CurrencyId`currency_id<br/>`Balance`amount<br/>`Balance`fee<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>  |
| Transfer multiasset with fee |        |           |                  |         | `BoxVersionedMultiAsset`asset<br/>`BoxVersionedMultiAsset`fee<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/> |
| Transfer multicurrencies     |        |           |                  |         | `VecTupleCurrencyIdBalance`currencies<br/>`u32`fee_item<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>       |
| Transfer multiassets         |        |           |                  |         | `BoxVersionedMultiAssets`assets<br/>`u32`fee_item<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>             |

## Identity

| Name              | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                       |
| ----------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------- |
| Add registrar     |        |           |                  |         | `AccountIdLookupOfT`account<br/>                                                                                |
| Set identity      |        |           |                  |         | `IdentityInfo`info<br/>                                                                                         |
| Set subs          |        |           |                  |         | `VecTupleAccountIdData`subs<br/>                                                                                |
| Clear identity    |        |           |                  |         |                                                                                                                 |
| Request judgement |        |           |                  |         | `Compactu32`reg_index<br/>`Compactu128`max_fee<br/>                                                             |
| Cancel request    |        |           |                  |         | `RegistrarIndex`reg_index<br/>                                                                                  |
| Set fee           |        |           |                  |         | `Compactu32`index<br/>`Compactu128`fee<br/>                                                                     |
| Set account id    |        |           |                  |         | `Compactu32`index<br/>`AccountIdLookupOfT`new\_<br/>                                                            |
| Set fields        |        |           |                  |         | `Compactu32`index<br/>`IdentityFields`fields<br/>                                                               |
| Provide judgement |        |           |                  |         | `Compactu32`reg_index<br/>`AccountIdLookupOfT`target<br/>`JudgementBalanceOfT`judgement<br/>`Hash`identity<br/> |
| Kill identity     |        |           |                  |         | `AccountIdLookupOfT`target<br/>                                                                                 |
| Add sub           |        |           |                  |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Rename sub        |        |           |                  |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Remove sub        |        |           |                  |         | `AccountIdLookupOfT`sub<br/>                                                                                    |
| Quit sub          |        |           |                  |         |                                                                                                                 |

## Contracts

| Name                             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                       |
| -------------------------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Call old weight                  |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`data<br/>            |
| Instantiate with code old weight |        |           |                  |         | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`code<br/>`Vecu8`data<br/>`Vecu8`salt<br/>         |
| Instantiate old weight           |        |           |                  |         | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Vecu8`data<br/>`Vecu8`salt<br/> |
| Upload code                      |        |           |                  |         | `Vecu8`code<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Determinism`determinism<br/>                                                                 |
| Remove code                      |        |           |                  |         | `CodeHash`code_hash<br/>                                                                                                                                        |
| Set code                         |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CodeHash`code_hash<br/>                                                                                                           |
| Call                             |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`data<br/>                |
| Instantiate with code            |        |           |                  |         | `CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`code<br/>`Vecu8`data<br/>`Vecu8`salt<br/>             |
| Instantiate                      |        |           |                  |         | `CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Bytes`data<br/>`Bytes`salt<br/>     |

## DiaOracleModule

| Name                   | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                   |
| ---------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------- |
| Add currency           |        |           |                  |         | `Vecu8`blockchain<br/>`Vecu8`symbol<br/>    |
| Remove currency        |        |           |                  |         | `Vecu8`blockchain<br/>`Vecu8`symbol<br/>    |
| Authorize account      |        |           |                  |         | `AccountId`account_id<br/>                  |
| Deauthorize account    |        |           |                  |         | `AccountId`account_id<br/>                  |
| Set updated coin infos |        |           |                  |         | `VecTupleVecu8Vecu8CoinInfo`coin_infos<br/> |
| Set batching api       |        |           |                  |         | `Vecu8`api<br/>                             |

## ZenlinkProtocol

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                                                                                                              |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Set fee receiver             |        |           |                  |         | `OptionLookupasStaticLookupSource`send_to<br/>                                                                                                                                                                                                                         |
| Set fee point                |        |           |                  |         | `u8`fee_point<br/>                                                                                                                                                                                                                                                     |
| Transfer                     |        |           |                  |         | `AssetId`asset_id<br/>`LookupasStaticLookupSource`recipient<br/>`Compactu128`amount<br/>                                                                                                                                                                               |
| Create pair                  |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>                                                                                                                                                                                                                             |
| Add liquidity                |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu128`amount_0_desired<br/>`Compactu128`amount_1_desired<br/>`Compactu128`amount_0_min<br/>`Compactu128`amount_1_min<br/>`Compactu32`deadline<br/>                                                                    |
| Remove liquidity             |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu128`liquidity<br/>`Compactu128`amount_0_min<br/>`Compactu128`amount_1_min<br/>`LookupasStaticLookupSource`recipient<br/>`Compactu32`deadline<br/>                                                                   |
| Swap exact assets for assets |        |           |                  |         | `Compactu128`amount_in<br/>`Compactu128`amount_out_min<br/>`VecAssetId`path<br/>`LookupasStaticLookupSource`recipient<br/>`Compactu32`deadline<br/>                                                                                                                    |
| Swap assets for exact assets |        |           |                  |         | `Compactu128`amount_out<br/>`Compactu128`amount_in_max<br/>`VecAssetId`path<br/>`LookupasStaticLookupSource`recipient<br/>`Compactu32`deadline<br/>                                                                                                                    |
| Bootstrap create             |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu128`target_supply_0<br/>`Compactu128`target_supply_1<br/>`Compactu128`capacity_supply_0<br/>`Compactu128`capacity_supply_1<br/>`Compactu32`end<br/>`VecAssetId`rewards<br/>`VecTupleAssetIdAssetBalance`limits<br/> |
| Bootstrap contribute         |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu128`amount_0_contribute<br/>`Compactu128`amount_1_contribute<br/>`Compactu32`deadline<br/>                                                                                                                          |
| Bootstrap claim              |        |           |                  |         | `LookupasStaticLookupSource`recipient<br/>`AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu32`deadline<br/>                                                                                                                                                          |
| Bootstrap end                |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>                                                                                                                                                                                                                             |
| Bootstrap update             |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu128`target_supply_0<br/>`Compactu128`target_supply_1<br/>`Compactu128`capacity_supply_0<br/>`Compactu128`capacity_supply_1<br/>`Compactu32`end<br/>`VecAssetId`rewards<br/>`VecTupleAssetIdAssetBalance`limits<br/> |
| Bootstrap refund             |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>                                                                                                                                                                                                                             |
| Bootstrap charge reward      |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`VecTupleAssetIdAssetBalance`charge_rewards<br/>                                                                                                                                                                             |
| Bootstrap withdraw reward    |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`LookupasStaticLookupSource`recipient<br/>                                                                                                                                                                                   |

## Farming

| Name                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                                                                                                                                                                                                        |
| ------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create farming pool |        |           |                  |         | `VecTupleCurrencyIdOfTPerbill`tokens_proportion<br/>`VecTupleCurrencyIdOfTBalanceOfT`basic_rewards<br/>`OptionCurrencyIdOfTBlockNumberForTVecCurrencyIdOfTBalanceOfT`gauge_init<br/>`Balance`min_deposit_to_start<br/>`Compactu32`after_block_to_start<br/>`Compactu32`withdraw_limit_time<br/>`Compactu32`claim_limit_time<br/>`u8`withdraw_limit_count<br/>    |
| Charge              |        |           |                  |         | `PoolId`pid<br/>`VecTupleCurrencyIdOfTBalanceOfT`rewards<br/>                                                                                                                                                                                                                                                                                                    |
| Deposit             |        |           |                  |         | `PoolId`pid<br/>`Balance`add_value<br/>`OptionTupleBalanceOfTBlockNumber`gauge_info<br/>                                                                                                                                                                                                                                                                         |
| Withdraw            |        |           |                  |         | `PoolId`pid<br/>`OptionBalance`remove_value<br/>                                                                                                                                                                                                                                                                                                                 |
| Claim               |        |           |                  |         | `PoolId`pid<br/>                                                                                                                                                                                                                                                                                                                                                 |
| Withdraw claim      |        |           |                  |         | `PoolId`pid<br/>                                                                                                                                                                                                                                                                                                                                                 |
| Force retire pool   |        |           |                  |         | `PoolId`pid<br/>                                                                                                                                                                                                                                                                                                                                                 |
| Set retire limit    |        |           |                  |         | `u32`limit<br/>                                                                                                                                                                                                                                                                                                                                                  |
| Close pool          |        |           |                  |         | `PoolId`pid<br/>                                                                                                                                                                                                                                                                                                                                                 |
| Reset pool          |        |           |                  |         | `PoolId`pid<br/>`OptionVecTupleCurrencyIdOfTBalanceOfT`basic_rewards<br/>`OptionBalance`min_deposit_to_start<br/>`OptionBlockNumber`after_block_to_start<br/>`OptionBlockNumber`withdraw_limit_time<br/>`OptionBlockNumber`claim_limit_time<br/>`Optionu8`withdraw_limit_count<br/>`OptionCurrencyIdOfTBlockNumberForTVecCurrencyIdOfTBalanceOfT`gauge_init<br/> |
| Kill pool           |        |           |                  |         | `PoolId`pid<br/>                                                                                                                                                                                                                                                                                                                                                 |
| Edit pool           |        |           |                  |         | `PoolId`pid<br/>`OptionVecTupleCurrencyIdOfTBalanceOfT`basic_rewards<br/>`OptionBlockNumber`withdraw_limit_time<br/>`OptionBlockNumber`claim_limit_time<br/>`OptionVecTupleCurrencyIdOfTBalanceOfT`gauge_basic_rewards<br/>`Optionu8`withdraw_limit_count<br/>                                                                                                   |
| Gauge withdraw      |        |           |                  |         | `PoolId`gid<br/>                                                                                                                                                                                                                                                                                                                                                 |
| Force gauge claim   |        |           |                  |         | `PoolId`gid<br/>                                                                                                                                                                                                                                                                                                                                                 |

## AssetRegistry

| Name           | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                                                                 |
| -------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Register asset |        |           |                  |         | `AssetMetadataBalanceCustomMetadata`metadata<br/>`OptionAssetId`asset_id<br/>                                                                                                                                             |
| Update asset   |        |           |                  |         | `AssetId`asset_id<br/>`Optionu32`decimals<br/>`OptionVecu8`name<br/>`OptionVecu8`symbol<br/>`OptionBalance`existential_deposit<br/>`OptionOptionVersionedMultiLocation`location<br/>`OptionCustomMetadata`additional<br/> |

## VestingManager

| Name                    | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                            |
| ----------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------- |
| Remove vesting schedule |        |           |                  |         | `AccountIdLookupOfT`who<br/>`u32`schedule_index<br/> |
