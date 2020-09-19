#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include <journal.h>
#define PROJECT_NAME    "journal"



void addtodo();
void viewtodo();
void mark_done();
void delete_todo();

struct todos
{
    char taskname[35];
    char time[6];
    char note[200];
    char status[1];
};

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */


/* Add your test functions in this format for testing*/
  CU_add_test(suite, "addtodo", test_add);
  CU_add_test(suite, "delete_todo", test_delete);
  CU_add_test(suite, "viewtodo", test_view);
  CU_add_test(suite, "mark_done", test_mark);


/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  
  /* run the unit test framework*/
  CU_basic_run_tests();
  
  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}
