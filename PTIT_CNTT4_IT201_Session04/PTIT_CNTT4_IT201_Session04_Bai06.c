#include <stdio.h>
#include <string.h>

struct Student {
  int id;
  char name[50];
  int age;
};

int findStudentById(struct Student students[], int size, int targetId) {
  for (int i = 0; i < size; i++) {
    if (students[i].id == targetId) {
      return i;
    }
  }
  return -1;
}

int main() {
  struct Student students[5];

  for (int i = 0; i < 5; i++) {
    printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
    printf("ID: ");
    scanf("%d", &students[i].id);
    getchar();
    printf("Ten: ");
    fgets(students[i].name, 50, stdin);
    students[i].name[strcspn(students[i].name, "\n")] = 0;
    printf("Tuoi: ");
    scanf("%d", &students[i].age);
  }

  int targetId;
  printf("Nhap ID can tim: ");
  scanf("%d", &targetId);

  int index = findStudentById(students, 5, targetId);
  if (index >= 0) {
    printf("{ id: %d, name: \"%s\", age: %d }\n",
           students[index].id, students[index].name, students[index].age);
  } else {
    printf("Sinh vien khong ton tai\n");
  }

  return 0;
}