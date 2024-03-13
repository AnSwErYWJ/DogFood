#include <stdio.h>
#include <string.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offsetof(type,member) );})

typedef struct
{
    char gender;
    int id;
    int age;
    char name[20];
} student_t;

int main(void)
{
    student_t stu;
    student_t *pstu;

    stu.gender = '1';
    stu.id = 9527;
    stu.age = 24;
    strcpy(stu.name, "answerywj");

    pstu = container_of(&stu.id, student_t, id);

    printf("gender= %c\n", pstu->gender);
    printf("age= %d\n", pstu->age);
    printf("name= %s\n", pstu->name);

    return 0;
}