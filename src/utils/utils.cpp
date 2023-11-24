#include "utils/utils.hpp"
#include <stdexcept>
//---------------------------------------------------------------------------
// AnyBlob - Universal Cloud Object Storage Library
// Dominik Durner, 2022
//
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
// SPDX-License-Identifier: MPL-2.0
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
namespace anyblob {
namespace utils {
//---------------------------------------------------------------------------
string hexEncode(const uint8_t* input, uint64_t length, bool upper)
// Encodes a string as a hex string
{
    const char hex[] = "0123456789abcdef";
    string output;
    output.reserve(length << 1);
    for (auto i = 0u; i < length; i++) {
        output.push_back(upper ? toupper(hex[input[i] >> 4]) : hex[input[i] >> 4]);
        output.push_back(upper ? toupper(hex[input[i] & 15]) : hex[input[i] & 15]);
    }
    return output;
}
//---------------------------------------------------------------------------
string encodeUrlParameters(const string& encode)
// Encodes a string for url
{
    string result;
    for (auto c : encode) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
            result += c;
        else {
            result += "%";
            result += hexEncode(reinterpret_cast<uint8_t*>(&c), 1, true);
        }
    }
    return result;
}
//---------------------------------------------------------------------------
}; // namespace utils
}; // namespace anyblob
