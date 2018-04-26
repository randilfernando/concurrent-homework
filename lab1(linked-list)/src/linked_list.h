/*
 * structure to store list node
 */
struct list_node_s {
    int data;
    struct list_node_s *next;
};

/*
 * function to check member
 */
int Member(int value, struct list_node_s *head_p) {
    struct list_node_s *current_p = head_p;

    while (current_p != NULL && current_p->data < value)
        current_p = current_p->next;

    if (current_p == NULL || current_p->data > value) {
        return 0;
    } else {
        return 1;
    }
}

/*
 * function to insert value
 */
int Insert(int value, struct list_node_s **head_p) {
    struct list_node_s *current_p = *head_p;
    struct list_node_s *prev_p = NULL;
    struct list_node_s *temp_p;

    while (current_p != NULL && current_p->data < value) {
        prev_p = current_p;
        current_p = current_p->next;
    }

    if (current_p == NULL || current_p->data > value) {
        temp_p = malloc(sizeof(struct list_node_s));
        temp_p->data = value;
        temp_p->next = current_p;

        if (prev_p == NULL) /*new 1st node*/
            *head_p = temp_p;
        else
            prev_p->next = temp_p;
        return 1;
    } else { /*value already is in list */
        return 0;
    }
}

/*
 * function to delete value
 */
int Delete(int value, struct list_node_s **head_p) {
    struct list_node_s *current_p = *head_p;
    struct list_node_s *prev_p = NULL;

    while (current_p != NULL && current_p->data < value) {
        prev_p = current_p;
        current_p = current_p->next;
    }

    if (current_p != NULL && current_p->data == value) {

        if (prev_p == NULL) { /*deleting 1st node*/
            *head_p = current_p->next;
            free(current_p);
        } else {
            prev_p->next = current_p->next;
            free(current_p);
        }
        return 1;
    } else { /*value is not in list */
        return 0;
    }

}