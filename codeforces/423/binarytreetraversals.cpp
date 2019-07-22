#include <bits/stdc++.h>
using namespace std;

struct Node {
  struct Node* left;
  struct Node* right;
  char ele;
};

Node* btfo(char* inorder, char* aftorder, int length) {
  if (length == 0) return NULL;
  Node* node = new Node;
  node->ele = *(aftorder + length - 1);
  cout << node->ele;
  int rootIndex = 0;
  for (; rootIndex < length; ++rootIndex) if (inorder[rootIndex] == *(aftorder + length - 1))
    break;
  node->left = btfo(inorder, aftorder, rootIndex);
  node->right = btfo(inorder + rootIndex + 1, aftorder + rootIndex, length - (rootIndex + 1));
  return node;
}

char af[100005], in[100005];

int main() {
  int T, N;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    scanf("%s %s", in, af);
    in[N] = '\0';
    af[N] = '\0';
    btfo(in, af, N);
    printf("\n");
  }
  return 0;
}
