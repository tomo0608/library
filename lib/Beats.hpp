#pragma once

#include "Lazy_Segment_Tree.hpp"

namespace tomo0608 {
    // Sにはメンバ変数failが必要

    template<class S,
        S(*op)(S, S),
        S(*e)(),
        class F,
        S(*mapping)(F, S),
        F(*composition)(F, F),
        F(*id)()>
    class Beats : public Lazy_Segment_Tree<S, op, e, F, mapping, composition, id> {
        using base = Lazy_Segment_Tree<S, op, e, F, mapping, composition, id>;
        using base::Lazy_Segment_Tree;
        void all_apply(int k, F f)const override {
            base::d[k] = mapping(f, base::d[k]);
            if (k < base::size) {
                base::lz[k] = composition(f, base::lz[k]);
                if (base::d[k].fail) base::push(k), base::update(k);
            }
        }
    };
} // namespace tomo0608