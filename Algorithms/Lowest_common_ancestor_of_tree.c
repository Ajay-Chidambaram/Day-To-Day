/****************************************************************
          only the Algorithm snippet is here ..
****************************************************************/


struct node *lca( struct node *root, int v1, int v2 ) {

    struct node *t1, *t2;

    if(root == NULL)
        return NULL;

    if(root->data == v1 || root->data == v2)
    {
        return root;
    }

    t1 = lca(root->left,v1,v2);
    
    t2 = lca(root->right,v1,v2);

    if((t1 != NULL && t2 != NULL) && ((t1->data == v1 && t2->data == v2) || (t1->data == v2 && t2->data == v1)))
        return root;

    else if(t1 != NULL && t2 == NULL)
        return t1;
    
    else if(t2 != NULL && t1 == NULL)
        return t2;

    else
        return NULL;
}
