struct student* sx(struct student * head)
{ // �õݹ飬ÿ���ҳ�ԭ������ѧ����С��Ԫ�أ����뵽������ĺ��档
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
