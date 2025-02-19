/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License Version 2.0 with LLVM Exceptions
 * (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 *   https://llvm.org/LICENSE.txt
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <unifex/tag_invoke.hpp>

#include <unifex/detail/prologue.hpp>

namespace unifex {
namespace _pipe_cpo {
inline const struct open_pipe_cpo {
  template <typename Executor>
  auto operator()(Executor&& executor) const
      noexcept(is_nothrow_tag_invocable_v<
               open_pipe_cpo,
               Executor>)
          -> tag_invoke_result_t<
              open_pipe_cpo,
              Executor> {
    return unifex::tag_invoke(*this, (Executor &&) executor);
  }
} open_pipe{};
} // namespace _pipe_cpo

using _pipe_cpo::open_pipe;
} // namespace unifex

#include <unifex/detail/epilogue.hpp>
