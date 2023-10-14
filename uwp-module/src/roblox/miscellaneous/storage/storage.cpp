#include "storage.h"

namespace module {
	storage* storage::singleton{ nullptr };
	auto storage::getSingleton() -> storage* {
		if (singleton == nullptr)
			singleton = new storage();
		
		return singleton;
	}

	auto storage::exist(const char* index) -> bool {
		return (this->_items[index] != NULL);
	}

	auto storage::foreach(storageIterator it) -> void {
		for (const auto& [key, value] : _items)
			it(key, value);
	}

	auto storage::remove(const char* index) -> void {
			this->_items.erase(index);
	}
}