#include "HashTable.h"
#include "Exceptions/NullPointer.h"
#include "Exceptions/NoValue.h"

int HashTable::hashFunction(const Key &key, int table_size, const int multiplier) const {
    int hashResult = 0;
    for (int i = 0; i != key.size(); ++i) {
        hashResult = (multiplier * hashResult + key[i]) % table_size;
    }
    hashResult = (hashResult * 2 + 1) % table_size;
    return hashResult;
}

int HashTable::hashFunction1(const Key &key, int table_size) const {
    return hashFunction(key, table_size, table_size - 1);
}

int HashTable::hashFunction2(const Key &key, int table_size) const {
    return hashFunction(key, table_size, table_size + 1);
}

void HashTable::resize() {
    int past_buffer_size = _buffer_size;
    _buffer_size *= 2;
    _size_all_non_nullptr = 0;
    _essential_size = 0;
    Table table2 = _table;
    
    for (size_t i = 0; i < past_buffer_size; ++i) {
        _table[i].second.first = nullptr;
    }
    
    _table.resize(_buffer_size);
    for (int i = 0; i < past_buffer_size; ++i) {
        if (table2[i].second.first && table2[i].second.first) {
            insert(table2[i].first, *(table2[i].second.first));
        }
    }
    // удаление предыдущего массива
    for (int i = 0; i < past_buffer_size; ++i) {
        delete table2[i].second.first;
    }
}

void HashTable::rehash() {
    _size_all_non_nullptr = 0;
    _essential_size = 0;
    Table table2 = _table;
    
    for (size_t i = 0; i < _buffer_size; ++i) {
        _table[i].second.first = nullptr;
    }
    
    for (int i = 0; i < _buffer_size; ++i) {
        if (table2[i].second.first && table2[i].second.first) {
            insert(table2[i].first, *(table2[i].second.first));
        }
    }
    // удаление предыдущего массива
    for (int i = 0; i < _buffer_size; ++i) {
        delete table2[i].second.first;
    }
}

HashTable::HashTable() {
    _buffer_size = _initial_size;
    _essential_size = 0;
    _size_all_non_nullptr = 0;
    _table.resize(_buffer_size);
    
    for (size_t i = 0; i < _buffer_size; ++i) {
        _table[i].first = "";
        _table[i].second.first = nullptr;
        _table[i].second.second = true;
    }
}

HashTable::HashTable(const HashTable &b) {
    for (size_t i = 0; i < _buffer_size; ++i) {
        delete _table[i].second.first;
    }
    _buffer_size = b._buffer_size;
    _essential_size = b._essential_size;
    _size_all_non_nullptr = b._size_all_non_nullptr;
    _table.resize(_buffer_size);
    for (size_t i = 0; i < _buffer_size; ++i) {
        _table[i].first = b._table[i].first;
        _table[i].second.second = b._table[i].second.second;
        if (b._table[i].second.first != nullptr) {
            _table[i].second.first = new Value(b._table[i].second.first->_age, b._table[i].second.first->_weight);
            if (_table[i].second.first == nullptr) {
                throw Exceptions::NullPointer("null pointer in copy constructor");
            }
        } else {
            _table[i].second.first = nullptr;
        }
    }
}

HashTable::HashTable(HashTable &&b) noexcept {
    _buffer_size = b._buffer_size;
    b._buffer_size = 0;
    _essential_size = b._essential_size;
    b._essential_size = 0;
    _size_all_non_nullptr = b._size_all_non_nullptr;
    b._size_all_non_nullptr = 0;
    _table.resize(_buffer_size);
    _table = std::move(b._table);
}

HashTable::~HashTable() {
    for (size_t i = 0; i < _buffer_size; ++i) {
        delete _table[i].second.first;
    }
}

bool HashTable::contains(const Key &k) const {
    int h1 = hashFunction1(k, _buffer_size); // значение, отвечающее за начальную позицию
    int h2 = hashFunction2(k, _buffer_size); // значение, ответственное за "шаг" по таблице
    int i = 0;
    while (_table[h1].second.first != nullptr && i < _buffer_size) {
        if (_table[h1].first == k && _table[h1].second.second) {
            return true;
        } // такой элемент есть
        h1 = (h1 + h2) % _buffer_size;
        ++i; // если у нас i >=  buffer_size, значит мы уже обошли абсолютно все ячейки, именно для этого мы считаем i, иначе мы могли бы зациклиться.
    }
    return false;
}

bool HashTable::erase(const Key &k) {
    
    int h1 = hashFunction1(k, _buffer_size);
    int h2 = hashFunction2(k, _buffer_size);
    int i = 0;
    while (_table[h1].second.first != nullptr && i < _buffer_size) {
        if (_table[h1].first == k && _table[h1].second.first) {
            _table[h1].second.second = false;
            --_essential_size;
            return true;
        }
        h1 = (h1 + h2) % _buffer_size;
        ++i;
    }
    return false;
    
}

bool HashTable::insert(const Key &k, const Value &v) {
    if (_essential_size + 1 > int(_rehash_size * _buffer_size)) {
        resize();
    } else if (_size_all_non_nullptr > 2 * _essential_size) {
        rehash();
    } // происходит рехеш, так как слишком много deleted-элементов
    int h1 = hashFunction1(k, _buffer_size);
    int h2 = hashFunction2(k, _buffer_size);
    int i = 0;
    int first_deleted = -1; // запоминаем первый подходящий (удаленный) элемент
    
    while (_table[h1].second.first != nullptr && i < _buffer_size) {
        if (_table[h1].first == k && _table[h1].second.first) {
            return false;
        } // такой элемент уже есть, а значит его нельзя вставлять повторно
        if (!_table[h1].second.first && first_deleted == -1) { // находим место для нового элемента
            first_deleted = h1;
        }
        h1 = (h1 + h2) % _buffer_size;
        ++i;
    }
//    std::cout << first_deleted;
    if (first_deleted == -1) // если не нашлось подходящего места, создаем новый Node
    {
        _table[h1].first = k;
        _table[h1].second.second = true;
        _table[h1].second.first = new Value(v);
        if (_table[h1].second.first == nullptr) {
            throw Exceptions::NullPointer("null pointer in insert");
        }
        ++_size_all_non_nullptr; // так как мы заполнили один пробел, не забываем записать, что это место теперь занято
        
    } else {
        _table[first_deleted].first = k;
        _table[first_deleted].second.first = new Value(v);
        _table[first_deleted].second.second = true;
    }
    ++_essential_size; // и в любом случае мы увеличили количество элементов
    
    return true;
}

void HashTable::clear() {
    _essential_size = 0;
    _size_all_non_nullptr = 0;
    _buffer_size = 8;
    _table.resize(_buffer_size);
    for (size_t i = 0; i < _buffer_size; ++i) {
        _table[i].second.first = nullptr;
        _table[i].first = "";
    }
}

size_t HashTable::size() const {
    return _essential_size;
}

bool HashTable::empty() const {
    return _essential_size == 0;
}

void HashTable::swap(HashTable &b) {
    _table.swap(b._table);
    std::swap(_essential_size, b._essential_size);
    std::swap(_buffer_size, b._buffer_size);
    std::swap(_size_all_non_nullptr, b._size_all_non_nullptr);
}

Value &HashTable::at(const Key &k) {
    int h1 = hashFunction1(k, _buffer_size); // значение, отвечающее за начальную позицию
    int h2 = hashFunction2(k, _buffer_size); // значение, ответственное за "шаг" по таблице
    int i = 0;
    while (_table[h1].second.first != nullptr && i < _buffer_size) {
        if (_table[h1].first == k && _table[h1].second.first) {
            return *_table[h1].second.first;
        } // такой элемент есть
        h1 = (h1 + h2) % _buffer_size;
        ++i; // если у нас i >=  buffer_size, значит мы уже обошли абсолютно все ячейки, именно для этого мы считаем i, иначе мы могли бы зациклиться.
    }
    throw Exceptions::NoValue("no value in at");
}

const Value &HashTable::at(const Key &k) const {
    int h1 = hashFunction1(k, _buffer_size); // значение, отвечающее за начальную позицию
    int h2 = hashFunction2(k, _buffer_size); // значение, ответственное за "шаг" по таблице
    int i = 0;
    while (_table[h1].second.first != nullptr && i < _buffer_size) {
        if (_table[h1].first == k && _table[h1].second.first) {
            return *_table[h1].second.first;
        } // такой элемент есть
        h1 = (h1 + h2) % _buffer_size;
        ++i; // если у нас i >=  buffer_size, значит мы уже обошли абсолютно все ячейки, именно для этого мы считаем i, иначе мы могли бы зациклиться.
    }
    throw Exceptions::NoValue("no value in const at");
}

bool operator==(const HashTable &a, const HashTable &b) {
    if (a._essential_size != b._essential_size) {
        return false;
    }
    for (size_t i = 0; i < a._buffer_size; ++i) {
        Key aKey = a._table[i].first;
        Value* aValue = a._table[i].second.first;
        if (aValue && a._table[i].second.second) {
            if (!b.contains(aKey) ||
                b.at(aKey)._age != aValue->_age ||
                b.at(aKey)._weight != aValue->_weight) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const HashTable &a, const HashTable &b) {
    return !(a == b);
}

HashTable &HashTable::operator=(const HashTable &b) {
    if (*this == b) {
        return *this;
    }
    for (size_t i = 0; i < _buffer_size; ++i) {
        delete _table[i].second.first;
    }
    _buffer_size = b._buffer_size;
    _essential_size = b._essential_size;
    _size_all_non_nullptr = b._size_all_non_nullptr;
    _table.resize(_buffer_size);
    for (size_t i = 0; i < _buffer_size; ++i) {
        _table[i].first = b._table[i].first;
        _table[i].second.second = b._table[i].second.second;
        if (b._table[i].second.first != nullptr) {
            _table[i].second.first = new Value(b._table[i].second.first->_age, b._table[i].second.first->_weight);
            if (_table[i].second.first == nullptr) {
                throw Exceptions::NullPointer("null pointer in copy assignment");
            }
        } else {
            _table[i].second.first = nullptr;
        }
    }
    return *this;
}

HashTable &HashTable::operator=(HashTable &&b) noexcept {
    if (*this == b) {
        return *this;
    }
    _buffer_size = b._buffer_size;
    b._buffer_size = 0;
    _essential_size = b._essential_size;
    b._essential_size = 0;
    _size_all_non_nullptr = b._size_all_non_nullptr;
    b._size_all_non_nullptr = 0;
    _table.resize(_buffer_size);
    _table = std::move(b._table);
    return *this;
}

Value &HashTable::operator[](const Key &k) {
    int h1 = hashFunction1(k, _buffer_size); // значение, отвечающее за начальную позицию
    int h2 = hashFunction2(k, _buffer_size); // значение, ответственное за "шаг" по таблице
    if (!this->contains(k)) {
        Value v;
        this->insert(k, v);
    }
    while (_table[h1].second.first != nullptr && _table[h1].first != k && _table[h1].second.second) {
        h1 = (h1 + h2) % _buffer_size;
    }
    return *_table[h1].second.first;
}
