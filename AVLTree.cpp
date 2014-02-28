#include "AVLTree.hpp"
#include <queue>

AVLTree::AVLTree() : root(NULL) {
}

AVLTree::~AVLTree() {
  destruct_helper( root );
}

void AVLTree::insert(const City& city) {
  insert_helper(city, root);
}

void AVLTree::remove(const std::string& name) {
}

void AVLTree::remove(int x, int y) {
}

void AVLTree::print() const {
  std::queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    Node * curr = q.front();
    q.pop();
    if(curr==NULL) continue;
    q.push( curr->left );
    q.push( curr->right );
    std::cout << curr->city.name << " ";
  }
}

void AVLTree::printinorder() const {
  printinorder_helper(root);
}

void AVLTree::printinorder_helper(Node * t) const {
  if(t == NULL) return;
  printinorder_helper(t->left);
  std::cout << t->city.name << ": (" << t->city.x << "," << t->city.y << ") ";
  printinorder_helper(t->right);
}

void AVLTree::insert_helper(const City& city, Node * & t) {
  if( t == NULL ) {
    t = new Node( city, NULL, NULL, 0 );
  } else if( city < t->city ) {
    insert_helper( city, t->left );
    if( height( t->left ) - height( t->right ) == 2 ) {
      if( city < t->left->city ) {
	rotateWithLeftChild( t );
      } else {
	doubleWithLeftChild( t );
      }
    }
  } else if( t->city < city ) {
    insert_helper( city, t->right );
    if( height( t->right ) - height( t->left ) == 2 ) {
      if( t->right->city < city ) {
	rotateWithRightChild( t );
      } else {
	doubleWithRightChild( t );
      }
    }
  }
  else {
    // duplicate item so do nothing
  }

  t->height = MAX( height(t->left), height(t->right) ) + 1;
}

void AVLTree::rotateWithLeftChild(Node * & k2) {
  Node * k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = MAX( height(k2->left), height(k2->right) ) + 1;
  k1->height = MAX( height(k1->left), k2->height ) + 1;
  k2 = k1;
}

void AVLTree::rotateWithRightChild(Node * & k1) {
  Node * k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;
  k1->height = MAX( height( k1->left ), height( k1->right ) ) + 1;
  k2->height = MAX( k1->height, height( k2->right ) ) + 1;
  k1 = k2;
}

void AVLTree::doubleWithLeftChild(Node * & t) {
  rotateWithRightChild( t->left );
  rotateWithLeftChild( t );
}

void AVLTree::doubleWithRightChild(Node * & t) {
  rotateWithLeftChild( t->right );
  rotateWithRightChild( t );
}

void AVLTree::destruct_helper(Node * & t) {
  if(t == NULL) return;
  destruct_helper(t->left);
  destruct_helper(t->right);
  delete t;
}

int AVLTree::height( Node * t ) const {
  return (t == NULL) ? -1 : t->height;
}
