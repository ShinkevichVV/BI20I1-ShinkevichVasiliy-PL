#include <iostream>
#include <time.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

struct list {
    int field;
    struct list* ptr;
};

struct list* init() 
{
    int field;
    struct list* lst;
    lst = new struct list;
    field = rand() % 101;
    lst->field = field;
    lst->ptr = NULL;
    return(lst);
}

struct list* addelem(list* lst) {
    struct list* temp;
    temp = init();
    lst->ptr = temp;
    temp->field = rand() % 101;
    return temp;
}

struct list* deletelem(list* deletehead, list* root) {
    struct list* temp;
    temp = root;
    while (temp->ptr != deletehead) {
        temp = temp->ptr;
    }
    temp->ptr = deletehead->ptr;
    delete deletehead;
    return temp;
}

void listprint(list* root) {
    struct list* p;
    p = root;
    do {
        cout << p->field << " ";
        p = p->ptr;
    } while (p != NULL);
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    struct list* temp, * root;
    root = init();
    temp = root;
    struct list* deletehead;
    for (int i = 1; i < 25; i++) {
        temp = addelem(temp);
    }
    deletehead = root;
    for (int n = 1; n < 15; n++) {
        deletehead = deletehead->ptr;
    }
    cout << "Список: ";
    listprint(root);
    cout << endl;
    deletelem(deletehead, root);
    cout << "Список после удаления 15-го элемента: ";
    listprint(root);
    cout << endl;
    return 0;
}