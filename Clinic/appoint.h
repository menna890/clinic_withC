#pragma once
typedef struct appointment{
    int id_Dr ;
    int id_pat;
    int idapp ;
    float times;
    struct appointment*nx;
    char name [20];
}app;
typedef struct DR{
     char name[20];
     char specialization[20];
    int ID ;
    struct DR*nx;    
    app * appointments;
    int id_special;
}DR;
DR *list_dr =NULL;
DR * search_dr(int iddr){
    if(list_dr->ID==iddr){
        return list_dr;
    }
    else{
        DR* last=list_dr;
        while(last -> nx->ID!=iddr){
            last=last ->nx;
    }
    return last ->nx;
}
    
}
void add_appointment(int IDp,int ID_drrr, const char namep[20],float times){
    app* temp=(app*)malloc(sizeof(app));
    strcpy(temp ->name,namep);
    temp ->idapp=IDp;
    temp ->times=times;
    temp ->id_Dr=ID_drrr;
    temp ->nx=NULL;
    DR* temp_dr=(DR *)search_dr(ID_drrr);
    if(temp_dr->appointments==NULL){
         temp_dr->appointments=temp;
     }
     else{
         app* last=temp_dr->appointments;
         while(last ->nx!=NULL){
             last =last -> nx;
         }
         last->nx =temp;
     } 
}
void add_dr(int IDp, const char namep[20], int id_special, const char specialization[20]) {
    DR* temp = (DR*) malloc(sizeof(DR));
   // Initialize array members to zero
    memset(temp->name, 0, sizeof(temp->name));
    memset(temp->specialization, 0, sizeof(temp->specialization));
        
        strncpy(temp->name, namep, sizeof(temp->name) - 1);
        strncpy(temp->specialization,specialization, sizeof(temp->specialization) - 1);
    // Initialize the new node with given parameters
    temp->ID = IDp;
    temp->id_special = id_special;
    temp->nx = NULL;
   // Correct the assignment to check for NULL using '=='
    if (list_dr == NULL) {
        list_dr = temp;
    } else {
        DR* last = list_dr;
        while (last->nx != NULL) {
            last = last->nx;
        }
        last->nx = temp;
    }
}
void add_all_doctors(){
    // Example of adding doctors
    add_dr(1,"Dr. mahammed",1,"Cardiology");
    add_dr(2,"Dr.jack",1,"Cardiology");
    add_dr(3,"Dr.max",1,"Cardiology");
    add_dr(4,"Dr.hala",2,"Neurology");
    add_dr(5,"Dr.ali",2,"Neurology");
    add_dr(6, "Dr. Smith", 2, "Neurology");
    add_dr(7,"Dr.mona",3,"ENT (Ear, Nose, and Throat)");
    add_dr(8,"Dr.menna",3,"ENT (Ear, Nose, and Throat)");
    add_dr(9,"Dr.maram",3,"ENT (Ear, Nose, and Throat)");
    add_appointment(1,1,"Sunday",10.30);
    add_appointment(2,1,"Monday",10.30);
    add_appointment(3,1,"Monday",11.30);
    add_appointment(1,2,"Monday",5);
    add_appointment(2,2,"Monday",12);
    add_appointment(1,3,"Monday",9);
    add_appointment(2,3,"saturday",8);
    add_appointment(1,4,"Monday",8);
    add_appointment(2,4,"Sunday",9);
    add_appointment(1,5,"Wednesday",9);
    add_appointment(2,5,"Tuesday",9);
    add_appointment(1,6,"Monday",1);
    add_appointment(2,6,"Sunday",2);
    add_appointment(1,7,"Wednesday",10);
    add_appointment(2,7,"thursday",9);
    add_appointment(1,8,"thursday",11);    
    add_appointment(2,8,"thursday",1);
    add_appointment(1,9,"thursday",2);
    add_appointment(2,9,"Wednesday",11);
}