#ifndef AVL_MASTER
#define AVL_MASTER

#include <string.h>

// This file is released "as it" into the public domain, without any warranty, express or implied.
// AVL tree is a self-balancing binary search tree, AVL stands for Adelson-Velskii and Landis.

enum avl_direction {
	AVL_LOW_TO_HIGH, AVL_HIGH_TO_LOW,
};

struct avl_node {
	void *key;
	void *value;
	struct avl_node *rel[3]; // [0, 1, 2] = [left child, right child, parent]
	int height;
};

struct avl_manager {
	struct avl_node *root;
	size_t count;
	int affected;
	int search_only;

	int (*comparator)(const void *, const void *);

	struct avl_node *(*inserter)(void *, const void *);

	void *inserter_argument;
};

#define avl_left rel[0]
#define avl_right rel[1]
#define avl_parent rel[2]

// h_ prefixed functions are intended for internal usage only.
// Thanks to the rotations, the heights of your BSTs are always lesser than 1.44 * log2(number of keys).
static inline void h_avl_rotate(struct avl_node *a, const int rel_a, struct avl_node *b, const int rel_b) {
	if ((b->rel[rel_b] = a->rel[rel_a])) {
		a->rel[rel_a]->avl_parent = b;
	} else {
		b->rel[rel_b] = a->rel[rel_a];
	}
	b->avl_parent = a;
	a->rel[rel_a] = b;
}

static inline void h_avl_swap(struct avl_node **root, const struct avl_node *a, struct avl_node *b) {
	if (a->avl_parent) {
		a->avl_parent->rel[a->avl_parent->avl_right == a] = b;
	} else {
		*root = b;
	}
	b->avl_parent = a->avl_parent;
}

static inline int h_avl_height(const struct avl_node *node) {
	if (node->avl_right) {
		if (node->avl_left) {
			return 1 + node->rel[node->avl_right->height > node->avl_left->height]->height;
		} else {
			if (node->avl_right) {
				return 1 + node->avl_right->height;
			} else {
				return 1;
			}
		}
	} else {
		if (node->avl_left) {
			return 1 + node->avl_left->height;
		} else {
			if (node->avl_right) {
				return 1 + node->avl_right->height;
			} else {
				return 1;
			}
		}
	}
}

static inline char h_avl_op_kind(const struct avl_node *node) {
	if (node->avl_left) {
		if (node->avl_right) {
			if (node->avl_left->height > node->avl_right->height) {
				return 'L';
			} else {
				return 'R';
			}
		} else {
			return 'L';
		}
	} else {
		return 'R';
	}
}

static inline char h_avl_has_op(const struct avl_node *node) {
	switch ((node->avl_left ? node->avl_left->height : 0) - (node->avl_right ? node->avl_right->height : 0)) {
		case 2 :
			return 'L';
		case -2 :
			return 'R';
	}
	return 0;
}

// Used after an insertion to execute at most 1 rotation.
static inline void h_avl_rebalance(struct avl_node **root, struct avl_node *top) {
	struct avl_node *middle, *bottom;
	char op[3];
	int i;
	// Maybe "top" is now too tall.
	while (top) {
		i = top->height;
		top->height = h_avl_height(top);
		if (i == top->height) { // Height not change ?
			break; // Retracing can stop.
		}
		*op = h_avl_has_op(top);
		if (*op) {
			middle = top->rel[*op == 'R'];
			op[1] = h_avl_op_kind(middle);
			i = op[1] == 'R';
			bottom = middle->rel[i];
			top->height = bottom->height;
			if (op[0] == op[1]) {
				h_avl_swap(root, top, middle);
				h_avl_rotate(middle, !i, top, i); // LL or RR done.
			} else {
				h_avl_swap(root, top, bottom);
				h_avl_rotate(bottom, !i, middle, i);
				h_avl_rotate(bottom, i, top, !i); // LR or RL done.
				middle->height = bottom->height++; // The 3 height has changed.
			}
			// Rebalanced out, nobody above would notice.
			break;
		}
		top = top->avl_parent;
	}
}

struct avl_node *avl_at(struct avl_manager *const manager, const void *key) {
	// retrieves a node from an AVL tree based on a specified key.
	struct avl_node *curr, *new_node;
	int i;
	if (manager->root) {
		curr = manager->root;
		for (;;) {
			const int cmp = manager->comparator(key, curr->key);
			if (cmp > 0) {
				if (curr->avl_right) {
					curr = curr->avl_right;
				} else {
					if (manager->search_only) {
						return 0;
					}
					i = 1;
					break;
				}
			} else if (cmp == 0) {
				manager->affected = 0;
				return curr;
			} else {
				if (curr->avl_left) {
					curr = curr->avl_left;
				} else {
					if (manager->search_only) {
						return 0;
					}
					i = 0;
					break;
				}
			}
		}
	} else if (manager->search_only) {
		return 0;
	} else {
		curr = 0;
		i = -1;
	}
	// This may replace root.
	new_node = *(i >= 0 ? &curr->rel[i] : &manager->root) = manager->inserter(manager->inserter_argument, key);
	new_node->height = 1;
	new_node->avl_parent = curr;
	h_avl_rebalance(&manager->root, curr);
	++manager->count;
	manager->affected = 1;
	return new_node;
}

__attribute__((unused)) void avl_walk(const struct avl_manager *manager, void(*fn)(const struct avl_node *, void *), void *args, const enum avl_direction direction) {
	struct avl_node *stack[64], *curr;
	int index = 0;
	const int opposite = !direction;
	if (manager->root) {
		curr = manager->root;
		do {
			while (curr) {
				stack[index++] = curr;
				curr = curr->rel[direction];
			}
			if (index) {
				curr = stack[--index];
				fn(curr, args);
				curr = curr->rel[opposite];
			}
		} while (index || curr);
	}
}

/*
 Every AVL tree can be colored such that it obeys all the properties of a red-black tree.
 Read more : https://www.math.toronto.edu/askold/2014-UMN-4-e-Adelson-.pdf
*/

#endif // AVL_MASTER
