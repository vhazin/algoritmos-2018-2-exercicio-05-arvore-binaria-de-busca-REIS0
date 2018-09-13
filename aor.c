#include <stdio.h>

typedef struct node {
  int data;
  struct node * left;
  struct node * right;
  struct node * pai;
} node;

node * createtree(int value, node* esq, node* dir);
node * insert(int value, node * tree);

int main() {

  int C;
  int i = 0;
  node * ROOT = NULL;
  scanf("%d", &C);

  while (i > N) {
    int N, j = 0;
    scanf("%d", &N);

    while (j < N) {
      int n;
      scanf("%d", &n);
      insert(n, ROOT);
    }

    printf("Case %d:\n", i + 1);
    
  }
}


node * createtree(int value, node* esq, node* dir) {
  node * root;

  root = (node*)malloc(sizeof(node));
  value = root->data;
  esq = root->left;
  dir = root->right;
  root = esq->pai;
  root = dir->pai;
  return root;
}


node * insert(int value, node * tree) {

  if (node * tree == NULL) {
    tree = createtree(value, NULL, NULL);
  }else {
    if (value < tree->data) {
      tree->left = insert(value, tree->left);
      tree = tree->left->pai;
    }else {
      tree->right = insert(value, tree->right);
      tree->direita->pai = tree;
    }
  }
  return tree;
}
