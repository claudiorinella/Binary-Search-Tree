#include <stdio.h>

#include <stdlib.h>

#if !defined TRUE && !defined FALSE
# define TRUE 1
# define FALSE 0
# endif

typedef int Boolean;

#ifndef NULL
# define NULL((void * ) 0)
# endif

struct btree {
  int value;
  struct btree * left_ptr;
  struct btree * right_ptr;
};

/*Definitions and comments of the functions at line 254*/




/*============Declarations=============*/
void visit_r(struct btree * ptr);
void visit_pre(struct btree * ptr);
void visit_post(struct btree * ptr);
void insert_inorder(struct btree ** ptrptr, int value);
void init(struct btree ** ptrptr);
Boolean search(struct btree * ptr, int target);
int VisitAndCopy(struct btree * ptr, int * C, int i);
void Common_Elem(struct btree * ptr1, struct btree * ptr2, struct btree ** ptr3, int a, int b);
int n_elem_min(struct btree * pointer, int s, int d);
int depth(struct btree * point, int d);




/*=============MAIN===================*/

int main() {
  struct btree * punt;
  init( & punt);

  struct btree * ptr;
  init( & ptr);

  int * Ta, na;
  int i;
  Boolean exit = FALSE;

  do {

    printf("\n\n It is possible to create a Binary Search Tree named T alpha.");
    printf("\n\n How many elements does the user want to insert? Enter a number.\n");

    scanf("\n%d", & na);
    if (na > 0 && na < 100) {
      Ta = calloc(na, sizeof(int));
      printf("\n\n Enter %d numbers\n", na);

      for (i = 0; i < na; i++) {
        scanf("\n%d", & Ta[i]);
        insert_inorder( & punt, Ta[i]);
        exit = TRUE;
      }
    } else
      printf("\n\n Enter a numeric value (positive and smaller than 100) \n\n");

  }

  while (exit == FALSE);

  printf("\n\n now we will make a visit of T alpha \n\n");
  visit_pre(punt);

  exit = FALSE;
  int * Tb, nb;
  do {

    printf("\n\n It is possible to create a Binary Search Tree named T beta.");
    printf("\n\n How many elements does the user want to insert? Enter a number.");

    scanf("\n%d", & nb);
    if (nb > 0 && nb < 100) {
      Tb = calloc(nb, sizeof(int));
      printf("\n\n Enter %d numbers", nb);

      for (i = 0; i < nb; i++) {
        scanf("\n%d", & Tb[i]);
        insert_inorder( & ptr, Tb[i]);
        exit = TRUE;
      }
    } else
      printf("\n\n Enter a numeric value (positive and smaller than 100) \n\n");

  }
  while (exit == FALSE);

  printf("\n\n now we will make a visit of T beta \n\n");
  visit_pre(ptr);

  exit = FALSE;
  int m;
  m = 0;
  int target;
  char choose;

  /*USE OF n_elem_min in T ALPHA*/

  do {

    printf("\n\n It is possible to know how many elements are smaller than one "
      "chosen in T alpha\n\n");
    printf("\n\nDo you want to get this information?  Enter 'y' or 'n' \n\n");
    scanf("%s", & choose);

    switch (choose) {
    case 'y':
      printf("\n\n Enter the number \n\n");
      scanf("%d", & target);
      m = n_elem_min(punt, target, m);
      printf("\n\n The values smaller than %d in T alpha are %d \n\n ", target,
        m);
      m = 0;
      choose = 0;
      break;

    case 'n':
      printf("\n Let's move on\n");
      choose = 0;
      exit = TRUE;
      break;

    default:
      printf("\n\n You should had entered 'y' or 'n'.");
      choose = 0;
      break;
    }
  } while (exit == FALSE);

  /*USE OF n_elem_min in T BETA*/

  exit = FALSE;

  do {

    printf("\n\n It is possible to know how many elements are smaller than one "
      "chosen in T beta\n\n");
    printf("\n\nDo you want to get this information? Enter 'y' or 'n' \n\n");
    scanf("%s", & choose);

    switch (choose) {
    case 'y':
      printf("\n\n Enter the number \n\n");
      scanf("%d", & target);
      m = n_elem_min(ptr, target, m);
      printf("\n\n The values smaller than %d in T beta are %d \n\n ", target,
        m);
      m = 0;
      choose = 0;
      break;

    case 'n':
      printf("\n Let's move on\n");
      choose = 0;
      exit = TRUE;
      break;

    default:
      printf("\n\n You should had entered 'y' or 'n'.");
      choose = 0;
      break;
    }
  } while (exit == FALSE);

  /*USE OF depth IN T ALPHA*/

  do {

    printf("\n\n It is possible to know the depth T alpha\n\n");
    printf("\n\nDo you want to get this information? Enter 'y' or 'n' \n\n");
    scanf("%s", & choose);

    switch (choose) {
    case 'y':
      m = -1;
      m = depth(punt, m);
      printf("\n\n the maximum depth of T alpha is %d \n\n", m);
      choose = 0;
      exit = TRUE;
      break;

    case 'n':
      printf("\n Let's move on\n");
      choose = 0;
      exit = TRUE;
      break;

    default:
      printf("\n\n You should had entered 'y' or 'n'.");
      choose = 0;
      break;
    }
  } while (exit == FALSE);

  exit = FALSE;

  do {

    printf("\n\n It is possible to know the depth T beta\n\n");
    printf("\n\nDo you want to get this information? Enter 'y' or 'n' \n\n");
    scanf("%s", & choose);

    switch (choose) {
    case 'y':
      m = -1;
      m = depth(ptr, m);
      printf("\n\n the maximum depth of T beta is %d \n\n", m);
      choose = 0;
      exit = TRUE;
      break;

    case 'n':
      printf("\n Let's move on\n");
      choose = 0;
      exit = TRUE;
      break;

    default:
      printf("\n\n You should had entered 'y' or 'n'.");
      choose = 0;
      break;
    }
  } while (exit == FALSE);

  printf("\n\nI gave you all the information I could give! Goodbye\n\n");

  free(ptr);
  free(punt);
  free(Ta);
  free(Tb);

  return 0;
}





/*============DEFINITIONS===============*/

/*n_elem_min returns the number of nodes of the tree*/

int n_elem_min(struct btree * pointer, int s, int d) {
  if (pointer == NULL)
    return d;
  else if ((pointer -> value) < s) {
    d++;
    d = n_elem_min(pointer -> left_ptr, s, d);
    d = n_elem_min(pointer -> right_ptr, s, d);

  } else {
    d = n_elem_min(pointer -> left_ptr, s, d);
  }

  return d;
}





/*"depth" returns the number which represents how deep is the tree*/

int depth(struct btree * point, int d) {
  if (point -> left_ptr == NULL && point -> right_ptr == NULL) {

    d++;
    return d;

  } else if (point -> left_ptr != NULL && point -> right_ptr == NULL)
    return depth(point -> left_ptr, d + 1);

  else if (point -> left_ptr == NULL && point -> right_ptr != NULL)
    return depth(point -> right_ptr, d + 1);

  else {

    int a, b;
    a = depth(point -> left_ptr, d + 1);
    b = depth(point -> right_ptr, d + 1);
    if (a > b)
      return depth(point -> left_ptr, d + 1);
    else
      return depth(point -> right_ptr, d + 1);
  }
}




void visit_r(struct btree * ptr) {
  if (ptr != NULL) {

    visit_r(ptr -> left_ptr);
    printf("\n I print the value: %d \n\n", ptr -> value);

    visit_r(ptr -> right_ptr);
  }
  printf("Let's go back... \n\n");
}




/*visit_pre= pre-order visit of the tree*/

void visit_pre(struct btree * ptr) {
  if (ptr != NULL) {
    printf("%d\n\n", ptr -> value);
    visit_pre(ptr -> left_ptr);
    visit_pre(ptr -> right_ptr);
  }
}




/* visit_post= post-visit of tree*/

void visit_post(struct btree * ptr) {
  if (ptr != NULL) {
    visit_post(ptr -> left_ptr);
    visit_post(ptr -> right_ptr);
    printf("%d\n\n", ptr -> value);
  }
}




/*"insert_inorder" will add a new element to the tree*/

void insert_inorder(struct btree ** ptrptr, int value) {
  if ( * ptrptr != NULL) { // NON è una foglia
    if (value <= ( * ptrptr) -> value) // si discende l’albero
      insert_inorder( & (( * ptrptr) -> left_ptr), value);
    else
      insert_inorder( & (( * ptrptr) -> right_ptr), value);
  } else { // foglia raggiunta... aggiungi elemento
    ( * ptrptr) = (struct btree * ) malloc(sizeof(struct btree));
    ( * ptrptr) -> value = value; // metti valore
    ( * ptrptr) -> left_ptr = NULL; // inizializza figli...
    ( * ptrptr) -> right_ptr = NULL; // a NULL.
  }
}




void init(struct btree ** ptrptr) {
  * ptrptr = NULL;
}




/*"search" will search a number in the tree*/
Boolean search(struct btree * ptr, int target) {
  if (ptr != NULL) { // it is not a leave
    if (ptr -> value == target) { // found
      return TRUE;
    } else { // not found

      if (target < ptr -> value) // go to the left
        return search(ptr -> left_ptr, target);
      else // or go to the right
        return search(ptr -> right_ptr, target);
    }
  } else // else the number is not in the tree
    return FALSE;
}




/*"VisitAndCopy" will copy the number of the tree in a array 
 *and it will return the number of nodes of the tree*/

int VisitAndCopy(struct btree * ptr, int * C, int i) {

  if (ptr == NULL) {
    return i;
  }
  C[i] = ptr -> value;
  i++;
  if (ptr -> left_ptr != NULL) {
    i = VisitAndCopy(ptr -> left_ptr, C, i);
  }
  if (ptr -> right_ptr != NULL) {
    i = VisitAndCopy(ptr -> right_ptr, C, i);
  }

  return i;
}




/*"Common_Elem" takes as input two pointers of two trees,
    How many nodes they have
    and it will return a tree having the common elements
    of the two trees*/

void Common_Elem(struct btree * ptr1, struct btree * ptr2, struct btree ** ptr3,
  int a, int b) {

  int i = 0;
  int * A;
  A = (int * ) calloc(a, sizeof(int));
  i = VisitAndCopy(ptr1, A, i);
  int * B;
  B = (int * ) calloc(b, sizeof(int));
  int j = 0;
  j = VisitAndCopy(ptr2, B, j);

  init(ptr3);

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if (A[i] == B[j]) {
        int val;
        val = A[i];
        insert_inorder(ptr3, val);

        free A;
        free B;
      }
    }
  }
}
