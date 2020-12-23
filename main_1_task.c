#include <stdio.h>
#include <stdlib.h>

struct ListElement {
    struct ListElement* next;  
    int data; };
typedef struct ListElement ListElement;

struct MyList {
    ListElement* head; 
    int kol; 
};
typedef struct MyList MyList;

void Add_MyList(MyList* s, int i) {
    if (i == 1) {
        ListElement* s1 = (ListElement*) malloc( sizeof(ListElement) );
        printf("E+nter data\n");
        scanf("%d",&s1->data);
        s1->next = s->head;
        s->head = s1;
        s->kol++;
        return 0;
    }
    if(i != s->kol+1) {
        int j = 1;
        ListElement* s1 = s->head;
        while (j != i-1)
        {
            s1 = s1->next;
            j++;
        }

        ListElement* s2 = (ListElement*) malloc( sizeof(ListElement) );
        printf("Enter data\n");
        scanf("%d",&s2->data);

        s2->next = s1->next;
        s1->next = s2;

        s->kol++;
    }
    else if(i == s->kol+1) {
        int j = 1;
        ListElement* s1 = s->head;
        while (j != s->kol) {
            s1 = s1->next;
            j++;
        }
        ListElement* s2 = (ListElement*) malloc( sizeof(ListElement) );
        printf("Enter data\n");
        scanf("%d",&s2->data);

        s2->next = NULL;
        s1->next = s2;

        s->kol++;
    }

    return 0;

}

void Delete_Element(MyList* s, int i) {
    if (i == 1) {
        ListElement* h = s->head;
        s->head = s->head->next;
        free(h);
        return 0;
    }
    int j = 1;
    ListElement* s1 = s->head;
    while (j != i-1) {
        s1 = s1->next;
        j++;
    }

    ListElement* sn = s1->next;
    s1->next = s1->next->next;

    free(sn);

    s->kol--;
    return 0;

}

void See_MyList(MyList* s) {
    ListElement* s1 = s->head;
    int i = 0;
    while (i!=s->kol) {
        printf("element %d: %d\n",i+1,s1->data);
        s1 = s1->next;
        i++;
    }
}


void Menu(MyList** s) {
    printf("1 - Add element \n2 - Delete element \n3 - See my List\n");
    int i;
    scanf("%d",&i);
    switch(i) {
        case 1:
            printf("Where to add the element?\n");
            int j;
            scanf("%d",&j);
            Add_MyList(*s,j);
            Menu(s);

        case 2:
            printf("Where to delete the element?\n");
            int k;
            scanf("%d",&k);
            Delete_Element(*s,k);
            Menu(s);

        case 3:
            See_MyList(*s);
            Menu(s);

        default:
                printf("You entered the wrong number\n");
                Menu(s);
    }
}

int main(void) {
    MyList s;
    s.head = NULL;

    s.kol = 0;
    MyList* s1 = &s;
    Menu(&s1);

    return 0;
}