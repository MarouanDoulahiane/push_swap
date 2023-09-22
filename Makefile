all:
	 gcc -o push_swap main.c ft_sort.c ft_atol.c ft_error.c ft_split.c ft_stack.c ft_stack_utilis.c


git:
	git.exe add .
	git.exe commit -m 'update'
	git.exe push
