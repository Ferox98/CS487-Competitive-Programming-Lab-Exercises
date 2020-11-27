#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    bool is_end_of_word;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = NULL;
        is_end_of_word = false;
    }
};

void insert(TrieNode* root, string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
        int idx = word[i] - 'a';
        if (!node->children[idx]) {
            node->children[idx] = new TrieNode();
        }
        node = node->children[idx];
    }
    cout << "inserted" << endl;
    node->is_end_of_word = true;
}

bool search(TrieNode* root, string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
        int idx = word[i] - 'a';
        if (!node->children[idx]) return false;
        node = node->children[idx];
    }
    return (node != NULL && node->is_end_of_word);
}

int main() {
    TrieNode* root = new TrieNode();
    vector<string> words = {"Anteneh", "Abel", "Faya", "Kaleab"};
    cout << "inserting" << endl;
    for (auto& str : words) insert(root, str);
    bool res = search(root, "Feysel");
    cout << res << endl;
    res = search(root, "Faya");
}