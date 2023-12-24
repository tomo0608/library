#include<array>
#include<vector>
#include<string>
#include<functional>

namespace tomo0608{
    template<int char_size = 26, char base = 'a'>
    struct Trie{
        struct TrieNode{
            std::array<int, char_size> nxt;
            std::vector<int> accept;
            int sz;
            TrieNode(): sz(0){std::fill(std::begin(nxt), std::end(nxt), -1);}
        };
        std::vector<TrieNode> nodes;
        int root;

        Trie(): root(0){nodes.emplace_back(TrieNode());}

        void update_direct(int node, int id){
            nodes[node].accept.emplace_back(id);
        }

        void update_child(int node, int child, int id){
            ++nodes[node].sz;
        }

        void add(const std::string &s, int str_index, int node_index, int id){
            if(str_index == (int)s.size()){
                update_direct(node_index, id);
            }else{
                const int c = s[str_index] - base;
                if(nodes[node_index].nxt[c] == -1){
                    nodes[node_index].nxt[c] = (int)nodes.size();
                    nodes.emplace_back(TrieNode());
                }
                add(s, str_index + 1, nodes[node_index].nxt[c], id);
                update_child(node_index, nodes[node_index].nxt[c], id);
            }
        }

        void add(const std::string &s, int id){
            add(s, 0, 0, id);
        }

        void add(const std::string &s){
            add(s, nodes[0].sz);
        }

        void query(const std::string &s, const std::function<void(int)> &f, int str_index, int node_index){
            for(auto &idx : nodes[node_index].accept)f(idx);
            if(str_index == (int)s.size())return;
            const int c = s[str_index] - base;
            if(nodes[node_index].nxt[c] == -1)return;
            query(s, f, str_index + 1, nodes[node_index].nxt[c]);
        }
        
        void query(const std::string &s, const std::function<void(int)> &f){
            query(s, f, 0, 0);
        }

        int count() const{
            return (nodes[0].sz);
        }

        int size() const{
            return ((int)nodes.size());
        }

    };
}// namespace tomo0608