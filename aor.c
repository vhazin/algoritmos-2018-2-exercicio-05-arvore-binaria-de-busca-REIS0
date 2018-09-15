#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node * left;
  struct node * right;
} node;

node * createtree(int value);
void insert(int value, node * tree);
void preordem(node * x);
void inordem(node * x);
void postordem(node * x);

int main() {

  int C;
  int i = 0;
  scanf("%d", &C);

  while (i < C) {
    node * ROOT = NULL;
    int N, j = 0;
    scanf("%d", &N);

    while (j < N) {
      int n;
      scanf("%d", &n);
      if (j == 0) {
        ROOT = createtree(n);
      }else {
        insert(n, ROOT);
      }
      j++;
    }

    int s = i + 1;
    printf("Case %d:\n", s);
    printf("Pre.:");
    preordem(ROOT);
    printf("\n");
    printf("In..:");
    inordem(ROOT);
    printf("\n");
    printf("Post:");
    postordem(ROOT);
    printf("\n");
    free(ROOT);
    i++;
    printf("\n");
  }
}


node * createtree(int value) {
  node * root = (node*)malloc(sizeof(node));

  root->data = value;
  root->left = NULL;
  root->right = NULL;
  return root;
}


void insert(int value, node * tree) {
  if (value <= tree->data) {
    if (tree->left == NULL) {
      node * node = createtree(value);
      tree->left = node;
      return;
    }else {
      insert(value,  tree->left);
    }
  }else {
    if (tree->right == NULL) {
      node * node = createtree(value);
      tree->right = node;
      return;
    }else {
      insert(value, tree->right);
    }
  }
}


void preordem(node * x) {
  if (x != NULL) {
    printf(" %d", x->data);
    preordem(x->left);
    preordem(x->right);
  }
}


void inordem(node * x) {
  if (x != NULL) {
    inordem(x->left);
    printf(" %d", x->data);
    inordem(x->right);
  }
}


void postordem(node * x) {
  if (x != NULL) {
    postordem(x->left);
    postordem(x->right);
    printf(" %d", x->data);
  }
}
