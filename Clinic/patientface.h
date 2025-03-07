#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"operation.h"
int choice;
void interface();
void patient_mode(){
//    char name[20];
int idDr=0, idPatient=0, idAppointment=0, spec=0;
//    int idPat;
     interface();
                   if(choice==0){
                      return ;
                   }
                
                                
}
void interface(){
    char name[20];
    bool flag= true;
     while(flag){
                printf("Enter your name:");
                scanf("%s",name); 
                printf("\nPlease Enter your numberphone : ");
                scanf("%d",&idPat); 
           // Check if patient is registered
                if (search_patient(idPat) != NULL) {
                    printf("Welcome back, %s!\n", name);
                    print_info_patient(idPat);
                    printf("\nwhat you want ? \n1_Change_reservation\n2_Delete_account\n3_add\n4_show my profile\n0_Exit\n");
                    scanf("%d", &choice);
                    
                } 
                else {
                    printf("New patient! Adding to system...\n");
                    add_patient(idPat, name);
                     operation(idPat); 
                    // print_info_patient(idPatient);  
                }
                
                switch(choice){
                case 1: 
                    change_reservation(idPat);
                    break;
                case 2:
                    delete_account(idPat);
                    break;
                case 3:
                    operation(idPat); 
                    break;
                case 4:
                    print_info_patient(idPat);
                    break;
                case 0:
                    flag=false;
                    break;
                   }
                   
}
    
}