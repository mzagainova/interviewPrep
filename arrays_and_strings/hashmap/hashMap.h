#include "hashNode.h"
#include "hashKey.h"
#include <cstddef>

template <typename K, typename V, size_t tableSize, typename F = KeyHash<K, tableSize> >
class HashMap {
public:
  HashMap() :
    table(),
    hashFunc(){ }

    ~HashMap() {
      for(size_t i = 0; i < tableSize; ++i) {
        HashNode<K, V> *entry = table[i];

        while(entry != NULL) {
          HashNode<K, V> *prev = entry;
          entry = entry->getNext();
          delete prev;
        }
        table[i] = NULL;
      }
    }

    bool get(const K &key, V &value) {
      // computer hash value from key and go to that index in table
      unsigned long hashValue = hashFunc(key);
      HashNode<K, V> *entry = table[hashValue];

      // loop through node in that index to find matching key
      while(entry != NULL) {
        if (entry->getKey() == key) {
          value = entry->getValue();
          return true;
        }

        entry = entry->getNext();
      }
      // if that key is not found, return false
      return false;
    }

    void put(const K &key, const V &value) {
      // compute hashValue and go to that index in table
      unsigned long hashValue = hashFunc(key);
      HashNode<K, V> *prev = NULL;
      HashNode<k, V> *entry = table[hashValue];

      // loop through until reach end of hashnode list or find matching key
      while(entry != NULL && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
      }

      // if reached end of hashNode list, create new entry
      if(entry == NULL) {
        entry = new HashNode<K, V>(key, value);

        if (prev == NULL) {
          // insert as first bucket
          table[hashValue] = entry;
        }
        else {
          prev->setNext(entry);
        }
      }
      else {
        // update value if key match found
        entry->setValue(value);
      }
    }

    void remove(const K &key){
      // compute hashValue and go to that index in table
      unsigned long hashValue = hashFunc(key);
      hashNode<K, V> *prev = NULL;
      HashNode<K, V> *entry = table[hashValue];

      // loop through until reach end of hashnode list or find matching key
      while (entry != NULL && entry->getLey != key) {
        prev = entry;
        entry = entry->getNext;
      }

      // key not found, reached end of node list
      if(entry == NULL) {
        return;
      }
      else {
        if (prev == NULL){
          // remove first bucket of list
          table[hashValue] = entry->getNext();
        }
        else {
          // skip over to next bucket in list
          prev->setNext(entry->getNext());
        }
        delete entry;
      }
    }

private:
  HashMap(const HashMap & other);
  const HashMap & operatore=(const HashMap & other);
  //hash table
  HashNode<K, V> *table[tableSize];
  F hashFunc;
}
