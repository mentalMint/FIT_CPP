#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include <vector>
#include <memory>

struct Student {
    unsigned _age;
    unsigned _weight;
    Student(const unsigned& age = 0, unsigned weight = 0) : _age(age), _weight(weight) {}
};

typedef std::string Key;
typedef Student Value;
typedef std::vector<std::pair<Key, std::pair<Value*, bool>>> Table;

class HashTable {
public:
    HashTable();
    
    ~HashTable();
    
    HashTable(const HashTable &b);
    
    HashTable(HashTable &&b) noexcept ;
    
    
    HashTable &operator=(const HashTable &b);
    
    HashTable &operator=(HashTable &&b) noexcept ;
    
    
    // Обменивает значения двух хэш-таблиц.
    void swap(HashTable &b);
    
    // Очищает контейнер.
    void clear();
    
    // Удаляет элемент по заданному ключу.
    bool erase(const Key &k);
    
    // Вставка в контейнер. Возвращаемое значение - успешность вставки.
    bool insert(const Key &k, const Value &v);
    
    // Проверка наличия значения по заданному ключу.
    bool contains(const Key &k) const;
    
    // Возвращает значение по ключу. Небезопасный метод.
    // В случае отсутствия ключа в контейнере, следует вставить в контейнер
    // значение, созданное конструктором по умолчанию и вернуть ссылку на него.
    Value &operator[](const Key &k);
    
    // Возвращает значение по ключу. Бросает исключение при неудаче.
    Value &at(const Key &k);
    
    const Value &at(const Key &k) const;
    
    size_t size() const;
    
    bool empty() const;
    
    friend bool operator==(const HashTable &a, const HashTable &b);
    
    friend bool operator!=(const HashTable &a, const HashTable &b);
    
private:
    int _initial_size = 8;
    const double _rehash_size = 0.75;
//    std::vector<std::pair<Key, Value*>> _table;
    Table _table;
    
    int _essential_size; // сколько элементов у нас сейчас в массиве (без учета deleted)
    int _buffer_size; // размер самого массива, сколько памяти выделено под хранение нашей таблицы
    int _size_all_non_nullptr; // сколько элементов у нас сейчас в массиве (с учетом deleted)

    
    int hashFunction(const Key &key, int table_size, const int multiplier) const;
    
    int hashFunction1(const Key &key, int table_size) const;
    
    int hashFunction2(const Key &key, int table_size) const;
    
    void resize();
    
    void rehash();

};

bool operator==(const HashTable &a, const HashTable &b);

bool operator!=(const HashTable &a, const HashTable &b);


#endif //HASHTABLE_HASHTABLE_H
