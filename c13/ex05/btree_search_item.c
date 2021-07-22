#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *))
{
	void	*temp;

	if (!root)
		return (0);
	temp = btree_search_item(root->left, data_ref, cmpf);
	if (temp)
		return (temp);
	if ((*cmpf)(data_ref, root->item) == 0)
		return (root);
	temp = btree_search_item(root->right, data_ref, cmpf);
	if (temp)
		return (temp);
	return (0);
}
