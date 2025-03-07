#include <stdlib.h>
#include <stdio.h>
#include "patientface.h"
#include"doctors.h"
#include"Admin.h"
void main (void){
    add_all_doctors();
    while(1){
    printf("\n1_Admin\n2_User? Enter 0 to exit.\n");
    scanf("%d", &choice);
 switch (choice) {
        case 1:
            admin();    
        break;
        case 2:
            patient_mode();
        break;
        default:
        printf("Invalid option. Please try again.\n");
                break;
                
        } 
        
//        if (choice == 0){
            continue;// Exit the loop and end the program
//}
}
}