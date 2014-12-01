#include <stdio.h>  //printf
#include <stdlib.h> // malloc
typedef struct tree {
    int item;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree;


void *search_tree(tree *l, int x)
{
    if (l == NULL) return(NULL);

    if (l->item == x) return(l);

    if (x < l->item)
        return( search_tree(l->left, x) );
    else
        return( search_tree(l->right, x) );
}

tree *find_minimum(tree *t)
{
    tree *min;      /* pointer to minimum */

    if (t == NULL) return(NULL);

    min = t;
    while (min->left != NULL)
        min = min->left;
    return(min);
}

void process_item(int item)
{
    printf("Node(=%d)\n", item);
}

void traverse_tree(tree *l)
{
    if (l != NULL) {
        traverse_tree(l->left);
        process_item(l->item);
        traverse_tree(l->right);
    }
}

void insert_tree(tree **l, int x/*, tree *parent*/)
{
    tree *p;       /* temp pointer */

    if (*l == NULL) {
        p = malloc(sizeof(tree));
        p->item = x;
        p->left = p->right = NULL;
        /*p->parent = parent;*/
        *l = p;     /* link into parent's record */
        return;
    }

    if (x < (*l)->item)
        insert_tree(&((*l)->left), x/*, *l*/);
    else
        insert_tree(&((*l)->right), x/*, *l*/);
}

int main(int argc, char *argv[]) {
    tree *root = NULL;
    insert_tree(&root, 3/*, root*/);
    insert_tree(&root, 6/*, root*/);
    insert_tree(&root, 2/*, root*/);
    insert_tree(&root, 1/*, root*/);
    insert_tree(&root, 4/*, root*/);
    insert_tree(&root, 9/*, root*/);

    printf("Find minimum = %d\n", (find_minimum(root))->item );
    printf("Inorder Traversal of Tree:\n");
    traverse_tree(root);
}




