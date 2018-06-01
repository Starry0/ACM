struct student* sx(struct student * head)
{ // 用递归，每次找出原链表中学号最小的元素，插入到新链表的后面。
struct student *cursor, *first, *prev, *min;
first = NULL;

if (head == NULL)
return NULL;

for (cursor = min = head; cursor->next != NULL; cursor = cursor->next)
{
if (cursor->next->num < min->num)
{
prev = cursor;
min = cursor->next;
}
}

first = min;

if (min == head)
head = head->next;
else
prev->next = min->next;

first->next = sx(head);

return first;
}
