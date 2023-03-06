# Pendulum 2.2.x

## System

| Name                    | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                         |
| ----------------------- | ------ | --------- | --------- | ------- | --------------------------------- |
| Remark                  |        |           |           |         | `Bytes`remark<br/>                |
| Set heap pages          |        |           |           |         | `u64`pages<br/>                   |
| Set code                |        |           |           |         | `Vecu8`code<br/>                  |
| Set code without checks |        |           |           |         | `Vecu8`code<br/>                  |
| Set storage             |        |           |           |         | `VecKeyValue`items<br/>           |
| Kill storage            |        |           |           |         | `VecKey`keys<br/>                 |
| Kill prefix             |        |           |           |         | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event       |        |           |           |         | `Bytes`remark<br/>                |

## ParachainSystem

| Name                     | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                        |
| ------------------------ | ------ | --------- | --------- | ------- | -------------------------------- |
| Set validation data      |        |           |           |         | `ParachainInherentData`data<br/> |
| Sudo send upward message |        |           |           |         | `UpwardMessage`message<br/>      |
| Authorize upgrade        |        |           |           |         | `Hash`code_hash<br/>             |
| Enact authorized upgrade |        |           |           |         | `Vecu8`code<br/>                 |

## Timestamp

| Name | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments            |
| ---- | ------ | --------- | --------- | ------- | -------------------- |
| Set  |        |           |           |         | `Compactu64`now<br/> |

## Balances

| Name                | Nano S             | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                                                                  |
| ------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------------------ |
| Transfer            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Set balance         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>`CompactBalance`new_reserved<br/> |
| Force transfer      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>    |
| Transfer keep alive | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Transfer all        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                         |
| Force unreserve     |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                           |

## Sudo

| Name                  | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                   |
| --------------------- | ------ | --------- | --------- | ------- | ------------------------------------------- |
| Sudo                  |        |           |           |         | `Call`call<br/>                             |
| Sudo unchecked weight |        |           |           |         | `Call`call<br/>`Weight`weight<br/>          |
| Set key               |        |           |           |         | `AccountIdLookupOfT`new\_<br/>              |
| Sudo as               |        |           |           |         | `AccountIdLookupOfT`who<br/>`Call`call<br/> |

## Democracy

| Name                      | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                      |
| ------------------------- | ------ | --------- | --------- | ------- | ------------------------------------------------------------------------------ |
| Propose                   |        |           |           |         | `BoundedCallOfT`proposal<br/>`CompactBalance`amount<br/>                       |
| Second                    |        |           |           |         | `Compactu32`proposal<br/>                                                      |
| Vote                      |        |           |           |         | `Compactu32`ref_index<br/>`AccountVote`vote<br/>                               |
| Emergency cancel          |        |           |           |         | `ReferendumIndex`ref_index<br/>                                                |
| External propose          |        |           |           |         | `BoundedCallOfT`proposal<br/>                                                  |
| External propose majority |        |           |           |         | `BoundedCallOfT`proposal<br/>                                                  |
| External propose default  |        |           |           |         | `BoundedCallOfT`proposal<br/>                                                  |
| Fast track                |        |           |           |         | `H256`proposal_hash<br/>`BlockNumber`voting_period<br/>`BlockNumber`delay<br/> |
| Veto external             |        |           |           |         | `H256`proposal_hash<br/>                                                       |
| Cancel referendum         |        |           |           |         | `Compactu32`ref_index<br/>                                                     |
| Delegate                  |        |           |           |         | `AccountIdLookupOfT`to<br/>`Conviction`conviction<br/>`Balance`balance<br/>    |
| Undelegate                |        |           |           |         |                                                                                |
| Clear public proposals    |        |           |           |         |                                                                                |
| Unlock                    |        |           |           |         | `AccountIdLookupOfT`target<br/>                                                |
| Remove vote               |        |           |           |         | `ReferendumIndex`index<br/>                                                    |
| Remove other vote         |        |           |           |         | `AccountIdLookupOfT`target<br/>`ReferendumIndex`index<br/>                     |
| Blacklist                 |        |           |           |         | `H256`proposal_hash<br/>`OptionReferendumIndex`maybe_ref_index<br/>            |
| Cancel proposal           |        |           |           |         | `Compactu32`prop_index<br/>                                                    |

## Council

| Name                | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                                         |
| ------------------- | ------ | --------- | --------- | ------- | ----------------------------------------------------------------------------------------------------------------- |
| Set members         |        |           |           |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                              |
| Execute             |        |           |           |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                              |
| Propose             |        |           |           |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                    |
| Vote                |        |           |           |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                       |
| Close old weight    |        |           |           |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Compactu64`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |
| Disapprove proposal |        |           |           |         | `Hash`proposal_hash<br/>                                                                                          |
| Close               |        |           |           |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/>     |

## TechnicalCommittee

| Name                | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                                         |
| ------------------- | ------ | --------- | --------- | ------- | ----------------------------------------------------------------------------------------------------------------- |
| Set members         |        |           |           |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                              |
| Execute             |        |           |           |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                              |
| Propose             |        |           |           |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                    |
| Vote                |        |           |           |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                       |
| Close old weight    |        |           |           |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Compactu64`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |
| Disapprove proposal |        |           |           |         | `Hash`proposal_hash<br/>                                                                                          |
| Close               |        |           |           |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/>     |

## Scheduler

| Name                 | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                                                                  |
| -------------------- | ------ | --------- | --------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| Schedule             |        |           |           |         | `BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                   |
| Cancel               |        |           |           |         | `BlockNumber`when<br/>`u32`index<br/>                                                                                                      |
| Schedule named       |        |           |           |         | `TaskName`id<br/>`BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>  |
| Cancel named         |        |           |           |         | `TaskName`id<br/>                                                                                                                          |
| Schedule after       |        |           |           |         | `BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                  |
| Schedule named after |        |           |           |         | `TaskName`id<br/>`BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/> |

## Preimage

| Name               | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments         |
| ------------------ | ------ | --------- | --------- | ------- | ----------------- |
| Note preimage      |        |           |           |         | `Vecu8`bytes<br/> |
| Unnote preimage    |        |           |           |         | `Hash`hash<br/>   |
| Request preimage   |        |           |           |         | `Hash`hash<br/>   |
| Unrequest preimage |        |           |           |         | `Hash`hash<br/>   |

## Multisig

| Name                 | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                                                               |
| -------------------- | ------ | --------- | --------- | ------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        |           |           |         | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        |           |           |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        |           |           |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        |           |           |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |

## Treasury

| Name             | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                       |
| ---------------- | ------ | --------- | --------- | ------- | --------------------------------------------------------------- |
| Propose spend    |        |           |           |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Reject proposal  |        |           |           |         | `Compactu32`proposal_id<br/>                                    |
| Approve proposal |        |           |           |         | `Compactu32`proposal_id<br/>                                    |
| Spend            |        |           |           |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Remove approval  |        |           |           |         | `Compactu32`proposal_id<br/>                                    |

## Bounties

| Name                 | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                          |
| -------------------- | ------ | --------- | --------- | ------- | ---------------------------------------------------------------------------------- |
| Propose bounty       |        |           |           |         | `CompactBalance`amount<br/>`Bytes`description<br/>                                 |
| Approve bounty       |        |           |           |         | `Compactu32`bounty_id<br/>                                                         |
| Propose curator      |        |           |           |         | `Compactu32`bounty_id<br/>`AccountIdLookupOfT`curator<br/>`CompactBalance`fee<br/> |
| Unassign curator     |        |           |           |         | `Compactu32`bounty_id<br/>                                                         |
| Accept curator       |        |           |           |         | `Compactu32`bounty_id<br/>                                                         |
| Award bounty         |        |           |           |         | `Compactu32`bounty_id<br/>`AccountIdLookupOfT`beneficiary<br/>                     |
| Claim bounty         |        |           |           |         | `Compactu32`bounty_id<br/>                                                         |
| Close bounty         |        |           |           |         | `Compactu32`bounty_id<br/>                                                         |
| Extend bounty expiry |        |           |           |         | `Compactu32`bounty_id<br/>`Bytes`remark<br/>                                       |

## ChildBounties

| Name               | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                                                 |
| ------------------ | ------ | --------- | --------- | ------- | ------------------------------------------------------------------------------------------------------------------------- |
| Add child bounty   |        |           |           |         | `Compactu32`parent_bounty_id<br/>`CompactBalance`amount<br/>`Vecu8`description<br/>                                       |
| Propose curator    |        |           |           |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>`AccountIdLookupOfT`curator<br/>`CompactBalance`fee<br/> |
| Accept curator     |        |           |           |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Unassign curator   |        |           |           |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Award child bounty |        |           |           |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>`AccountIdLookupOfT`beneficiary<br/>                     |
| Claim child bounty |        |           |           |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Close child bounty |        |           |           |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |

## Authorship

| Name       | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                  |
| ---------- | ------ | --------- | --------- | ------- | -------------------------- |
| Set uncles |        |           |           |         | `VecHeader`new_uncles<br/> |

## Session

| Name       | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                        |
| ---------- | ------ | --------- | --------- | ------- | -------------------------------- |
| Set keys   |        |           |           |         | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys |        |           |           |         |                                  |

## ParachainStaking

| Name                            | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                                                                                                                                      |
| ------------------------------- | ------ | --------- | --------- | ------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Force new round                 |        |           |           |         |                                                                                                                                                                                                                |
| Set inflation                   |        |           |           |         | `Perquintill`collator_max_rate_percentage<br/>`Perquintill`collator_annual_reward_rate_percentage<br/>`Perquintill`delegator_max_rate_percentage<br/>`Perquintill`delegator_annual_reward_rate_percentage<br/> |
| Set max selected candidates     |        |           |           |         | `u32`new\_<br/>                                                                                                                                                                                                |
| Set blocks per round            |        |           |           |         | `BlockNumber`new\_<br/>                                                                                                                                                                                        |
| Set max candidate stake         |        |           |           |         | `Balance`new\_<br/>                                                                                                                                                                                            |
| Force remove candidate          |        |           |           |         | `LookupasStaticLookupSource`collator<br/>                                                                                                                                                                      |
| Join candidates                 |        |           |           |         | `Balance`stake<br/>                                                                                                                                                                                            |
| Init leave candidates           |        |           |           |         |                                                                                                                                                                                                                |
| Execute leave candidates        |        |           |           |         | `LookupasStaticLookupSource`collator<br/>                                                                                                                                                                      |
| Cancel leave candidates         |        |           |           |         |                                                                                                                                                                                                                |
| Candidate stake more            |        |           |           |         | `Balance`more<br/>                                                                                                                                                                                             |
| Candidate stake less            |        |           |           |         | `Balance`less<br/>                                                                                                                                                                                             |
| Join delegators                 |        |           |           |         | `LookupasStaticLookupSource`collator<br/>`Balance`amount<br/>                                                                                                                                                  |
| Leave delegators                |        |           |           |         |                                                                                                                                                                                                                |
| Delegator stake more            |        |           |           |         | `LookupasStaticLookupSource`candidate<br/>`Balance`more<br/>                                                                                                                                                   |
| Delegator stake less            |        |           |           |         | `LookupasStaticLookupSource`candidate<br/>`Balance`less<br/>                                                                                                                                                   |
| Unlock unstaked                 |        |           |           |         | `LookupasStaticLookupSource`target<br/>                                                                                                                                                                        |
| Claim rewards                   |        |           |           |         |                                                                                                                                                                                                                |
| Increment collator rewards      |        |           |           |         |                                                                                                                                                                                                                |
| Increment delegator rewards     |        |           |           |         |                                                                                                                                                                                                                |
| Execute scheduled reward change |        |           |           |         |                                                                                                                                                                                                                |

## XcmpQueue

| Name                              | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                               |
| --------------------------------- | ------ | --------- | --------- | ------- | ------------------------------------------------------- |
| Service overweight                |        |           |           |         | `OverweightIndex`index<br/>`XcmWeight`weight_limit<br/> |
| Suspend xcm execution             |        |           |           |         |                                                         |
| Resume xcm execution              |        |           |           |         |                                                         |
| Update suspend threshold          |        |           |           |         | `u32`new\_<br/>                                         |
| Update drop threshold             |        |           |           |         | `u32`new\_<br/>                                         |
| Update resume threshold           |        |           |           |         | `u32`new\_<br/>                                         |
| Update threshold weight           |        |           |           |         | `XcmWeight`new\_<br/>                                   |
| Update weight restrict decay      |        |           |           |         | `XcmWeight`new\_<br/>                                   |
| Update xcmp max individual weight |        |           |           |         | `XcmWeight`new\_<br/>                                   |

## PolkadotXcm

| Name                             | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                                                                                                 |
| -------------------------------- | ------ | --------- | --------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Send                             |        |           |           |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedXcmTuple`message<br/>                                                                                                    |
| Teleport assets                  |        |           |           |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Reserve transfer assets          |        |           |           |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Execute                          |        |           |           |         | `BoxVersionedXcmTasSysConfigRuntimeCall`message<br/>`XcmWeight`max_weight<br/>                                                                                            |
| Force xcm version                |        |           |           |         | `BoxMultiLocation`location<br/>`XcmVersion`xcm_version<br/>                                                                                                               |
| Force default xcm version        |        |           |           |         | `OptionXcmVersion`maybe_xcm_version<br/>                                                                                                                                  |
| Force subscribe version notify   |        |           |           |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Force unsubscribe version notify |        |           |           |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Limited reserve transfer assets  |        |           |           |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |
| Limited teleport assets          |        |           |           |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |

## DmpQueue

| Name               | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                               |
| ------------------ | ------ | --------- | --------- | ------- | ------------------------------------------------------- |
| Service overweight |        |           |           |         | `OverweightIndex`index<br/>`XcmWeight`weight_limit<br/> |

## Vesting

| Name                  | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                |
| --------------------- | ------ | --------- | --------- | ------- | ---------------------------------------------------------------------------------------- |
| Vest                  |        |           |           |         |                                                                                          |
| Vest other            |        |           |           |         | `AccountIdLookupOfT`target<br/>                                                          |
| Vested transfer       |        |           |           |         | `AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/>                                |
| Force vested transfer |        |           |           |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/> |
| Merge schedules       |        |           |           |         | `u32`schedule1_index<br/>`u32`schedule2_index<br/>                                       |

## Utility

| Name          | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                       |
| ------------- | ------ | --------- | --------- | ------- | ----------------------------------------------- |
| Batch         |        |           |           |         | `VecCall`calls<br/>                             |
| As derivative |        |           |           |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     |        |           |           |         | `VecCall`calls<br/>                             |
| Dispatch as   |        |           |           |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   |        |           |           |         | `VecCall`calls<br/>                             |
| With weight   |        |           |           |         | `Call`call<br/>`Weight`weight<br/>              |

## Currencies

| Name                     | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                 |
| ------------------------ | ------ | --------- | --------- | ------- | ----------------------------------------------------------------------------------------- |
| Transfer                 |        |           |           |         | `LookupasStaticLookupSource`dest<br/>`CurrencyId`currency_id<br/>`Compactu128`amount<br/> |
| Transfer native currency |        |           |           |         | `LookupasStaticLookupSource`dest<br/>`Compactu128`amount<br/>                             |
| Update balance           |        |           |           |         | `LookupasStaticLookupSource`who<br/>`CurrencyId`currency_id<br/>`Amount`amount<br/>       |

## Tokens

| Name                | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                                                           |
| ------------------- | ------ | --------- | --------- | ------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| Transfer            |        |           |           |         | `LookupasStaticLookupSource`dest<br/>`CurrencyId`currency_id<br/>`CompactBalance`amount<br/>                                        |
| Transfer all        |        |           |           |         | `LookupasStaticLookupSource`dest<br/>`CurrencyId`currency_id<br/>`bool`keep_alive<br/>                                              |
| Transfer keep alive |        |           |           |         | `LookupasStaticLookupSource`dest<br/>`CurrencyId`currency_id<br/>`CompactBalance`amount<br/>                                        |
| Force transfer      |        |           |           |         | `LookupasStaticLookupSource`source<br/>`LookupasStaticLookupSource`dest<br/>`CurrencyId`currency_id<br/>`CompactBalance`amount<br/> |
| Set balance         |        |           |           |         | `LookupasStaticLookupSource`who<br/>`CurrencyId`currency_id<br/>`CompactBalance`new_free<br/>`CompactBalance`new_reserved<br/>      |

## XTokens

| Name                         | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                                                                 |
| ---------------------------- | ------ | --------- | --------- | ------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| Transfer                     |        |           |           |         | `CurrencyId`currency_id<br/>`Balance`amount<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>                   |
| Transfer multiasset          |        |           |           |         | `BoxVersionedMultiAsset`asset<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>                                 |
| Transfer with fee            |        |           |           |         | `CurrencyId`currency_id<br/>`Balance`amount<br/>`Balance`fee<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>  |
| Transfer multiasset with fee |        |           |           |         | `BoxVersionedMultiAsset`asset<br/>`BoxVersionedMultiAsset`fee<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/> |
| Transfer multicurrencies     |        |           |           |         | `VecTupleCurrencyIdBalance`currencies<br/>`u32`fee_item<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>       |
| Transfer multiassets         |        |           |           |         | `BoxVersionedMultiAssets`assets<br/>`u32`fee_item<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>             |

## VestingManager

| Name                    | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                            |
| ----------------------- | ------ | --------- | --------- | ------- | ---------------------------------------------------- |
| Remove vesting schedule |        |           |           |         | `AccountIdLookupOfT`who<br/>`u32`schedule_index<br/> |
