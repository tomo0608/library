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
  bundledCode: "#line 1 \"lib/Formal_Power_Series.hpp\"\n#include <vector>\n#include<atcoder/modint>\n\
    #include <atcoder/convolution>\n\nnamespace tomo0608 {\n    template<typename\
    \ mint>\n    struct formal_power_series : std::vector<mint> {\n        using std::vector<mint>::vector;\n\
    \        using FPS = formal_power_series;\n\n        FPS operator-() const {\n\
    \            FPS res(*this);\n            for (auto& e : res) e = -e;\n      \
    \      return res;\n        }\n        FPS& operator*=(const mint& c) {\n    \
    \        for (auto& e : *this)e *= c;\n            return *this;\n        }\n\
    \        FPS& operator/=(const mint& c) {\n            for (auto& e : *this)e\
    \ /= c;\n            return *this;\n        }\n    };\n} // namespace tomo0608\n"
  code: "#include <vector>\n#include<atcoder/modint>\n#include <atcoder/convolution>\n\
    \nnamespace tomo0608 {\n    template<typename mint>\n    struct formal_power_series\
    \ : std::vector<mint> {\n        using std::vector<mint>::vector;\n        using\
    \ FPS = formal_power_series;\n\n        FPS operator-() const {\n            FPS\
    \ res(*this);\n            for (auto& e : res) e = -e;\n            return res;\n\
    \        }\n        FPS& operator*=(const mint& c) {\n            for (auto& e\
    \ : *this)e *= c;\n            return *this;\n        }\n        FPS& operator/=(const\
    \ mint& c) {\n            for (auto& e : *this)e /= c;\n            return *this;\n\
    \        }\n    };\n} // namespace tomo0608"
  dependsOn: []
  isVerificationFile: false
  path: lib/Formal_Power_Series.hpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Formal_Power_Series.hpp
layout: document
redirect_from:
- /library/lib/Formal_Power_Series.hpp
- /library/lib/Formal_Power_Series.hpp.html
title: lib/Formal_Power_Series.hpp
---
