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
  bundledCode: "#line 1 \"lib/RangeSet.hpp\"\n#include<set>\n#include<vector>\n#include<limits>\n\
    \nnamespace tomo0608 {\n\n    template<class T = long long>\n    struct RangeSet\
    \ {\n    public:\n        const T inf = std::numeric_limits<T>::max() / 2;\n \
    \       std::set<std::pair<T, T>> st;\n\n        RangeSet() {\n            st.emplace(-inf\
    \ - 1, -inf);\n            st.emplace(inf, inf + 1);\n        }\n\n        int\
    \ size() const { return st.size() - 2; }\n\n        std::vector<std::pair<T, T>>\
    \ get_all_sections() const {\n            auto l = std::next(st.begin()), r =\
    \ std::prev(st.end());\n            std::vector<std::pair<T, T>> ret;\n      \
    \      while (l != r) {\n                ret.emplace_back(*l);\n             \
    \   l = std::next(l);\n            }\n            return ret;\n        }\n\n \
    \       bool is_covered(const T l, const T r) const {\n            auto it = std::prev(st.upper_bound({\
    \ l, inf }));\n            return (it->first <= l && r <= it->second);\n     \
    \   }\n\n        bool is_covered(const T x) const { return is_covered(x, x + 1);\
    \ }\n\n        std::pair<T, T> is_covered_by(const T l, const T r) const {\n \
    \           auto it = std::prev(st.upper_bound({ l, inf }));\n            if (it->first\
    \ <= l && r <= it->second)return *it;\n            return { -inf, -inf };\n  \
    \      }\n\n        std::pair<T, T> is_covered_by(const T x) const { return is_covered_by(x,\
    \ x + 1); }\n\n        T insert_section(T l, T r) {\n            auto it = std::prev(st.upper_bound({\
    \ l, -inf }));\n            T len = 0;\n            if (it->first <= l && r <=\
    \ it->second)return len;\n\n            T nxtleft = l;\n            if (it->first\
    \ <= l && l <= it->second) {\n                l = it->first;\n               \
    \ nxtleft = it->second;\n                it = st.erase(it);\n            }\n \
    \           else {\n                it = next(it);\n            }\n\n        \
    \    while (r > it->second) {\n                len += it->first - nxtleft;\n \
    \               nxtleft = it->second;\n                it = st.erase(it);\n  \
    \          }\n\n            if (it->first <= r) {\n                len += it->first\
    \ - nxtleft;\n                r = it->second;\n                st.erase(it);\n\
    \            }\n            else {\n                len += r - nxtleft;\n    \
    \        }\n            st.emplace(l, r);\n            return len;\n        }\n\
    \n        T insert(T x) { return insert_section(x, x + 1); }\n\n        T insert_length(T\
    \ l, T d) {\n            auto it = std::prev(st.upper_bound({ l, -inf }));\n\n\
    \            T nxtleft = l;\n            if (it->first <= l and l <= it->second)\
    \ {\n                l = it->first;\n                nxtleft = it->second;\n \
    \               it = st.erase(it);\n            }\n            else {\n      \
    \          it = std::next(it);\n            }\n\n            T r = l, lastr =\
    \ l;\n            while (d >= it->first - nxtleft) {\n                d -= it->first\
    \ - nxtleft;\n                lastr = it->first;\n                nxtleft = it->second;\n\
    \                it = st.erase(it);\n            }\n            r = nxtleft +\
    \ d;\n            if (d > 0) lastr = nxtleft + d;\n\n            st.emplace(l,\
    \ r);\n            return lastr;\n        }\n\n        T erase_section(const T\
    \ l, const T r) {\n            auto it = std::prev(st.upper_bound({ l, -inf }));\n\
    \n            if (it->first <= l && r <= it->second) {\n                if (it->first\
    \ < l)st.emplace(it->first, l);\n                if (r < it->second)st.emplace(r,\
    \ it->second);\n                st.erase(it);\n                return r - l;\n\
    \            }\n\n            T len = 0;\n\n            if (it->first <= l &&\
    \ l < it->second) {\n                len += it->second - l;\n                if\
    \ (it->first < l)st.emplace(it->first, l);\n                it = st.erase(it);\n\
    \            }\n            else {\n                it = std::next(it);\n    \
    \        }\n\n            while (it->second <= r) {\n                len += it->second\
    \ - it->first;\n                it = st.erase(it);\n            }\n          \
    \  if (it->first < r) {\n                len += r - it->first;\n             \
    \   st.emplace(r, it->second);\n                st.erase(it);\n            }\n\
    \            return len;\n        }\n\n        T erase(const T x) { return erase_section(x,\
    \ x + 1); }\n\n        T mex(const T x = 0) const {\n            auto it = std::prev(st.upper_bound({\
    \ x, -inf }));\n            if (it->first <= x && x < it->second)return it->second;\n\
    \            return x;\n        }\n\n        T sum(T l = -std::numeric_limits<T>::max()\
    \ / 2, T r = std::numeric_limits<T>::max() / 2) {\n            auto it = std::prev(st.upper_bound({\
    \ l, -inf }));\n            if (it->first <= l && r <= it->second)return r - l;\n\
    \n            T len = 0;\n            if (it->first <= l && l < it->second)len\
    \ += it->second - l;\n            it = std::next(it);\n            while (it->second\
    \ <= r) {\n                len += it->second - it->first;\n                it\
    \ = std::next(it);\n            }\n            if (it->first < r)len += r - it->first;\n\
    \            return len;\n        }\n    };\n}\n"
  code: "#include<set>\n#include<vector>\n#include<limits>\n\nnamespace tomo0608 {\n\
    \n    template<class T = long long>\n    struct RangeSet {\n    public:\n    \
    \    const T inf = std::numeric_limits<T>::max() / 2;\n        std::set<std::pair<T,\
    \ T>> st;\n\n        RangeSet() {\n            st.emplace(-inf - 1, -inf);\n \
    \           st.emplace(inf, inf + 1);\n        }\n\n        int size() const {\
    \ return st.size() - 2; }\n\n        std::vector<std::pair<T, T>> get_all_sections()\
    \ const {\n            auto l = std::next(st.begin()), r = std::prev(st.end());\n\
    \            std::vector<std::pair<T, T>> ret;\n            while (l != r) {\n\
    \                ret.emplace_back(*l);\n                l = std::next(l);\n  \
    \          }\n            return ret;\n        }\n\n        bool is_covered(const\
    \ T l, const T r) const {\n            auto it = std::prev(st.upper_bound({ l,\
    \ inf }));\n            return (it->first <= l && r <= it->second);\n        }\n\
    \n        bool is_covered(const T x) const { return is_covered(x, x + 1); }\n\n\
    \        std::pair<T, T> is_covered_by(const T l, const T r) const {\n       \
    \     auto it = std::prev(st.upper_bound({ l, inf }));\n            if (it->first\
    \ <= l && r <= it->second)return *it;\n            return { -inf, -inf };\n  \
    \      }\n\n        std::pair<T, T> is_covered_by(const T x) const { return is_covered_by(x,\
    \ x + 1); }\n\n        T insert_section(T l, T r) {\n            auto it = std::prev(st.upper_bound({\
    \ l, -inf }));\n            T len = 0;\n            if (it->first <= l && r <=\
    \ it->second)return len;\n\n            T nxtleft = l;\n            if (it->first\
    \ <= l && l <= it->second) {\n                l = it->first;\n               \
    \ nxtleft = it->second;\n                it = st.erase(it);\n            }\n \
    \           else {\n                it = next(it);\n            }\n\n        \
    \    while (r > it->second) {\n                len += it->first - nxtleft;\n \
    \               nxtleft = it->second;\n                it = st.erase(it);\n  \
    \          }\n\n            if (it->first <= r) {\n                len += it->first\
    \ - nxtleft;\n                r = it->second;\n                st.erase(it);\n\
    \            }\n            else {\n                len += r - nxtleft;\n    \
    \        }\n            st.emplace(l, r);\n            return len;\n        }\n\
    \n        T insert(T x) { return insert_section(x, x + 1); }\n\n        T insert_length(T\
    \ l, T d) {\n            auto it = std::prev(st.upper_bound({ l, -inf }));\n\n\
    \            T nxtleft = l;\n            if (it->first <= l and l <= it->second)\
    \ {\n                l = it->first;\n                nxtleft = it->second;\n \
    \               it = st.erase(it);\n            }\n            else {\n      \
    \          it = std::next(it);\n            }\n\n            T r = l, lastr =\
    \ l;\n            while (d >= it->first - nxtleft) {\n                d -= it->first\
    \ - nxtleft;\n                lastr = it->first;\n                nxtleft = it->second;\n\
    \                it = st.erase(it);\n            }\n            r = nxtleft +\
    \ d;\n            if (d > 0) lastr = nxtleft + d;\n\n            st.emplace(l,\
    \ r);\n            return lastr;\n        }\n\n        T erase_section(const T\
    \ l, const T r) {\n            auto it = std::prev(st.upper_bound({ l, -inf }));\n\
    \n            if (it->first <= l && r <= it->second) {\n                if (it->first\
    \ < l)st.emplace(it->first, l);\n                if (r < it->second)st.emplace(r,\
    \ it->second);\n                st.erase(it);\n                return r - l;\n\
    \            }\n\n            T len = 0;\n\n            if (it->first <= l &&\
    \ l < it->second) {\n                len += it->second - l;\n                if\
    \ (it->first < l)st.emplace(it->first, l);\n                it = st.erase(it);\n\
    \            }\n            else {\n                it = std::next(it);\n    \
    \        }\n\n            while (it->second <= r) {\n                len += it->second\
    \ - it->first;\n                it = st.erase(it);\n            }\n          \
    \  if (it->first < r) {\n                len += r - it->first;\n             \
    \   st.emplace(r, it->second);\n                st.erase(it);\n            }\n\
    \            return len;\n        }\n\n        T erase(const T x) { return erase_section(x,\
    \ x + 1); }\n\n        T mex(const T x = 0) const {\n            auto it = std::prev(st.upper_bound({\
    \ x, -inf }));\n            if (it->first <= x && x < it->second)return it->second;\n\
    \            return x;\n        }\n\n        T sum(T l = -std::numeric_limits<T>::max()\
    \ / 2, T r = std::numeric_limits<T>::max() / 2) {\n            auto it = std::prev(st.upper_bound({\
    \ l, -inf }));\n            if (it->first <= l && r <= it->second)return r - l;\n\
    \n            T len = 0;\n            if (it->first <= l && l < it->second)len\
    \ += it->second - l;\n            it = std::next(it);\n            while (it->second\
    \ <= r) {\n                len += it->second - it->first;\n                it\
    \ = std::next(it);\n            }\n            if (it->first < r)len += r - it->first;\n\
    \            return len;\n        }\n    };\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/RangeSet.hpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/RangeSet.hpp
layout: document
redirect_from:
- /library/lib/RangeSet.hpp
- /library/lib/RangeSet.hpp.html
title: lib/RangeSet.hpp
---
