#pragma once
#include <memory>
#include <string>
//---------------------------------------------------------------------------
// AnyBlob - Universal Cloud Object Storage Library
// Dominik Durner, 2022
//
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
// SPDX-License-Identifier: MPL-2.0
//---------------------------------------------------------------------------
namespace anyblob {
namespace utils {
//---------------------------------------------------------------------------
/// Encode url special characters in %HEX
std::string encodeUrlParameters(const std::string& encode);
/// Encode everything from binary representation to hex
std::string hexEncode(const uint8_t* input, uint64_t length, bool upper = false);
//---------------------------------------------------------------------------
}; // namespace utils
}; // namespace anyblob
