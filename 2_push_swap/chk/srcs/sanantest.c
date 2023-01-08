#include "chker.h"

void    print_queue(t_stack *s, char ab) // delete
{
    t_node *head;
	char	c = 'a';

    head = s->atop;
	if (ab)
		head = s->btop;
    printf("############\n");
    while (head)
    {
        printf("|%10d|\n", head->val);
        head = head->next;
    }
    printf("############\n");
	if (!ab)
    	printf("%c size = %d\n", c, s->asize);
	else
    	printf("%c size = %d\n", c, s->bsize);
    printf( "############\n");
}
void    print_queue_ab(t_stack *s) // delete
{
    t_node	*head_a;
    t_node	*head_b;
    head_a = s->atop;
    head_b = s->btop;
	int		at = 0, ab = 0, bt = 0, bb = 0;
    printf("##########################\n");
    while (head_a && head_b)
    {
        printf("|%11d | %-10d|\n", head_a->val, head_b->val);
		
        head_a = head_a->next;
        head_b = head_b->next;
    }
    while (head_a)
    {
        printf("|%11d |           |\n", head_a->val);
        head_a = head_a->next;
    }
    while (head_b)
    {
        printf("|            | %-10d|\n", head_b->val);
        head_b = head_b->next;
    }
	if(s->atop)
		at = s->atop->val;
	if(s->btop)
		bt = s->btop->val;
	if(s->abot)
		ab = s->abot->val;
	if(s->bbot)
		bb = s->bbot->val;
	
    printf("##########################\n");
    printf("  a size = %d |  b size = %d \n", s->asize, s->bsize);
	printf("  top%d bot%d |  top%d bot%d \n", at, ab, bt, bb);
    printf("##########################\n\n");
}

