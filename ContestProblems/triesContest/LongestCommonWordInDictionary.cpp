class Trie {
public:
    Trie* prefix[26];
    bool isEnd;

    Trie() {
        for (int i = 0; i < 26; i++) {
            prefix[i] = nullptr;
        }
        isEnd = false;
    }
};

class Solution {
public:
    void insertWord(Trie* root, const string& word) {
        Trie* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->prefix[index] == NULL) {
                node->prefix[index] = new Trie();
            }
            node = node->prefix[index];
        }
        node->isEnd = true;
    }

    string DFS(Trie* node, string currWord) {
        string longest = currWord;
        for (int i = 0; i < 26; i++) {
            if (node->prefix[i] && node->prefix[i]->isEnd) {
                string nextWord = currWord + char('a' + i);
                string candidate = DFS(node->prefix[i], nextWord);
                if (candidate.size() > longest.size() || (candidate.size() == longest.size() && candidate < longest)) {
                    longest = candidate;
                }
            }
        }
        return longest;
    }

    string longestWord(vector<string>& words) {
        Trie* root = new Trie();
        for (const string& word : words) {
            insertWord(root, word);
        }
        return DFS(root, "");
    }
};
