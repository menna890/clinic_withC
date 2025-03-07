#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"doctors.h"
typedef struct patient{
    app * appointments;
    char name [20];
    int ID    ;
    struct patient*nx;
    int id_appointment;
}patient;
patient*list_patient=NULL;
patient* search_patient(int idpat) {
    patient* current = list_patient;
    while (current != NULL) {
        if (current->ID == idpat) {
            return current;  // Patient found
        }
        current = current->nx;
    }
    return NULL;  // No patient found
}
void add_patient(int IDp, const char namep[20]) {
    if (search_patient(IDp) != NULL) {
        printf("Patient with phonenumber %d is already registered.\n", IDp);
        return;  // Exit the function if patient already exists
    }

    // If the patient does not exist, proceed to add them
    patient* temp = (patient*)malloc(sizeof(patient));
    if (temp == NULL) {
        printf("Failed to allocate memory for new patient.\n");
        return;
    }
    memset(temp->name, 0, sizeof(temp->name));
    strncpy(temp->name, namep, sizeof(temp->name) - 1);
    temp->ID = IDp;
    temp->nx = NULL;

    if (list_patient == NULL) {
        list_patient = temp;
    } else {
        patient* last = list_patient;
        while (last->nx != NULL) {
            last = last->nx;
        }
        last->nx=temp;
    }
}
void print_info_patient(int idp){
    patient*tempp=(patient*)search_patient(idp);
     printf("hello : %s \nyour phone : %d\n",tempp->name,tempp->ID);
    if(tempp->appointments->nx==NULL){
     DR*tempdr=(DR*)search_dr(tempp->appointments->id_Dr);
    printf("\nyour reservation is in %s ,with DR/\" %s \"\n",tempdr->specialization,tempdr ->name);
    printf("in the day : %s\nthe time : %.2f AM\n",tempp->appointments->name,tempp->appointments->times);
    }    
    else{
        app*last=tempp->appointments;
        while(last->nx){
     DR*tempdr=(DR*)search_dr(last->id_Dr);
    printf("\nyour reservation is in %s ,with DR/\" %s \"\n",tempdr->specialization,tempdr ->name);
    printf("in the day : %s\nthe time : %.2f AM\n",last->nx->name,last->nx->times);
    last=last->nx;

        }


    }
}
