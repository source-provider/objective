#pragma once
#include <Windows.h>
#include <string>
#include <map>

#include <utilities/hashing/fnv.h>
namespace module {
	class storage {
	private:
		static storage* singleton;
		std::map<const char*, std::intptr_t> _items;
	public:
		using storageIterator = void(*)(const char*, std::intptr_t);
	public:
		static auto getSingleton() -> storage*;

		template<typename T = std::intptr_t>
		auto store(const char* index, T value) -> void {
			this->_items[index] = reinterpret_cast<std::intptr_t>(value);
		}

		template<typename T = std::intptr_t>
		auto find(const char* index) -> T {
			return reinterpret_cast<T>(this->_items[index]);
		}

		auto exist(const char* index) -> bool;
		auto foreach(storageIterator it) -> void;
		auto remove(const char* index) -> void;
	};
}
