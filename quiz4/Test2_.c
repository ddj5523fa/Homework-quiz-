#include <stdlib.h>

typedef struct
{
    int **parent;
    int max_level;
} TreeAncestor;

TreeAncestor *treeAncestorCreate(int n, int *parent, int parentSize)
{
    TreeAncestor *obj = malloc(sizeof(TreeAncestor));
    obj->parent = malloc(n * sizeof(int *));

    int max_level = 32 - __builtin_clz(n);  //

    for (int i = 0; i < n; i++)
    {
        obj->parent[i] = malloc(max_level * sizeof(int));  //
        /*for (int j = 0; j < max_level; j++)
            obj->parent[i][j] = -1;*/
        memset(obj->parent[i], -1, max_level * sizeof(int));
    }
    for (int i = 0; i < parentSize; i++)
        obj->parent[i][0] = parent[i];


    for (int i = 0; i < parentSize; i++)
    {

        for (int j = 1; j<max_level; j++)
        {
            if(obj->parent[i][j + (-1)] == -1)
                break;
            else
                obj->parent[i][j] = obj->parent[obj->parent[i][j - 1]][j - 1];

        }

    }
    obj->max_level = max_level; //
    return obj;
}

int treeAncestorGetKthAncestor(TreeAncestor *obj, int node, int k)
{
    int max_level = obj->max_level;
    for (int i = 0; i < max_level && node != -1; ++i)
        if (k & (1<<i))
            node = obj->parent[node][i];
    return node;
}

void treeAncestorFree(TreeAncestor *obj)
{
    for (int i = 0; i < obj->max_level; i++)
        free(obj->parent[i]);
    free(obj->parent);
    free(obj);
}
