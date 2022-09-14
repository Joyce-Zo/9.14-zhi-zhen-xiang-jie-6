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
	void* p = &a;	// void* 类型的指针，可以接收任意类型的地址
	*p = 0;	err	   void* 类型的指针，不可进行解引用操作
	p++;		err	   void* 类型的指针，不可进行+-整数的操作

	return 0;
}
#include<stdlib.h>
int cmp_int(const void* e1, const void* e2)
函数类型int	必须是const void*element
{
	return *(int*)e1 - *(int*)e2;
			(int*)强制类型转换
	 返回值 两数相等 - 0
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
			字符串比较用strcmp，大于返回>0，小于返回<0，等于返回0
}

void sort4()
{
	struct Stu s[3] = { {"Joyce",21},{"Knaznaz",45},{"Sir",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
		第一个元素:待排序数组的首元素地址
		第二个元素:待排序数组的元素个数
		第三个元素:待排序数组每个元素的大小，单位是字节
		第四个元素:函数指针，比较2个元素所用函数的地址 - 函数指针的2个参数：待比较2个元素的地址

}
int main()
{
	sort1();
	sort2();
	sort3();
	sort4();
	return 0;
}

   自定义任意类型的 冒泡函数

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
	int i = 0;// 趟数
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			  2个元素的比较
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				  交换2个元素
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