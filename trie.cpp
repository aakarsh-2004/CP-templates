class TrieNode {
public:
    int strings_ending_here;
    int strings_going_below;
    
    TrieNode* children[26];
    TrieNode() {
        strings_ending_here = 0;
        strings_going_below = 0;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* curr = root;

        for(auto ch: word) {
            if(curr -> children[ch - 'a'] == nullptr) {
                curr -> children[ch - 'a'] = new TrieNode();
            }
            curr = curr -> children[ch - 'a'];
            curr -> strings_going_below++;
        }
        curr -> strings_ending_here++;
    }

    int countWordsEqualTo(const string& word) {
        TrieNode* curr = root;

        for(auto ch: word) {
            if(curr -> children[ch - 'a'] == nullptr) {
                return 0;
            }
            curr = curr -> children[ch - 'a'];
        }
        return curr -> strings_ending_here;
    }

    int countWordsStartingWith(const& string word) {
        TrieNode* curr = root;

        for(auto ch: word) {
            if(curr -> children[ch - 'a'] == nullptr) {
                return 0;
            }
            curr = curr -> children[ch - 'a'];
        }
        return curr -> strings_going_below;
    }
};