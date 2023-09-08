#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Node
{
	int			value;
	struct Node	*next;
}				Node;

void	insert_first(Node **root, int value)
{
	Node *new_node = malloc(sizeof(Node));

	new_node->value = value;
	new_node->next = *root;
	*root = new_node;
}

void	insert_last(Node **root, int value)
{
	Node	*new_node = malloc(sizeof(Node));
	if (!new_node)
		exit(1);

	new_node->next = NULL;
	new_node->value = value;

	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	Node	*current = *root;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}

void	insert_after(Node *node, int value)
{
	Node	*new_node = malloc(sizeof(Node));
	new_node->value = value;
	new_node->next = node->next;
	node->next = new_node;
}

void	deallocate(Node **root)
{
	Node	*current = *root;

	while (current != NULL)
	{
		Node	*tmp_node = current;
		current = current->next;
		free(tmp_node);
	}
	*root = NULL;
}

void	deallocate_recursive(Node **root)
{
	Node *current = *root;

	if (current == NULL)
		return;
	else if (current->next == NULL)
	{
		free(current);
		current = NULL;
		return;
	}
	deallocate_recursive(&current->next);
	*root = NULL;
}

int main(void)
{
	Node *root = NULL;
	// Node	*root = malloc(sizeof(Node));

	// root->value = 15;
	// root->next = NULL;
	srand(time(NULL));
	int	i = 3;
	while (i--)
		insert_last(&root, 1 + i);
	insert_first(&root, 0);
	insert_after(root, -1);
	Node	*current = root;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	deallocate_recursive(&root);
	if (root == NULL) {
		printf("The list is empty.\n");
		printf("address: %p", root);
	} else {
		printf("The list is not empty.\n");
		printf("address: %p", root);
		fflush(stdout);
	}
	return (0);
}
