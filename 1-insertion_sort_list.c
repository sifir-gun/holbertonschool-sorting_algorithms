#include "sort.h"
/**
 * swap_nodes - Échange deux nœuds dans une liste doublement chaînée
 * @list: Pointeur vers le pointeur de tête de la liste
 * @node1: Premier nœud à échanger
 * @node2: Deuxième nœud à échanger
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * insertion_sort_list -  insére chq élmnt dans sa pos correcte selon le prev
 * @list: liste
 *
 * Return: liste trier
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			print_list(*list);
		}
		current = next;
	}
}
