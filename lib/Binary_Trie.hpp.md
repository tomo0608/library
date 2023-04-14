---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Binary_Trie.hpp\"\n#include<assert.h>\n\nnamespace tomo0608\
    \ {\n    template<typename U = unsigned, int B = 32>\n    class binary_trie {\n\
    \        struct node {\n            int cnt; // \u90E8\u5206\u6728\u306E\u8981\
    \u7D20\u6570\n            node* ch[2]; // \u5DE6\u53F3\u306E\u5B50\u306E\u30DD\
    \u30A4\u30F3\u30BF\n            node(): cnt(0), ch{ nullptr, nullptr } {}\n  \
    \      };\n        node* add(node* t, U val, int b = B - 1) {\n            if\
    \ (!t)t = new node;\n            t->cnt += 1;\n            if (b < 0)return t;\n\
    \            bool f = (val >> (U)b) & (U)1;\n            t->ch[f] = add(t->ch[f],\
    \ val, b - 1);\n            return t;\n        }\n        node* sub(node* t, U\
    \ val, int b = B - 1) {\n            assert(t);\n            t->cnt -= 1;\n  \
    \          if (t->cnt == 0)return nullptr;\n            if (b < 0)return t;\n\
    \            bool f = (val >> (U)b) & (U)1;\n            t->ch[f] = sub(t->ch[f],\
    \ val, b - 1);\n            return t;\n        }\n        U get_min(node* t, U\
    \ val, int b = B - 1)const {\n            assert(t);\n            if (b < 0)return\
    \ 0;\n            bool f = (val >> (U)b) & (U)1;\n            f ^= !t->ch[f];\n\
    \            return get_min(t->ch[f], val, b - 1) | ((U)f << (U)b);\n        }\n\
    \        U get(node* t, int k, int b = B - 1)const {\n            if (b < 0)return\
    \ 0;\n            int m = t->ch[0] ? t->ch[0]->cnt : 0;\n            return k\
    \ < m ? get(t->ch[0], k, b - 1) : get(t->ch[1], k - m, b - 1) | ((U)1 << (U)b);\n\
    \        }\n        int count_lower(node* t, U val, int b = B - 1) {\n       \
    \     if (!t || b < 0)return 0;\n            bool f = (val >> (U)b) & (U)1;\n\
    \            return (f && t->ch[0] ? t->ch[0]->cnt : 0) + count_lower(t->ch[f],\
    \ val, b - 1);\n        }\n        node* root;\n    public:\n        binary_trie():\
    \ root(nullptr) {}\n        int size()const {\n            return root ? root->cnt\
    \ : 0;\n        }\n        bool empty() const {\n            return !root;\n \
    \       }\n        void insert(U val) {\n            root = add(root, val);\n\
    \        }\n        void erase(U val) {\n            root = sub(root, val);\n\
    \        }\n        U max_element(U bias = 0)const { // a[i] ^ bias \u304C\u6700\
    \u5927\u3068\u306A\u308B a[i]\u3092\u8FD4\u3059\n            return get_min(root,\
    \ ~bias);\n        }\n        U min_element(U bias = 0)const { // a[i] ^ bias\
    \ \u304C\u6700\u5C0F\u3068\u306A\u308B a[i]\u3092\u8FD4\u3059\n            return\
    \ get_min(root, bias);\n        }\n        int lower_bound(U val) { // return\
    \ id\n            return count_lower(root, val);\n        }\n        int upper_bound(U\
    \ val) { // return id\n            return count_lower(root, val + 1);\n      \
    \  }\n        U operator[](int k)const {\n            assert(0 <= k && k < size());\n\
    \            return get(root, k);\n        }\n        int count(U val)const {\n\
    \            if (!root)return 0;\n            node* t = root;\n            for\
    \ (int i = B - 1; i >= 0; i--) {\n                t = t->ch[(val >> (U)i) & (U)1];\n\
    \                if (!t)return 0;\n            }\n            return t->cnt;\n\
    \        }\n    };\n} // namespace tomo0608\n"
  code: "#include<assert.h>\n\nnamespace tomo0608 {\n    template<typename U = unsigned,\
    \ int B = 32>\n    class binary_trie {\n        struct node {\n            int\
    \ cnt; // \u90E8\u5206\u6728\u306E\u8981\u7D20\u6570\n            node* ch[2];\
    \ // \u5DE6\u53F3\u306E\u5B50\u306E\u30DD\u30A4\u30F3\u30BF\n            node():\
    \ cnt(0), ch{ nullptr, nullptr } {}\n        };\n        node* add(node* t, U\
    \ val, int b = B - 1) {\n            if (!t)t = new node;\n            t->cnt\
    \ += 1;\n            if (b < 0)return t;\n            bool f = (val >> (U)b) &\
    \ (U)1;\n            t->ch[f] = add(t->ch[f], val, b - 1);\n            return\
    \ t;\n        }\n        node* sub(node* t, U val, int b = B - 1) {\n        \
    \    assert(t);\n            t->cnt -= 1;\n            if (t->cnt == 0)return\
    \ nullptr;\n            if (b < 0)return t;\n            bool f = (val >> (U)b)\
    \ & (U)1;\n            t->ch[f] = sub(t->ch[f], val, b - 1);\n            return\
    \ t;\n        }\n        U get_min(node* t, U val, int b = B - 1)const {\n   \
    \         assert(t);\n            if (b < 0)return 0;\n            bool f = (val\
    \ >> (U)b) & (U)1;\n            f ^= !t->ch[f];\n            return get_min(t->ch[f],\
    \ val, b - 1) | ((U)f << (U)b);\n        }\n        U get(node* t, int k, int\
    \ b = B - 1)const {\n            if (b < 0)return 0;\n            int m = t->ch[0]\
    \ ? t->ch[0]->cnt : 0;\n            return k < m ? get(t->ch[0], k, b - 1) : get(t->ch[1],\
    \ k - m, b - 1) | ((U)1 << (U)b);\n        }\n        int count_lower(node* t,\
    \ U val, int b = B - 1) {\n            if (!t || b < 0)return 0;\n           \
    \ bool f = (val >> (U)b) & (U)1;\n            return (f && t->ch[0] ? t->ch[0]->cnt\
    \ : 0) + count_lower(t->ch[f], val, b - 1);\n        }\n        node* root;\n\
    \    public:\n        binary_trie(): root(nullptr) {}\n        int size()const\
    \ {\n            return root ? root->cnt : 0;\n        }\n        bool empty()\
    \ const {\n            return !root;\n        }\n        void insert(U val) {\n\
    \            root = add(root, val);\n        }\n        void erase(U val) {\n\
    \            root = sub(root, val);\n        }\n        U max_element(U bias =\
    \ 0)const { // a[i] ^ bias \u304C\u6700\u5927\u3068\u306A\u308B a[i]\u3092\u8FD4\
    \u3059\n            return get_min(root, ~bias);\n        }\n        U min_element(U\
    \ bias = 0)const { // a[i] ^ bias \u304C\u6700\u5C0F\u3068\u306A\u308B a[i]\u3092\
    \u8FD4\u3059\n            return get_min(root, bias);\n        }\n        int\
    \ lower_bound(U val) { // return id\n            return count_lower(root, val);\n\
    \        }\n        int upper_bound(U val) { // return id\n            return\
    \ count_lower(root, val + 1);\n        }\n        U operator[](int k)const {\n\
    \            assert(0 <= k && k < size());\n            return get(root, k);\n\
    \        }\n        int count(U val)const {\n            if (!root)return 0;\n\
    \            node* t = root;\n            for (int i = B - 1; i >= 0; i--) {\n\
    \                t = t->ch[(val >> (U)i) & (U)1];\n                if (!t)return\
    \ 0;\n            }\n            return t->cnt;\n        }\n    };\n} // namespace\
    \ tomo0608"
  dependsOn: []
  isVerificationFile: false
  path: lib/Binary_Trie.hpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Binary_Trie.hpp
layout: document
redirect_from:
- /library/lib/Binary_Trie.hpp
- /library/lib/Binary_Trie.hpp.html
title: lib/Binary_Trie.hpp
---
