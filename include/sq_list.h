#define LISTT_INIT_SIZE 100
#define LIST_INCREMENT 10

/*define the datastructure of a sequence list*/
typedef struct{
    int *elem;
    int length;
    int listsize;
} SQ_LIST;
