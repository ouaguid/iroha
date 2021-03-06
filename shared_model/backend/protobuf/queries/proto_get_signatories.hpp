/**
 * Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IROHA_PROTO_GET_SIGNATORIES_H
#define IROHA_PROTO_GET_SIGNATORIES_H

#include "backend/protobuf/common_objects/trivial_proto.hpp"
#include "interfaces/queries/get_signatories.hpp"
#include "queries.pb.h"

namespace shared_model {
  namespace proto {
    class GetSignatories final : public CopyableProto<interface::GetSignatories,
                                                      iroha::protocol::Query,
                                                      GetSignatories> {
     public:
      template <typename QueryType>
      explicit GetSignatories(QueryType &&query);

      GetSignatories(const GetSignatories &o);

      GetSignatories(GetSignatories &&o) noexcept;

      const interface::types::AccountIdType &accountId() const override;

     private:
      // ------------------------------| fields |-------------------------------

      const iroha::protocol::GetSignatories &account_signatories_;
    };

  }  // namespace proto
}  // namespace shared_model

#endif  // IROHA_PROTO_GET_SIGNATORIES_H
