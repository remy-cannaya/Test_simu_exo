#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#include "CUnit.h"
#include "Basic.h"
#include "Automated.h"
#include "Console.h"





enum danger {RAS, IMMINENT, GRAVE};
enum action_csc {FREINAGE, DECELARATION, RIEN};

bool detect_freinage = false;
bool freinage_auto = false;
bool demande_freinage_urgence = false;

struct info_radar
{
  bool detect;
  float distance;
};

struct info_CDB
{
  struct info_radar radar;
  bool detect_freinage;
};




struct message_danger
{
  float latitude;
  float longitude;
  float altitude;
  float vitesse;
  float dirx;
  float diry;
  /*time_t heure_courante = time();*/
  //time_t heure_expiration;
  /*enum danger;*/

};



/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }


/*
float distance_securite(float vitesse){
	return((vitesse/10.0)*6.0);
}


bool test_csc_break(bool detect_radar, float distance, float vitesse){
    	struct message_danger m;
	if(detect_radar == true){
	    if(distance < distance_securite(vitesse)){
	    freinage_auto = true;
	       printf("Le freinage automatique vient d'etre enclenche\n");
	    }
	    else{
	       printf("Aucune action du vehicule sur le systeme de freinage\n");
	    }
	}
	    else if(danger==RAS){
	    freinage_auto = true;
	    }
	else{
	    freinage_auto = false;
	}    
	return freinage_auto;
}*/



/************* Test case functions ****************/



void csc_test_1(void) {
  CU_ASSERT_EQUAL( test_csc_break(true,20.0,68.6),true);
  CU_ASSERT_EQUAL( test_csc_break(false,20.0,68.6),false);
}
/*
void csc_test_2(void) {
  CU_ASSERT_EQUAL( max(2,2), 2);
  CU_ASSERT_EQUAL( max(0,0), 0);
  CU_ASSERT_EQUAL( max(-1,-1), -1);
}

void csc_test_3(void) {
  CU_ASSERT_EQUAL( max(-1,-2), -2);
}
*/




/************* Test Runner Code goes here **************/

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "csc_test_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "csc_test_1", csc_test_1)) /*||
        (NULL == CU_add_test(pSuite, "csc_test_2", csc_test_2)) ||
        (NULL == CU_add_test(pSuite, "csc_test_3", csc_test_3))*/
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

  /* // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_automated_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");*/

   // Run all tests using the automated interface
   CU_automated_run_tests();
   CU_list_tests_to_file();

   // Run all tests using the console interface
   CU_console_run_tests();

   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
