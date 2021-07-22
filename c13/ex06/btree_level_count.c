#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	size_left;
	int	size_right;

	if (!root)
		return (0);
	size_left = btree_level_count(root->left);
	size_right = btree_level_count(root->right);
	if (size_left >= size_right)
		return (size_left + 1);
	return (size_right + 1);
}
