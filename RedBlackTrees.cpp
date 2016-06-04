#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
struct LLRB {
    long val, cnt;
    bool red;
    int children;
    struct LLRB *left, *right;

    LLRB(int v, int c) : val(v), cnt(c), red(true), children(0), left(NULL), right(NULL) {
    }
};

int size(const LLRB *node) {
    return node == NULL ? 0 : node->cnt + node->children;
}

bool is_red(const LLRB *node) {
    return node == NULL ? false : node->red;
}

void rot_l(LLRB **node) {
    LLRB *tmp = *node;
    *node = (*node)->right;
    tmp->right = (*node)->left;
    (*node)->left = tmp;
    tmp->children = size(tmp->left) + size(tmp->right);
    (*node)->children = size(tmp) + size((*node)->right);
    swap((*node)->red, (*node)->left->red);
}

void rot_r(LLRB **node) {
    LLRB *tmp = *node;
    *node = (*node)->left;
    tmp->left = (*node)->right;
    (*node)->right = tmp;
    tmp->children = size(tmp->left) + size(tmp->right);
    (*node)->children = size((*node)->left) + size(tmp);
    swap((*node)->red, (*node)->right->red);
}

void balance(LLRB **node) {
    if (is_red((*node)->left)) {
        if (is_red((*node)->left->left))
            rot_r(node);
        if (is_red((*node)->right)) {
            (*node)->red = true;
            (*node)->left->red = false;
            (*node)->right->red = false;
        }
    } else if (is_red((*node)->right)) {
        rot_l(node);
    }
}

void insert(LLRB **node, int val, int cnt = 1) {
    while (*node) {
        balance(node);
        (*node)->children += cnt;
        node = val < (*node)->val ? &(*node)->left : &(*node)->right;
    }
    *node = new LLRB(val, cnt);
}

long rank(LLRB *node, long i) {
    long r = size(node->left) + 1;
    if (i == r)
        return node->val;
    else if (i < r)
        return rank(node->left, i);
    else
        return rank(node->right, i - r);
}

int rankof(const LLRB *node, long val){
	int result=0;
	while(node){
		if(val<node->val){
			node=node->left;
		}else{
			result+=size(node->left)+node->cnt;
			node=node->right;
		}
	}
	return result;
}

int main() {
    LLRB* root = NULL;
    long N, Ka = 0;
    //freopen("1.out","r",stdin);
    scanf("%ld", &N);
    while (N--) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            long b;
            scanf("%ld", &b);
            insert(&root, b);
            Ka++;
        } else {
            int f = Ka - Ka / 3 + 1;//this prints the exactly 1/3rd number in descending order
            //cout<<"Ka "<<Ka<<" f "<<f<<endl;
            if (Ka < 3)
                printf("No reviews yet\n");
            else {
                long m = rank(root, f);
                printf("%ld\n", m);
            }

        }
    }
}
