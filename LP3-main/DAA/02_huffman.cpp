#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
    public:
        char c;
        int freq;
        Node *left, *right;
        Node(char name, int frequency) {
            freq = frequency;
            c = name;
            left = right = nullptr;
        }
};

class compare {
    public:
        bool operator()(Node *a, Node *b) {
            return a->freq > b->freq;
        }
};

void preorder(Node* root, vector<string> &ans, string temp) {
    if(!root) return;
    if(!root->left && !root->right) {
        ans.push_back(temp);
        return;
    }
    preorder(root->left, ans, temp+"0");
    preorder(root->right, ans, temp+"1");
}

vector<string> huffmanCodes(string S, vector<int> freq) {
    priority_queue<Node*,vector<Node*>, compare> minH;
    for(int i = 0; i < freq.size(); i++) {
        Node* curr = new Node(S[i], freq[i]);
        minH.push(curr);
    }

    while(minH.size() > 1) {
        Node *left = minH.top(); minH.pop();
        Node *right = minH.top(); minH.pop();

        Node *newNode = new Node('$',left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        minH.push(newNode);
    }

    Node *root = minH.top(); minH.pop();
    vector<string> ans;
    preorder(root, ans, "");

    return ans;
}

int main() {
    string S = "abcedf";
    vector<int> freq = {5,9,12,13,16,45};
    vector<string> ans = huffmanCodes(S, freq);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<endl;
    }
}