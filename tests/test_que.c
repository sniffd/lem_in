#include <stdlib.h>
#include <stdio.h>
#include "ft_queue.h"

void	*input(void *it)
{
	int		*a;

	a = (int*)malloc(sizeof(int));
	*a = ((int)*(int*)it);
	return(a);
}

void	print_qint(void *it)
{
	int	num;

	num = ((int)*(int*)it);
	printf("%d\n", num);
}

int		main(void)
{
	t_fque		*head;
	t_fque		*tail;
	int			num;

	head = NULL;
	tail = NULL;
	num = 90;
	add_qnode(&head, &tail, &num, input);
	num = 100;
	add_qnode(&head, &tail, &num, input);
	num = 110;
	add_qnode(&head, &tail, &num, input);
	num = 120;
	add_qnode(&head, &tail, &num, input);
	print_qnode(head, print_qint);
	printf("\n");
	del_qnode(&head);
	print_qnode(head, print_qint);
	printf("\n");
	num = 80;
	add_qnode(&head, &tail, &num, input);
	print_qnode(head, print_qint);
	printf("\n");
	del_qnode(&head);
	del_qnode(&head);
	del_qnode(&head);
	print_qnode(head, print_qint);
	printf("\n");
	del_qnode(&head);
	del_qnode(&head);
	print_qnode(head, print_qint);
	printf("\n");
	num = 125;
	add_qnode(&head, &tail, &num, input);
	num = 135;
	add_qnode(&head, &tail, &num, input);
	print_qnode(head, print_qint);
	printf("\n");
	return (0);
}