#include <cstdio>
#include <string>
#include <iostream>
//#include <unordered_map>
//#include <vector>
using namespace std;

struct TrieNode{
	//char val;
	//long count;
	//bool used;
	bool hasChild[26];
	TrieNode* children[26];
	//unordered_map<char, TrieNode*> children;
	TrieNode() {
		memset(hasChild, false, sizeof hasChild);
	};	
};

class Trie {
private:
	TrieNode *root;
public:
	long len;
	Trie() {
		root = new TrieNode();
		len = 0;
		//root->count = 1;
	}

	~Trie() {
		len = 0;
		Trie_deconst_util(root);
	}

	void Trie_deconst_util(TrieNode *root) {
		if (!root)
			return;
		int i;
		for (i = 0; i < 26; i++) {
			if (root->hasChild[i]) {
				Trie_deconst_util(root->children[i]);
			}
		}
		// for (auto &x : root->children) {
		// 	if (hasChild[x - root->children.begin()])
		// 	//Trie_deconst_util(x.second);
		// 		Trie_deconst_util(x);
		// 	//root->children.erase(x.first);
		// }

		delete root;
	}

	void insertTrie(string word) {
		//string substr;
		TrieNode *node = root;
		long r = 0;
		bool create = false;
		//bool IdontWantToUseFlag = false;
		for (auto x : word) {
			//node->count++;
			int idx = x - 'a';
			r++;
			if (!node->hasChild[idx]) {
				if (!create)
					len += r;
				create = true;
				node->hasChild[idx] = true;
				node->children[idx] = new TrieNode();
				node = node->children[idx];
				continue;
			}
			node = node->children[idx];
			//len++;
			//if (!IdontWantToUseFlag)
			//substr += x;
		}
		if (!create)
			len += word.size();
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, i;
	cin >> T;
	long N;
	int long j;
	for (i = 1; i <= T; i++) {
	        cin >> N;
		string dummy;
		Trie dict;
		for (j = 0; j < N; j++) {
		        cin >> dummy;
			//cout << word << endl;
			dict.insertTrie(dummy);
		}
		printf("Case #%d: %ld\n", i, dict.len);
	}
}
