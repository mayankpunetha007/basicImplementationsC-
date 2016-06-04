#include <iostream>
#include <map>
#include <string>
#include <stack>

struct trie_node_t {
    typedef std::map<char, trie_node_t *> child_node_t;
    child_node_t m_childMap;
    trie_node_t() :m_childMap(std::map<char, trie_node_t*>()) {}

    void insert( std::string& word ) {
        trie_node_t *pNode = this;
        for ( std::string::const_iterator itr = word.begin(); itr != word.end(); ++itr) {
            char letter = *itr;
            if ( pNode->m_childMap.find(letter) == pNode->m_childMap.end()){
                pNode->m_childMap[letter] = new trie_node_t();
            }
            pNode = pNode->m_childMap[letter];
        }
    }

    void print() {
    }
};

int main () {
    trie_node_t trie;
    trie.insert(std::string("aab"));
    trie.print();
}
