#pragma once
#include <roblox/miscellaneous/configuration.hpp>
#include <cstdint>
#include "random.h"


#pragma warning(disable: 4307)
namespace module::security::obfuscation::string
{
	template <uint32_t size, uint32_t counter>
	struct obfuscatedString {
		static constexpr std::array<uint8_t, size> XOR = uniformDistribution<uint8_t, size, counter>(0, 255);
		std::array<char, size> encrypted;

		static constexpr __forceinline auto encrypt(uint32_t idx, char C) -> char {
			return C ^ XOR[idx];
		}

		template <size_t... idx>
		__forceinline constexpr obfuscatedString(const char* str, std::index_sequence<idx...>) :
			encrypted({ encrypt(idx, str[idx])... }) { }

		__forceinline const char* decrypt() noexcept {
			for (uint32_t x = 0; x < size; x++)
				encrypted[x] ^= XOR[x];

			return encrypted.data();
		}
	};
}

#if EXPLOIT_DEBUG_MODE
#define obfuscate_str(s) s
#define obfuscate_str_tea(s) s
#else 
#define obfuscate_str(s) (module::security::obfuscation::string::obfuscatedString<sizeof(s), __COUNTER__>(s, std::make_index_sequence<sizeof(s)>()).decrypt())
#define obfuscate_str_tea(s) (module::security::obfuscation::string::obfuscatedString<sizeof(s), __COUNTER__>(s, std::make_index_sequence<sizeof(s)>()).decrypt())
#endif
