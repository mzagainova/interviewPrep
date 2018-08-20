template <typename K, typename V>
class HashNode {
public:
  HashNode(const K &key, const V &value):
  _key(key), _value(value), _next(NULL) {
  }

  K getKey() const{
    return _key;
  }

  V getValue() const{
    return _value;
  }

  void setValue(V value) {
    HashNode::_value = value;
  }

  HashNode *getNext() const{
    return _next;
  }

  HashNode *setNext(HashNode *next) {
    HashNode::_next = next;
  }

private:
  K _key;
  V _value;
  HashNode *_next;
  // copy and assignment not allowed
  HashNode(const HashNode &);
  HashNode & operator=(const HashNode &);
}
