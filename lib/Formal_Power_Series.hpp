#include <vector>
#include<atcoder/modint>
#include <atcoder/convolution>

namespace tomo0608 {
    template<typename mint>
    struct formal_power_series : std::vector<mint> {
        using std::vector<mint>::vector;
        using FPS = formal_power_series;

        FPS operator-() const {
            FPS res(*this);
            for (auto& e : res) e = -e;
            return res;
        }
        FPS& operator*=(const mint& c) {
            for (auto& e : *this)e *= c;
            return *this;
        }
        FPS& operator/=(const mint& c) {
            for (auto& e : *this)e /= c;
            return *this;
        }
    };
} // namespace tomo0608