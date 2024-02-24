#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>

static int counter = 0;

typedef struct
{
   int elem;
   bool isin;
   struct Stack *next;
} Stack;

Stack *stack_init();// initialize Stack.
bool is_empty_s(Stack *s);// check empty Stack.
int push_s(Stack *s, int n); // return 1 if overflow
int pop_s(Stack *s, int *n); // return 2 if Stack is empty.
void print_s(Stack *s);

int main()
{
   setlocale(0, "");
   Stack *s = stack_init();
   char c = 0;
   int in = 0;
   printf_s("Введите начальные элементы списка: ");
   while (scanf_s("%d", &in) == 1)
   {
      push_s(s, in);
      c--;
   }
   printf_s("Что вы хотите сделать с вашим списком? + x добавить элемент x, - удалить последний элемент, 0 - завершить программу: \n");
   while ((c = getchar()) != '0')
   {
      int tmp = 0;
      if (c == '+')
      {
         scanf_s("%d", &tmp);
         getchar();
         push_s(s, tmp);
      } else if (c == '-')
      {
         getchar();
         pop_s(s, &in);
      }
   }
   printf_s("Ваш список: \n");
   print_s(s);

   return 0 * _getch();
}

void print_s(Stack *s)
{
   printf_s("Ваш стэк:\n");
   int c = counter;
   if (c)
   {
      while (c)
      {
         if (s->isin) s = s->next;
         printf_s("%d\n", s->elem);
         s = s->next;
         c--;
      }
   }
   else
   {
      printf_s("Стэк пуст");
   }
}

bool is_empty_s(Stack *s)
{
   return s->next;
}

Stack *stack_init()
{
   Stack *s = (Stack *) malloc(sizeof(Stack));
   s->elem = 0;
   s->isin = true;
   s->next = NULL;
   counter = 0;
   return s;
}

int push_s(Stack *s, int n)
{
   Stack *z = (Stack *) malloc(sizeof(Stack));
   if (z)
   {
      z->elem = n;
      z->isin = false;
      z->next = s->next;
      s->next = z;
      counter++;
      return 0;
   }
   return 1;
}

int pop_s(Stack *s, int *n)
{
   if (is_empty_s(s))
   {
      Stack *tmp = s;
      tmp = tmp->next;
      Stack *p = tmp;
      *n = s->elem;
      s->next = p->next;
      free(p);
      counter--;
      return 0;
   }
   return 2;
}

