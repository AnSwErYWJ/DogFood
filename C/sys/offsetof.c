#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

typedef struct
{
    char gender;
    int id;
    int age;
    char name[20];
} student_t;

int main(void)
{
    int gender_offset;
    int id_offset;
    int age_offset;
    int name_offset;

    gender_offset = offsetof(student_t, gender);
    id_offset = offsetof(student_t, id);
    age_offset = offsetof(student_t, age);
    name_offset = offsetof(student_t, name);

    printf("gender_offset = %d\n", gender_offset);
    printf("id_offset = %d\n", id_offset);
    printf("age_offset = %d\n", age_offset);
    printf("name_offset = %d\n", name_offset);

    return 0;
}