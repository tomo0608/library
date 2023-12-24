#pragma once
#include<vector>
#include<assert.h>

namespace tomo0608 {
    template<class Monoid, Monoid(*op)(Monoid, Monoid), Monoid(*e)()> struct segment_tree_2d {
        int _H, _W, size_H, size_W, size, log_H, log_W;
        std::vector<Monoid> d;
        int id(int h, int w) const { return h * 2 * size_W + w; }
        segment_tree_2d() : segment_tree_2d(0) {}
        explicit segment_tree_2d(int h, int w) : segment_tree_2d(std::vector<std::vector<Monoid>>(h, std::vector<Monoid>(w, e()))) {}
        explicit segment_tree_2d(std::vector<std::vector<Monoid>> a) : _H((int)a.size()), _W((int)a[0].size()) {
            log_H = 0;
            while ((1U << log_H) < (unsigned int)(_H)) log_H++;
            log_W = 0;
            while ((1U << log_W) < (unsigned int)(_W)) log_W++;
            size_H = 1 << log_H;
            size_W = 1 << log_W;
            d = std::vector<Monoid>(size_H * size_W * 4, e());
            for (int h = 0; h < _H; h++)for (int w = 0; w < _W; w++)d[id(size_H + h, size_W + w)] = a[h][w];
            for (int w = size_W; w < 2 * size_W; w++)for (int h = size_H - 1; h >= 1; h--)d[id(h, w)] = op(d[id(2 * h, w)], d[id(2 * h + 1, w)]);
            for (int h = 0; h < 2 * size_H; h++)for (int w = size_W - 1; w >= 1; w--)d[id(h, w)] = op(d[id(h, 2 * w)], d[id(h, 2 * w + 1)]);
        }

        void update(int h, int w, const Monoid& x) {
            assert(0 <= h && h < _H && 0 <= w && w < _W);
            h += size_H;
            w += size_W;
            d[id(h, w)] = x;
            for (int i = h >> 1; i; i >>= 1) {
                d[id(i, w)] = op(d[id(2 * i + 0, w)], d[id(2 * i + 1, w)]);
            }
            for (; h; h >>= 1) {
                for (int j = w >> 1; j; j >>= 1) {
                    d[id(h, j)] = op(d[id(h, 2 * j + 0)], d[id(h, 2 * j + 1)]);
                }
            }
        }

        Monoid get(int h, int w)const {
            assert(0 <= h && h < _H && 0 <= w && w < _W);
            return d[id(h + size_H, w + size_W)];
        }

        Monoid inner_prod(int h, int w_l, int w_r) const {
            Monoid sml = e(), smr = e();

            while (w_l < w_r) {
                if (w_l & 1)sml = op(sml, d[id(h, w_l++)]);
                if (w_r & 1)smr = op(d[id(h, --w_r)], smr);
                w_l >>= 1;
                w_r >>= 1;
            }
            return op(sml, smr);
        }

        Monoid prod(int h_l, int h_r, int w_l, int w_r) const {
            assert(0 <= h_l && h_l <= h_r && h_r <= _H);
            assert(0 <= w_l && w_l <= w_r && w_r <= _W);
            Monoid sml = e(), smr = e();
            h_l += size_H;
            h_r += size_H;
            w_l += size_W;
            w_r += size_W;

            while (h_l < h_r) {
                if (h_l & 1) sml = op(sml, inner_prod(h_l++, w_l, w_r));
                if (h_r & 1) smr = op(inner_prod(--h_r, w_l, w_r), smr);
                h_l >>= 1;
                h_r >>= 1;
            }
            return op(sml, smr);
        }
    };
} // namespace tomo0608