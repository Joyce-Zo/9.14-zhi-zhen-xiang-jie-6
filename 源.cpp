#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void bubble_sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[10] = { 1,24,55,7,2,4,6,8,1,7};
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

int main()
{
	int a = 10;
	int* pa = &a;
	char* pc = &a;
	void* p = &a;	// void* ���͵�ָ�룬���Խ����������͵ĵ�ַ
	*p = 0;	err	   void* ���͵�ָ�룬���ɽ��н����ò���
	p++;		err	   void* ���͵�ָ�룬���ɽ���+-�����Ĳ���

	return 0;
}
#include<stdlib.h>
int cmp_int(const void* e1, const void* e2)
��������int	������const void*element
{
	return *(int*)e1 - *(int*)e2;
			(int*)ǿ������ת��
	 ����ֵ ������� - 0
	   a>b - 1   |  a<b - -1
}

void sort1()
{
	int arr[10] = { 1,3,5,7,9,2,4,321312,32134,44 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 < *(float*)e2)
		return -1;
	else
		return 1;
	return ((int)*(float*)e1 - *(float*)e2);
}

void sort2()
{
	float arr[] = { 5.6,6.7,8.8,9.1,4.6,3.0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", arr[i]);
	}
}

struct Stu {
	char name[20];
	int age;
};

int  cmp_stu_by_age(const void*e1, const void*e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void sort3()
{
	struct Stu s[3] = {{"Joyce",21},{"Knaznaz",45},{"Sir",25}};
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s ", s[i]);
	}
}
#include<string.h>
int  cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
			�ַ����Ƚ���strcmp�����ڷ���>0��С�ڷ���<0�����ڷ���0
}

void sort4()
{
	struct Stu s[3] = { {"Joyce",21},{"Knaznaz",45},{"Sir",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
		��һ��Ԫ��:�������������Ԫ�ص�ַ
		�ڶ���Ԫ��:�����������Ԫ�ظ���
		������Ԫ��:����������ÿ��Ԫ�صĴ�С����λ���ֽ�
		���ĸ�Ԫ��:����ָ�룬�Ƚ�2��Ԫ�����ú����ĵ�ַ - ����ָ���2�����������Ƚ�2��Ԫ�صĵ�ַ

}
int main()
{
	sort1();
	sort2();
	sort3();
	sort4();
	return 0;
}

   �Զ����������͵� ð�ݺ���

void swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void*base, int sz, int width, int(*cmp)( const void* e1, const void* e2))
{
	int i = 0;// ����
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			  2��Ԫ�صıȽ�
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				  ����2��Ԫ��
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}

		}
	}
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void sort1()
{
	int arr[10] = { 2,5,7,4,3,8,0,1,6,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	sort1();
	return 0;
}