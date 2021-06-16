#include "unity.h"
#include "libft.h"
#include <bsd/string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

void	setUp(void)
{
// set stuff up here
}

void	tearDown(void)
{
// clean stuff up here
}

void	test_ft_lstnew(void)
{
	const char	s[] = "42Wolfsburg";
	t_list		*current;

	current = ft_lstnew((char *)s);
	TEST_ASSERT_EQUAL_STRING("42Wolfsburg", current -> content);
	TEST_ASSERT_NULL(current -> next);
	free(current);
}

void	test_ft_lstadd_front(void)
{
	const char	s[] = "Head";
	const char	s1[] = "New head";
	t_list		*head;
	t_list		*new_head;

	head = ft_lstnew((char *)s);
	new_head = ft_lstnew((char *)s1);
	ft_lstadd_front(&head, new_head);
	TEST_ASSERT_EQUAL_STRING("New head", head -> content);
	TEST_ASSERT_EQUAL_STRING("Head", head -> next -> content);
	TEST_ASSERT_NULL(head -> next -> next);
	free(head -> next);
	free(head);
}

void	test_ft_lstsize(void)
{
	const char	s[] = "Head";
	const char	s1[] = "New head";
	t_list		*head;
	t_list		*new_head;

	head = ft_lstnew((char *)s);
	new_head = ft_lstnew((char *)s1);
	ft_lstadd_front(&head, new_head);
	TEST_ASSERT_EQUAL(2, ft_lstsize(head));
	free(head -> next);
	free(head);
}

void	test_ft_lstlast(void)
{
	const char	s[] = "Head";
	const char	s1[] = "New head";
	t_list		*head;
	t_list		*new_head;
	t_list		*last;

	head = ft_lstnew((char *)s);
	new_head = ft_lstnew((char *)s1);
	ft_lstadd_front(&head, new_head);
	last = ft_lstlast(head);
	TEST_ASSERT_EQUAL_STRING("Head", last -> content);
	free(head -> next);
	free(head);
}

void	test_ft_lstadd_back(void)
{
	const char	s[] = "Head";
	const char	s1[] = "New head";
	const char	s2[] = "New last";
	t_list		*head;
	t_list		*new_head;
	t_list		*new_last;

	head = ft_lstnew((char *)s);
	new_head = ft_lstnew((char *)s1);
	new_last = ft_lstnew((char *)s2);
	ft_lstadd_front(&head, new_head);
	ft_lstadd_back(&head, new_last);
	TEST_ASSERT_EQUAL_STRING("New last", ft_lstlast(head)-> content);
	TEST_ASSERT_NULL(head -> next -> next -> next);
	free(head -> next -> next);
	free(head -> next);
	free(head);
}

void	f_del(void *content)
{
	content = NULL;
}

void	test_ft_lstdelone(void)
{
	const char	s[] = "Head";
	t_list		*head;

	head = ft_lstnew((char *)s);
	TEST_ASSERT_EQUAL_STRING("Head", head -> content);
	ft_lstdelone(head, f_del);
}

void	test_ft_lstclear(void)
{
	const char	s[] = "Head";
	const char	s1[] = "New head";
	const char	s2[] = "New last";
	t_list		*head;
	t_list		*new_head;
	t_list		*new_last;

	head = ft_lstnew((char *)s);
	new_head = ft_lstnew((char *)s1);
	new_last = ft_lstnew((char *)s2);
	ft_lstadd_front(&head, new_head);
	ft_lstadd_back(&head, new_last);
	ft_lstclear(&head, f_del);
	TEST_ASSERT_NULL(head);
}

void	f(void *content)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)content;
	while (s[i] !='\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
		i++;
	}
}

void	test_ft_lstiter(void)
{
	const char	s[] = "Head";
	const char	s1[] = "New head";
	const char	s2[] = "New last";
	t_list		*head;
	t_list		*new_head;
	t_list		*new_last;

	head = ft_lstnew((char *)s);
	new_head = ft_lstnew((char *)s1);
	new_last = ft_lstnew((char *)s2);
	ft_lstadd_front(&head, new_head);
	ft_lstadd_back(&head, new_last);
	ft_lstiter(head, f);
	TEST_ASSERT_EQUAL_STRING("NEW HEAD", head -> content);
	TEST_ASSERT_EQUAL_STRING("HEAD", head -> next -> content);
	TEST_ASSERT_EQUAL_STRING("NEW LAST", head -> next -> next -> content);
	TEST_ASSERT_NULL(head -> next -> next -> next);
	ft_lstclear(&head, f_del);
}

void	*func(void *content)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)content;
	while (s[i] !='\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
		i++;
	}
	return ((void *)s);
}

void	test_ft_lstmap(void)
{
	const char	s[] = "Head";
	const char	s1[] = "New head";
	const char	s2[] = "New last";
	t_list		*head;
	t_list		*new_head;
	t_list		*new_last;
	t_list		*new_one;

	head = ft_lstnew((char *)s);
	new_head = ft_lstnew((char *)s1);
	new_last = ft_lstnew((char *)s2);
	ft_lstadd_front(&head, new_head);
	ft_lstadd_back(&head, new_last);
	TEST_ASSERT_EQUAL_STRING("New head", head -> content);
	TEST_ASSERT_EQUAL_STRING("Head", head -> next -> content);
	TEST_ASSERT_EQUAL_STRING("New last", head -> next -> next -> content);
	TEST_ASSERT_NULL(head -> next -> next -> next);
	new_one = ft_lstmap(head, func, f_del);
	TEST_ASSERT_EQUAL_STRING("NEW HEAD", new_one -> content);
	TEST_ASSERT_EQUAL_STRING("HEAD", new_one -> next -> content);
	TEST_ASSERT_EQUAL_STRING("NEW LAST", new_one -> next -> next -> content);
	TEST_ASSERT_NULL(new_one -> next -> next -> next);
	ft_lstclear(&head, f_del);
	ft_lstclear(&new_one, f_del);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_lstnew);
	RUN_TEST(test_ft_lstadd_front);
	RUN_TEST(test_ft_lstsize);
	RUN_TEST(test_ft_lstlast);
	RUN_TEST(test_ft_lstadd_back);
	RUN_TEST(test_ft_lstdelone);
	RUN_TEST(test_ft_lstclear);
	RUN_TEST(test_ft_lstiter);
	RUN_TEST(test_ft_lstmap);
	return (UNITY_END());
}
