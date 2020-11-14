#include <iostream>
#include <time.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

struct tnode {
    int field;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* init() {
    int field;
    struct tnode* tnode;
    tnode = new struct tnode;
    field = 3;
    tnode->field = field;
    tnode->left = NULL;
    tnode->right = NULL;
    return tnode;
}

struct tnode* addtree(tnode* tree) {
    int data = rand() % 101;
    struct tnode* temp;
    temp = init();
    if (tree->field > data) {
        tree->right = temp;
    }
    else if (tree->field < data) {
        tree->left = temp;
    }
    else {
        delete temp;
    }
    return tree;
}

struct tnode* addtreeManual(tnode* root, int data) {
    struct tnode* temp;
    struct tnode* temp1;
    temp = init();
    temp->field = data;
    temp1 = root;
    while (temp1->left != NULL and temp1->right != NULL) {
        if (temp1->field > data) {
            temp1 = temp1->left;
        }
        else if (temp1->field < data) {
            temp1 = temp1->right;
        }
    }
    if (temp1->field > data) {
        temp1->left = temp;
    }
    else if (temp1->field < data) {
        temp1->right = temp;
    }
    return root;
}

struct tnode* delettree(tnode* del_tree, tnode* root) {
    struct tnode* temp;
    temp = root;
    while (temp->left != del_tree) {
        temp = temp->left;
    }
    temp->left = del_tree->left;
    delete del_tree;
    return temp;
}

struct tnode* deleteTreeByValue(tnode* root, int data) {
    struct tnode* temp;
    struct tnode* temp1;
    temp1 = root;
    bool flag = true;
    while (data != temp1->left->field and data != temp1->right->field) {
        if (temp1->field > data) {
            temp1 = temp1->left;
        }
        else if (temp1->field < data) {
            temp1 = temp1->right;
        }
        else {

            flag = false;
        }

    }
    if (temp1->left->field == data) {
        delete temp1->left;
        temp1->left = NULL;
    }
    else {
        delete temp1->right;
        temp1->right = NULL;
    }

    return NULL;
}
void print(tnode* root, int u)
{
    struct tnode* temp;
    temp = root;
    if (root == NULL) return;
    else
    {
        print(temp->left, ++u);
        for (int i = 0; i < u; ++i) cout << "|";
        cout << temp->field << endl;
        u--;
    }
    print(root->right, ++u);
}

void treeprint(tnode* tree, int u)
{
    if (tree != NULL)
    {
        treeprint(tree->left, ++u);
        for (int i = 0; i < u; ++i) cout << "|";
        cout << tree->field << endl;
        u--;
    }
    if (tree != NULL) {
        treeprint(tree->right, ++u);
    }


}
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    struct tnode* temp, * root;
    root = init();
    temp = root;
    struct tnode* del_item;
    temp = addtreeManual(root, 1);
    temp = addtreeManual(root, 5);
    temp = addtreeManual(root, 4);
    temp = addtreeManual(root, 8);
    temp = addtreeManual(root, 2);
    temp = addtreeManual(root, 0);

    deleteTreeByValue(root, 8);
    temp = addtreeManual(temp, 9);



    cout << "Бинарное дерево: " << endl;
    treeprint(root, 0);
    cin.ignore().get();
    return 0;
}