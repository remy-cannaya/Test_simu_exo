#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float distance_securite(float vitesse){
	return((vitesse/10.0)*6.0);
}

bool test_csc_break(bool detect_radar, float distance, float vitesse){
	bool freinage_auto;
    	if(detect_radar == true){
	    if(distance < distance_securite(vitesse)){
	    freinage_auto = true;
	       printf("Le freinage automatique vient d'etre enclenche\n");
	    }
	    else{
	       printf("Aucune action du vehicule sur le systeme de freinage\n");
	    }
	}
	    /*else if(danger==RAS){
	    freinage_auto = true;
	    }*/
	else{
	    freinage_auto = false;
	}    
	return freinage_auto;
}
