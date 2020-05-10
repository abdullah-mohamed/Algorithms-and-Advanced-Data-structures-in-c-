#include <iostream>
#include <cstdlib>
#define ALPHABET_SIZE 26

using namespace std;

typedef struct TrieNode{
	struct TrieNode *characters[ALPHABET_SIZE];			// This should have a destructor or use smart pointers
	bool isEndOfWord;
} TrieNode;


class TrieRoot{
private: 
	TrieNode *root;
public:
	TrieRoot(){
		root = new(std::nothrow) TrieNode();
	}
	
	~TrieRoot(){
		free(root);
	}
	
	void addKey(string s){				// make sure s is all small letters
		TrieNode *p = root;
		
		for(int i = 0; i < (int)s.length(); i++){
			int c = (int)s[i]-'a';
			if(p->characters[c] == NULL) p->characters[c] = new TrieNode();
			p = p->characters[c];
			if(i == (int)s.size()-1) p->isEndOfWord = true;
		}
	}
	
	bool searchKey(string key){
		bool ans = true;
		TrieNode *p = root;
		
		for(int i = 0; i < (int)key.length(); i++){
			int c = (int)key[i]-'a';
			//cout << c << " " <<  p->characters[c] << "\n";
			if(p->characters[c] != NULL) p = p->characters[c];
			else {ans = false; break;}
		}
		return ans;
	}
};

int main(){
	TrieRoot *root = new TrieRoot();
	root->addKey("abd");
	cout << root->searchKey("abd") << "\n";
	cout << root->searchKey("abdallah") << "\n";
	
	root->addKey("abdallah");
	cout << root->searchKey("abdallah") << "\n";
	return 0;
}