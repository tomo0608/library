---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"z_algorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#include <bits/stdc++.h>\n\ntemplate <class T> std::vector<int> z_algorithm(std::vector<T>\
    \ S) {\n    size_t n = S.size();\n    std::vector<int> Z(n);\n    Z[0] = n;\n\
    \    int i = 1, j = 0;\n    while (i < n) {\n        while (i + j < n && S[j]\
    \ == S[i + j])\n            j++;\n        Z[i] = j;\n\n        if (!j) {\n   \
    \         i++;\n            continue;\n        }\n        int k = 1;\n       \
    \ while (k < j && k + Z[k] < j) {\n            Z[i + k] = Z[k];\n            k++;\n\
    \        }\n        i += k;\n        j -= k;\n    }\n    return Z;\n};\n\nstd::vector<int>\
    \ z_algorithm(std::string S) {\n    size_t n = S.size();\n    std::vector<int>\
    \ Z(n);\n    Z[0] = n;\n    int i = 1, j = 0;\n    while (i < n) {\n        while\
    \ (i + j < n && S[j] == S[i + j])\n            j++;\n        Z[i] = j;\n\n   \
    \     if (!j) {\n            i++;\n            continue;\n        }\n        int\
    \ k = 1;\n        while (k < j && k + Z[k] < j) {\n            Z[i + k] = Z[k];\n\
    \            k++;\n        }\n        i += k;\n        j -= k;\n    }\n    return\
    \ Z;\n};\n\nusing namespace std;\nint main() {\n    string s;cin >> s;\n    vector<int>\
    \ a = z_algorithm(s);\n    for (int i = 0; i < a.size() - 1; i++)cout << a[i]\
    \ << ' ';\n    cout << a.back() << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <bits/stdc++.h>\n\ntemplate <class T> std::vector<int> z_algorithm(std::vector<T>\
    \ S) {\n    size_t n = S.size();\n    std::vector<int> Z(n);\n    Z[0] = n;\n\
    \    int i = 1, j = 0;\n    while (i < n) {\n        while (i + j < n && S[j]\
    \ == S[i + j])\n            j++;\n        Z[i] = j;\n\n        if (!j) {\n   \
    \         i++;\n            continue;\n        }\n        int k = 1;\n       \
    \ while (k < j && k + Z[k] < j) {\n            Z[i + k] = Z[k];\n            k++;\n\
    \        }\n        i += k;\n        j -= k;\n    }\n    return Z;\n};\n\nstd::vector<int>\
    \ z_algorithm(std::string S) {\n    size_t n = S.size();\n    std::vector<int>\
    \ Z(n);\n    Z[0] = n;\n    int i = 1, j = 0;\n    while (i < n) {\n        while\
    \ (i + j < n && S[j] == S[i + j])\n            j++;\n        Z[i] = j;\n\n   \
    \     if (!j) {\n            i++;\n            continue;\n        }\n        int\
    \ k = 1;\n        while (k < j && k + Z[k] < j) {\n            Z[i + k] = Z[k];\n\
    \            k++;\n        }\n        i += k;\n        j -= k;\n    }\n    return\
    \ Z;\n};\n\nusing namespace std;\nint main() {\n    string s;cin >> s;\n    vector<int>\
    \ a = z_algorithm(s);\n    for (int i = 0; i < a.size() - 1; i++)cout << a[i]\
    \ << ' ';\n    cout << a.back() << endl;\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-01-02 11:31:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/z_algorithm.test.cpp
- /verify/z_algorithm.test.cpp.html
title: z_algorithm.test.cpp
---
