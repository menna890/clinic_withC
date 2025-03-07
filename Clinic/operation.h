#include"patientdetails.h"
int choice;
int idDr, idPat, idAppointment, spec; 
void delete_account(int idpat);
void reservation(int id_App, int iddr, int idpat,int idsp);
void change_reservation(int idpat);
void delete_reservationpat(int idpat,int id_app,int id_Dr);
int operation(int idPatient){
    int idDr, idAppointment, spec;
    printf("Available specializations:\n1_Cardiology 2_Neurology 3_ENT\n");
                printf("Which specialization do you need? ");
                scanf("%d", &spec);
                 switch (spec) {
                            case 1:
                            case 2:
                            case 3:
                                print_info_spcial(spec);
                                  break;
                           default:
                            printf("Invalid option. Please try again.\n");
                                break;
                 }
                printf("\nEnter the ID of the doctor you choose: ");
                scanf("%d", &idDr);
                printf("Enter the ID of the appointment you choose: ");
                scanf("%d", &idAppointment);
                reservation(idAppointment, idDr, idPatient,spec);
                print_info_patient(idPatient);
                printf("\nwhat you want ? \n1_Change_reservation\n2_Delete_account\n3_add\n4_show my profile\n0_Exit\n");
                scanf("%d", &choice);
                return choice;
    
}


void change_reservation(int idpat){
        int iddr,appointment,ch, last_app,last_dr;
        printf("please enter the number of appointment you want to change");
        scanf("%d",&last_app);
        printf("please enter the number of doctor you want to change");
        scanf("%d",&last_dr);
        printf("which specialization Do you want ? 1_ Neurology 2_ Cardiology 3_  Dentistry ");
        scanf("%d",&ch);
        print_info_spcial(ch);
        printf("which appointment suits you ,please Enter the number ");
        printf("number of DR :");
        scanf("%d",&iddr);
        printf("number of appointment :");
        scanf("%d",&appointment);
        print_info_patient(idpat);
        delete_reservationpat( idpat,last_app,last_dr);
        reservation(appointment,iddr,idpat,ch);
}
void delete_reservationpat(int idpat,int id_app,int id_Dr){
    patient*temp=(patient*)search_patient(idpat);
    app *temp_appoint=(app*)search_Appointment(id_Dr,id_app);
if (temp ->appointments->idapp==id_app){
    add_appointment(temp->appointments->idapp,temp ->appointments ->id_Dr,temp ->appointments ->name,temp ->appointments ->times);
    if(temp ->appointments->nx==NULL){
        temp ->appointments=NULL;
    }
    else{
    temp ->appointments=temp ->appointments->nx;
}
}
else{
    app* last=temp ->appointments;
    while(last->nx->idapp!=id_app){
        last=last->nx;
    }
    add_appointment(last->nx->idapp,last->nx ->id_Dr,last->nx->name,last->nx->times);
    
}
        
    }
void delete_account(int idpat){
    patient* temppat=(patient*)search_patient(idpat);
    if (list_patient->ID==temppat->ID){
        patient* delete=list_patient;
        list_patient=list_patient ->nx;
        free(delete);}
    else{
        patient* last=list_patient;
        while(last->nx->ID!=idpat){
            last=last->nx;
        }
        patient* delete=last->nx;
        last->nx=last->nx->nx;
        free(delete);
        printf("Your account was deleted....");
    }
}
void reservation(int id_App, int iddr, int idpat,int idsp) {
    DR* tempdr = (DR*)search_dr(iddr);
    patient* temppat = (patient*)search_patient(idpat);

    if (temppat == NULL) {
        printf("No patient with ID %d registered. Please register first.\n", idpat);
        return;
    }
    if (tempdr == NULL&&tempdr->id_special!=idsp) {
        printf("No doctor with ID %d found.\n", iddr);
        return;
    }
if (temppat->appointments==NULL){
    temppat->appointments = (app*)search_Appointment(iddr, id_App);
    delete_appointmentfromdr(id_App, iddr);}
else{
    app*last=temppat->appointments;
    while(last->nx!=NULL){
        last=last->nx;
    }
last->nx = (app*)search_Appointment(iddr, id_App);
delete_appointmentfromdr(id_App, iddr);
}    
}
    
