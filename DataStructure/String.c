//written by talaxy

#include<stdio.h>
#include<stdlib.h>
#define STRINGMAX 100

typedef struct {
    char data[STRINGMAX];
    int length;
} String;

String * create_string() {
    String * str = (String *) malloc(sizeof(String));
    str->length = 0;
    return str;
}

int empty_string(String * str) {
    if (str->length) return 0;
    else return 1;
}

int full_string(String * str) {
    if (str->length == STRINGMAX) return 1;
    else return 0;
}


void add_string(String * str, char value) {
    if (!full_string(str)) {
        str->data[str->length] = value;
        str->length++;
    }
}

void pop_string(String * str) {
    if (!empty_string(str)) {
        str->length--;
    }
}

String * copy_string(char * origin, int length) {
    String * str = create_string();
    for (int i = 0; i < length; i++) {
        add_string(str, origin[i]);
    }
    return str;
}

void insert_string(String * str, int pos, char value) {
    if (pos >= 0 && pos < str->length) {
        if (!full_string(str)) {
            for (int i = str->length; i > pos; i--) {
                str->data[i] = str->data[i - 1];
            }
            str->data[pos] = value;
        }
        str->length++;
    }
}

void remove_string(String * str, int pos) {
    if (pos >= 0 && pos < str->length)  {
        str->length--;
        for (int i = pos; i < str->length; i++) {
            str->data[i] = str->data[i + 1];
        }
    }
}

void assign_string(String * str, int pos, char value) {
    if (pos >= 0 && pos < str->length) {
        str->data[pos] = value;
    }
}

int find_string(String * str, char value) {
    int pos = -1;
    for (int i  = 0; i < str->length; i++) {
        if (str->data[i] == value) {
            pos = i;
            break;
        }
    }
    return pos;
}

String * substr_string(String * str, int pos, int length) {
    int end = pos + length;
    if (pos < 0 || length < 1 || end > str->length) return NULL;
    String * substr = create_string();
    for (int i = pos; i < end; i++) {
        add_string(substr, str->data[i]);
    }
    return substr;
}

String * merge_string(String * s1, String * s2) {
    String * str = create_string();
    for (int i = 0; i < s1->length; i++) {
        add_string(str, s1->data[i]);
    }
    for (int i = 0; i < s2->length; i++) {
        add_string(str, s2->data[i]);
    }
    return str;
}

int compare_string(String * s1, String * s2) {
    int length = s1->length;
    if (s2->length < length) length = s2->length;
    for (int i = 0; i < length; i++) {
        if (s1->data[i] < s2->data[i]) {
            return -1;
            break;
        }
        else if (s1->data[i] > s2->data[i]) {
            return 1;
            break;
        }
    }
    if (s1->length < s2->length) return -1;
    else if (s1->length > s2->length) return 1;
    else return 0;
}

void print_string(String * str) {
    if (!str) return;
    for (int i = 0; i < str->length; i++) {
        printf("%c", str->data[i]);
    }
}

void delete_string(String * str) {
    free(str);
}

int find_str_string(String * s, String * t) {
    int i = 0, j = 0;
    while (i < s->length && j < s->length) {
        if (s->data[i] == t->data[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
        if (j == t->length) return i - t->length;
    }
    return -1;
}

int kmp_string(String * s, String * t) {
    int next[STRINGMAX];
    next[0] = -1;
    int i = 0, j = -1;
    while (i < t->length) {
        if (j == -1 || t->data[i] == t->data[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else j = next[j];
    }
    i = j = 0;
    while (i < s->length && j < t->length) {
        if (j == -1 || s->data[i] == t->data[j]) {
            i++;
            j++;
        }
        else j = next[j];
        if (j == t->length) return i - t->length;
    }
    return -1;
}