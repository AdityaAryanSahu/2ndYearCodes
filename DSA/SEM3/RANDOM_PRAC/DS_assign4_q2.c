#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FILE_NODE, DIR_NODE } NodeType;

typedef struct Node {
    char name[100];
    NodeType type;
    int size;
    struct Node* parent;
    struct Node* children;
    struct Node* next;
} Node;

void create(Node* parent, const char* name, NodeType type, int size) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->type = type;
    newNode->size = (type == FILE_NODE) ? size : 0;
    newNode->parent = parent;
    newNode->children = NULL;
    newNode->next = parent->children;
    parent->children = newNode;
}

void deleteNode(Node* node) {
    if (node->type == DIR_NODE) {
        Node* child = node->children;
        while (child) {
            Node* nextChild = child->next;
            deleteNode(child);
            child = nextChild;
        }
    }
    free(node);
}

void deleteNodeByName(Node* parent, const char* name) {
    Node* prev = NULL;
    Node* curr = parent->children;

    while (curr != NULL && strcmp(curr->name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        if (prev == NULL) {
            parent->children = curr->next;
        } else {
            prev->next = curr->next;
        }
        deleteNode(curr);
    }
}

void listContents(Node* dir) {
    if (dir->type != DIR_NODE) {
        printf("%s is not a directory.\n", dir->name);
        return;
    }
    Node* child = dir->children;
    while (child != NULL) {
        printf("%s (%s)\n", child->name, (child->type == DIR_NODE) ? "DIR" : "FILE");
        child = child->next;
    }
}

Node* moveNode(Node* sourceParent, const char* name, Node* destParent) {
    Node* prev = NULL;
    Node* curr = sourceParent->children;

    while (curr != NULL && strcmp(curr->name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        if (prev == NULL) {
            sourceParent->children = curr->next;
        } else {
            prev->next = curr->next;
        }

        curr->next = destParent->children;
        destParent->children = curr;
        curr->parent = destParent;
        return curr;
    }

    printf("Node %s not found in %s.\n", name, sourceParent->name);
    return NULL;
}

Node* findNode(Node* root, const char* name) {
    if (strcmp(root->name, name) == 0) {
        return root;
    }
    if (root->type == DIR_NODE) {
        Node* child = root->children;
        while (child != NULL) {
            Node* found = findNode(child, name);
            if (found) return found;
            child = child->next;
        }
    }
    return NULL;
}

int calculateSize(Node* dir) {
    if (dir->type == FILE_NODE) {
        return dir->size;
    }
    int totalSize = 0;
    Node* child = dir->children;
    while (child != NULL) {
        totalSize += calculateSize(child);
        child = child->next;
    }
    return totalSize;
}

int main() {
    Node* root = (Node*)calloc(1, sizeof(Node));

    strcpy(root->name, "root");
    root->type = DIR_NODE;

    create(root, "dir1", DIR_NODE, 0);
    create(root, "file1.txt", FILE_NODE, 100);

    Node* dir1 = findNode(root, "dir1");
    create(dir1, "file2.txt", FILE_NODE, 200);
    create(dir1, "dir2", DIR_NODE, 0);

    printf("Contents of root:\n");
    listContents(root);
    printf("\nContents of dir1:\n");
    listContents(dir1);

    printf("\nMoving file2.txt to root\n");
    moveNode(dir1, "file2.txt", root);
    printf("\nAfter moving,\nContents of root:\n");
    listContents(root);
    printf("\nContents of dir1:\n");
    listContents(dir1);

    printf("\nFinding dir2 recursively:\n");
    Node* dir2 = findNode(root, "dir2");
    if (dir2) {
        printf("Found: %s\n", dir2->name);
    } else {
        printf("dir2 not found.\n");
    }

    printf("\nTotal size of root: %d\n", calculateSize(root));

    printf("\nDeleting dir1\n");
    deleteNodeByName(root, "dir1");
    printf("\nAfter deletion, contents of root:\n");
    listContents(root);

    deleteNode(root);
    return 0;
}
