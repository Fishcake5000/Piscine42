#ifndef BRUTE_SOLV_H
# define BRUTE_SOLV_H
int	ft_find_zero(int **array, int *pos, int size);
int	ft_check_count(int *tab, int clue, int size);
int	ft_check_clues(int **array, int **clues, int *pos, int size);
int	ft_check_rep(int **array, int size, int *pos);
int	ft_brute_solv(int **array, int **clues, int is_flip, int size);
#endif
